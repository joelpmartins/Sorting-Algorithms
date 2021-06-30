void modoTeste(int vetor[], int tamanho, int tipo){
	const char* descricao;
	double inicio, fim, resultado;
	int i, j;

	FILE *arquivo;
	if(fopen("resultado.csv", "r")==NULL){
		arquivo=fopen("resultado.csv", "w+");
    }else{
        arquivo=fopen("resultado.csv", "r+");
    }

	printf("\n[Método]\t\t[Tempo(ms)]\t[Tamanho]\n");
    fprintf(arquivo,"Método, Média(ms), Tamanho(vetor)\n");
	for(i=1; i<11; i++){
		for(j=0; j<100; j++){
			switch(i){
				case 1:{
					//resultado=insertionSort(vetor, tamanho)+resultado;
					descricao="Insertion Sort";
					break;
				}
				case 2:{
					resultado=binaryInsertionSort(vetor, tamanho)+resultado;
					descricao="Insertion Sort com busca binária";
					break;
				}
				case 3:{
					resultado=selectionSort(vetor, tamanho)+resultado;
					descricao="Selection Sort";
					break;
				}
				case 4:{
					resultado=bubbleSort(vetor, tamanho)+resultado;
					descricao="Bubble Sort";
					break;
				}
				case 5:{
					resultado=combSort(vetor, tamanho)+resultado;
					descricao="Comb Sort";
					break;
				}
				case 6:{
					inicio=clock();
					mergeSort(vetor, 0, tamanho-1);
					fim=clock();
					resultado=calculate_time(inicio, fim)+resultado;
					descricao="Merge Sort";
					break;
				}
				case 7:{
					inicio=clock();
					heapSort(vetor, tamanho);
					fim=clock();
					resultado=calculate_time(inicio, fim)+resultado;
                    descricao="Heap Sort";
					break;
				}
				case 8:{
					resultado=shellSort(vetor, tamanho)+resultado;
					descricao="Shell Sort";
					break;
				}
				case 9:{
					inicio=clock();
					timSort(vetor, tamanho);
					fim=clock();
					resultado=calculate_time(inicio, fim)+resultado;
                    descricao="Tim Sort";
					break;
				}
				case 10:{
					inicio=clock();
                    quickSort(vetor, 0, tamanho-1);
                    fim=clock();
                    resultado=calculate_time(inicio, fim)+resultado;
                    descricao="Quick Sort";
					break;
				}
			}
		}
		resultado=resultado/100;
		imprimir_resultado(descricao, resultado, tamanho);
		fprintf(arquivo,"%s, %f, %d\n", descricao, resultado, tamanho);
	}
	printf("*** resultados desses testes foram salvos em 'resultado.csv'.\n");
}
