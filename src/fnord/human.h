/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2015 Laura Schlimmer, Paul Asmuth
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "fnord/stdtypes.h"
#include "fnord/UnixTime.h"
#include "fnord/duration.h"
#include "fnord/option.h"

namespace fnord {

enum class HumanDataType {
  DATETIME,
  DATETIME_NULLABLE,
  URL,
  URL_NULLABLE,
  CURRENCY,
  CURRENCY_NULLABLE,
  UNSIGNED_INTEGER,
  UNSIGNED_INTEGER_NULLABLE,
  SIGNED_INTEGER,
  SIGNED_INTEGER_NULLABLE,
  FLOAT,
  FLOAT_NULLABLE,
  BOOLEAN,
  BOOLEAN_NULLABLE,
  TEXT,
  UNKNOWN
};

class Human {
public:

  static Option<Duration> parseDuration(const String& str);

  static Option<UnixTime> parseTime(const String& str);

  static HumanDataType detectDataType(
      const String& value,
      HumanDataType prev = HumanDataType::UNKNOWN);

};

}
