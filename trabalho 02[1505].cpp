#include <stdio.h>
#include <stdlib.h>
#define COL 8
#define LIN 7


void mostrarPoltronas(int mateatro [LIN][COL]){
	int i, j, mostrar = 10;
	for (i = 0; i < LIN; i++, mostrar = mostrar + 2){
		for (j = 0; j < COL; j++, mostrar++){
			if (mateatro[i][j] != 1)
				mateatro[i][j] = mostrar+1;
			}
		
		}
	}

	
void consultarPoltronas (int consulta[58][58],int ficha){
	int i, j, cont = 0;
	int mostrar = 1;
	for (i = 0; i < 58; i++){
		if (consulta[i][0]==ficha && cont == 0){
			printf ("\n-> Numero de cadeiras alocadas %d", consulta[i][1]);
			cont++;
			for (j = 2, cont = 0; j < 58; j++){
				if (consulta[i][j] != 0){
					if (cont > 7){
						cont = 0;
						mostrar++;
					}
					cont++;
					printf("\n-> Numeracao das cadeiras  %d", consulta[i][j]);	
					printf("\tLinha: %d Coluna: %d", mostrar, cont);
					}
				}
			}
		}
	}


int funcefetuar (int *ptr, int poltronas, int *pont, int consulta[58][58], int ficha){
	int i, j, cont = 0, cont2, cont3 = 0;
	int *in, *fim, *aux, *aux2;
	aux = pont;

	int *aux4;
	aux4 = pont;
	int mostrar = 10;
	
	for (i = 0, cont2 = 0; i < 56 && cont2 != poltronas; i++){
		
		if (*aux != 1){
			cont2++;
			if (cont2 == 1){
				aux2 = aux;
			}
		}
		aux++;
		cont3++;
		if (cont2 == poltronas){
			break;
		}
		if (cont3 >= 8){
			cont3 = 0;
			cont2 = 0;
		}
	}
	
	if (cont2 == poltronas){
		for (j = 2; cont2 > 0; cont2--, j++){
			consulta[ficha][j] = *aux2;
			*aux2 = 1;
			aux2++;
		}
		aux++;
	}
	else {
		for (j = 2 ;poltronas > 0; pont++, j++){
			if (*pont != 1){
				consulta[ficha][j] = *pont;
				*pont = 1;
				poltronas--;
			}
		}
	}
	return *ptr;
}

void deletarPoltronas(int ficha, int quantia, int consulta[58][58], int mateatro[LIN][COL]){
	int i, j, k, cont=2, aux, cont2=0, quantia2=quantia;
	int vet[56] = {0};
	
	for (i = 0; i < 58; i++){
	if (consulta[i][0]==ficha){
		for (k = 0, j = 2; j < 58; j++, k++){
			if (consulta[i][j] != 0){
				vet[k] = consulta[i][j];
				aux = j;
				cont++;
				}
			}
		}
	}
	for (i = 6; quantia > 0 && i >= 0; i--){
		cont2++;
		j=9;
		for (j = 7; j >= 0 && quantia > 0; j--){
			aux = (i * 10 + 10) + j;
			for (k = 56; k >= 0; k--){
				if (vet[k] != 0){
					if (vet[k] == aux){
						mateatro[i][j] = aux;
						consulta[ficha][k+2] = 0;
						consulta[ficha][1]--;
						quantia--;
					}
				}
			}
		}
	}
}

	

main (){
	int mateatro[LIN][COL] = {0};
	int consulta[58][58] = {0};
	int i, j, esc, ficha, cont=56, quantia=0;
	int poltronas=0, *pont;
	int livres = 56;
	
	FILE *ptr;
	char nomeArq[20];
	
	pont = &mateatro[0][0];
	
	
	
	INICIO:

		mostrarPoltronas(mateatro);
		for (i = 0; i < LIN; i++){
			printf ("\n\n");
			for (j = 0; j < COL; j++){
				printf ("\t    P%d", mateatro[i][j]);
			}
		}
	printf ("\n\t********************************************************************\n");
	printf ("\t|            Faca a escolha das opcoes de 0 a 5                    |\n");
	printf ("\t********************************************************************\n");
	printf ("\t|0 - fechar programa                                               |\n");
	printf ("\t|1 - Efetuar reserva                                               |\n");
	printf ("\t|2 - Cancelar reserva                                              |\n");
	printf ("\t|3 - Consultar reserva                                             |\n");
	printf ("\t|4 - Salvar reserva                                                |\n");
	printf ("\t|5 - Abrir reserva                                                 |\n");
	printf ("\t|------------------------------------------------------------------|\n");
	scanf ("%d", &esc);
	
	if (esc > 5){
		printf ("Opção inexistente");
		goto INICIO;
		system ("pause");
		system ("cls");
	}

	
	switch (esc){
		case 0:
			break;
		case 1:
				for (i = 0; i < 56; i++){
					if (consulta[i][1] == 0){
						consulta[i][0] = i;
						ficha = i;
						printf ("-> Ficha de armazenamento: %d", consulta[i][0]);
						break;
					}
					
				}
				livres = 56;
				for (j = 0; j < 58; j++){
					if (consulta[j][1] != 0){
				 		livres = livres - consulta [j][1];
					}
				}
				printf ("\n-> Poltronas disponiveis %d", livres);
				printf ("\n-> Numero de poltronas a ser reservada: ");
				scanf ("%d", &poltronas);
				if (poltronas <= livres && livres > 0){
					*pont = funcefetuar(*mateatro, poltronas, pont, consulta, ficha);
					consulta[i][1] = poltronas;
					system ("cls");
					}
				else {
					printf ("Numero de cadeiras nao disponivel\n");
					system ("pause");
					system ("cls");
					}
				goto INICIO;
				
		case 2:
			
				printf ("Ficha: ");
				scanf ("%d", &ficha);
				printf ("-> Quantia de Poltronas a retirar reservas: ");
				scanf ("%d", &quantia);
				deletarPoltronas(ficha, quantia, consulta, mateatro);
				printf ("\n\n");
				system ("cls");
				goto INICIO;
				
		case 3:
			
			printf ("-> Digite o numero de sua ficha: ");
			scanf ("%d", &ficha);
			consultarPoltronas (consulta, ficha);
			printf ("\n\n");
			system ("pause");
			system ("cls");
			goto INICIO;
			
		case 4:
			
			int k;
			for (k = 0; k < 1; ){
			
				SALVAR:
				
				printf ("-> Nome do arquivo para salvar, colocar .txt no final ex: (teste.txt): ");
				fflush(stdin);
				for (i = 0; i < 1;){
					gets(nomeArq);
					if ((ptr=fopen(nomeArq,"r")) == NULL){
						ptr=fopen(nomeArq, "w");
						i++;
						k++;
						}
					else {
						printf ("Arquivo com mesmo nome encontrado\n");
						printf ("-> Reescrever reservas salvas 1 salvar com nome diferente 0: ");
						scanf ("%d", &j);
							if (j == 1){
								ptr=fopen(nomeArq, "w");
								i++;
								k++;
									}
							else {
								goto SALVAR;
								}
						}
					}
				}
			for (i = 0; i < 58; i++){
					for (j = 0; j < 58; j++){
					fprintf(ptr, "%d ", consulta[i][j]);
					}
				fprintf (ptr, "\n");
				}
			
			for (i = 0; i < LIN; i++){
					for (j = 0; j < COL; j++){
						fprintf(ptr, "%d ", mateatro[i][j]);
					}
				fprintf (ptr, "\n");
			}
			
			fclose(ptr);
			printf ("\n\n");
			system ("cls");
			fclose (ptr);
			goto INICIO;
		case 5:
			printf ("-> Abrir arquivo existente 1 abrir novo 0: ");
			scanf ("%d", &i);
			
			if (i == 1){
				
			PROCURAR:
				
			printf ("\n-> Nome do arquivo para abrir, colocar .txt no final ex: (teste.txt): ");  // salvar
			fflush(stdin);
			for (i = 0; i < 1;){
				gets(nomeArq);
				if ((ptr=fopen(nomeArq,"r")) != NULL){
					printf ("\nArquivo Encontrado\n");
					i++;
					
					for (i = 0; i < 58; i++){
						for (j = 0; j < 58; j++){

							fscanf(ptr, "%d ", &consulta[i][j]);
							}
						}
			
					for (i = 0; i < LIN; i++){
						for (j = 0; j < COL; j++){
							fscanf(ptr, "%d ", &mateatro[i][j]);
							}
						}
					fclose(ptr);
					}
				else {
					for (j = 0; j < 1; ){
						printf ("-> Voltar menu 1, tentar novamente 0: ");
						fflush(stdin);
						scanf ("%d", &j);
						if (j == 1){
							system ("cls");
							goto INICIO;
							}
						else {
							goto PROCURAR;
							}
						}
					}
				}
			}
			else {															// Novo arquivo
				int mostrar = 10;
				for (j = 0; j < 1; ){
					printf ("\n-> Nome para o novo arquivo ex: (teste.txt): ");
					fflush(stdin);
					for (i = 0; i < 1;){
						gets(nomeArq);
						if ((ptr=fopen(nomeArq,"r")) == NULL){
							ptr=fopen(nomeArq, "w");
							j++;
							i++;
							}
						else {
							printf ("Ja existe reservas com esse nome, Mude o nome do arquivo\n");
							printf ("\n-> Nome para o novo arquivo ex: (teste.txt): ");
							}
						}
					}
				for (i = 0; i < 58; i++){
					for (j = 0; j < 58; j++){
						fprintf(ptr, "%d ", consulta[i][j] = 0);
						}
					fprintf (ptr, "\n");
					}	
			
				for (i = 0; i < LIN; i++, mostrar = mostrar + 2){
					for (j = 0; j < COL; j++, mostrar++){
						fprintf(ptr, "%d ", mateatro[i][j] = mostrar);
						}
					fprintf (ptr, "\n");
					}	
			
			fclose(ptr);
			printf ("\n\n");
			system ("pause");
			system ("cls");
			fclose (ptr);
			goto INICIO;
				
			}
			
		system ("pause");
		system ("cls");
		fclose (ptr);
		goto INICIO;
	}
}
