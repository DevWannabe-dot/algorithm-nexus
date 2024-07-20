/**
 * @file    xor_swap.c
 * @brief   XOR swap algorithm implementation in C (valeu Dani)
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2024-04-18
*/

/* Inclusions */
#include "headers/xor_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char ** argv)
{
    if(argc != NO_ARGS_PROVIDED + 2) return NOT_ENOUGH_ARGS;

    int x = strtod(argv[1], NULL), y = strtod(argv[2], NULL);

    printf("x = %d\n"
            "y = %d\n", x, y);

    printf(" -> "); print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y);
    x = x ^ y;
    printf("\n -> "); print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y);
    y = x ^ y;
    printf("\n -> "); print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y);
    x = x ^ y;
    printf("\n -> "); print_Base10ToBase2(x); printf(", "); print_Base10ToBase2(y); printf("\n");

    printf("x = %d\n"
            "y = %d\n", x, y);

    return SUCCESS;
}