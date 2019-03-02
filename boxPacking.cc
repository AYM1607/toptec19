#include <iostream>
#include <vector>

int main()
{
    long long n, m, k, temp, remainingSpace, result = 0;
    std::vector<long long> vec;
    std::cin >> n >> m >> k;
    remainingSpace = k;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        vec.push_back(temp);
    }
    for (auto i = vec.rbegin(); i != vec.rend() && m > 0; i++) {
        if (*i <= remainingSpace) {
            remainingSpace -= *i;
            result++;
        } else {
            m--;
            if (m > 0) {
                result++;
                remainingSpace = k - *i;
            }
        }
    }
    std::cout << result << std::endl;
}