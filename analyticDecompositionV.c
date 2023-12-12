/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "headers/errors.h"

/* Constantes */
    // Códigos de erro
#define WRONG_MODE          (ARG_ERR_OFFSET + 2)
    // Valores
#define TOTAL_ARGS          (4) // programName + mode + let1 + let2
#define PI                  (3.1415926535)
#define LINHAS              (2)
#define COLUNAS             (2)
    // Macros
#define DEF_ANGLE_RAD(dg)   (dg * PI / 180)

/* Tipos */

/* Funções */
int main(int argc, char ** argv){
    if(argc != 4) return ARG_ERR_OFFSET;
	
    double angle_degrees, angle_rad, v, compX, compY;

    if(strcmp(argv[1], "compose") == 0) {
        compX = strtod(argv[2], NULL); compY = strtod(argv[3], NULL);

        v = sqrt(pow(compX, 2) + pow(compY, 2));
        angle_degrees = atan(compY/compX) * 180 / PI;

        printf("For 2 vectors a = %lf and b = %lf, the resulting vector is:\n"
                "\tc = %lf, %.1lf degrees counterclockwise from the horizontal axis.", compX, compY, v, angle_degrees);
    } else if (strcmp(argv[1], "decompose") == 0) {
        v = strtod(argv[2], NULL); angle_degrees = strtod(argv[3], NULL);

        angle_rad = DEF_ANGLE_RAD(angle_degrees);

        compX = cos(angle_rad) * v;
        compY = sin(angle_rad) * v;

        printf("For a vector of module %lf with %.1lf degrees counterclockwise from the horizontal axis:\n"
                "\tOx = %lf"
                "\tOy = %lf", v, angle_degrees, compX, compY);
    } else {
        return WRONG_MODE;
    }
    
    return SUCESSO;
}