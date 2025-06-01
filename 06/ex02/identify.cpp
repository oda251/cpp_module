#include "identify.hpp"

Base* generate(void) {
  int random = rand() % 3;
  switch (random) {
    case 0:
      return new A();
    case 1:
      return new B();
    case 2:
      return new C();
  }
  return NULL;
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "The type is A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "The type is B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "The type is C" << std::endl;
}

void identify(Base& p) {
  try {
    A &a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "The type is A" << std::endl;
  } catch (std::exception &e) {
    try {
      B &b = dynamic_cast<B&>(p);
      (void)b;
      std::cout << "The type is B" << std::endl;
    } catch (std::exception &e) {
      try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "The type is C" << std::endl;
      } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
      }
    }
  }
}
