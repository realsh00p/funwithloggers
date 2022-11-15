#include "Foo.hpp"

#include "LogStream.hpp"

#include <random>

static std::random_device r;

auto randnum(int min, int max) {
  std::default_random_engine e1(r());
  std::uniform_int_distribution<int> uniform_dist(min, max);
  return uniform_dist(e1);
}

auto operator<<(LogStream &ls, const Foo &) -> LogStream & {
  return ls << "foo: " << randnum(0, 100);
}
