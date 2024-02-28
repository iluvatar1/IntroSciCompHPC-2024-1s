#include <cstdio>
#include <cmath>

int main(void)
{
  const double XMIN = 0.0;
  const double XMAX = 11.0;
  const double DX = 0.1;
  const int NSTEPS = int((XMAX-XMIN)/DX);

  for(int ii = 1; ii < NSTEPS; ++ii) {
    double x = XMIN + ii*DX;
    printf("%25.16e%25.16e\n", x, std::tgamma(x));
  }

  return 0;
}