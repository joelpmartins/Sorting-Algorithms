/******************************************************************************************
ALGORITMOS DE ORDENAÇÃO: INSERTION SORT, INSERTION SORT COM BUSCA BINÁRIA, SELECTION SORT,
BUBBLE SORT, COMB SORT, MERGE SORT, HEAP SORT, SHELL SORT, TIM SORT E QUICK SORT.

AUTORES: JOEL, CRISTOFERSON E MAURICIO.

IDE: CODE::BLOCKS 20.03.
COMPILADOR: GCC 9.3.0.

ÚLTIMA ATUALIZAÇÃO: 29/06/2021.
*******************************************************************************************/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Headers/insertionSort.h"
#include "Headers/binaryInsertionSort.h"
#include "Headers/selectionSort.h"
#include "Headers/bubbleSort.h"
#include "Headers/combSort.h"
#include "Headers/mergeSort.h"
#include "Headers/heapSort.h"
#include "Headers/shellSort.h"
#include "Headers/timSort.h"
#include "Headers/quickSort.h"

#ifdef _WIN32
	#define limite 500000
#else
	#define limite 2000000
#endif

int tamanho_lista();
int tipo_lista();
double calcular_tempo(double inicio, double fim);
double calcular_media(double resultado[], int tamanho);
void gerar_lista(int vetor[], int tamanho, int tipo);
void gerar_resultado(int vetor[], int tamanho, int n, int tipo);

int main(){
	int menu, tamanho, tipo, vetor[limite];
	setlocale(LC_ALL, "Portuguese");
	while(1){
		menu=0;
		tamanho=tamanho_lista();
		tipo=tipo_lista();
		printf("\n<> MENU <>\n\n1. Insertion Sort\n2. Insertion Sort com busca binária\n3. Selection Sort\n4. Bubble Sort\n5. Comb Sort\n6. Merge Sort\n7. Heap Sort\n8. Shell Sort\n9. Tim Sort\n10. Quick Sort\n11. Todos\n12. Sair\n\n>> ");
		while(menu<1 || menu>12){
			scanf("%d", &menu);
            if(menu<1 || menu>12){
                printf("\n[X] OPÇÃO INVÁLIDA!\n\n>> ");
            }else if(menu==12){
                printf("*** programa foi encerrado.\n");
                exit(1);
            }
		}
		gerar_resultado(vetor, tamanho, menu, tipo);
		printf("................................................\n");
	}
	return 0;
}

int tamanho_lista(){
	int tamanho=0;
	printf("<> INFORME O TAMANHO DA LISTA <>\n\n>> ");
	while(tamanho<1 || tamanho>limite){
		scanf("%d", &tamanho);
		if(tamanho<1 || tamanho>limite){
			printf("[X] TAMANHO INVÁLIDO!\n\n>> ");
		}
	}
	return tamanho;
}

int tipo_lista(){
	int tipo=0;
	printf("\n<> ESCOLHA O TIPO DE LISTA QUE DESEJA GERAR <>\n\n1. Crescente\n2. Decrescente\n3. Aleatória\n\n>> ");
	while(tipo<1 || tipo>3){
		scanf("%d", &tipo);
		if(tipo<1 || tipo>3){
			printf("\n[X] OPÇÃO INVÁLIDA!\n\n>> ");
		}
	}
	return tipo;
}

void gerar_lista(int vetor[], int tamanho, int tipo){
	int i=0, temp=0;
	switch(tipo){
		case 1:{ // gera lista de números em ordem crescente
			for(i=0; i<tamanho; i++){
				vetor[i]=i;
			}
			break;
		}
		case 2:{ // gera lista de números em ordem decrescente
			for(i=tamanho-1; i>-1; i--){
                vetor[i]=temp++;
            }
			break;
		}
		case 3:{ // gera lista de números aleatórios
			for(i=0; i<tamanho; i++){
				vetor[i]=rand()%tamanho;
			}
			break;
		}
	}
}

double calcular_tempo(double inicio, double fim){
	double tempo;
	tempo=(double)(fim-inicio)/CLOCKS_PER_SEC; // realiza o cálculo do tempo de execução em segundos
	return tempo;
}

double calcular_media(double resultado[], int tamanho){
    double m, media=0, temp;
    int c=0, i, j, n1, n2;
    for(i=1; i<tamanho; i++){ // ordenação da lista de resultados usando o método Insertion Sort
        temp=resultado[i];
        j=i-1;
        while(j>-1 && resultado[j]>temp){
            resultado[j+1]=resultado[j];
            j=j-1;
        }
        resultado[j+1]=temp;
    }
    n1=tamanho/2-tamanho/4; // n1 será atribuído o valor do elemento do meio da primeira metade do vetor resultado
    n2=tamanho/2+tamanho/4; // n2 será atribuído o valor do elemento do meio da segunda metade do vetor resultado
    m=(resultado[n2]-resultado[n1])*0.25+(resultado[n2]-resultado[n1]); // m será atribuído o valor do que seria uma espécie de margem de erro
    for(i=0; i<tamanho; i++){
        if((resultado[n1]-m)<=resultado[i] && (resultado[n2]+m)>=resultado[i]){ // com o valor de m será verificado se o resultado analisado é um valor fora da curva, ou seja, muito maior ou menor que os outros resultados
            media=resultado[i]+media; // soma dos resultados que estão dentro do padrão
            c++; // quantidade de resultados dentro do padrão
        }
    }
    media=media/c; // divisão da soma dos resultados pela quantidade de resultados dentro do padrão para gerar a média
    return media;
}

void gerar_resultado(int vetor[], int tamanho, int n, int tipo){
    const char* descricao;
    double inicio, fim, resultado[100];
    int temp=n;
    printf("\n[Método]\t\t[Tempo(s)]\t[Tamanho]\n");
    if(n>10){
        temp=1;
    }
    for(int i=temp;i<n+1; i++){
        for(int j=0; j<100; j++){
            gerar_lista(vetor, tamanho, tipo);
            switch(i){
                case 1:{
                    inicio=clock();
                    insertionSort(vetor, tamanho);
                    fim=clock();
                    descricao="Insertion Sort";
                    break;
                }
                case 2:{
                    inicio=clock();
                    binaryInsertionSort(vetor, tamanho);
                    fim=clock();
                    descricao="Insertion Sort com busca binária";
                    break;
                }
                case 3:{
                    inicio=clock();
                    selectionSort(vetor, tamanho);
                    fim=clock();
                    descricao="Selection Sort";
                    break;
                }
                case 4:{
                    inicio=clock();
                    bubbleSort(vetor, tamanho);
                    fim=clock();
                    descricao="Bubble Sort";
                    break;
                }
                case 5:{
                    inicio=clock();
                    combSort(vetor, tamanho);
                    fim=clock();
                    descricao="Comb Sort";
                    break;
                }
                case 6:{
                    inicio=clock();
                    mergeSort(vetor, 0, tamanho-1);
                    fim=clock();
                    descricao="Merge Sort";
                    break;
                }
                case 7:{
                    inicio=clock();
                    heapSort(vetor, tamanho);
                    fim=clock();
                    descricao="Heap Sort";
                    break;
                }
                case 8:{
                    inicio=clock();
                    shellSort(vetor, tamanho);
                    fim=clock();
                    descricao="Shell Sort";
                    break;
                }
                case 9:{
                    inicio=clock();
                    timSort(vetor, tamanho);
                    fim=clock();
                    descricao="Tim Sort";
                    break;
                }
                case 10:{
		    inicio=clock();
                    quickSort(vetor, 0, tamanho-1);
                    fim=clock();
                    descricao="Quick Sort";
                    i=n+1;
		    break;
		}
            }
            resultado[j]=calcular_tempo(inicio, fim);
        }
        printf("%s,\t\t%.10f,\t%d\n", descricao, calcular_media(resultado, 100), tamanho);
    }
}
