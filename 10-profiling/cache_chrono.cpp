#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <iostream>

/*
   Tests cache misses.
*/

void print_elapsed(auto start, auto end );

int main(int argc, char **argv)
{
  if (argc < 3){
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]);
  long sJ = atoi(argv[2]);

  auto start = std::chrono::steady_clock::now();
  
  printf("Operating on matrix of size %ld by %ld\n", sI, sJ);

  long *arr = new long[sI*sJ]; // double array.
  auto end = std::chrono::steady_clock::now();
  print_elapsed(start, end);
  
  // option 1
  start = std::chrono::steady_clock::now();
  for (long i=0; i < sI; ++i)
    for (long j=0; j < sJ; ++j)
      arr[(i * (sJ)) + j ] = i;
  end = std::chrono::steady_clock::now();
  print_elapsed(start, end);
  
  // option 2
  start = std::chrono::steady_clock::now();
  for (long i=0; i < sI; ++i)
      for (long j=0; j < sJ; ++j)
         arr[(j * (sI)) + i ] = i;
  end = std::chrono::steady_clock::now();
  print_elapsed(start, end);

  // option 3
  start = std::chrono::steady_clock::now();
  for (int i=0; i < sI*sJ; ++i) arr[i] = i;
  end = std::chrono::steady_clock::now();
  print_elapsed(start, end);

  printf("%ld\n", arr[0]);
  
  return 0;
}
  

void print_elapsed(auto start, auto end )
{
  std::cout << "Elapsed time in ms: "
	    << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
	    << "\n";
}
