/* This programs shows times to divide and to multiply by
 * the inverse. Also compares times to multiply and to 
 * add-multiply. Try compiling without optimization and
 * with -O3 flag.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
  const int n = 512;
  float ***a;
  clock_t cputime1, cputime2;
  float tmp;
  int i,j,k;

  // Allocating memory for array/matrix
  a = malloc(n*sizeof(float **));
  for (i=0; i<n; i++){
    a[i] = malloc(n*sizeof(float*));
    for (j=0; j<n; j++)
      a[i][j] = malloc(n*sizeof(float));
  }

  cputime1 = clock();
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        a[i][j][k] = pow((float)k,3);
  cputime2 = clock() - cputime1;
  printf("Time to compute integer powers:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);
  
  cputime1 = clock();
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        a[i][j][k] = pow((float)k,3.0);
  cputime2 = clock() - cputime1;
  printf("Time to compute non-integer powers:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);

  cputime1 = clock();
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        a[i][j][k] = ((float)k)/((float)(i+1));
  cputime2 = clock() - cputime1;
  printf("Time to compute divisions:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);

  cputime1 = clock();
  for (i=0; i<n; i++)
    tmp = 1.0/(i+1);
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        a[i][j][k] = ((float)k)*tmp;
  cputime2 = clock() - cputime1;
  printf("Time to compute multiplications:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);

  cputime1 = clock();
  for (i=0; i<n; i++)
    tmp = 1.0/(i+1);
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        a[i][j][k] = ((float)k)*tmp+(float)j;
  cputime2 = clock() - cputime1;
  printf("Time to add-multiply floats:\t %f\n", ((double)cputime2)/CLOCKS_PER_SEC);
  return 0;
}
