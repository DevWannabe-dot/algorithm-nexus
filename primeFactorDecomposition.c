/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "headers/errors.h"

/* Constantes */
#define TRUE    (1 == 1)
#define FALSE   (!TRUE)

/* Tipos */
typedef uint8_t bool_t;

/* Funções */
bool_t ehPrimo(unsigned long n) {
    int iterator = n;
    
    if(n != 1 && n != 2) {
        if(n % --iterator == 0) return FALSE;
    }
    return TRUE;
}
void DecomposePrimeFactors(unsigned long n) {
    unsigned long primo = 2;

    printf("%lu", n);

    while(n != 1) {
        if(n % primo == 0) {
            n /= primo;
            printf(" : %lu = %lu", primo, n);
        } else {
            do {
                primo++;
            } while (ehPrimo(primo) == FALSE);
        }
    }
}
int main(int argc, char ** argv) {
    unsigned long num;

    if(argc != 2) return NOT_ENOUGH_ARGS;
    
    num = strtoul(argv[1], NULL, 0);

    DecomposePrimeFactors(num);

    return SUCESSO;
}