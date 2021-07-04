/**
 * @file    functions-team-19.h.
 * @brief   Ficheiro que contém os cabeçalhos das funções necessárias para o funcionamento do programa principal.
 * @author  Guilherme Teixeira / Guilherme Nunes / João Martins / Tiago Ribeiro / Henrique Policarpo.
 * @version 1.0.
 */

void cleanConsole();
void limpaInput();
void helpflag();
void separacao();
int menu();
void intro();
void matriz16x2(int *array_uni, int new_array[2][16]);
int min(int *array_unidim, int n);
void ordemCrescente(int *array_unidim, int *array_crescente, int n);
void div2(float *array_unidim, float *array_dividido, int n);
void intToFloat(int *array_int, float *array_float, int n);
void intToFloatBi(int array_int[16][16], float array_float[16][16]);
int numsDiv3(int *array_unidim, int *numsDiv3, int n);
int produtoInterno(int *array1, int *array2 ,int n);
int numsPrimos(int *array_uni, int *array_primos, int n);
void matrix16x16(int matriz_final[16][16], int *matriz1, int *matriz2);
int verificaNumsIguais(float *matriz, int n);
int verificaZeros(float *matriz, int n);
void condensa(float matrix[16][16]);
void ajuda();
