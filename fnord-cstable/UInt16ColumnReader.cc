/**
 * This file is part of the "libfnord" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <fnord-cstable/UInt16ColumnReader.h>

namespace fnord {
namespace cstable {

UInt16ColumnReader::UInt16ColumnReader(
    void* data,
    size_t size) :
    reader_(data, size) {}

bool UInt16ColumnReader::next(
    uint64_t* rep_level,
    uint64_t* def_level,
    uint16_t* data) {
  *rep_level = *reader_.readUInt8();
  *def_level = 0;
  *data = *reader_.readUInt16();
  return true;
}

} // namespace cstable
} // namespace fnord