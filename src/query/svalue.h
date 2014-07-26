/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * Licensed under the MIT license (see LICENSE).
 */
#ifndef _FNORDMETRIC_QUERY_SVALUE_H
#define _FNORDMETRIC_QUERY_SVALUE_H
#include <stdlib.h>
#include <string>
#include <vector>
#include <assert.h>

namespace fnordmetric {
namespace query {
class Token;

class SValue {
public:
  enum kSValueType {
    T_STRING,
    T_FLOAT,
    T_INTEGER,
    T_BOOL,
    T_UNDEFINED
  };

  explicit SValue();
  explicit SValue(const std::string& string_value);
  explicit SValue(int64_t integer_value);
  explicit SValue(double float_value);
  explicit SValue(bool bool_value);
  explicit SValue(const char* str_value, size_t len, bool copy);
  SValue(const SValue& copy);
  SValue& operator=(const SValue& copy);
  bool operator==(const SValue& other) const;
  ~SValue();

  static std::string makeUniqueKey(SValue* arr, size_t len);

  template <typename T> T getValue() const;
  kSValueType getType() const;
  int64_t getInteger() const;
  double getFloat() const;
  bool getBool() const;
  const std::string getString() const;
  std::string toString() const;

  static SValue* fromToken(const Token* token);

protected:
  struct {
    kSValueType type;
    union {
      int64_t t_integer;
      double t_float;
      bool t_bool;
      struct {
        char* ptr;
        uint32_t len;
      } t_string;
    } u;
  } data_;
};

}
}
#endif