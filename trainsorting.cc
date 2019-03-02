#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int numberOfCases, arraySize, temp, maxLenght;
    std::cin >> numberOfCases;
    for (int z = 0; z < numberOfCases; z++) {
        maxLenght = 0;
        std::cin >> arraySize;
        std::vector<int> vec(arraySize), inc(arraySize, 1), dec(arraySize, 1);
        for (int i = 0; i < arraySize; i++) {
            std::cin >> temp;
            vec[i] = temp;
        }

        for (int i = arraySize - 1; i >= 0; i--) {
            for (int j = i + 1; j < arraySize; j++) {
                if (vec[j] > vec[i] && inc[j] + 1 > inc[i]) {
                    inc[i] = inc[j] + 1;
                }
                if (vec[j] < vec[i] && dec[j] + 1 > dec[i]) {
                    dec[i] = dec[j] + 1;
                }
            }
        }

        auto j = dec.begin();
        for (auto i = inc.begin(); i != inc.end(); i++, j++) {
            if (*i + *j - 1 > maxLenght) {
                maxLenght = *i + *j - 1;
            }
        }
        std::cout << maxLenght << std::endl;
    }
}