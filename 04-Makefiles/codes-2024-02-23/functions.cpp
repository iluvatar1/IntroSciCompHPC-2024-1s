#include <iostream>
#include <cmath>
#include "functions.h"

float sumup(int nterms)
{
  float result = 0;
  for(int n = 1; n <= nterms; n++) {
    result += 1.0/n;
  }
  return result;
}
float sumdown(int nterms)
{
  float result = 0;
  for(int n = nterms; n >= 1; n--) {
    result += 1.0/n;
  }
  return result;
}