#include <iostream>
#include <vector>

int main()
{
    int columnOddCount, rowOddCount, matrixSize, temp, columnLastTrue, rowLastTrue;
    std::cin >> matrixSize;
    while (matrixSize != 0) {
        columnOddCount = 0;
        rowOddCount = 0;
        rowLastTrue = 0;
        columnLastTrue = 0;
        std::vector<bool> columnOdd(matrixSize, false), rowOdd(matrixSize, false);
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                std::cin >> temp;
                if (temp == 1) {
                    rowOdd[i] = !rowOdd[i];
                    columnOdd[j] = !columnOdd[j];
                }
            }
        }
        for (int i = 0; i < matrixSize; i++) {
            if (columnOdd[i] == true) {
                columnOddCount++;
                columnLastTrue = i;
            }
            if (rowOdd[i] == true) {
                rowOddCount++;
                rowLastTrue = i;
            }
        }
        if (columnOddCount > 1 || rowOddCount > 1) {
            std::cout << "Corrupt" << std::endl;
        } else if (columnOddCount == 1 && rowOddCount == 1) {
            std::cout << "Change bit (" << rowLastTrue + 1 << "," << columnLastTrue + 1 << ")" << std::endl;
        } else {
            std::cout << "OK" << std::endl;
        }
        std::cin >> matrixSize;
    }
}