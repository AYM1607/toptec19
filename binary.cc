#include <iostream>
#include <string>

char getSum(char first, char second, int& carry)
{
    char result;
    if (first == second) {
        result = carry == 1 ? '1' : '0';
        carry = first == '1' || second == '1' ? 1 : 0;
    } else {
        result = carry == 1 ? '0' : '1';
    }
    return result;
};

void deleteLeadingZeros(std::string& string)
{
    while (string[0] == '0') {
        string.erase(0, 1);
    }
}

int main()
{
    char tempChar;
    int carry, numberOfCases;
    std::string first, second, result;
    std::cin >> numberOfCases;
    for (int i = 1; i <= numberOfCases; i++) {
        std::cin >> first >> second;
        std::string::reverse_iterator ritFirst = first.rbegin();
        std::string::reverse_iterator ritSecond = second.rbegin();
        carry = 0;
        result = "";
        while (ritFirst != first.rend() || ritSecond != second.rend()) {
            if (ritFirst == first.rend()) {
                tempChar = getSum('0', *ritSecond, carry);
                result.insert(0, 1, tempChar);
                ritSecond++;
                continue;
            }
            if (ritSecond == second.rend()) {
                tempChar = getSum(*ritFirst, '0', carry);
                result.insert(0, 1, tempChar);
                ritFirst++;
                continue;
            }
            tempChar = getSum(*ritFirst, *ritSecond, carry);
            result.insert(0, 1, tempChar);
            ritFirst++;
            ritSecond++;
        }
        if (carry) {
            result.insert(0, 1, '1');
        }
        deleteLeadingZeros(result);
        std::cout << i << ' ' << result << std::endl;
    }
    return 0;
}