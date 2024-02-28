#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include "functions.h"

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
    //Se genera la semilla
    std::mt19937 gen(seed);
    //Se genera la distribución normal
    std::normal_distribution<double> dis(mu, sigma);

    //Se crea un vector de enteros con el tamaño de los bins
    std::vector<int> histogram(nbins, 0);

    for (int n = 0; n < nsamples; ++n)
    {   
        //Se genera una distribucion con la semilla
        double r = dis(gen);
        
        //Se genera el histograma 
        if (r >= xmin && r <= xmax)
        {   
            //Se calcula el bin index
            int bin_index = static_cast<int>((r - xmin) / (xmax - xmin) * nbins);
            ++histogram[bin_index];
        }
    }

    std::string filename = "random_pdf_seed_" + std::to_string(seed) + ".txt";
    std::ofstream outfile(filename);

    for (int i = 0; i < nbins; ++i)
    {   
        //Se calcula el centro del bin
        double bin_center = xmin + (i + 0.5) * (xmax - xmin) / nbins;
        //Se calcula el ancho del bin
        double bin_width = (xmax - xmin) / nbins;
        //Se calcula el valor de la pdf
        double pdf_value = static_cast<double>(histogram[i]) / (nsamples * bin_width);

        outfile << bin_center << "\t" << pdf_value << "\n";
    }

    outfile.close();
}

// void integrate_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins){

//     return 0;
    
// }
