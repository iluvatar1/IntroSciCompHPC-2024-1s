#include <iostream>
#include <cmath>

using namespace std;


int main() {
    for (int num = 10; num <= 30; ++num) {
        bool esPrimo = true;

        if (num > 1) {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                esPrimo = false;
                break;
            }
        }
        if (esPrimo) {
            std::cout << num << " ";
        }
        }
    }
    return 0;
}
