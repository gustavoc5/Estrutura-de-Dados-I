// TAD para Lista Dinâmica Duplamente Encadeada Circular

#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definição do struct música
struct musica {
  char autor[30];
  char nome[30];
};

// definição do struct elemento
typedef struct elemento {
  struct elemento *ant;
  Musica *dado;
  struct elemento *prox;
} Elemento;

// função para alocar memória do tipo Playlist
Playlist *criar_playlist() {
  // 'pl' é um ponteiro para ponteiro do tipo Elemento
  Playlist *pl = (Playlist *)malloc(sizeof(Playlist));

  // se a alocação estiver correta 'pl' aponta para NULL (Playlist vazia)
  if (pl != NULL) {
    *pl = NULL;
  } else {
    return NULL;
  }

  return pl;
}

// função para liberar memória
int liberar_playlist(Playlist *pl) {
  // verifica se a Playlist foi alocada corretamente
  if (pl == NULL) {
    return 0;
  }

  // verifica se a Playlist não está vazia
  if ((*pl) != NULL) {
    Elemento *no, *aux;
    no = *pl;

    // laço percorre a Playlist até o último elemento, liberando o anterior
    while (no->prox != (*pl)) {
      aux = no;
      no = no->prox;
      free(aux);
    }

    // libera o último elemento
    free(no);

    // libera o ponteiro de ponteiro (Playlist)
    free(pl);
  }

  return 1;
}

//**************************************************************************
// função para obter o tamanho da Playlist
int tamanho_playlist(Playlist *pl) {
  // verifica se a Playlist foi alocada corretamente ou se a Playlist está vazia
  if (pl == NULL || (*pl) == NULL) {
    return 0;
  }

  // iniciaplza o contador de elementos
  int cont = 0;

  // cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da
  // Playlist
  Elemento *no;
  no = *pl;

  // incrementa 'cont' até acabar o último elemento da Playlist
  do {
    cont++;
    no = no->prox;
  } while (no != (*pl));

  // retorna a quantidade de elementos da Playlist
  return cont;
}

//**************************************************************************
// função para verificar se a Playlist está vazia
int playlist_vazia(Playlist *pl) {
  // verifica se houve problema na criação da Playlist
  // ou seja, 'pl' não é uma Playlist váplda
  if (pl == NULL) {
    return -1;
  }

  // verifica se a Playlist foi criada corretamente
  // mas não contém nenhum valor (Playlist vazia)
  if (*pl == NULL) {
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}

//**************************************************************************
// função para alocar memória do tipo Elemento
Elemento *criar_elemento() {
  // 'no' é um ponteiro do tipo Elemento
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));

  // retorna ponteiro alocado
  return no;
}

//**************************************************************************
// função para inserir elemento no início da Playlist
int inserir_playlist_inicio(Playlist *pl, Musica *dado) {

  // verifica se a Playlist foi criada corretamente
  if (pl == NULL) {
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo
  // ele na Playlist)
  Elemento *no;
  no = criar_elemento();

  // verifica se a memória foi alocada corretamente
  if (no == NULL) {
    return 0;
  }
  // atribui valores ao elemento novo
  no->dado = dado;
  // verifica se a Playlist está vazia
  if ((*pl) == NULL) {

    // insere elemento único no início da Playlist
    no->prox = no; // próximo elemento na Playlist circular é ele mesmo
    no->ant = no;

    *pl = no;
    // 'no' passa a ser o primeiro elemento da Playlist
  } else {
    Elemento *aux;
    aux = *pl;
    // percorre a Playlist até o último elemento
    while (aux->prox != (*pl)) {
      aux = aux->prox;
    }

    aux->prox = no;

    // insere elemento no início da Playlist
    // 'no' é o próximo elemento na Playlist circular após o último
    no->ant = (*pl)->ant;
    (*pl)->ant = no;

    no->prox = *pl; // primeiro elemento antigo '*pl' é o próximo após o 'no'
    *pl = no;       // 'no' passa a ser o primeiro elemento
  }

  return 1;
}

//**************************************************************************
// função para inserir elemento no final da Playlist
int inserir_playlist_final(Playlist *pl, Musica *dado) {
  // verifica se a Playlist foi criada corretamente
  if (pl == NULL) {
    return 0;
  }
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo
  // ele na Playlist)
  Elemento *no;
  no = criar_elemento();

  // verifica se a memória foi alocada corretamente
  if (no == NULL) {
    return 0;
  }
  // atribui valores ao elemento novo
  no->dado = dado;
  // verifica se a Playlist está vazia
  if ((*pl) == NULL) {

    // insere elemento único no início da Playlist
    no->ant = no;
    no->prox = no; // próximo elemento na Playlist circular é ele mesmo

    *pl = no; // 'no' passa a ser o primeiro elemento da Playlist

  } else {
    Elemento *aux;
    aux = *pl;

    // percorre a Playlist até o último elemento
    while (aux->prox != (*pl)) {
      aux = aux->prox;
    }

    // insere elemento no final da Playlist
    aux->prox =
        no; // 'no' é o próximo elemento na Playlist circular após o último
    no->ant = aux;
    no->prox = *pl; // primeiro elemento '*pl' é o próximo após o 'no'
  }

  return 1;
}

//**************************************************************************
// função para inserir elemento na Playlist de forma ordenada
int inserir_playlist_ordenada(Playlist *pl, Musica *dado) {
  // verifica se a Playlist foi criada corretamente
  if (pl == NULL) {
    return 0;
  }
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele
  // na Playlist)
  Elemento *no;
  no = criar_elemento();
  // verifica se a memória foi alocada corretamente
  if (no == NULL) {
    return 0;
  }
  // atribui valores ao elemento novo
  no->dado = dado;
  // verifica se a Playlist está vazia
  if ((*pl) == NULL) {

    // insere elemento único no início da Playlist
    no->prox = no; // próximo elemento na Playlist circular é ele mesmo
    no->ant = no;

    *pl = no; // 'no' passa a ser o primeiro elemento da Playlist
  } else {
    // primeira posição é a correta para inserção do elemento novo
    if (strcmp((*pl)->dado->nome, dado->nome) > 0) {
      Elemento *aux;
      aux = *pl;
      // percorre a Playlist até o último elemento
      while (aux->prox != (*pl)) {
        aux = aux->prox;
      }
      // insere elemento no início da Playlist
      aux->prox =
          no; // 'no' é o próximo elemento na Playlist circular após o último
      no->prox = *pl; // primeiro elemento antigo '*pl' é o próximo após o 'no'
      no->ant = aux;
      *pl = no; // 'no' passa a ser o primeiro elemento
    }
    // senão, percorre a Playlist, a partir do segundo elemento, até achar o
    // local correto e insere
    Elemento *anterior, *atual;
    anterior = *pl;
    atual = anterior->prox;
    // percorre a Playlist até o último elemento ou até encontrar um
    // elemento maior que o novo
    while (atual != (*pl) && (strcmp(atual->dado->nome, dado->nome) < 0)) {
      anterior = atual;
      atual = atual->prox;
    }
    // insere elemento na posição correta da Playlist (meio)
    anterior->prox = no; // 'no' é o próximo elemento na Playlist circular
                         // após o anterior
    no->prox = atual;    // 'atual' é o próximo elemento após o 'no'
    no->ant = anterior;
  }
  return 1;
}

// função para remover elemento do início da Playlist
int remover_playlist_inicio(Playlist *pl) {
  // verifica se a Playlist foi criada corretamente
  if (pl == NULL) {
    return 0;
  }
  // verifica se a Playlist está vazia (não existem elementos a serem
  // removidos)
  if ((*pl) == NULL) {
    return 0;
  }
  // verifica se existe apenas um elemento na Playlist (após remoção a
  // Playlist fica vazia)
  if ((*pl)->prox == (*pl)) {
    // libera elemento único
    free(*pl);
    // indica que a Playlist ficou vazia
    *pl = NULL;
    return 1;
  }
  Elemento *atual, *aux;
  atual = *pl; // 'no' é o elemento a ser removido
  aux = *pl;
  // percorre a Playlist até o último elemento
  while (aux->prox != (*pl)) {
    aux = aux->prox;
  }
  // remove o primeiro elemento da Playlist
  aux->prox = atual->prox; // 'no->prox' é o próximo elemento na Playlist
                           // circular após o último
  *pl = atual->prox;       // primeiro elemento da Playlist '*pl' passa a ser o
                           // 'no->prox'
  // libera Elemento 'no'
  free(atual);
  return 1;
}

// função para remover elemento do final da Playlist
int remover_playlist_final(Playlist *pl) {
  // verifica se a Playlist foi criada corretamente
  if (pl == NULL) {
    return 0;
  }

  // verifica se a Playlist está vazia (não existem elementos a serem
  // removidos)
  if ((*pl) == NULL) {
    return 0;
  }

  // verifica se existe apenas um elemento na Playlist (após remoção a
  // Playlist fica vazia)
  if ((*pl)->prox == (*pl)) {
    // libera elemento único
    free(*pl);
    // indica que a Playlist ficou vazia
    *pl = NULL;

    return 1;
  }

  Elemento *anterior, *atual;
  atual = *pl; // 'no' é o elemento a ser removido

  // percorre a Playlist até 'no' ser o último elemento, armazenando o
  // elemento anterior
  while (atual->prox != (*pl)) {
    anterior = atual;
    atual = atual->prox;
  }

  // remove o último elemento da Playlist
  anterior->prox = atual->prox; // 'no->prox' passa a ser o próximo elemento
  atual->ant = anterior;
  // na Playlist circular após o 'anterior', libera Elemento 'no'
  free(atual);

  return 1;
}

// função para remover elemento do meio da Playlist
int remover_playlist_meio(Playlist *pl, char *nome) {
  // verifica se a Playlist foi criada corretamente
  if (pl == NULL) {
    return 0;
  }
  // verifica se a Playlist está vazia (não existem elementos a serem removidos)
  if ((*pl) == NULL) {
    return 0;
  }
  Elemento *atual;
  Elemento *anterior;
  atual = *pl;
  // elemento a ser removido está no início da Playlist
  if (strcmp(atual->dado->nome, nome) == 0) {
    // verifica se existe apenas um elemento na Playlist (após remoção a
    // Playlist fica vazia)
    if (atual->prox == atual) {
      // indica que a Playlist ficou vazia e remove o 'no'
      *pl = NULL;
      free(atual);

      // libera Elemento 'no'
      return 1;

      // remove o primeiro elemento
    } else {
      anterior = *pl;
      // percorre a Playlist até o último elemento
      while (anterior->prox != (*pl)) {
        anterior = anterior->prox;
      }
      // remove primeiro elemento 'no' (no = *pl)
      anterior->prox = atual->prox;
      *pl = atual->prox;
      // libera Elemento 'no'
      free(atual);
      return 1;
    }
  }
  anterior = atual;
  atual = atual->prox;
  // percorre a Playlist até achar o elemento a ser removido, ou até encontrar o
  // primeiro elemento
  while (atual != (*pl) && strcmp(atual->dado->nome, nome) != 0) {
    anterior = atual;
    atual = atual->prox;
  }
  // elemento a ser removido não foi encontrado
  if (atual == (*pl)) {
    return 0;
  }

  // remove o elemento 'no'
  anterior->prox = atual->prox; // 'no->prox' passa a ser o próximo element na
                                // Playlist circular após o 'anterior'
  // libera Elemento 'no'
  free(atual);

  return 1;
}

// função para buscar o elemento que está na posição 'pos' (primeiro elemento
// está na posição '1')
int buscar_playlist_posicao(Playlist *pl, int pos, Musica *dado) {
  // verifica se a Playlist foi criada corretamente, se está vazia ou se a
  // posição 'pos' é inváplda
  if (pl == NULL || (*pl) == NULL || pos <= 0) {
    return 0;
  }
  Elemento *no = *pl;
  int i = 1;
  // percorre a Playlist até achar posicao desejada, ou até encontrar o último
  // elemento
  while (no->prox != (*pl) && i < pos) {
    no = no->prox;
    i++;
  }

  // verifica se a posicao desejada existe na Playlist
  if (i != pos) {
    return 0;

  } else {
    // copia o dado da posição desejada (parâmetro passado por referência)
    no->dado = dado;
    return 1;
  }
}

// função para buscar o elemento "dado"
int buscar_playlist_nome(Playlist *pl, char *nome, int *pos) {
  // verifica se a Playlist foi criada corretamente ou se está vazia
  if (pl == NULL || (*pl) == NULL) {
    return 0;
  }

  Elemento *no = *pl;
  int i = 1;

  // percorre a Playlist até achar o elemento desejado, ou até encontrar o
  // último elemento
  while (no->prox != (*pl) && strcmp(no->dado->nome, nome) != 0) {
    no = no->prox;
    i++;
  }

  // verifica se dado procurado existe na Playlist
  if (strcmp(no->dado->nome, nome) != 0) {
    return 0;

  } else {
    // copia a posição da Playlist onde o dado foi encontrado (parâmetro passado
    // por referência)
    *pos = i;
    return 1;
  }
}

int imprimir_playlist(Playlist *pl) {
  // verifica se a Playlist foi criada corretamente
  if (pl == NULL) {
    return 0;
  }

  if ((*pl) == NULL) {
    printf(" Playlist vazia!");
  }

  // imprime primeiro elemento
  Elemento *no;
  no = (*pl);

  // percorre Playlist até o último elemento
  while (no->prox != (*pl)) {
    printf("\n%s - %s", no->dado->autor, no->dado->nome);
    no = no->prox;
  }

  // imprime último elemento
  printf("\n%s - %s", no->dado->autor, no->dado->nome);

  return 1;
}

// função que cria e aloca um dado do tipo música
int criar_dado(Musica **dado) {
  *dado = (Musica *)malloc(sizeof(Musica));
  if (*dado == NULL) {
    return 0;
  }
  printf("\nDigite o nome do autor: ");
  scanf(" %[^\n]", (*dado)->autor);

  printf("\nDigite o nome da música: ");
  scanf(" %[^\n]", (*dado)->nome);

  return 1;
}

int imprimir_dado(Musica *dado) {
  // verifica se o dado exite
  if (dado == NULL) {
    return 0;
  }

  // imprime os campos caso exista
  printf("\n -----------------------\n");
  printf("%s - %s", dado->autor, dado->nome);
  printf("\n -----------------------\n");

  return 1;
}
// função para determinar a posição da playlist
int posicao_playlist(Playlist *pl, int *posi, Musica *dado) {
  printf("teste02\n");
  if (pl == NULL || (*pl) == NULL || *posi < -1) {
    return 0;
  }
  // posi = 0 representa a primeira música da playlist
  if (*posi == 0) {
    *posi = 1;
  }
  // posi = -1 representa o último elemento da playlist, logo, recebe o valor do
  // tamanho da playlist
  if (*posi == -1) {
    *posi = tamanho_playlist(pl);
  }
  Elemento *no = *pl;
  int i = 1;

  // percorre a Playlist até achar posicao desejada, ou até encontrar o último
  // elemento
  while (no->prox != (*pl) && i < *posi) {
    no = no->prox;
    i++;
  }
  // verifica se a posicao desejada existe na Playlist
  if (i != *posi) {
    return 0;
  } else {
    // copia o dado da posição desejada (parâmetro passado por referência)
    no->dado = dado;
  }
  return 1;
}
