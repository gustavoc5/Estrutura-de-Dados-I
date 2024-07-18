
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"
#define MAX 100

// definição do tipo produto
struct produto {
  int codigo;
  char nome[30];
  float preco;
  int qtd;
};

// definição do tipo lista
struct lista {
  int qtd;
  Produto dados[MAX];
};

// função para alocar memória do tipo Lista
Lista *criar_lista() {
  // 'li' é um ponteiro do tipo Lista
  Lista *li = (Lista *)malloc(sizeof(Lista));

  // se a alocação estiver correta qtd da lista é zero
  if (li != NULL) {
    li->qtd = 0;
  }

  return li;
}
// função para alocar memória do tipo Produto
Produto *criar_produto() {
  // 'p' é um ponteiro do tipo Produto
  Produto *p = (Produto *)malloc(sizeof(Produto));

  printf("Digite um codigo: ");
  scanf("%d", &p->codigo);
  printf("Digite o nome do produto: ");
  scanf(" %[^\n]", p->nome);
  printf("Digite o preço do produto: ");
  scanf("%f", &p->preco);
  printf("Digite a quantidade de produtos: ");
  scanf("%d", &p->qtd);

  return p;
}

// função para inserir o produto no início da lista
int inserir_lista_inicio(Produto *p, Lista *li) {

  // movimenta todos os elementos da lista uma posição para frente
  for (int i = li->qtd - 1; i >= 0; i--) {
    li->dados[i + 1] = li->dados[i];
  }

  // insere o Produto na primeira posição do vetor
  li->dados[0] = *p;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}

// função para retornar o menor produto
Produto *menor_preco(Lista *li) {
  int i;
  Produto *menor = &li->dados[li->qtd - 1];
  // comparando todos os produtos, e se for menor armazenar no Produto menor
  for (i = li->qtd - 1; i >= 0; i--) {
    if (li->dados[i].preco < menor->preco) {
      menor->preco = li->dados[i].preco;
      menor->codigo = li->dados[i].codigo;
      strcpy(menor->nome, li->dados[i].nome);
      menor->qtd = li->dados[i].qtd;
    }
  }
  return menor;
}

// função para remover elementos da lista
int remover_lista(Lista *li) {
  int i, n;
  // descobrindo quantos elementos serão removidos
  printf("Quantos elementos você quer remover? ");
  scanf("%d", &n);
  // verificando se a quantidade de elementos para ser removidos é menor ou
  // igual a quantidade de produtos da lista
  if (n <= li->qtd) {
    // decrementando a quantidade de quantidade de elementos da lsita
    for (i = 0; i < n; i++)
      li->qtd--;

    return 1;
  } else {
    return -1;
  }
}

// função para imprimir a lista
int imprimir_lista(Lista *li, int i) {
  // verifica se a lista foi criada corretamente
  if (li == NULL) {
    return 0;
  }
  if (i < li->qtd) {
    imprimir_produto(&li->dados[i]);
    i++;
    return imprimir_lista(li, i);
  } else {
    return 1;
  }
}

// função para imprimir o produto
void imprimir_produto(Produto *p) {
  // imprimindo todos os campos do Produto
  printf("\n%d\n%s\n%.3f\n%d\n", p->codigo, p->nome, p->preco, p->qtd);
}

// função para trocar dois elementos da lista
int troca_elemento(Lista *li, int i, int j) {
  // alocando um Produto para ser utilizado como auxiliar
  Produto *v = (Produto *)malloc(sizeof(Produto));
  // verificando se algumas das posições é maior que o número de quantidade de
  // elementos
  if ((i || j) > li->qtd)
    return -1;
  // verificando se os dois numeros de posição são iguais
  if (i == j)
    return 1;
  // verificando se a lista existe
  if (li != NULL) {

    // troca dos produtos usando o Produto auxiliar, primeiramente copiando o
    // dados[i-1], para v, depois o dados[j-1] para o dados[i-1], e por último
    // copaindo o de v para dados[j-1]
    v->codigo = li->dados[i - 1].codigo;
    li->dados[i - 1].codigo = li->dados[j - 1].codigo;
    li->dados[j - 1].codigo = v->codigo;
    strcpy(v->nome, li->dados[i - 1].nome);
    strcpy(li->dados[i - 1].nome, li->dados[j - 1].nome);
    strcpy(li->dados[j - 1].nome, v->nome);
    v->preco = li->dados[i - 1].preco;
    li->dados[i - 1].preco = li->dados[j - 1].preco;
    li->dados[j - 1].preco = v->preco;
    v->qtd = li->dados[i - 1].qtd;
    li->dados[i - 1].qtd = li->dados[j - 1].qtd;
    li->dados[j - 1].qtd = v->qtd;
    return 1;
  } else
    return -1;
}

// função para liberar a lista
int liberar_lista(Lista *li) {
  // verifica se a lista foi alocada corretamente
  if (li == NULL) {
    return 0;
  }

  // libera o ponteiro (Lista)
  free(li);

  return 1;
}