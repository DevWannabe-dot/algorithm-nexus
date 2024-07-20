/**
 * @file    euclid_algorithm.cpp
 * @brief   Receives two numbers (argv[1], argv[2]) to compute their GCD/GCF/HCF.
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2024-07-19
*/

/* Inclusions */
#include "headers/errors.h"
#include "headers/xor_swap.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/* Constants */

/* Types */

/* Functions */
int euclidAlgo(long a, long b)
{
    int i = 1;

    while(b*(i+1) < a){
        i++;
    }
    if(b*i == a) return b; // If there is no remainder, b must be (a, b).

    return euclidAlgo(b, a-(b*i));
}
long euclidCalcGDC(long a, long b)
{
    long GDC = 1;

    if(a < b) xorSwap(&a, &b); // can't divide a integer by a greater integer and get quotient > 0
    if(a == b) return a; // mdc(a, a) = ax + ay (Bézout) = a^2(x+y) | a \forall a \therefore (a, a) = a.

    GDC = euclidAlgo(a, b);

    return GDC;
}
int main(int argc, char * argv[])
{
    long a, b;

    if(argc != NO_ARGS_PROVIDED + 2) return NOT_ENOUGH_ARGS;

    a = strtol(argv[1], nullptr, 0);
    b = strtol(*(&argv[1] + sizeof(char)), nullptr, 0);

    cout << euclidCalcGDC(a, b);
    
    return SUCCESS;
}