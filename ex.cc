#include <iostream>
#include <vector>

int main()
{
    int arraySize, temp;
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

    for (auto i = inc.begin(); i != inc.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    for (auto i = dec.begin(); i != dec.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}