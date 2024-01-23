/* Shows a way to do operations that require a specific order (e.g., 
 * transpositions) while avoiding cache misses. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )

int main(){
const int n = 512;
  const int csize = 32;
  float ***a, ***b;
  clock_t cputime1, cputime2;
  int i,j,k,ii,jj,kk;
  
  // Allocating memory for array/matrix
  a = malloc(n*sizeof(float **));
  for (i=0; i<n; i++){
    a[i] = malloc(n*sizeof(float*));
    for (j=0; j<n; j++)
      a[i][j] = malloc(n*sizeof(float));
  }
  b = malloc(n*sizeof(float **));
  for (i=0; i<n; i++){
    b[i] = malloc(n*sizeof(float*));
    for (j=0; j<n; j++)
      b[i][j] = malloc(n*sizeof(float));
  }

  // Filling matrices with zeros
  for(i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      for (k=0; k<n; ++k)
        a[i][j][k] = 0;
  for(i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      for (k=0; k<n; ++k)
        b[i][j][k] = 0;

  // Direct (inefficient) transposition
  cputime1 = clock();
  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      for (k=0; k<n; ++k)
        a[i][j][k] = b[k][j][i];
  cputime2 = clock() - cputime1;
  printf("Time for transposition: %f\n", ((double)cputime2)/CLOCKS_PER_SEC);

  // Transposition using cache-blocking
  cputime1 = clock();
  for (ii=0; ii<n; ii+=csize)
    for (jj=0; jj<n; jj+=csize)
      for (kk=0; kk<n; kk+=csize)
        for (i=ii; i<min(n,ii+csize-1); ++i)
          for (j=jj; j<min(n,jj+csize-1); ++j)
            for (k=kk; k<min(n,kk+csize-1); ++k)
              a[i][j][k] = b[k][j][i];
  cputime2 = clock() - cputime1;
  printf("Time for transposition: %f\n", ((double)cputime2)/CLOCKS_PER_SEC);

  return 0;
}
