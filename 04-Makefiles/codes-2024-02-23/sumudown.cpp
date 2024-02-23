#include <iostream>
#include <cmath>

float sumup(int nterms);
float sumdown(int nterms);

int main(int argc, char **argv)
{
  std::cout.precision(6); std::cout.setf(std::ios::scientific);
  for (int ii = 1; ii <= 10000; ++ii) {
    double sum1 = sumup(ii);
    double sum2 = sumdown(ii);
    std::cout << ii << "\t" << sum1 << "\t" << sum2
              << "\t" << std::fabs(sum1-sum2)/sum2 << "\n";
  }

  return 0;
}

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