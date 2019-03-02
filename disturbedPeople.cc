#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    int arraySize, temp, answer = 0;
    std::unordered_set<int> set;
    std::cin >> arraySize;
    std::vector<int> vec;

    for (int i = 0; i < arraySize; i++) {
        std::cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i < arraySize; i++) {
        if (i > 0 && i < arraySize - 1) {
            if (vec[i] == 0 && vec[i - 1] == 1 && vec[i + 1] == 1) {
                set.insert(i);
            }
        }
    }
    for (int i = 0; i < arraySize; i++) {
        if (set.count(i) > 0) {
            if (set.count(i - 2) > 0) {
                set.erase(i - 2);
            }
            if (set.count(i + 2) > 0) {
                set.erase(i + 2);
            }
            answer++;
            set.erase(i);
        }
    }
    std::cout << answer << std::endl;
}