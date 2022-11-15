#pragma once

#include "Logger.hpp"

#include <optional>
#include <sstream>
#include <type_traits>

template <typename T, typename Err = int>
class Result {
public:
  Result(T _t) : t(_t) {}

  auto has_value() const -> bool { return t.has_value(); }
  auto value() const -> T const & { return t.value(); }
  auto err() const -> Err { return e; }

  auto operator()() const -> bool { return has_value(); }

private:
  std::optional<T> t;
  Err e;
};

template <typename T>
auto operator<<(LogStream &ls, const Result<T> &r) -> LogStream & {
  if (!r.has_value()) {
    return ls << "erroneous result: " << r.err();
  }
  return ls << r.value();
}
