/**
 * @file    ITA-escolha-de-especialidade.cpp
 * @brief   Receives three grades via argv[1], argv[2] and argv[3], outputs general classification to stdout and a database file(.bin).
 * @author  Pedro Henrique Pinto de Oliveira
 * @date    2024-05-18
*/

/* Inclusions */
#include "headers/errors.h"
#include <iostream>
using namespace std;

/* Constants */

/* Types */

/* Functions */
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

    return SUCCESS;
}