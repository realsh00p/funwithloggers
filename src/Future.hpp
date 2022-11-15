#pragma once

#include "LogStream.hpp"
#include "Logger.hpp"
#include "Result.hpp"

#include <future>
#include <sstream>

template <typename T>
auto operator<<(LogStream &ls, std::future<T> f) -> LogStream & {
  if (!f.valid()) {
    return ls << "<invalid future>";
  }
  return ls << f.get();
}
