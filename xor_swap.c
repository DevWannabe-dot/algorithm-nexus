/**
 * @file    xor_swap.c
 * @brief   XOR swap algorithm implementation in C (valeu Dani)
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2024-04-18
*/

/* Inclusions */
#include "headers/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

/* Constants */
#define INTMAX_MAX_32B_EXP  (31)

/* Types */
typedef uint_fast8_t int_bin;

/* Functions */
int_bin * evaluate_Base10ToBase2(int Base10_N, int_bin * Base2_N)
{
    // i is the number of decimal places, j is the array index
    for(int i = 1; i < INTMAX_MAX_32B_EXP; i++)
    {
        // I could've written pow(2, i), I just wanted to demonstrate an interesting logarithmic property
        if(pow(exp(i), log(2)) > Base10_N){
            for(int j = i-1; j >= 0; j--){
                Base2_N[j] = Base10_N % 2;
                Base10_N = (Base10_N - (Base10_N % 2)) / 2;
            }
        }
    }    

    return Base2_N;
}
void print_Base10ToBase2(int Base10_N)
{
    int_bin * Base2_N = malloc(INTMAX_MAX_32B_EXP * sizeof(int_bin)); memset(Base2_N, 2, INTMAX_MAX_32B_EXP);

    Base2_N = evaluate_Base10ToBase2(Base10_N, Base2_N);

    for(int i = 0; i < INTMAX_MAX_32B_EXP; i++)
    {
        printf("%d", Base2_N[i]);
        if(Base2_N[i+1] == 2) break;
    }
}

int main(int argc, char ** argv)
{
    if(argc != NO_ARGS_PROVIDED + 2) return NOT_ENOUGH_ARGS;

    int x = strtod(argv[1], NULL), y = strtod(argv[2], NULL);

    printf("x = %d\n"
            "y = %d\n", x, y);

    print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y); printf(" -> ");
    x = x ^ y;
    print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y); printf(" -> ");
    y = x ^ y;
    print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y); printf(" -> ");
    x = x ^ y;
    print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y); printf("\n");

    printf("x = %d\n"
            "y = %d\n", x, y);

    return SUCCESS;
}