// (Accepted)

#include <iostream>

int main(int argc, char **argv) {
  int w;
  std::cin >> w;
  if (w % 2 || w == 2) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  std::cout << "YES" << std::endl;  // subtract 2 to get a valid split
  return 0;
}