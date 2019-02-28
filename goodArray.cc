#include <iostream>
#include <set>
#include <vector>

std::set<long> found;

void printVector(std::vector<long> vec)
{
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

bool isVectorNice(std::vector<long> vec, long sum)
{
    for (auto i = vec.begin(); i != vec.end(); i++) {
        if (sum - *i == *i) {
            return true;
        }
    }
    return false;
}

long vectorSum(std::vector<long> vec)
{
    long sum = 0;
    for (auto i = vec.begin(); i != vec.end(); i++) {
        sum += *i;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    bool resultFlag = false;
    long arraySize, temp, sum, index = 0;
    std::vector<long> vec;
    std::vector<long> niceIndexes;
    std::cin >> arraySize;
    for (int i = 0; i < arraySize; i++) {
        std::cin >> temp;
        vec.push_back(temp);
    }
    sum = vectorSum(vec);
    for (auto i = vec.begin(); i != vec.end(); i++, index++) {
        temp = *i;
        if (found.count(temp) != 0) {
            niceIndexes.push_back(index + 1);
            continue;
        }
        vec.erase(i);
        if (isVectorNice(vec, sum - temp)) {
            found.insert(temp);
            niceIndexes.push_back(index + 1);
        }
        vec.insert(i, temp);
    }
    if (niceIndexes.empty()) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << niceIndexes.size() << std::endl;
        printVector(niceIndexes);
    }
}