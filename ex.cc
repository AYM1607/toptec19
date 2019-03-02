#include <iostream>
#include <map>
#include <unordered_map>

int main()
{
    std::unordered_map<long double, long long> map;
    std::cout << map[1234567.5] << std::endl;
}