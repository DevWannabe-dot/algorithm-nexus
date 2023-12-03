/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constantes */
    // Códigos de erro
#define SUCESSO             (0)
#define ARG_ERR_OFFSET      (0)
#define NOT_ENOUGH_ARGS     (ARG_ERR_OFFSET + 1)
    // Valores
#define PI                  (3.1415926535)
#define LINHAS              (2)
#define COLUNAS             (2)
    // Macros
#define DEF_ANGLE_RAD(dg)   (dg * PI / 180)

/* Tipos */

/* Funções */
int main(int argc, char ** argv){
    if(argc != 3) return ARG_ERR_OFFSET;
	
    double angle_degrees = strtod(argv[2], NULL), angle_rad, v = strtod(argv[1], NULL), compX, compY;

    angle_rad = DEF_ANGLE_RAD(angle_degrees);

    compX = cos(angle_rad) * v;
    compY = sin(angle_rad) * v;

    printf("Para o vetor de modulo %lf no sentido %d graus:\n"
            "\tOx = %lf"
            "\tOy = %lf", v, (int)angle_degrees, compX, compY);
    
    return SUCESSO;
}