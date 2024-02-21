#include <iostream>
#include <fstream>
#include <cmath>

float sumk(int k){

    float sum = 0.0;

    for(int i = 1; i <= k; i++){
        sum += 0.1;
    }

    return std::fabs(k/10 - sum);

}

    



int main(void){

    int N = 1e2;

    for( int i = 1; i <=N; i++){
        float val = sumk(i);
        std::cout << i << " " << val << "\n";

    }


    return 0;
}