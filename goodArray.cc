#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

std::set<long> found;
std::unordered_map<long long, long long> map;

void printVector(std::vector<long long> vec)
{
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

bool isVectorNice(long long sum)
{
    return map[sum] != 0;
}

long long vectorSum(std::vector<long long> vec)
{
    long long sum = 0;
    for (auto i = vec.begin(); i != vec.end(); i++) {
        sum += *i;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    //bool resultFlag = false;
    long long arraySize, temp, sum, index = 0;
    std::vector<long long> vec;
    std::vector<long long> niceIndexes;
    std::cin >> arraySize;
    for (long long i = 0; i < arraySize; i++) {
        std::cin >> temp;
        vec.push_back(temp);
        map[temp * 2]++;
    }
    sum = vectorSum(vec);

    for (auto i = vec.begin(); i != vec.end(); i++, index++) {
        temp = *i;
        map[temp * 2]--;
        if (isVectorNice(sum - temp)) {
            niceIndexes.push_back(index + 1);
        }
        map[temp * 2]++;
    }
    if (niceIndexes.empty()) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << niceIndexes.size() << std::endl;
        printVector(niceIndexes);
    }
}