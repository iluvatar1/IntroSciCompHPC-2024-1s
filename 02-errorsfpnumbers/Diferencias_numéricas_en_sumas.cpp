#include <iostream>
#include <cmath>

using namespace std;

double Sum(double k){
    return 1.0/k;
}


double RelativeDifference(double a, double b){
    //return abs(a-b)/max(abs(a), abs(b));
    return abs(a-b)/abs(b);
}


int main() {
    
    int n = 10;
    double sum1 = 0.0;
    double sum2 = 0.0;

    for (int k =1; k <n, ++k;){
        sum1 += Sum(k);
        cout<< "k: " << k << endl;
        cout << "Sum1: " << sum1 << endl;
    }

    for (int k =1; k <=n, ++k;){
        sum2 += Sum(k);
        cout << "Sum2: " << sum2 << endl;
    }

    //cout << "Sum1: " << sum1 << endl;
    //cout << "Sum2: " << sum2 << endl;
    cout << "Relative Difference: " << RelativeDifference(sum1, sum2) << endl;
}