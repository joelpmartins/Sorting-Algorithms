int binarySearch(int vetor[], int temp, int inicio, int fim){
	int meio=(inicio+fim)/2;
	if(fim<=inicio){
		return (temp>vetor[inicio])?(inicio+1):inicio;
	}
	if(temp==vetor[meio]){
		return meio+1;
	}
	if(temp>vetor[meio]){
		return binarySearch(vetor, temp, meio+1, fim);
	}
	return binarySearch(vetor, temp, inicio, meio-1);
}

void binaryInsertionSort(int vetor[], int tamanho){
	int i, j, pos, temp;
	for(i=1; i<tamanho; i++){
		j=i-1;
		temp=vetor[i];
		pos=binarySearch(vetor, temp, 0, j);
		while(j>=pos){
			vetor[j+1]=vetor[j];
			j--;
		}
		vetor[j+1]=temp;
	}
}
