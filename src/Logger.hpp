#pragma once

#include "LogStream.hpp"

class Logger {
public:
  auto log() -> LogStream { return LogStream(); }
};
