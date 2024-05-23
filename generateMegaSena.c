/**
 * @file    generateMegaSena.c
 * @brief   Generates six numbers from 1 to 60 for the "Mega-Sena" raffle if no arguments are passed. Otherwise, draws between argv[2] numbers argv[1] times.
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2023-12-27
*/

/* Inclusions */
#include "headers/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
#define N_NUMEROS_SORTEADOS     (6)
#define N_NUMEROS_POSSIVEIS     (60)

/* Types */

/* Functions */
int main(int argc, char ** argv) {
    srand(time(NULL));

    if(argc == NO_ARGS_PROVIDED){
        for(int i = 0; i < N_NUMEROS_SORTEADOS; i++) {
            int nAtual = (rand() % N_NUMEROS_POSSIVEIS) + 1;

            printf("%d", nAtual);
            if(i != N_NUMEROS_SORTEADOS-1)
                { printf(" "); }
        }
    } else if(argc == NO_ARGS_PROVIDED + 2) {
        for(int i = 0; i < (int)strtod(argv[1], NULL); i++) {
            int nAtual = (rand() % (int)strtod(argv[2], NULL)) + 1;

            printf("%d", nAtual);
            if(i != (int)strtod(argv[1], NULL)-1)
                { printf(" "); }
        }
    }
    return SUCCESS;
}