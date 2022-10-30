#include "Logger.hpp"
#include "LogStream.hpp"

struct Foo {};

auto operator<<(LogStream&& ls, const Foo&) -> LogStream& {
  return ls << "foo " << (int)777;
}

int main(void)
{

  Foo foo1;
  const Foo foo2;

  Logger logger;
  logger.log() << "asdf";
  logger.log() << (int)123;
  logger.log() << (double)456.789;
  logger.log() << Foo{};
  logger.log() << foo1;
  logger.log() << foo2;
  return 0;
}
