#include "functions.h"

float sumup(int nterms)
{
    float result = 0.0;
    for(int k = 1; k <= nterms; k++) {
        result += 1.0/k;
    }
    return result;
}

float sumdown(int nterms)
{
    float result = 0.0;
    for(int k = nterms; k >= 1; k--) {
        result += 1.0/k;
    }
    return result;
}
