// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados
// descomplicada em lingugem C (André Backes)"

#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

//**************************************************************************
// DECLARAÇÃO DE ESTRUTURAS
//**************************************************************************

// definição da struct aluno
struct aluno {
	int matricula;
	char nome[10];
	float nota;
};

// definição da struct elemento
struct elemento {
	Aluno *dado; // o dado é um ponteiro para um dado do tipo Aluno
	Lista prox;
};

// renomeando a "struct elemento" para "Elemento"
typedef struct elemento Elemento;

//**************************************************************************
// FUNÇÕES QUE RETORNAM INFORMAÇÕES SOBRE A LISTA
//**************************************************************************

// função para obter o tamanho da lista
int tamanho_lista(Lista *li) {
	// a lista não foi criada corretamente
	if (li == NULL) {
		return -1;
	}

	int cont = 0;
	Elemento *no = *li;

	// acrescenta cont até acabar a lista
	while (no != NULL) {
		cont++;
		no = no->prox;
	}

	return cont;
}

// função para verificar se a lista está vazia
int lista_vazia(Lista *li) {
	// verifica se houve problema na criação da lista
	// ou seja, li não é uma lista válida
	if (li == NULL) {
		return -1;
	}

	// verifica se a lista foi criada corretamente
	// mas não contém nenhum valor
	if (*li == NULL) {
		return 1;
	}

	// se houver elementos, retorna 0
	return 0;
}

// função para verificar se a lista está cheia (não se aplica)
int lista_cheia(Lista *li) {
	return 0;
}

//**************************************************************************
// FUNÇÕES PARA ALOCAÇÃO DE MEMÓRIA DINÂMICA
//**************************************************************************

// função para alocar memória do tipo Aluno
int criar_dado(Aluno **dado) {
	*dado =(Aluno *)malloc(sizeof(Aluno *)); // usa ponteiro para ponteiro pois o valor de dado muda dentro da função

	if (*dado == NULL) {
		return 0;
	}

	printf("\nDigite a matrícula do aluno: ");
	scanf("%d", &(*dado)->matricula);

	printf("Digite o nome do aluno: ");
	scanf("%s", (*dado)->nome);

	printf("Digite a nota do aluno: ");
	scanf("%f", &(*dado)->nota);

	return 1;
}

// função para alocar memória do tipo Elemento
Elemento *criar_elemento() {
	Elemento *no = (Elemento *)malloc(sizeof(Elemento));

	return no;
}

// função para alocar memória do tipo Lista
Lista *criar_lista() {
	Lista *li = (Lista *)malloc(sizeof(Lista));

	// se a lista foi criada corretamente, indica que ela está vazia
	if (li != NULL) {
		*li = NULL;
	}

	return li;
}

//**************************************************************************
// FUNÇÕES PARA DESALOCAÇÃO DE MEMÓRIA DINÂMICA
//**************************************************************************

// função para liberar memória
int liberar_lista(Lista *li) {
	if (li == NULL) {
		return 0;
	}

	// libera todos os nós da lista que foram alocados
	Elemento *no;
	while (*li != NULL) {
		no = *li;
		*li = (*li)->prox;
		free(no);
	}

	// libera o ponteiro da lista
	free(li);

	return 1;
}

//**************************************************************************
// FUNÇÕES DE INSERÇÃO
//**************************************************************************

// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, Aluno *dado) {
	if (li == NULL) {
		return 0;
	}

	// cria um elemento novo
	Elemento *no;
	no = criar_elemento();

	if (no == NULL) {
		return 0;
	}

	// atribui valores ao elemento novo
	no->dado = dado;
	no->prox = (*li);

	// insere elemento no início da lista
	*li = no;

	return 1;
}

// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, Aluno *dado) {
	if (li == NULL) {
		return 0;
	}

	// cria um elemento novo
	Elemento *no;
	no = criar_elemento();

	if (no == NULL) {
		return 0;
	}

	// atribui valores ao elemento novo
	no->dado = dado;
	no->prox = NULL;

	// se a lista estiver vazia, insere no início da lista
	if (*li == NULL) {
		*li = no;

	} else {
		// senão percorre a lista até o fim e insere no final
		Elemento *aux;
		aux = *li;

		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = no;
	}

	return 1;
}

// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, Aluno *dado) {
	if (li == NULL) {
		return 0;
	}

	// cria um elemento novo
	Elemento *no;
	no = criar_elemento();

	if (no == NULL) {
		return 0;
	}

	// atribui valores ao elemento novo
	no->dado = dado;

	// se a lista estiver vazia, insere no início da lista
	if (*li == NULL) {
		no->prox = NULL;
		*li = no;

	} else {
		// senão percorre a lista até achar o local correto e insere
		Elemento *anterior, *atual;
		atual = *li;

		while (atual != NULL && atual->dado < dado) {
			anterior = atual;
			atual = atual->prox;
		}

		// insere na primeira posição
		if (atual == *li) {
			no->prox = *li;
			*li = no;

		} else {
			no->prox = atual;
			anterior->prox = no;
		}
	}

	return 1;
}

//**************************************************************************
// FUNÇÕES DE REMOÇÃO
//**************************************************************************

// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li) {
	if (li == NULL) {
		return 0;
	}

	// lista vazia, não remove nada
	if ((*li) == NULL) {
		return 0;
	}

	// muda inicio para o proximo elemento
	Elemento *atual;
	atual = *li;
	*li = atual->prox;

	// libera Elemento atual
	free(atual);

	return 1;
}

// função para remover elemento do final da lista
int remover_lista_final(Lista *li) {
	if (li == NULL) {
		return 0;
	}

	// lista vazia, não remove nada
	if ((*li) == NULL) {
		return 0;
	}

	// percorre lista até o final
	Elemento *anterior, *atual;
	atual = *li;

	while (atual->prox != NULL) {
		anterior = atual;
		atual = atual->prox;
	}

	// remove o primeiro elemento, se este for o único da lista
	if (atual == (*li)) {
		*li = atual->prox; // igual *li = NULL

	} else {
		anterior->prox = atual->prox; // igual anterior->prox = NULL
	}

	// libera Elemento atual
	free(atual);

	return 1;
}

// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int dado) {
	if (li == NULL) {
		return 0;
	}

	// lista vazia, não remove nada
	if ((*li) == NULL) {
		return 0;
	}

	// percorre a lista até achar o elemento e remove
	Elemento *anterior, *atual;
	atual = *li;

	while (atual != NULL && atual->dado->matricula != dado) {
		anterior = atual;
		atual = atual->prox;
	}

	// elemento não foi encontrado
	if (atual == NULL) {
		return 0;
	}

	// remove o primeiro elemento
	if (atual == (*li)) {
		*li = atual->prox;

	} else {
		anterior->prox = atual->prox;
	}

	// libera Elemento atual
	free(atual);
	return 1;
}

//**************************************************************************
// FUNÇÕES DE BUSCA
//**************************************************************************

// função para buscar um aluno pela posição no vetor
int buscar_lista_posicao(Lista *li, int pos, Aluno **dado) {
	// verifica se a lista foi criada corretamente, se não está vazia e se a
	// posição é válida (note que é a posição na lista não é o índice do vetor)
	if (li == NULL || (*li) == NULL || pos <= 0) {
		return 0;
	}

	Elemento *aux;
	int i;

	aux = *li; // o ponteiro aux aponta para o primeiro elemento
	i = 1;	 // inicializa contador de posições

	while (aux != NULL && i < pos) {
		aux = aux->prox;
		i++;
	}

	// posição não existe na lista
	if (aux == NULL) {
		return 0;
	}

	// copia o dado da posição desejada (parâmetro passado por referência)
	*dado = aux->dado;

	return 1;
}

// função para buscar um aluno pelo número de matrícula
int buscar_lista_dado(Lista *li, int matricula, int *pos) {
	// verifica se a lista foi criada corretamente
	if (li == NULL || (*li) == NULL) {
		return 0;
	}

	Elemento *aux;
	int i;

	aux = *li; // o ponteiro aux aponta para o primeiro elemento
	i = 1;	 // inicializa contador de posições

	// procura a posição no vetor que contém um aluno com o número de matrícula
	// desejado
	while (aux != NULL && aux->dado->matricula != matricula) {
		aux = aux->prox;
		i++;
	}

	// verifica se elemento não foi encontrado
	if (aux == NULL) {
		return 0;
	}

	// copia a posição da lista onde a matrícula foi encontrada (parâmetro pos
	// passado por referência)
	*pos = i;

	return 1;
}

//**************************************************************************
// FUNÇÕES DE IMPRESSÃO DE DADOS
//**************************************************************************

// função para imprimir a lista dinâmica
int imprimir_lista(Lista *li) {
	// verifica se a lista exite e se não é vazia
	if (li == NULL || (*li) == NULL) {
		return 0;
	}

	Elemento *aux;
	aux = (*li); // o ponteiro aux aponta para o primeiro elemento

	// percorre todos os elementos da lista
	while (aux != NULL) {
		imprime_dado(aux->dado); // imprime todos os campos da estrutura
								 // aux->dado do tipo Aluno
		aux = aux->prox;
	}

	return 1;
}

// função para imprimir os campos do tipo Aluno
int imprime_dado(Aluno *dado) {
	// verifica se o dado exite
	if (dado == NULL) {
		return 0;
	}

	// se existe imprime os campos
	printf("\n -----------------------\n");
	printf(" Matrícula: %d\n", dado->matricula);
	printf(" Nome: %s\n", dado->nome);
	printf(" Nota: %.2f\n", dado->nota);
	printf(" -----------------------\n");

	return 1;
}
// função responsável por inverter os elementos da lista
Lista *inverter_lista(Lista *li) {
	Lista li2 = NULL;
	Lista aux;

	if (li == NULL || (*li) == NULL)
		return 0;
	// é necessário de um auxiliar (aux) para armazenar os valores enquanto não
	// há a troca/inversão entre li e li2
	while (*li != NULL) {
		aux = *li;
		*li = (*li)->prox;
		aux->prox = li2;
		li2 = aux;
	}
	*li = li2;
	return li;
}
// função que remove elementos com a mesma matrícula
Lista remover_repetidos(Lista *li) {
	Lista anterior, atual, prox;
	Lista l2 = NULL;
	l2 = *li;

	for (atual = l2; atual != NULL; atual = atual->prox) {
		anterior = NULL;
		for (prox = atual->prox; prox != NULL;) { // percorre a lista
			if (atual->dado->matricula ==
				prox->dado->matricula) { // verifica se há elementos repetidos
				if (anterior == NULL)
					atual->prox = prox->prox;
				else
					anterior->prox = prox->prox;
				Lista remover = prox;
				prox = prox->prox;
				free(remover); // em caso de repetição, é necessário um free no
							   // elemento repetido
			} else {
				anterior = prox;
				prox = prox->prox;
			}
		}
	}
	return l2; // retorna a lista 2 sem os elementos repetidos
}
// retorna a lista concatenada
Lista *concatena(Lista *li1, Lista *li2) {
	// análise se as funções não estão vazias ou com erro
	if (li1 == NULL)
		return li2;
	if (li2 == NULL)
		return li1;

	Lista *li3;
	while (li1 != NULL) {
		li3 = li1;
		li1 = &(*li1)->prox;
	}
	(*li3)->prox = *li2;
	// concatena as duas listas e armazena em li3, retornando-o
	return li3;
}
// Retorna se a lista está em ordem crescente
int ordenada(Lista li) {
	if (li != NULL) {
		// enquanto houver o próximo elemento, verifica se o dado anterior é
		// maior que o posterior, se sim, a função retorna 0 denotando que não
		// está ordenada
		while ((*li).prox != NULL) {
			if (li->dado->matricula > li->prox->dado->matricula)
				return 0;
			li = li->prox;
		}
	}
	// caso o algoritmo funcione corretamente, logo a lista está ordenada e
	// retorna 1
	return 1;
}