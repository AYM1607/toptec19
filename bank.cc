#include <cstdlib>
#include <iostream>
#include <string>

long long bankDay, bankMonth, bankYear, customerDay, customerMonth, numberOfCases, priorOrAfter, customerYear;

bool isLeapYear(long long year)
{
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

long long daysInMonth(long long month, long long year)
{
    int isLeap = isLeapYear(year);
    return (month == 2) ? (28 + isLeap) : 31 - (month - 1) % 7 % 2;
}

std::string getText(long long days)
{
    std::string result = "";
    result += days == 1 || days == -1 ? "DAY " : "DAYS ";
    result += days > 0 ? "AFTER" : "PRIOR";
    return result;
}

void printResult(long long j)
{
    if (std::abs(priorOrAfter) > 7) {
        std::cout << j + 1 << " OUT OF RANGE\n";
    } else {
        std::cout << j + 1 << " " << customerMonth << "/" << customerDay << "/" << customerYear << " IS " << std::abs(priorOrAfter) << " ";
        std::cout << getText(priorOrAfter) << std::endl;
    }
}

int main()
{
    char trash;
    std::cin >> numberOfCases;
    for (int j = 0; j < numberOfCases; j++) {
        priorOrAfter = 0;
        std::cin >> bankMonth >> trash >> bankDay >> trash >> bankYear >> customerMonth >> trash >> customerDay;
        if (bankMonth == customerMonth) {
            if (customerDay == bankDay) {
                std::cout << j + 1 << " SAME DAY\n";
            } else {
                priorOrAfter = customerDay - bankDay;
                customerYear = bankYear;
                printResult(j);
            }
        } else if (bankMonth == 1) {
            if (customerMonth == 12 || customerMonth == 2) {
                priorOrAfter += customerMonth == 2 ? customerDay + (daysInMonth(bankMonth, bankYear) - bankDay) : -(bankDay) - (daysInMonth(customerMonth, bankYear) - customerDay);
                customerYear = customerMonth == 2 ? bankYear : bankYear - 1;
                printResult(j);
            } else {
                std::cout << j + 1 << " OUT OF RANGE\n";
            }
        } else if (bankMonth == 12) {
            if (customerMonth == 11 || customerMonth == 1) {
                priorOrAfter += customerMonth == 1 ? customerDay + (daysInMonth(bankMonth, bankYear) - bankDay) : -(bankDay) - (daysInMonth(customerMonth, bankYear) - customerDay);
                customerYear = customerMonth == 11 ? bankYear : bankYear + 1;
                printResult(j);
            } else {
                std::cout << j + 1 << " OUT OF RANGE\n";
            }
        } else {
            if (customerMonth == bankMonth - 1 || customerMonth == bankMonth + 1) {
                priorOrAfter += customerMonth > bankMonth ? customerDay + (daysInMonth(bankMonth, bankYear) - bankDay) : -(bankDay) - (daysInMonth(customerMonth, bankYear) - customerDay);
                customerYear = bankYear;
                printResult(j);
            } else {
                std::cout << j + 1 << " OUT OF RANGE\n";
            }
        }
    }
}