/**
 * @file    main-team-19.c.
 * @brief   Este programa oferece ao usuário um MENU com diversas funcionalidades. Para mais informações ler README.txt.
 * @author  Guilherme Teixeira / Guilherme Nunes / João Martins / Tiago Ribeiro / Henrique Policarpo.
 * @version 1.0.
 */

#include <stdio.h>
#include "functions-team-19.h" 
#include<math.h>
#include<string.h>
#include <stdlib.h>

/**
 * Esta é a função principal to programa, onde são conjugadas todas as funções criadas de modo a oferecer ao usuário uma vasta gama de funcionalidades.
 */
int main(int argc, char *argv[])
{
  /* ↓ Mostra alguma ajuda caso seja adicionada a flag --help. ↓ */
  if(argc == 2)
  {
    char help[7] = "--help";
    char arg1[7];

    strcpy(arg1, argv[1]);
    int compara = strcmp(help, arg1);

    if(compara == 0) 
      helpflag();   
  }

  /* ↓ Declaração de variáveis. ↓ */
  int array_utilizador[16], i=0, j=0, opcao_menu, linha, coluna, array16x2[2][16], array_crescente[16], array_multiplos3[16], ultima_pos, novo_array[16], enter = 0;
  int array_primos[16]={}, pos_ultimpo_primo=0, matrix16[16][16], ha_zeros=0, ha_repetidos=0, contador_zeros=0, mult_DP=0, contador_multiplicacoes=0;
  float array_dividido[16], array_utilizador_float[16], matrix16_float[16][16];
  char avancar[5], *pos;

  /* ↓ Introdução / Validação de números. ↓ */
  intro();
  printf("\t\tOlá! Por favor, insira 16 números (-1 a 35):\n");
  for(i=0; i<16; i++)
  {
    printf(" ");
    for(j=0; j<=i; j++)
      printf("┇");

    printf(" %dº -> ", i+1);
    
    while(scanf("%d", &array_utilizador[i]) != 1)
    {
      limpaInput();
      printf(" - Erro! Digite um número, não uma letra: ");
    }

    while(array_utilizador[i]<-1 || array_utilizador[i]>35)
    {
      printf(" - Erro! Deve estar compreendido entre -1 e 35: ");
      while(scanf("%d", &array_utilizador[i]) != 1)
      {
          limpaInput();
          printf(" - Erro! Digite um número, não uma letra: ");
      }
    }
  }
  printf("\n");


  /* ↓ Enquanto a opção escolhida não for sair, o programa vai estar sempre a mostrar o menu e a executar funcionalidades. ↓ */
  opcao_menu = menu();
  while(opcao_menu != 12) 
  {
    printf("\n");
    switch (opcao_menu)
    {
    case 1:
      printf(" OPÇÃO %d: MATRIZ 16X2 - (1ªLINHA = VETOR INICIAL / 2ªLINHA = 4 X 1ªLINHA)\n\n", opcao_menu);

      /* ↓ Organiza os números na forma de matriz. ↓ */
      matriz16x2(array_utilizador, array16x2);
      for(linha=0; linha<=1; linha++)
      {
        for(coluna=0; coluna<16; coluna++)
          printf("%d\t", array16x2[linha][coluna]);
        printf("\n");
      }
      break;
    case 2:
      printf(" OPÇÃO %d: IDENTIFICAÇÃO DO VALOR MÍNIMO (VETOR INICIAL)\n\n", opcao_menu);
      printf(" O valor mínimo relativamente a todos os elementnos do vetor é: %d\n", min(array_utilizador, 16));
      break;
    case 3:
      ordemCrescente(array_utilizador, array_crescente, 16);
      printf(" OPÇÃO %d: VETOR INICIAL ORDENADO POR ORDEM CRESCENTE\n\n", opcao_menu);

      /* ↓ Organiza os números na forma de vetor. ↓ */
      printf(" (");
      for(coluna=0; coluna<16; coluna++)
      {
        if(coluna != 15)
          printf("%d, ", array_crescente[coluna]);
        else
          printf("%d", array_crescente[coluna]);
      }
      printf(")\n");
      break;
    case 4:
      intToFloat(array_utilizador, array_utilizador_float, 16);
      div2(array_utilizador_float, array_dividido, 16);
      printf(" OPÇÃO %d: DIVISÃO DE ELEMENTOS POR 2\n\n", opcao_menu);

      /* ↓ Organiza os números na forma de vetor. ↓ */
      printf(" (");
      for(coluna=0; coluna<16; coluna++)
      {
        if(coluna!=15)
          printf("%.1f, ", array_dividido[coluna]); 
        else
          printf("%.1f", array_dividido[coluna]);
      }
      printf(")\n");
      break;
    case 5:
      ultima_pos = numsDiv3(array_utilizador, array_multiplos3, 16);
      printf(" OPÇÃO %d: ELEMENTOS DIVISÍVEIS POR 3\n\n", opcao_menu);

      /* ↓ Organiza os números na forma de vetor. ↓ */
      if(ultima_pos == -2)
        printf("Não existem elementos divisíveis por 3, no array digitado.\n");
      else
      {
        printf(" (");
        for(coluna=0; coluna<16; coluna++)
        {
          if(array_multiplos3[coluna] != 0)
          {
            if(coluna!=ultima_pos)
              printf("%d, ", array_multiplos3[coluna]);  
            else
              printf("%d)", array_multiplos3[coluna]);
          }
        }
      }
      printf("\n");
      break; 
    case 6:
      printf(" OPÇÃO %d: CÁLCULO E DEVOLUÇÃO DO LOGARITMO (BASE NATURAL) DE TODOS OS VALORES\n\n", opcao_menu);
      for(coluna=0; coluna<16; coluna++)
      {
        printf(" log(%d) = ", array_utilizador[coluna]);
        if(array_utilizador[coluna]<0) // Não existe logarítmo de 0 nem de números inferiores a zero.
          printf("Inexistente (número < 0).\n");
        else if(array_utilizador[coluna]==0)
          printf("Inexistente (número = 0).\n");  
        else
          printf("%.3f\n", log(array_utilizador[coluna]));
      }
      break;
    case 7:
      printf(" OPÇÃO %d: LEITURA DE NOVO VETOR E DEVOLUÇÃO DO PRODUTO INTERNO\n\n", opcao_menu);

      /* ↓ Pede 16 números sem restrições. ↓ */
      for(i=0; i<16; i++)
      {
        printf(" ");
        for(j=0; j<=i; j++)
          printf("┇");
        printf(" %dº -> ", i+1);
        while(scanf("%d", &novo_array[i]) != 1)
        {
          limpaInput();
          printf(" - Erro! Digite um número, não uma letra: ");
        }
      }
      printf("\n");

      /* ↓ Calcula-se e mostra-se o valor do PI ↓ */
      int pi = produtoInterno(array_utilizador, novo_array, 16);
      printf("O produto inteiro do vetor inicial com o novo vetor digitado é: %d\n", pi);
      break;
    case 8:
      pos_ultimpo_primo = numsPrimos(array_utilizador, array_primos, 16);
      printf(" OPÇÃO %d: IDENTIFICAÇÃO DOS NÚMEROS PRIMOS DO VETOR INICIAL\n\n", opcao_menu);

      /* ↓ Organiza os números na forma de vetor. ↓ */
      printf(" (");
      for(coluna=0; coluna<16; coluna++)
      {
        if(array_primos[coluna] != 0)
        {
          if(coluna != pos_ultimpo_primo)
            printf("%d, ", array_primos[coluna]);
          else
            printf("%d)", array_primos[coluna]);
        }
      }
      printf("\n");
      break;
    case 9:
      ordemCrescente(array_utilizador, array_crescente, 16);
      matrix16x16(matrix16, array_utilizador, array_crescente);
      printf(" OPÇÃO %d: MATRIZ 16X16 - PRODUTO DO VETOR INICIAL COM ELE MESMO ORDENADO POR ORDEM CRESCENTE\n", opcao_menu);
      printf("\n");

      /* ↓ Organiza os números na forma de matriz. ↓ */
      for(linha=0; linha<16; linha++)
      { 
        for(coluna=0; coluna<16; coluna++)
          printf("%d\t", matrix16[linha][coluna]);
        printf("\n");
      }
      break;
    case 10:
      printf(" OPÇÃO %d: CALCULAR O DETERMINANTE DA MATRIZ 16x16 DA OPÇÃO 9\n\n", opcao_menu);
      ordemCrescente(array_utilizador, array_crescente, 16);
      matrix16x16(matrix16, array_utilizador, array_crescente);
      intToFloat(array_utilizador, array_utilizador_float, 16);
      /* ↓ Transforma a matriz 16x16 em float, para não haver problemas com as divisões. ↓ */
      intToFloatBi(matrix16, matrix16_float);

      ha_zeros = verificaZeros(array_utilizador_float, 16);
      ha_repetidos = verificaNumsIguais(array_utilizador_float, 16);
      if(ha_repetidos == 1 || ha_zeros == 1) // Se houver repetidos ou se existir um zero no array digitado, já se sabe que o determinante sera 0 (filas nulas - propriedade da Álgebra).
      {
        if(ha_repetidos == 1 && ha_zeros == 0)
          printf(" O determinante é 0. Há pelo menos dois elementos repetidos no mesmo vetor o que faz com que haja duas linhas dependentes.\n");
        else if((ha_repetidos == 0 || ha_repetidos ==1) && ha_zeros == 1)
          printf("  O determinante é 0. Há pelo menos um 0, o que faz com que haja pelo menos uma fila nula.\n");
      }
      else // Se não houver zeros nem números repetios no arrya digitado.
      {
        condensa(matrix16_float);

        for(linha=0; linha<16 && contador_zeros!=16; linha++)
        {
          contador_zeros=0;
          for(coluna=0; coluna<16 && contador_zeros!=16; coluna++)
          {
            if(matrix16_float[linha][coluna] == 0)
              contador_zeros++; // Conta os zeros de cada linha.
            else // Caso não haja filas com zeros, multiplica os números da diagonal principal.
            {
              if(linha == coluna)
              {
                mult_DP = mult_DP * matrix16_float[linha][coluna];
                contador_multiplicacoes++;
              }
            }
          }
          if(contador_zeros == 16) // Encontrou uma linha de zeros e sai do loop.
            printf(" O determinante é 0. Ao condensar, encontrou-se uma fila cheia de zeros.\n");
        }
      }
      if(contador_multiplicacoes == 16) // Não se encontraram filas de zeros.
        printf("Condensou-se a matriz toda e o determinante é a multiplicação dos elementos da DP --> %d\n", mult_DP);
      break;
    case 11:
      printf(" OPÇÃO %d: PAINEL DE AJUDA\n\n", opcao_menu);
      ajuda();
      break; 
    }
    printf("\n");

    limpaInput();
    do
    {
      printf("PRESSIONE ENTER PARA AVANÇAR -> ");
      fgets(avancar, 5, stdin);
      pos = strchr(avancar, '\n');
      *pos = '\0';

      if((strcmp(avancar, "\0") == 0))
      {
        enter = 1;
        cleanConsole();
      }
      else 
        enter = 0;
    }while(enter == 0);

    opcao_menu = menu();
  }
  printf("\n\t\t OBRIGADO POR USUFRUIR DO NOSSO PROGRAMA!\n\n");
  return 0;
}