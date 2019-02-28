#include <iostream>

int main() {
  int first = 0, second = 0, numberOfCases = 0;
  char colon = ' ';

  std::cin >> numberOfCases;

  for (int i = 0; i < numberOfCases; i++) {
    std::cin >> first >> colon >> second;
    if (second != 0) {
      std::cout << 0 << std::endl;
    } else if (first == 12) {
      std::cout << 24 << std::endl;
    } else {
      std::cout << (first + 12) % 24 << std::endl;
    }
  }
  return 0;
}