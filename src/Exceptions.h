#pragma once

class RuntimeException
{
public:
  RuntimeException(const char *m) { message = m; }

  const char *Message() { return message; }

private:
  const char *message;
};
