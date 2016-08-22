// https://codefights.com/challenge/T9mZQb7SF3jo9Dxhm/main

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>
#include <set>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cstdint>
#include <boost/unordered_map.hpp>
#include <random>


long MoreTimesLess(std::string n) {
  long j = 0;
  long c = 0;
  long k = 1;
  for(j = std::stol(n); k < sqrt(j);k++)
  {
  (j-k*k)%(2*k)?1:c++;
  }
    return c;
}


int main() {
    std::cout<<"477"<<"\n";
  return 0;
}

