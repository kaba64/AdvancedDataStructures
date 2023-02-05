#include <iostream>
#include "stack.h"

auto main() -> int
{
  Stack first;
  first.push(5);
  first.push(8);
  std::cout<<first.pop()<<","<<first.top<<"\n";
}
