#pragma once

struct Foo {};

class LogStream;

auto operator<<(LogStream &ls, const Foo &) -> LogStream &;
