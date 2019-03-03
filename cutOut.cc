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

    int arraySize, subArraySize, temp;
    std::vector<int> subArray;
    std::map<int, int> mappedElements;

    std::cin >> arraySize >> subArraySize;
    int arrayRepeats = arraySize / subArraySize;
    for (int i = 0; i < arraySize; i++) {
        std::cin >> temp;
        if (mappedElements.count(temp) > 0) {
            mappedElements[temp] = mappedElements[temp] + 1;
        } else {
            mappedElements[temp] = 1;
        }
    }
    if (subArraySize == 1) {
        long long MAX = -1;
        long long MAXINDEX = mappedElements.begin()->first;
        for (auto i = mappedElements.begin(); i != mappedElements.end(); i++) {
            if (i->second > MAX) {
                MAX = i->second;
                MAXINDEX = i->first;
            }
        }
        std::cout << MAXINDEX << std::endl;
        return 0;
    }
    while (subArray.size() < subArraySize) {
        subArray.clear();
        for (auto i = mappedElements.begin(); i != mappedElements.end() && subArray.size() < subArraySize; i++) {
            int numberToAdd = i->first;
            int ocurrances = i->second;
            for (int k = 0; k < ocurrances / arrayRepeats && subArray.size() < subArraySize; k++) {
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