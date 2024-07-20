/**
 * @file    xor_swap.h
 * @brief   Auxiliary header to xor_swap.c
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2024-07-19
 */

/* Inclusions */
#include "errors.h"
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
void xorSwap(long* a, long* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}