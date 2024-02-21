#include <iostream>
#include <cmath>
#include <iomanip> // Librería para setprecision

using namespace std;

float Sum1(int N){
    
    float sum1 = 0.0;

    for (float k = 1; k <=N; ++k){
        sum1 = sum1 + 1/k;
        //cout << "Sum2: " << sum2 << endl;
    }
    return sum1;
}

float Sum2(int N){
    
    float sum2 = 0.0;

    for (float k = N; k >= 1; --k){
        sum2 = sum2 + 1/k;
        //cout << "Sum2: " << sum2 << endl;
    }
    return sum2;
    
}

float RelativeDifference(float S1, float S2){
    return abs(1-S1/S2);
}


int main() {

    int N = 1e6;
    
    cout <<"N"<<"\t"<<"S1"<<"\t"<<"S2"<<"\t"<<"Delta"<<endl;

    for (int i = 1; i < N; ++i){
        float S1 = Sum1(i);
        float S2 = Sum2(i);
        float delta = abs(1-S1/S2);
        //float delta = RelativeDifference(S1, S2);
        if (i%1000 == 0){
            cout << i << "\t" << S1 << "\t" << S2 << "\t" << delta << endl;
        }
        
    }

    return 0;

}