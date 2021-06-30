void heapSort(int vetor[], int tamanho){
	int i=tamanho/2, filho, pai, temp;
	while(1){
		if(i>0){
			i--;
			temp=vetor[i];
		}else{
			tamanho--;
			if(tamanho<1){
				return;
			}
			temp=vetor[tamanho];
			vetor[tamanho]=vetor[0];
		}
		pai=i;
		filho=i*2+1;
		while(filho<tamanho){
			if((filho+1<tamanho) && (vetor[filho+1]>vetor[filho])){
				filho++;
			}
			if(vetor[filho]>temp){
				vetor[pai]=vetor[filho];
				pai=filho;
				filho=pai*2+1;
			}else{
				break;
			}
		}
		vetor[pai]=temp;
	}
}
