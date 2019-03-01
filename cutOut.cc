#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void printPairVector(std::map<long, long> vec)
{
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << "{" << i->first << "," << i->second << "}" << std::endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long arraySize, subArraySize, temp;
    std::vector<long> subArray;
    std::map<long, long> mappedElements;

    std::cin >> arraySize >> subArraySize;
    long arrayRepeats = arraySize / subArraySize;
    for (long i = 0; i < arraySize; i++) {
        std::cin >> temp;
        if (mappedElements.count(temp) > 0) {
            mappedElements[temp] = mappedElements[temp] + 1;
        } else {
            mappedElements[temp] = 1;
        }
    }
    while (subArray.size() < subArraySize) {
        subArray.clear();
        for (auto i = mappedElements.begin(); i != mappedElements.end(); i++) {
            long numberToAdd = i->first;
            long ocurrances = i->second;
            for (long k = 0; k < ocurrances / arrayRepeats && subArray.size() < subArraySize; k++) {
                subArray.push_back(numberToAdd);
            }
        }
        arrayRepeats--;
    }
    for (int i = 0; i < subArray.size(); i++) {
        std::cout << subArray[i];
        if (i != subArray.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}