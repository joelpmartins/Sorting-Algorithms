void merge(int vetor[], int inicio, int meio, int fim){
	int c1=inicio, c2=meio+1, temp=0, tamanho=fim-inicio+1, *vetorAux;
	vetorAux=(int*)malloc(tamanho * sizeof(int));
	while(c1<=meio && c2<=fim){
		if(vetor[c1]<vetor[c2]){
			vetorAux[temp]=vetor[c1];
			c1++;
		}else{
			vetorAux[temp]=vetor[c2];
			c2++;
		}
		temp++;
	}
	while(c1<=meio){
		vetorAux[temp]=vetor[c1];
		temp++;
		c1++;
	}
	while(c2<=fim){
		vetorAux[temp]=vetor[c2];
		temp++;
		c2++;
	}
	for(temp=inicio; temp<=fim; temp++){
		vetor[temp]=vetorAux[temp-inicio];
	}
	free(vetorAux);
}

void mergeSort(int vetor[], int inicio, int fim){
	if(inicio<fim){
		int meio=(fim+inicio)/2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, fim);
		merge(vetor, inicio, meio, fim);
	}
}
