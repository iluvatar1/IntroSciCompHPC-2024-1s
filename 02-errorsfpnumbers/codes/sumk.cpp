#include <iostream>
#include <fstream>
#include <cmath>

// declaration
float fun(int k);

int main(void) {
    std::ofstream outfile("data.txt");
    for(int m = 1; m <= 1000; m = m+1) {
        float val = fun(m);
        outfile << m << "\t" << val << "\n";
    }
    outfile.close();
    return 0;
}

// implementacion
float fun(int k)
{
    float result = 0.0;
    float sum = 0.0;
    for(int i=1;i<=k;i=i+1){
        sum = sum + 0.1; 
    }

    // warning: k/10 
    // std::cout << "-> " << k/10.0 << "\n";
    result = std::fabs(k/10.0-sum);

    return result;
}