#pragma once
#include <string>
#include <stdint.h>

struct Data {
  int content;
};

class Serializer {
private:
  Serializer(void);
  Serializer(Serializer const &other);
  Serializer& operator=(Serializer const &other);
  ~Serializer(void);

public:
  static uintptr_t serialize(Data *ptr);
  static Data * deserialize(uintptr_t raw);
};
