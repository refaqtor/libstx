// This file is part of the "libxzero" project, http://xzero.io/
//   (c) 2009-2015 Christian Parpart <trapni@gmail.com>
//   (c) 2014-2015 Paul Asmuth
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT
#pragma once

#include <unordered_map>

namespace xzero {
namespace reflect {

template <class ClassType>
class MetaClass {
public:
  template <class TargetType>
  static void reflectMethods(TargetType* target);

  template <class TargetType>
  static void reflectProperties(TargetType* target);

  template <class TargetType>
  static void reflect(TargetType* target);

  template <class TargetType>
  static void serialize(const ClassType& instance, TargetType* target);

  template <class TargetType>
  static ClassType unserialize(TargetType* target);

};

template <typename TargetType>
struct DummyTarget {};

template<typename T, typename X = void>
struct is_reflected : std::false_type {};

template<typename T>
struct is_reflected<
    T,
    decltype(T::reflect((xzero::reflect::DummyTarget<T>*) nullptr))> :
        std::true_type {};

template <class ClassType>
template <class TargetType>
void MetaClass<ClassType>::reflect(TargetType* target) {
  ClassType::reflect(target);
}

}
}
