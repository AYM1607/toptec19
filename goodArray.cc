#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

void printVector(std::vector<long long> vec)
{
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

long vectorSum(std::vector<long long> vec)
{
    long sum = 0;
    for (auto i = vec.begin(); i != vec.end(); i++) {
        sum += *i;
    }
    return sum;
}

int main()
{
    //bool resultFlag = false;
    long long arraySize, temp, sum, max = -1, maxIndex = 0, seMax = -1;
    std::vector<long long> vec;
    std::vector<long long> niceIndexes;
    std::cin >> arraySize;
    for (long long i = 0; i < arraySize; i++) {
        std::cin >> temp;
        vec.push_back(temp);
    }
    sum = vectorSum(vec);

    for (long long i = 0; i < arraySize; i++) {
        if (vec[i] > max) {
            max = vec[i];
            maxIndex = i;
        }
    }
    for (long long i = 0; i < arraySize; i++) {
        if (i == maxIndex) {
            continue;
        }
        if (vec[i] > seMax) {
            seMax = vec[i];
        }
    }

    for (long long i = 0; i < arraySize; i++) {
        if (i == maxIndex) {
            if (sum - seMax - vec[i] == seMax) {
                niceIndexes.push_back(i + 1);
            }
        } else {
            if (sum - max - vec[i] == max) {
                niceIndexes.push_back(i + 1);
            }
        }
    }

    if (niceIndexes.empty()) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << niceIndexes.size() << std::endl;
        printVector(niceIndexes);
    }
}