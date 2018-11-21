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
#define TAM 22500
#define QUAT_VERT 150

int vetorRotulos[QUAT_VERT];

typedef struct sArestas{
	int vertice1;
	int vertice2;
	double distancia;
}Arestas;

verticeTree(int *vetorRotulos){
	int i;
	for(i=1;i<=QUAT_VERT;i++){
		vetorRotulos[i]=i;
	}
}
void preencheVetores(Arestas *arestas){
	int  vertice1,vertice2,i;
	double distancia;
	char urlEntrada[60];

	strcpy (urlEntrada,"dados.txt");	
	
	FILE * file;
	file = fopen(urlEntrada, "rt");
	
			while (file == NULL){
			printf("Erro.\n");// se caso der errado, pelo menos libera a memoria alocada
			system("PAUSE");
			exit(1);
		}
				
		for(i=0;i<=TAM;i++){
		
			fscanf(file,"%d %d %lf\n", &vertice1,&vertice2,&distancia);
			arestas[i].vertice1=vertice1;
			arestas[i].vertice2=vertice2;
			arestas[i].distancia=distancia;
		}
		
		fclose(file);
}
void escolhaAlgoritmo(int *op)
{
	do{
		printf("0 - Sair\n"
		       "1 - Prim\n"
			   "2 - Kruskal\n"
			   "Digite uma opcao de menu\n");
		scanf("%d", &*op);
		fflush(stdin);
		system("cls");
	}while (*op < 1 || *op > 2);
	
}

void salvarvetores(Arestas *arestas,char *nome){
		int i;
		char urlEntrada[60];
        sprintf(urlEntrada, "retornos do algoritmo/dados_%s.txt",nome);	
		FILE * file;
		file = fopen(urlEntrada, "w");
		
		while (file == NULL){
			printf("Erro.\n");// se caso der errado, pelo menos libera a memoria alocada
			system("PAUSE");
			exit(1);
		}
		for(i=0;i<TAM;i++){
			fprintf(file,"Vertice1: %d\nVertice2: %d\nDistancia: %lf\n\n", arestas[i].vertice1,arestas[i].vertice2,arestas[i].distancia);;
		}
		
		fclose(file);
		
}

void imprimevetores(Arestas *arestas){
		int i;
		for(i=0;i<TAM;i++){
			printf("\n%d %d %f", arestas[i].vertice1,arestas[i].vertice2,arestas[i].distancia );
		}
}
void insertionSort(Arestas *arestas){
   int i, j;
   float valorAtual;
 
   for( j=1; j < TAM; j++ ) 
   {
      valorAtual = arestas[j].distancia;
      int vert1 = arestas[j].vertice1;
      int vert2 =arestas[j].vertice2;
      i = j-1;
      
      while(i >= 0 && arestas[i].distancia > valorAtual)
      {
        arestas[i+1].distancia = arestas[i].distancia;
        arestas[i+1].vertice1 = arestas[i].vertice1;
        arestas[i+1].vertice2 = arestas[i].vertice2;
        i--;
      } 
              
      arestas[i+1].distancia = valorAtual;
      arestas[i+1].vertice1 = vert1;
      arestas[i+1].vertice2 = vert2;
   }
}

void kruskal(Arestas *arestas,int *vetorRotulos,int k_grupos){
	int i,j,aux,aux_k=QUAT_VERT;
	for(i=0;i<TAM;i++){
		if(vetorRotulos[arestas[i].vertice1]!=vetorRotulos[arestas[i].vertice2]){
			
			
			if(aux_k == k_grupos)
			{
				if(k_grupos==QUAT_VERT){
					imprimevetores(arestas);
				}
				break;
			}
			aux_k--;
		  		
			printf("\n%d %d %f", arestas[i].vertice1,arestas[i].vertice2,arestas[i].distancia );
			
			aux=arestas[i].vertice2;
			vetorRotulos[arestas[i].vertice2] =vetorRotulos[arestas[i].vertice1];
			
			for(j=1;j<=QUAT_VERT;j++){
				if(vetorRotulos[j]==aux){
					vetorRotulos[j]=vetorRotulos[arestas[i].vertice1];
					
				}
			}
		}
	
	}
	printf("RESULTADO \n ROTULOS DOS AGRUPAMENTOS\n");
	printf("\n" );
	for(i=1;i<=QUAT_VERT;i++){
		printf(" %d ",vetorRotulos[i]);
	}
}

