#pragma once

struct Data {
  int content;
};

class Serializer {
  private:
    Serializer();
    Serializer(Serializer& src);
    ~Serializer();
    Serializer& operator=(Serializer& src);
  public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};