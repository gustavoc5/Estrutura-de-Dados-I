// Gustavo Rafael Paulino - 2022006185
// Vitor Ortiz Gomes  - 2022006256

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bibliotecas do projeto
#include "pilhaEncadeada.h"

// funcao principal
int main(void) {
	Pilha *p1 = NULL;
	Pilha *p2 = NULL;
	Pilha *p3 = NULL;
	Pilha *p4 = NULL;
	int o, d, opcao;
	char dado, aux;

	// menu de opções para execuções de operações sobre a pilha
	do {
		printf("\n\nMenu de opções");
		printf("\n1 - Começar jogo");
		printf("\n2 - Continuar jogando");
		printf("\n3 - Desistir e sair");
		printf("\nOpção: "); 
		scanf("%d", &opcao);

		switch (opcao) {
		case 1: // inicio case 1 usado para criar os tubos e inicializar o primeiro tubo,deixando pronto para o jogo começar
			p1 = criar_pilha();
			p2 = criar_pilha();
			p3 = criar_pilha();
			p4 = criar_pilha();

			dado = 'u';
			empilhar(p1, dado);
			dado = 'o';
			empilhar(p1, dado);
			dado = 'i';
			empilhar(p1, dado);
			dado = 'e';
			empilhar(p1, dado);
			dado = 'a';
			empilhar(p1, dado);

			*p4 = *p1;
			imprimir_pilha(p1, p2, p3);
			break;

		case 2: //  início case 2 para mover os dados de um tubo para outro  
			printf("Digite a coluna de origem e de destino: ");
			scanf("%d%d", &o, &d);
			mover_dado(d, o, p1, p2, p3);
			if (o == d) {
				printf("Não é possível fazer esta operação");
				break;
			}
      //-------origem 1---------
			switch (o) {
			case 1:
				if (*p1 == NULL) {
					printf("Tubo vazio");
					break;
				}

				switch (d) {
				case 2://-------inicio 1 para 2---------
					if (tamanho_pilha(p2) == 5) {
						printf("Tubo cheio");
						break;
					}
					dado = consultar_topo_pilha(p1, &dado);
					if (*p2 == NULL) {
						desempilhar(p1);
						empilhar(p2, dado);
					} else {
						aux = consultar_topo_pilha(p2, &aux);
						if (strcmp(&dado, &aux) > 0) {
							printf("Ordem não alfabética.\n");
						} else {
							desempilhar(p1);
							empilhar(p2, dado);
						}
					}
					imprimir_pilha(p1, p2, p3);
					break;
          //-------fim 1 para 2---------
				case 3://-------inicio 1 para 3---------
					if (tamanho_pilha(p3) == 5) {
						printf("Tubo cheio");
						break;
					}
					dado = consultar_topo_pilha(p1, &dado);
					if (*p3 == NULL) {
						desempilhar(p1);
						empilhar(p3, dado);
					} else {
						aux = consultar_topo_pilha(p3, &aux);
						if (strcmp(&dado, &aux) > 0) {
							printf("Ordem não alfabética.\n");
						} else {
							desempilhar(p1);
							empilhar(p3, dado);
						}
					}
					imprimir_pilha(p1, p2, p3);
					break; //-------fim 1 para 3---------
				}
				break; //-------fim origem 1---------
			case 2:
				if (*p2 == NULL) {
					printf("Tubo vazio");
					break;
				}
        //-------origem  2 ---------
				switch (d) {
				case 1://-------inicio 2 para 1---------
					if (tamanho_pilha(p1) == 5) {
						printf("Tubo cheio");
						break;
					}
					dado = consultar_topo_pilha(p2, &dado);
					if (*p1 == NULL) {
						desempilhar(p2);
						empilhar(p1, dado);
					} else {
						aux = consultar_topo_pilha(p1, &aux);
						if (strcmp(&dado, &aux) > 0) {
							printf("Ordem não alfabética.\n");

						} else {
							desempilhar(p2);
							empilhar(p1, dado);
						}
					}
					imprimir_pilha(p1, p2, p3);
					break;
          //-------fim 2 para 1---------
          case 3://-------inicio 2 para 3---------
					if (tamanho_pilha(p3) == 5) {
						printf("Tubo cheio");
						break;
					}
					dado = consultar_topo_pilha(p2, &dado);
					if (*p3 == NULL) {
						desempilhar(p2);
						empilhar(p3, dado);
					} else {
						aux = consultar_topo_pilha(p3, &aux);
						if (strcmp(&dado, &aux) > 0) {
							printf("Ordem não alfabética.\n");

						} else {
							desempilhar(p2);
							empilhar(p3, dado);
						}
					}
					imprimir_pilha(p1, p2, p3);
					break; //-------fim 2 para 3---------
				}
				break;//-------fim origem 2---------
				
				//-------origem 3---------
			case 3:
				if (*p3 == NULL) {
					printf("Tubo vazio");
					break;
				}

				switch (d) {
					//-------inicio 3 para 1---------
				case 1:
					if (tamanho_pilha(p1) == 5) {
						printf("Tubo cheio");
						break;
					}
					dado = consultar_topo_pilha(p3, &dado);
					if (*p1 == NULL) {
						desempilhar(p3);
						empilhar(p1, dado);
					} else {
						aux = consultar_topo_pilha(p1, &aux);
						if (strcmp(&dado, &aux) > 0) {
							printf("Ordem não alfabética.\n");

						} else {
							desempilhar(p3);
							empilhar(p1, dado);
						}
					}
					imprimir_pilha(p1, p2, p3);
					break;
			  //-------fim 3 para 1---------
				//-------inicio 3 para 2---------
				case 2:
					if (tamanho_pilha(p2) == 5) {
						printf("Tubo cheio");
						break;
					}
					dado = consultar_topo_pilha(p3, &dado);
					if (*p2 == NULL) {
						desempilhar(p3);
						empilhar(p2, dado);
					} else {
						aux = consultar_topo_pilha(p2, &aux);
						if (strcmp(&dado, &aux) > 0) {
							printf("Ordem não alfabética.\n");

						} else {
							desempilhar(p3);
							empilhar(p2, dado);
						}
					}
					imprimir_pilha(p1, p2, p3);
					break;
				}
				// //-------fim 3 para 2---------
				break;
				//-------fim origem 3---------
			}
			// fim case 2 geral
			break;
			// início case 3 geral para liberar as pilhas e sair
		case 3:
			liberar_pilha(p1);
			liberar_pilha(p2);
			liberar_pilha(p3);
			liberar_pilha(p4);
			return 0;
			break;
			// fim case 3 e encerramento do programa
		}
	} while (p3 != p4);
	printf("Parabéns, você venceu o jogo!"); // mensagem quando o jogo for concluído
	return 0;
}
