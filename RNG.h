#ifndef _RNG_H_
#define _RNG_H_

// Gera um número aleatório
int gera_aleatorio(void);
// Gera números aleatórios em sequência
int gera_aleatorioSeq(void);
// Escreve uma certa quantidade de números
// aleatórios em um arquivo
int salvaParaArquivo(int numDados, int sorted);
// Lê uma certa quantidade de números
// aleatórios de um arquivo
int* carregaDeArquivo(int numDados, int sorted);

#endif
