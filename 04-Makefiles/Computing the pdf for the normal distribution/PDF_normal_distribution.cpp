#include <iostream>
#include <fstream>
#include <vector>
#include <random>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

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

    return 0;
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{

    std::mt19937 gen(seed);
    std::normal_distribution<double> dis(mu, sigma);

    
    std::vector<int> histogram(nbins, 0);

    for (int n = 0; n < nsamples; ++n)
    {
        double r = dis(gen);
        if (r >= xmin && r <= xmax)
        {
            int bin_index = static_cast<int>((r - xmin) / (xmax - xmin) * nbins);
            ++histogram[bin_index];
        }
    }

    std::string filename = "random_pdf_seed_" + std::to_string(seed) + ".txt";
    std::ofstream outfile(filename);

    for (int i = 0; i < nbins; ++i)
    {
        double bin_center = xmin + (i + 0.5) * (xmax - xmin) / nbins;
        double bin_width = (xmax - xmin) / nbins;
        double pdf_value = static_cast<double>(histogram[i]) / (nsamples * bin_width);

        outfile << bin_center << "\t" << pdf_value << "\n";
    }

    outfile.close();
}
