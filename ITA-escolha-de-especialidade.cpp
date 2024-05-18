/* Inclusões */
#include "headers/errors.h"
#include <iostream>
using namespace std;

/* Constantes */
#define SUCESSO     (0)

/* Tipos */

/* Funções */
int main(int argc, char ** argv)
{
    try
    {
        if(argc != NOT_ENOUGH_ARGS)
        {
            throw 1;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << argv[0] << '\n';

    return SUCESSO;
}