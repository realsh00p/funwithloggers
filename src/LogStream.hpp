#pragma once

#include <utility>
#include <iostream>
#include <sstream>

class LogStream {
public:

  ~LogStream();

  template <typename T>
  auto operator<<(T t) -> LogStream&
  {
    std::ostringstream oss;
    if constexpr(std::is_floating_point_v<T>) {
      oss << "float: ";
    }
    if constexpr (std::is_integral_v<T>) {
      oss << "int: ";
    }

    oss << t;
    return *this << "T: " << std::move(oss);
  }

  auto operator<<(std::ostringstream v) -> LogStream&;
  auto operator<<(std::string v) -> LogStream&;
  auto operator<<(const char* v) -> LogStream&;

};


