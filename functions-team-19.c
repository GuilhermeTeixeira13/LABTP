/**
 * @file    functions-team-19.c.
 * @brief   Ficheiro que contém todas as funções necessárias para o funcionamento do programa principal.
 * @author  Guilherme Teixeira / Guilherme Nunes / João Martins / Tiago Ribeiro / Henrique Policarpo.
 * @version 1.0.
 */

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

/**
 * Função que limpa a consola.
*/
void cleanConsole()
{
    system("clear");
}

/**
 * Função que limpa o stdin.
 */
void limpaInput()
{
    while (getchar() != '\n');
}

/**
 * Função que imprime ajuda caso o programa seja executado na forma "./main.exe --help".
 */
void helpflag()
{
  printf("------------------------------------------------------------------------------------\n");
  printf("AJUDA ADICIONAL (--help)\n");
  printf("\n");
  printf("--> Este programa tem como objetivo possibilitar que o usuário escolha uma das várias\n");
  printf("opções disponíveis no 'menu base', opções estas que calculam diversas estatíticas e\n");
  printf("operações entre 16 valores de -1 a 35. Após o usuário escolher uma das opções, e após\n");
  printf("a mesma ser executada, o menu volta a ser exibido.\n");
  printf("\n");
  printf("IMPORTANTE:\n");
  printf(" . Matriz: Conjunto organizado de elementos ou de informações, com linhas e colunas,\n");
  printf(" usado geralmente para resolver problemas de forma padronizada.\n");
  printf(" . Vetor: composto de “n” quantidades que dependem de uma estrutura de coordenadas \n");
  printf(" n-dimensionais, que se modificam de acordo com as leis decretadas quando ela é \n");
  printf("alterada.\n");
  printf("\n");
  printf("-> Para uma ajuda mais específica/detalhada deve escolher a opção 11 do menu, dentro\n");
  printf("do programa.\n");
}

/**
 * Função que imprime uma linha horizontal para organização.
 */
void separacao()
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

/**
 * Função que imprime o MENU PRINCIPAL.
 * 
 * @return A opção do MENU, escolhida pelo utilizador do programa.
 */
int menu()
{
  int opcao;
  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("┃ *\t\t\t      ↓ MENU PRINCIPAL ↓                                * ┃\n");
  printf("┃                                                                                 ┃\n");
  printf("┃ 1 - CONSTRUÇÃO DE MATRIX 16X2 (1ªLINHA = VETOR INICIAL / 2ªLINHA = 4 X 1ªLINHA) ┃\n");
  printf("┃ 2 - IDENTIFICAÇÃO DO VALOR MÍNIMO (VETOR INICIAL)                               ┃\n"); 
  printf("┃ 3 - VETOR (INICIAL) ORDENADO POR ORDEM CRESCENTE                                ┃\n");
  printf("┃ 4 - CÁLCULO DA DIVISÃO DE TODOS OS ELEMENTOS POR 2 (VETOR INICIAL)              ┃\n");
  printf("┃ 5 - DEVOLUÇÃO DOS VALORES QUE SÃO DIVISÍVEIS POR 3 (VETOR INICIAL)              ┃\n");
  printf("┃ 6 - CÁLCULO DO LOG (BASE NATURAL) DE TODOS OS ELEMENTOS (VETOR INICIAL)         ┃\n");
  printf("┃ 7 - LEITURA DE NOVO VETOR E DEVOLUÇÃO DO PRODUTO INTERNO                        ┃\n");
  printf("┃ 8 - IDENTIFICAÇÃO DE NÚMEROS PRIMOS (VETOR INICIAL)                             ┃\n");
  printf("┃ 9 - MATRIZ 16X16 - PRODUTO DO VETOR INICIAL COM O MESMO VETOR ORDENADO          ┃\n");
  printf("┃ 10 - CÁLCULO DO DETERMINANTE DA MATRIZ 16X16                                    ┃\n");
  printf("┃ 11 - AJUDA                                                                      ┃\n");
  printf("┃ 12 - SAIR DO PROGRAMA                                                           ┃\n");
  printf("┃                                                                                 ┃\n");
  printf("┃ POR FAVOR, ESCOLHA UMA OPÇÃO --> ");
  scanf("%d", &opcao);
  while(opcao<1 || opcao>12)
  {
      printf("┃ - ERRO! DIGITE UMA OPÇÃO VÁLIDA -> ");
      scanf("%d", &opcao);
  }
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
  return opcao;
}

/**
 * Função que imprime uma tablea de ajudas.
 */
void ajuda()
{
  printf("\n");
  printf(" _________________________________________________\n");
  printf("|                                                 |\n");
  printf("|\t\t PAINEL DE AJUDA \t\t  |\n");
  printf("|_________________________________________________|\n");
  printf("|                                                 |\n");
  printf("| Função 1: Forma uma matriz 16x2, onde a         |\n");
  printf("|           primeira linha corresponde ao vetor   |\n");
  printf("|           inserido pelo utilizador e a segunda  |\n");
  printf("|           pelo quádruplo dos mesmos valores;    |\n");
  printf("|                                                 |\n");
  printf("| Função 2: Identifica o menor dos                |\n");
  printf("|           elementos do vetor inicial;           |\n");
  printf("|                                                 |\n");
  printf("| Função 3: Vetor inicial é ordenado por ordem    |\n");
  printf("|           crescente;                            |\n");
  printf("|                                                 |\n");
  printf("| Função 4: Divide todos os elementos do vetor    |\n");
  printf("|           inicial por dois;                     |\n");
  printf("|                                                 |\n");
  printf("| Função 5: Mostra os valores do vetor inicial    |\n");
  printf("|           que são divisíveis por três;          |\n");
  printf("|                                                 |\n");
  printf("| Função 6: Calcula o logaritmo de todos os       |\n");
  printf("|           elementos do vetor inicial;           |\n");
  printf("|                                                 |\n");
  printf("| Função 7: Lê um novo vetor, calcula e devolve   |\n");
  printf("|           o seu produto interno;                |\n");
  printf("|                                                 |\n");
  printf("| Função 8: Identifica todos os números primos    |\n");
  printf("|           do vetor inicial;                     |\n");
  printf("|                                                 |\n");
  printf("| Função 9: Calcula e mostra a matriz 16 por 16   |\n");
  printf("|           resultante do produto do vetor        |\n");
  printf("|           inicial, com o mesmo vetor ordenado   |\n");
  printf("|           por ordem crescente;                  |\n");
  printf("|                                                 |\n");
  printf("| Função 10: Cálculo do determinante da matriz    |\n");
  printf("|            mencionada na função 9;              |\n");
  printf("|                                                 |\n");
  printf("| Extra: Caso o programa seja executado por       |\n");
  printf("|        /main.exe --help aparece uma ajuda       |\n");
  printf("|        adicional.                               |\n");
  printf("|_________________________________________________|\n");
  printf("\n\n");
}

/**
 * Função que imprime uma mini-intro para o programa.
 */
void intro()
{
  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("┃ *\t\t\t   >  PROJETO // TEAM-19  <                               * ┃\n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

}

/**
 *  Função cria uma matriz 16x2 em que a primeira linha
 * é formada pelos elementos de *array_unidim enquanto que
 * a segunda surge a partir do quádruplo desses mesmos elementos.
 * 
 * @param int *array_unidim - Array unidimensional que formará a primeira linha.
 * @param int nova_matriz[2][16] - Array 16x2 que será criado e que contém a matriz pretendida.
 */
void matriz16x2(int *array_unidim, int nova_matriz[2][16])
{ 
  int c=0, l=0;

  for(l=0; l<2; l++)
  {
    for(c=0; c<16; c++)
    {
      if(l==0) 
        nova_matriz[l][c] = array_unidim[c]; 
      else     
        nova_matriz[l][c] = array_unidim[c]*4;
    }
  }
}

/**
 *  Função quer devolve o menor elemento dentro do vetor pretendido.
 * 
 * @param int *array_unidim - Array unidimensional no qual será procurado o valor mínimo.
 * @param int n - Tamanho do array_unidim.
 * 
 * @return O mínimo no vetor passado como argumento.
 */
int min(int *array_unidim, int n)
{
  int c=0, minimo = array_unidim[0];

  for(c=1; c<n; c++)
  {
    if(array_unidim[c]<minimo)
      minimo = array_unidim[c];
  }
  return minimo;
}

/**
 * Função que retorna o vetor que foi passado como 1º parâmetro, ordenado.
 * 
 * @param int *array_unidim - Array unidimensional que pretendemos ordenar.
 * @param int *array_crescente - Array no qual serão armazenados os elementos ordenados.
 * @param int n - Tamanho do array_unidim.
 */
void ordemCrescente(int *array_unidim, int *array_crescente, int n)
{
  int i, j, a;

  for(i=0; i<n; i++)
    array_crescente[i] = array_unidim[i];

  for(i=0; i<n; i++)
  {
    for(j=i+1; j<n; j++)
    {
      if(array_crescente[i]>array_crescente[j]) 
      {                       
        /*            Se existir alguma posição, à frente da analisada,
        cujo elemento é menor que o valor dela mesma, então os valores trocam de posições */
        a = array_crescente[i];
        array_crescente[i] = array_crescente[j];
        array_crescente[j] = a;
      }
    } 
  }
}

/**
 * Função responsável por dividir todos os valores do array por 2.
 * 
 * @param float *array_unidim - Array unidimensional que pretendemos dividir por 2.
 * @param float *array_dividido - Array no qual serão armazenados os elementos divididos por 2.
 * @param int n - Tamanho do array_unidim.
 */
void div2(float *array_unidim, float *array_dividido, int n)
{
  int c;

  for(c=0; c<n; c++)
    array_dividido[c] = array_unidim[c] / 2;
}

/**
 * Função responsável por "transformar" um array unidimensional inteiro em float (útil no decorrer do código).
 * 
 * @param int *array_int - Array inteiro unidimensional.
 * @param float *array_float - Array float unidimensional que será criado.
 * @param int n - Tamanho do array_unidim.
 */
void intToFloat(int *array_int, float *array_float, int n)
{
  int c;

  for(c=0; c<n; c++)
    array_float[c] = array_int[c];
}

/**
 * Função responsável por "transformar" um array bidimensional inteiro em float (útil no decorrer do código).
 * 
 * @param int array_int[16][16] - Array inteiro bidimensional 16x16.
 * @param float array_float[16][16] - Array float bidimensional 16x16 que será criado.
 */
void intToFloatBi(int array_int[16][16], float array_float[16][16])
{
  int c, l;

  for(l=0; l<16; l++)
  {
    for(c=0; c<16; c++)
      array_float[l][c] = array_int[l][c];
  }
}

/**
 * Função responsável por criar um array com os números presentes no array_unidim que são divisíveis por 3.
 * 
 * @param int *array_unidim - Array inteiro unidimensional.
 * @param int *numsDiv3 - Array inteiro unidimensional onde serão colocados os números pretendidos.
 * @param int n - Tamanho do array_unidim.
 * 
 * @return Posição do último número divísivel por 3 no array numsDiv3 (útil no decorrer do código).
 * (caso não hajam números divisíveis por 3 retorna -2)
 */
int numsDiv3(int *array_unidim, int *numsDiv3, int n)
{ 
  int c=0, ultimo = -2; 

  for(c=0; c<n; c++)
  {
    if(array_unidim[c] % 3 == 0)
      numsDiv3[c] = array_unidim[c];
    else
      numsDiv3[c] = 0;
  }
  for(c=0; c<n; c++)
  {
    if(numsDiv3[c]!=0)
      ultimo = c;
  }

  return ultimo;
}

/**
 * Função responsável por devolver o produto interno dos arrays passados como parâmetros.
 * 
 * @param int *array1 - Array inteiro unidimensional.
 * @param int int *array2 - Array inteiro unidimensional.
 * @param int n - Tamanho dos arrays.
 * 
 * @return Produto interno.
 * 
 * Para a função funcionar corretamente, o tamanho de array1 tem de ser igual ao tamanho de array2.
 */
int produtoInterno(int *array1, int *array2 ,int n)
{
  int l, produto_interno=0;

  for(l=0; l<n; l++)
    produto_interno += (array1[l]*array2[l]);

  return produto_interno;
}

/**
 * Função responsável por criar um novo array formado pelos números primos do array passado como 1ª parâmetro.
 * 
 * @param int *array_uni - Array unidimensional no qual pretendemos ver os números primos.
 * @param int int *array_primos - Array no qual serão armazenados os elementos primos do vetor array_uni.
 * @param int n - Tamanho do array_uni.
 * 
 * @return Posição do último número primo no array array_primos (útil no decorrer do código).
 */
int numsPrimos(int *array_uni, int *array_primos, int n)
{
  int c, i, contador_div=0, ultimo=0;

  for(c=0; c<n; c++) 
  {
    if(array_uni[c]>0) 
    {
      for(i=1; i<=array_uni[c]; i++) 
      {                              
        if(array_uni[c] % i == 0)    
          contador_div++;            
      }                              
      if(contador_div==2) // Se o número só tiver 2 divisores, então é primo
        array_primos[c] = array_uni[c];
      contador_div=0;
    }
  }

  for(c=0; c<n; c++)
  {
    if(array_primos[c]!=0)
      ultimo = c;
  }

  return ultimo;
}

/**
 * Função responsável por criar uma matriz 16x16 resultante da multiplicação de matriz1 com matriz2.
 * 
 * @param int matriz_final[16][16] - Matriz 16x16 resultante da multiplicação de matriz1 com matriz2.
 * @param int *matriz1 - Array unidimensional de 16 elementos.
 * @param int *matriz2 - Array unidimensional de 16 elementos.
 * 
 * O tamanho tanto da matriz1 como da matriz2 deve ser de 16.
 */
void matrix16x16(int matriz_final[16][16], int *matriz1, int *matriz2)
{
  int c, l;

  for(l=0; l<16; l++)
  {
    for(c=0; c<16; c++)
      matriz_final[l][c] = matriz1[l]*matriz2[c];
  }
}

/**
 * Função responsável por identificar se existem números repetidos na matriz unidimensional.
 * 
 * @param float *matriz - Matriz float unidimensional.
 * @param int n - Tamanho da matriz.
 * 
 * @return 1 se houverem números que se repetem.
 * @return 0 se não houver números repetidos.
 */
int verificaNumsIguais(float *matriz, int n)
{
  int colunas, i, repetido=0;

  for(colunas=0; colunas<n && repetido==0; colunas++) 
  {
    for(i=0; i<n; i++)
    {
      if(i!=colunas && matriz[colunas]==matriz[i])
        repetido=1;
    }
    }
    if(repetido==1)
      return 1;
    else
      return 0; 
}

/**
 * Função responsável por identificar se existem zeros na matriz unidimensional.
 * 
 * @param float *matriz - Matriz float unidimensional.
 * @param int n - Tamanho da matriz.
 * 
 * @return 1 se houverem zeros na matirz.
 * @return 0 se não houver zeros na matriz.
 */
int verificaZeros(float *matriz, int n)
{
  int colunas, zeros=0;

  for(colunas=0; colunas<n && zeros==0; colunas++) 
  {
    if(matriz[colunas]==0)
      zeros = 1;
  }
  if(zeros==1)
    return 1;
  else
    return 0; 
}

/**
 * Função responsável por deixar a matriz na sua forma condensada.
 * 
 * @param float matriz[16][16] - Matriz 16x16 que pretendemos condensar.
 */
void condensa(float matriz[16][16])
{
  int coluna=0, linha, c;
  float linha_nova[16][16];

  for(linha=1; linha<16; linha++)
  {
    for(coluna=0; coluna<16; coluna++)
      linha_nova[linha-1][coluna] = matriz[linha][coluna] +  ((-1)*(matriz[linha][linha-1])/(matriz[linha-1][linha-1])*(matriz[linha-1][coluna]));
    for(c=0; c<16; c++)
      matriz[linha][c] = linha_nova[linha-1][c];
  }
}
