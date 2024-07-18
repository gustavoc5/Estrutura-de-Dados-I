// Gustavo Rafael Paulino 2022006185
// Vítor Ortiz Gomes 2022006256

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "listaEncadeada.h"

// funcao principal
int main(void) {
	// no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
	// o ponteiro inicio conterá o endereço do primeiro elemento da lista
	Lista *li = NULL, *li2, li3, *conc1, *conc2, *conc3;
	int opcao, ok, pos, mat, tam;
	Aluno *dado;

	// menu de opções para execuções de operações sobre a lista
	do {
		printf("\n\nMenu de opções");
		printf("\n1 - Criar lista");
		printf("\n2 - Liberar lista");
		printf("\n3 - Inserir elemento no início");
		printf("\n4 - Inserir elemento no final");
		printf("\n5 - Inserir elemento (ordenado)");
		printf("\n6 - Remover elemento do início");
		printf("\n7 - Remover elemento do final");
		printf("\n8 - Remover elemento (qualquer)");
		printf("\n9 - Buscar elemento pela posição");
		printf("\n10 - Buscar elemento pelo dado");
		printf("\n11 - Imprimir lista");
		printf("\n12 - Concatenar duas listas");
		printf("\n13 - Remover valores repetidos");
		printf("\n14 - Inverter a lista");
		printf("\n15 - Ver se está ordenada");
		printf("\n16 - Tamanho da lista");
		printf("\n17 - Sair");
		printf("\nOpção: ");
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

			// inserir elemento no início
			ok = criar_dado(&dado);
			ok = inserir_lista_inicio(li, dado);

			if (ok == 1) {
				printf("\n Inserção realizada com sucesso!");
			} else {
				printf("\n Falha na inserção!");
			}

			break;

		case 4:

			// inserir elemento no final
			ok = criar_dado(&dado);
			ok = inserir_lista_final(li, dado);

			if (ok == 1) {
				printf("\n Inserção realizada com sucesso!");
			} else {
				printf("\n Falha na inserção!");
			}

			break;

		case 5:

			// inserir elemento de forma ordenada
			ok = criar_dado(&dado);
			ok = inserir_lista_ordenada(li, dado);

			if (ok == 1) {
				printf("\n Inserção realizada com sucesso!");
			} else {
				printf("\n Falha na inserção!");
			}

			break;

		case 6:

			// remover elemento do início
			ok = remover_lista_inicio(li);

			if (ok == 1) {
				printf("\n Remoção realizada com sucesso!");
			} else {
				printf("\n Falha na remoção!");
			}
			break;

		case 7:

			// remover elemento do final
			ok = remover_lista_final(li);

			if (ok == 1) {
				printf("\n Remoção realizada com sucesso!");
			} else {
				printf("\n Falha na remoção!");
			}
			break;

		case 8:

			// remover elemento do meio
			printf("\n Matrícula a ser removido: ");
			scanf("%d", &mat);

			ok = remover_lista_meio(li, mat);

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

			ok = buscar_lista_posicao(li, pos, &dado);

			if (ok) {
				printf("\n Busca realizada com sucesso!");
				printf("\n Elemento da %dª posição: ", pos);
				imprime_dado(dado);
			} else {
				printf("\n Posição não existe!");
			}

			break;

		case 10:

			// busca elemento pelo dado
			printf("\n Matrícula do aluno a ser buscado: ");
			scanf("%d", &mat);

			ok = buscar_lista_dado(li, mat, &pos);

			if (ok) {
				printf("\n Busca realizada com sucesso!");
				printf("\n Elemento da %dª posição: ", pos);
				imprime_dado(dado);
			} else {
				printf("\n Elemento não encontrado!");
			}

			break;

		case 11:

			// imprime a lista
			printf("\n Lista encadeada: \n");
			ok = imprimir_lista(li);

			if (!ok) {
				printf("\n Lista não encontrada!");
			}

			break;

		case 12:

			// concatena duas listas
			*conc1 = NULL;
			*conc2 = NULL;
			conc3 = concatena(conc1, conc2);
			imprimir_lista(conc3);

			break;

		case 13:

			// remover valores repetidos
			if (li == NULL) {
				printf("Lista não encontrada ou vazia");
				return 0;
			}
			li3 = remover_repetidos(li);
			imprimir_lista(&li3);

			break;

		case 14:

			// inverter a lista
			if (li == NULL) {
				printf("Lista não encontrada ou vazia");
				return 0;
			}
			li2 = inverter_lista(li);
			imprimir_lista(li2);

			break;

		case 15:

			// verifica se a lista está ordenada
			if (li == NULL) {
				printf("Lista não encontrada ou vazia");
				return 0;
			}
			ok = ordenada(*li);
			if (ok)
				printf("Lista ordenada");
			else
				printf("Lista não ordenada");
			break;

		case 16:

			// ver o tamanho da lista
			if (li == NULL) {
				printf("Lista não encontrada ou vazia");
				return 0;
			}
			tam = tamanho_lista(li);
			printf("Tamanho da lista: %d\n", tam);

			break;

		case 17:

			// libera memória e finaliza programa
			liberar_lista(li);
			printf("\nFinalizando...");
			break;

		default:
			printf("\nOpção inválida!");
			break;
		}

	} while (opcao != 17);

	return 0;
}
