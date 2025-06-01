#pragma once
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <stdlib.h>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);