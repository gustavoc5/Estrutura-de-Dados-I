//	Gustavo Rafael Paulino - 2022006185
//	Vítor Ortiz Gomes - 2022006256

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas do projeto
#include "produto.h"

int criar_dado(int *dado);

// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  // o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  Produto *p, *mp, *cp;
  int n, opcao, dado, ok, pos, i, j, ind = 0;

  // menu de opções para execuções de operações sobre a lista
  do {
    printf("\n\n-----------------Menu de opções-----------------");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Imprimir lista");
    printf("\n4 - Retornar o produto de menor preço");
    printf("\n5 - Remove últimos n elementos do final");
    printf("\n6 - Troca dois elementos");
    printf("\n7 - Criar produto");
    printf("\n8 - Sair");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:

      // criar lista
      li = criar_lista();

      if (li != NULL) {
        printf("\n Lista criada com sucesso!");
      } else {
        printf("\n Lista não criada!");
      }
      break;

    case 2:

      // liberar lista
      ok = liberar_lista(li);

      if (ok) {
        printf("\n Lista liberada com sucesso!");
      } else {
        printf("\n Lista não liberada!");
      }
      break;

    case 3:

      // imprime a lista
      printf("\n Lista estática: ");
      ok = imprimir_lista(li, ind);
      if (ok == 1)
        printf("Lista foi imprimida com sucesso");

      if (ok == 0)
        printf("Não foi possível imprimir a lista");

      break;

    case 4:
      // retornar produto de menor preço
      mp = menor_preco(li);
      imprimir_produto(mp);
      break;

    case 5:
      // remover elementos da lista
      ok = remover_lista(li);
      if (ok == 1) {
        printf("Elementos removidos com sucesso!");
      } else
        printf("Não foi possível remover os elementos");

      break;

    case 6:
      // trocar elemetos da lista
      printf("Digite as posições dos dois elementos que você quer trocar: ");
      // armazenando as posições que deverão ser trocadas
      scanf("%d%d", &i, &j);
      ok = troca_elemento(li, i, j);
      if (ok == 1)
        printf("Troca feita com sucesso!");
      else
        printf("Não foi possível efetuar a troca");
      break;

    case 7:

      // inserir elemento no início
      cp = criar_produto();
      ok = inserir_lista_inicio(cp, li);

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

    case 8:

      // libera memória e finaliza programa
      liberar_lista(li);
      printf("\nFinalaizando...");
      return 0;
      break;

    default:
      printf("\nOpção inválida!");
      break;
    }
  } while (opcao != 8);

  return 0;
}
