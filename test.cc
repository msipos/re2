#include "re2/re2.h"
#include "re2/set.h"

#include <cstdio>

int main() {
  RE2 pattern("[a-z]+");
  printf("match = %d == 1\n", RE2::FullMatch("foobar", pattern));
  printf("match = %d == 0\n", RE2::FullMatch("foobar2", pattern));
  
  RE2::Options options;
  RE2::Set s(options, RE2::ANCHOR_START);
  
  std::string foo = "abcd; efghg; abcd; efgh;";
  re2::StringPiece input(foo);
  
  RE2 pattern2("[a-z]+;");
  printf("size = %d == 24\n", input.size());
  printf("consume = %d == 1\n", RE2::Consume(&input, pattern2));
  printf("size = %d == 19\n", input.size());
}

