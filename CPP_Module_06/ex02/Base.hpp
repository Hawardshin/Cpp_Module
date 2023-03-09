#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

class Base{
  virtual ~Base();
}

Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);
