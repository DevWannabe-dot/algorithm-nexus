/**
 * @file    xor_swap.h
 * @brief   Auxiliary header to xor_swap.c
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2024-07-19
 */

#pragma once

#ifndef __XOR_SWAP_h__
#define __XOR_SWAP_h__

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

#ifdef __cplusplus
extern "C" {
#endif

/* Functions */
int_bin * evaluate_Base10ToBase2(int Base10_N, int_bin * Base2_N);
void print_Base10ToBase2(int Base10_N);
void xorSwap(long * a, long * b);

#ifdef __cplusplus
}
#endif
#endif // __XOR_SWAP_h__