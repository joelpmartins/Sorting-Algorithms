void combSort(int vetor[], int tamanho){
	int i, j, temp, intervalo, trocado=1;
	intervalo=tamanho;
	while(intervalo>1 || trocado==1){
		intervalo=intervalo*10/13;
		if(intervalo== 9 || intervalo==10){
			intervalo=11;
		}
		if(intervalo<1){
			intervalo=1;
		}
		trocado=0;
		for(i=0, j=intervalo; j<tamanho; i++, j++){
			if(vetor[i]>vetor[j]){
				temp=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=temp;
				trocado=1;
			}
		}
	}
}
