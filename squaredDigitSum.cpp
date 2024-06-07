/**
 * @file    squaredDigitSum.cpp
 * @brief   Receives initial term via argv[1] and iterates until desired term argv[2], mathematically optimized.
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2024-05-18
*/

/* Inclusions */
#include "headers/errors.h"
#include <iostream>
#include <string>
using namespace std;

/* Constants */

/* Types */

/* Functions */
void findNthTerm(int init, int target)
{
    for(int i = init; i < target; i++)
    {
        int squares_sum = 0;
        int temp = target;

        while(temp > 0)
        {
            int digit = temp % 10;
            squares_sum += digit * digit;
            temp /= 10;
        }
        // Implement a stack buffer which, if (i-init) % 8 == 0, will check if the last element belongs in the sequence, given that this sequence is continuous.
    }
}

int main(int argc, char ** argv)
{
    const char * str =
    R"(+-> 4 -> 16 -> 37 -> 58 ---+
|                          |
|                          |
+- 20 <- 42 <- 145 <- 89 <-+)";

    cout << "REACHED\n" << str << "\n";

    return SUCCESS;
}