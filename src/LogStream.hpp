#pragma once

#include <iostream>
#include <sstream>
#include <type_traits>
#include <utility>

class LogStream {
public:
  ~LogStream();

  auto operator<<(std::ostringstream v) -> LogStream &;
  auto operator<<(std::string v) -> LogStream &;
  auto operator<<(const char *v) -> LogStream &;
};

template <typename T>
auto operator<<(LogStream &&ls, T &&t) -> LogStream & {
  return ls << "custom: " << std::forward<T>(t);
}

template <typename T>
auto operator<<(LogStream &ls, T &&t)
    -> std::enable_if_t<std::is_fundamental_v<T>, LogStream> & {
  std::ostringstream oss;

  if constexpr (std::is_floating_point_v<T>) {
    oss << "float: ";
  }
  if constexpr (std::is_integral_v<T>) {
    oss << "int: ";
  }

  oss << t;
  return ls << "fundamental: " << std::move(oss);
}
