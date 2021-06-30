void insertionSort(int vetor[], int tamanho){
	int i, j, temp;
	for(i=1; i<tamanho; i++){
		temp=vetor[i];
		j=i-1;
		while(j>-1 && vetor[j]>temp){
			vetor[j+1]=vetor[j];
			j--;
		}
		vetor[j+1]=temp;
	}
}

void insertionSort_2(int vetor[], int esquerda, int direita){
	int i, j, temp;
	for(i=esquerda+1; i<=direita; i++){
		temp=vetor[i];
		j=i-1;
		while(j>=esquerda && vetor[j]>temp){
			vetor[j+1]=vetor[j];
			j--;
		}
		vetor[j+1]=temp;
	}
}
