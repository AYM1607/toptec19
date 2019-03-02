#include <algorithm>
#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<long long, long long> mappedIds;
    long long numberOfQueries, currentSize = 0, temp, currentLeft = 0, currentRight = 0, center, minPop, index;
    char queryType;
    std::cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++) {
        std::cin >> queryType >> temp;
        if (queryType == '?') {
            center = currentSize - currentRight - 1;
            index = center + mappedIds[temp];
            minPop = std::min(index, (currentSize - 1 - index));
            std::cout << minPop << std::endl;
        } else {
            if (mappedIds.empty()) {
                mappedIds[temp] = 0;
                currentSize++;
            } else {
                if (queryType == 'R') {
                    mappedIds[temp] = ++currentRight;
                } else {
                    mappedIds[temp] = --currentLeft;
                }
                currentSize++;
            }
        }
    }
}