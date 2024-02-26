#include <iostream>
#include <random>
#include <vector>
#include <fstream>

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


void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins) {
    std::mt19937 gen(seed);
    std::normal_distribution<> dis{mu, sigma};

    std::vector<int> histogram(nbins,  0); // Inicializa el histograma con ceros
    double bin_width = (xmax - xmin) / nbins;

    for(int n =  0; n < nsamples; ++n) {
        double r = dis(gen);
        int bin = std::min(static_cast<int>((r - xmin) / bin_width), nbins -  1); // Evita índices fuera de rango
        histogram[bin]++;
    }

    std::vector<double> pdf(nbins,  0.0); // Inicializa la PDF con ceros
    for(int i =  0; i < nbins; ++i) {
        pdf[i] = static_cast<double>(histogram[i]) / nsamples / bin_width;
    }
    
    std::ofstream file("random_pdf.txt");
    for(int i =  0; i < nbins; ++i) {
        file << xmin + i * bin_width << " " << pdf[i] << std::endl;
    }
    file.close();
}
