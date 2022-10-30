#include "LogStream.hpp"

LogStream::~LogStream() {
  std::cerr << std::endl;
}

auto LogStream::operator<<(std::ostringstream v) -> LogStream& {
  return *this << v.str();
}

auto LogStream::operator<<(std::string v) -> LogStream& {
  return *this << v.c_str();
}

auto LogStream::operator<<(const char* v) -> LogStream& {
  std::cerr << v;
  return *this;
}
