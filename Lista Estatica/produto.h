#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto Produto;

typedef struct lista Lista;

// função para criar produto
Produto *criar_produto();
// função para criar lista
Lista *criar_lista();
// funções para inserir e remover da lista
int inserir_lista_inicio(Produto *p, Lista *li);
int remover_lista(Lista *li);
// função para retornar o Produto de menor preço
Produto *menor_preco(Lista *li);
// funções para imprimir a lista e o produto
int imprimir_lista(Lista *li, int i);
void imprimir_produto(Produto *p);
// funções para trocar elementos da lista
int troca_elemento(Lista *li, int i, int j);
// função para liberar a lista
int liberar_lista(Lista *li);

#endif