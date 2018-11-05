#include <future>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "config.hpp"

using namespace std;

// a non-optimized way of checking for prime numbers:
bool is_prime(long int x) {
  cout << "Calculating. Please, wait...\n";
  for (long int i = 2; i < x; ++i)
    if (x % i == 0)
      return false;
  return true;
}

int main(int argc, char *argv[]) {
  fprintf(stdout, "%s Version %d.%d\n", argv[0], PROJECT_VERSION_MAJOR,
          PROJECT_VERSION_MINOR);

  long int number = 3132223133;

  // call is_prime(313222313) asynchronously:
  future<bool> fut = async(is_prime, number);

  cout << "Checking whether 313222313 is prime.\n";
  // ...

  bool ret = fut.get();

  // bool ret = fut.get(); // waits for is_prime to return

  if (ret)
    cout << "It is prime!\n";
  else
    cout << "It is not prime.\n";

  return 0;
}
