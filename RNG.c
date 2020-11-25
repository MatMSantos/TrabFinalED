#include "RNG.h"

// Gera um número aleatório
int gera_aleatorio(void)
{
    int min=0,max=100;
    int num;


    num = min + ( rand() % (max - min + 1) );
    return num;
}
