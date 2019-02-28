#include <iostream>

int main()
{
    int numberOfCases;
    long long oddJumps, evenJumps, jumps, result, temp;
    std::cin >> numberOfCases;
    for (int i = 0; i < numberOfCases; i++) {
        std::cin >> oddJumps >> evenJumps >> jumps;
        result = 0;
        temp = jumps / 2;
        result -= temp * evenJumps;
        temp = jumps - temp;
        result += temp * oddJumps;
        std::cout << result << std::endl;
    }
    return 0;
}