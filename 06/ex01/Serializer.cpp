#include "Serializer.hpp"

Serializer::Serializer() {};
Serializer::Serializer(Serializer& src) {};
Serializer::~Serializer() {};
Serializer& Serializer::operator=(Serializer& src) {};

uintptr_t Serializer::serialize(Data *ptr) {

}

Data* Serializer::deserialize(uintptr_t *raw) {
  
}