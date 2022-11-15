#include "Foo.hpp"
#include "Future.hpp"
#include "Logger.hpp"
#include "Result.hpp"

static Logger logger;

void log_primitives() {
  Foo foo1;
  const Foo foo2;

  logger.log() << "A: " << 123 << " B: " << 456.789;
  logger.log() << (int)123;
  logger.log() << (double)456.789;
  logger.log() << Foo{};
  logger.log() << foo1;
  logger.log() << foo2;
}

void log_futures() {
  std::promise<Foo> p1, p2;
  std::promise<Result<Foo>> p3, p4;

  std::thread([&] {
    p1.set_value({});
    p2.set_value({});
    p3.set_value({{}});
    p4.set_value({{}});
  }).join();

  logger.log() << "fut1: " << p1.get_future() << " fut2: " << p2.get_future();
  logger.log() << "fut3: " << p3.get_future() << " fut4: " << p4.get_future();
}

int main(void) {

  log_primitives();
  log_futures();

  return 0;
}
