// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas do projeto
#include "playlist.h"

int criar_dado(Musica **dado);

// funcao principal
int main(void) {
  // no início a playlist está vazia, logo, o ponteiro inicio tem valor NULL
  // o ponteiro inicio conterá o endereço do primeiro elemento da playlist
  Playlist *pl = NULL;
  int opcao, ok, pos, *posi = 0;
  char nome[30];
  Musica *dado;

  // menu de opções para execuções de operações sobre a playlist
  do {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar playlist");
    printf("\n2 - Liberar playlist");
    printf("\n3 - Inserir música no início");
    printf("\n4 - Inserir música no final");
    printf("\n5 - Inserir música (ordenado)");
    printf("\n6 - Remover música do início");
    printf("\n7 - Remover música do final");
    printf("\n8 - Remover música (qualquer)");
    printf("\n9 - Buscar música pela posição");
    printf("\n10 - Buscar música pelo nome");
    printf("\n11 - Imprimir playlist de músicas");
    printf("\n12 - Próxima Música");
    printf("\n13 - Música Anterior");
    printf("\n14 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:

      // criar playlist
      pl = criar_playlist();

      if (pl != NULL) {
        printf("\n Playlist criada com sucesso!");
      } else {
        printf("\n Playlist não criada!");
      }
      break;

    case 2:

      // liberar playlist
      ok = liberar_playlist(pl);
      pl = NULL;

      if (ok) {
        printf("\n Playlist liberada com sucesso!");
      } else {
        printf("\n Playlist não liberada!");
      }
      break;

    case 3:

      // inserir elemento no início
      ok = criar_dado(&dado);
      ok = inserir_playlist_inicio(pl, dado);

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

    case 4:

      // inserir elemento no final
      ok = criar_dado(&dado);
      ok = inserir_playlist_final(pl, dado);

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

    case 5:

      // inserir elemento de forma ordenada
      ok = criar_dado(&dado);
      ok = inserir_playlist_ordenada(pl, dado);

      if (ok == 1) {
        printf("\n Inserção realizada com sucesso!");
      } else {
        printf("\n Falha na inserção!");
      }

      break;

    case 6:

      // remover elemento do início
      ok = remover_playlist_inicio(pl);

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    case 7:

      // remover elemento do final
      ok = remover_playlist_final(pl);

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    case 8:

      // remover elemento do meio
      printf("\nMúsica a ser removida: ");
      scanf("%[^\n]", nome);

      ok = remover_playlist_meio(pl, nome);

      if (ok == 1) {
        printf("\n Remoção realizada com sucesso!");
      } else {
        printf("\n Falha na remoção!");
      }
      break;

    case 9:

      // busca elemento pela posicao
      printf("\n Posição do elemento a ser buscado: ");
      scanf("%d", &pos);

      ok = buscar_playlist_posicao(pl, pos, dado);

      if (ok) {
        printf("\n Busca realizada com sucesso!");
        printf("\n Música da %dª posição: ", pos);
        imprimir_dado(dado);
      } else {
        printf("\n Posição não existe!");
      }

      break;

    case 10:

      // busca elemento pelo nome da música
      printf("\n Nome da música a ser buscada: ");
      scanf("%s", nome);

      ok = buscar_playlist_nome(pl, nome, &pos);

      if (ok) {
        printf("\n Busca realizada com sucesso!");
        printf("\n Música com nome '%s' na playlist: ", nome);
        printf("%d", pos);
      } else {
        printf("\n Música não encontrada!");
      }

      break;

    case 11:

      // imprime a playlist
      printf("\n PLAYLIST: ");
      ok = imprimir_playlist(pl);

      break;

    case 12:
      // próxima música
      (*posi)++;
      ok = posicao_playlist(pl, posi, dado);
      if (ok) {
        printf("Próxima música: ");
        imprimir_dado(dado);
      } else {
        printf("\n Ocorreu um erro.");
      }

      break;

    case 13:
      // música anterior
      (*posi)--;
      ok = posicao_playlist(pl, posi, dado);

      if (ok) {
        printf("Música anterior: ");
        imprimir_dado(dado);
      } else {
        printf("\n Ocorreu um erro.");
      }

      break;

    case 14:

      // libera memória e finaliza programa
      liberar_playlist(pl);
      printf("\nFinalizando...");
      break;

    default:
      printf("\nOpção inválida!");
      break;
    }

  } while (opcao != 14);

  return 0;
}
