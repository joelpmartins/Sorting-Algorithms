void quickSort(int vetor[], int inicio, int fim){
	int i, j, pivo, temp;
	i=inicio;
	j=fim-1;
	pivo=vetor[(inicio+fim)/2];
	while(i<=j){
		while(vetor[i]<pivo && i<fim){
			i++;
		}
		while(vetor[j]>pivo && j>inicio){
			j--;
		}
		if(i<=j){
			temp=vetor[i];
			vetor[i]=vetor[j];
			vetor[j]=temp;
			i++;
			j--;
		}
	}
	if(j>inicio){
		quickSort(vetor, inicio, j+1);
	}
	if(i<fim){
		quickSort(vetor, i, fim);
	}
}
