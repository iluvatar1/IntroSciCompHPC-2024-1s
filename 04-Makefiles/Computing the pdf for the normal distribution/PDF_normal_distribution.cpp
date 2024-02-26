#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atoi(argv[3]);
  const double SIGMA = std::atoi(argv[4]);
  const double XMIN = std::atoi(argv[5]);
  const double XMAX = std::atoi(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  // TODO: histogram stuff

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    // TODO: fill here the counting histogram stuff
  }
  // TODO: compute and print the pdf

}