#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void printPairVector(std::vector<std::pair<int, int>> vec)
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
    std::vector<std::pair<int, int>> vec;
    //Inserting all the values in the map to a vector.
    std::copy(mappedElements.begin(), mappedElements.end(), std::back_inserter<std::vector<std::pair<int, int>>>(vec));
    //Sorting the values inside the vector.
    std::sort(vec.begin(), vec.end(), [](const std::pair<int, int>& l, const std::pair<int, int>& r) { if (l.second != r.second ) {return l.second < r.second; } return l.first < r.first; });
    auto i = vec.rbegin();
    while (subArray.size() < subArraySize) {
        int numberToAdd = i->first;
        int ocurrances = i->second;
        for (int k = 0; k < ocurrances / arrayRepeats; k++) {
            subArray.push_back(numberToAdd);
        }
        //std::cout << numberToAdd << " Can occure " << ocurrances / arrayRepeats << " times" << std::endl;
        i++;
    }

    for (auto j = subArray.begin(); j != subArray.end(); j++) {
        std::cout << *j << " ";
    }
    std::cout << std::endl;
}