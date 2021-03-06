/**
 * This file is part of the "libstx" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * libstx is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef _STX_JSON_JSONRPC_H
#define _STX_JSON_JSONRPC_H
#include <functional>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>
#include "stx/json/jsonrpchttpadapter.h"
#include "stx/reflect/reflect.h"

namespace stx {
namespace json {
class JSONRPCRequest;
class JSONRPCResponse;

class JSONRPC {
public:

  JSONRPC();

  void dispatch(JSONRPCRequest* req, JSONRPCResponse* res);

  template <class ServiceType>
  void registerService(ServiceType* service);

  template <class MethodType>
  void registerMethod(
      const std::string& method_name,
      MethodType* method_call,
      typename MethodType::ClassType* service);

  void registerMethod(
      const std::string& method,
      std::function<void (JSONRPCRequest* req, JSONRPCResponse* res)> handler);

protected:
  template <class ClassType>
  class ReflectionTarget {
  public:
    ReflectionTarget(JSONRPC* self, ClassType* service);

    template <typename MethodType>
    void method(MethodType* method_call);

    template <typename RPCCallType>
    void rpc(RPCCallType rpccall);

  protected:
    JSONRPC* self_;
    ClassType* service_;
  };

  std::unordered_map<
      std::string,
      std::function<void (JSONRPCRequest* req, JSONRPCResponse* res)>>
      handlers_;
};

} // namespace json
} // namespace stx

#include "jsonrpc_impl.h"
#endif
