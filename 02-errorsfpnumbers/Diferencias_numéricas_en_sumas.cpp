#include <iostream>
#include <cmath>
#include <iomanip> // Librería para setprecision

using namespace std;

double Sum1(int N){
    
    double sum1 = 0.0;

    for (float k = 1; k <N; ++k){
        sum1 += sum1 + 1/k;
        //cout << "Sum2: " << sum2 << endl;
    }
    return sum1;
}

double Sum2(int N){
    
    double sum2 = 0.0;

    for (float k = N; k >= 1; --k){
        sum2 += sum2 + 1/k;
        //cout << "Sum2: " << sum2 << endl;
    }
    return sum2;
    
}

double RelativeDifference(double S1, double S2){
    return abs(1-S1/S2);
}


int main() {

    int N = 10000;
    
    cout <<"N"<< "\t"<<"S1"<<"\t"<<"S2"<<"\t"<<"Delta"<<endl;

    for (int i = 1; i <= N; ++i){
        double S1 =+ Sum1(i);
        double S2 =+ Sum2(i);
        double delta = RelativeDifference(S1, S2);
        cout << i << "\t" << S1 << "\t" << S2 << "\t" << delta << endl;
    }

    return 0;

}