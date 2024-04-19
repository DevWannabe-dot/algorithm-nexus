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

/* Constants */
#define ARBITRARY_BASE2_MAX (100)

/* Functions */
void print_Base10ToBase2(int Base10_N, int * currentMaxDecimalPlaces)
{
    int Base2_N[ARBITRARY_BASE2_MAX], i;

    for(i = 0; Base10_N > 0; i++){
        Base2_N[i] = Base10_N % 2;
        Base10_N /= 2;
    }
    for(int v = *currentMaxDecimalPlaces-(i-1); v >= 0; v--){
        printf("0");
    }
    for(int j = i-1; j >= 0; j--){
        printf("%d", Base2_N[j]);
    }
    
    // Writes the largest binary number's places to the buffer
    if(i > *currentMaxDecimalPlaces) *currentMaxDecimalPlaces = i;
}

int main(int argc, char ** argv)
{
    if(argc != NO_ARGS_PROVIDED + 2) return NOT_ENOUGH_ARGS;

    int x = strtod(argv[1], NULL), y = strtod(argv[2], NULL), currentMaxDecimalPlaces = 1;

    printf("x = %d\n"
            "y = %d\n", x, y);

    print_Base10ToBase2(x, &currentMaxDecimalPlaces); printf(", "); print_Base10ToBase2(y, &currentMaxDecimalPlaces); printf(" -> ");
    x = x ^ y;
    print_Base10ToBase2(x, &currentMaxDecimalPlaces); printf(", "); print_Base10ToBase2(y, &currentMaxDecimalPlaces); printf(" -> ");
    y = x ^ y;
    print_Base10ToBase2(x, &currentMaxDecimalPlaces); printf(", "); print_Base10ToBase2(y, &currentMaxDecimalPlaces); printf(" -> ");
    x = x ^ y;
    print_Base10ToBase2(x, &currentMaxDecimalPlaces); printf(", "); print_Base10ToBase2(y, &currentMaxDecimalPlaces); printf("\n");

    printf("x = %d\n"
            "y = %d\n", x, y);

    return SUCESSO;
}