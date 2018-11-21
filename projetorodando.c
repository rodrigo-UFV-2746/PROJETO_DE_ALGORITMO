//MATERIA: PROJETO DE ALGORITMO
//UNIVERSIDADE FEDERAL DE VIÇOSA CAMPUS DE RIO PARANAÍBA 
//ALUNOS : Rodrigo de Oliveira Costa , Kleiber de Carvalho Ferreira,luiz Henrique França
//PROJETO2
#include <dir.h>
#include <time.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "algoritmos.h"

int main(){
	int op, tamanho,k_grupos;
	char nome[100];
	Arestas *arestas;
	
	
	
	arestas = (Arestas*) malloc(TAM* sizeof(Arestas));
		if (arestas == NULL){
			printf("Erro.\n");
			system("PAUSE");
			exit(1);
		}
		else{
			printf("Sucesso.\n");
		}	
	
	//escolhe o algoritmo utilizado
	escolhaAlgoritmo(&op);	
    verticeTree(vetorRotulos);
	//imprime os vetores para ver se ta tudo certinho
	preencheVetores(arestas);
	//imprimevetores(arestas);
	strcpy (nome,"entrada");
	salvarvetores(arestas,nome);
	
	

	switch(op) {
			case 1:
				printf("\n Algoritmo Prim ......:\n");
				salvarvetores(arestas,nome);
			break;
			case 2:
				
				printf("\n Algoritmo Kruskal ......:\n");
				insertionSort(arestas);
				strcpy (nome,"ordenados");
				do{
					printf("digite quantidade de grupos\n");
					scanf("%d",&k_grupos);
				}while(!(k_grupos >= 0 && k_grupos <= QUAT_VERT));
			    salvarvetores(arestas,nome);
			    kruskal(arestas,vetorRotulos,k_grupos);
				
			break;
			default:
				printf("\nInvalido");
		}

	return 0;
}

