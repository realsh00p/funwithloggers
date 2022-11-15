#include "LogStream.hpp"
#include "Logger.hpp"

#include <type_traits>

struct Foo {};

auto operator<<(LogStream &ls, const Foo &) -> LogStream & {
  return ls << "foo " << (int)777;
}

int main(void) {

  Foo foo1;
  const Foo foo2;

  static_assert(std::is_compound<Foo>::value);
  static_assert(std::is_compound<decltype(foo2)>::value);

  Logger logger;
  logger.log() << "asdf";
  logger.log() << (int)123;
  logger.log() << (double)456.789;
  logger.log() << Foo{};
  logger.log() << foo1;
  logger.log() << foo2;
  return 0;
}
