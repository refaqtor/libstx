// This file is part of the "x0" project, http://xzero.io/
//   (c) 2009-2014 Christian Parpart <trapni@gmail.com>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <xzero/IdleTimeout.h>
#include <xzero/DateTime.h>
#include <xzero/executor/NativeScheduler.h>
#include <xzero/WallClock.h>
#include <gtest/gtest.h>
#include <memory>

using namespace xzero;

TEST(NativeScheduler, executeAfter_without_handle) {
  WallClock* clock = WallClock::system();
  NativeScheduler scheduler;
  DateTime firedAt, start;
  int fireCount = 0;

  start = clock->get();

  printf("before executeAfter(): %f\n", start.value());
  auto handle = scheduler.executeAfter(TimeSpan::fromMilliseconds(3000), [&](){
    printf("fired at: %f\n", clock->get().value());
    firedAt = clock->get();
    fireCount++;
  });

  scheduler.runLoopOnce();

  double diff = firedAt.value() - start.value();
  printf("diff: %f\n", diff);
  printf("after runLoopOnce(): %f\n", clock->get().value());

  ASSERT_EQ(1, fireCount);
  ASSERT_NEAR(3, diff, 0.05);
}

TEST(NativeScheduler, DISABLED_cancelBeforeRun) {
  WallClock* clock = WallClock::system();
  NativeScheduler scheduler;
  int fireCount = 0;

  auto handle = scheduler.executeAfter(TimeSpan::fromSeconds(1), [&](){
    fireCount++;
  });
  handle->cancel();

  scheduler.runLoopOnce();

  ASSERT_EQ(0, fireCount);
}
