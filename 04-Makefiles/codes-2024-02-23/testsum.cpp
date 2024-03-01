#include <iostream>
#include <cmath> 
#include <cassert> 
#include "functions.h"

int main(int argc, char **argv) 
{
  float r1 = sumup(1);
  assert(std::fabs(1-1.0/r1) < 1.0e-3);

  return 0;
}

