#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include "functions.h"

int main(int argc, char **argv)
{
    if (argc != 8)
    {
        std::cerr << "Usage: " << argv[0] << " <seed> <nsamples> <mu> <sigma> <xmin> <xmax> <nbins>\n";
        return 1;
    }

    const int SEED = std::atoi(argv[1]);
    const int NSAMPLES = std::atoi(argv[2]);
    const double MU = std::atof(argv[3]);
    const double SIGMA = std::atof(argv[4]);
    const double XMIN = std::atof(argv[5]);
    const double XMAX = std::atof(argv[6]);
    const int NBINS = std::atoi(argv[7]);

    compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
    //std::cout << integrate_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS) << std::endl;

    return 0;
}

