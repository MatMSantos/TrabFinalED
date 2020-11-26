#ifndef _RNG_H_
#define _RNG_H_

// Gera um número aleatório
int geraAleatorio(void);
// Escreve uma certa quantidade de números
// aleatórios em um arquivo
int salvaParaArquivo(int numDados);
// Lê uma certa quantidade de números
// aleatórios de um arquivo
int* carregaDeArquivo(int numDados);

#endif
