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

void xorSwap(long* a, long* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int_bin *  evaluate_Base10ToBase2(int Base10_N, int_bin * Base2_N)
{
    // Allow for numbers between [-2^31, 2^31 -1] inclusive
    if(Base10_N < 0) Base2_N[0] = 1;

    for(int i = INTMAX_MAX_32B_EXP; i > 0; i--){
        int remainder = Base10_N % 2;
        
        Base2_N[i] = remainder;
        Base10_N = (Base10_N - remainder) / 2;
    }
    
    return Base2_N;     
}
void print_Base10ToBase2(int Base10_N)
{
    int_bin * Base2_N = (int_bin*) calloc((INTMAX_MAX_32B_EXP+1), sizeof(int_bin));
    int foundFirstHIGH = 0;

    Base2_N = evaluate_Base10ToBase2(Base10_N, Base2_N);
    
    if(Base2_N[0] == 1) printf("-");
    for(int i = 1; i < (INTMAX_MAX_32B_EXP+1); i++){
        if(!foundFirstHIGH) {
            // Try:
            foundFirstHIGH |= Base2_N[i];
            // If it's still not found, skip this iteration
            if(!foundFirstHIGH) continue;
        }
        printf("%d", Base2_N[i]);
    }
}
#ifndef EXTERN_XOR_SWAP
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
#endif