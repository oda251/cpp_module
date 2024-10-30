#include <iostream>
#include <stdint.h>
#include "Serializer.hpp"

int main(void) {
	Data data;
	int content = 42;
	data.content = content;
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	if (ptr->content == content)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Failure" << std::endl;
	return 0;
}
