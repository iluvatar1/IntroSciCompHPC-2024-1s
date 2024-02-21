#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

float Summation1(int N);
float Summation2(int N);

int main() {
    cout<<"N"<<setw(20)<<"S1"<<setw(20)<<"S2"<<setw(20)<<"△"<<endl;
    
    for (int N = 1; N <1000000; N++){
        // vector<int> indices(N);
        // iota(indices.begin(), indices.end(), 1);
        float sum1 = Summation1(N);
        float sum2 = Summation2(N);
        float delta = abs(1-sum1/sum2);
        if (N%1000 == 0){
            cout<<N<<setw(20)<<sum1<<setw(20)<<sum2<<setw(13)<<delta<<endl;
        }
    }
    
    int N = 10000; 
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 1);
    float sum1 = Summation1(N);
    float sum2 = Summation2(N);
    float delta = abs(1-sum1/sum2);
    cout<<N<<setw(20)<<sum1<<setw(20)<<sum2<<setw(13)<<delta<<endl;

    return 0;
}

float Summation1(int N){
    float sum1 = 0.0;
    for (float i = 1;i<=N; i++){
        sum1 = sum1 + 1/i;
        //cout<<"i: "<<i<<" S1: "<<sum1<<endl;
        //if (N%10 == 0){
            //cout<<i<<setw(20)<<sum1<<setw(20);
            
        //}
    }
    return sum1;
}

float Summation2(int N){
    float sum2 = 0.0;
    for (float i = N;i>=1; i--){
        //cout<<"i: "<<i<<" S2: "<<sum2<<endl;
        sum2 =sum2 + 1/i;
        //if (N%10 == 0){
        //    cout<<" S2: "<<sum2<<endl;
        //}
    }
    return sum2;
}

/*float Summation2(int N){
    for (int i = 0; i < indices.size(); i++){
            

    }

    double sum = std::accumulate(indices.rbegin(), indices.rend(), 0.0,
       [](double partialSum, int i) { return partialSum + 1.0 / i; });
    return sum;
    }*/


