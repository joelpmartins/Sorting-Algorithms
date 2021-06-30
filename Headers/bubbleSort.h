void bubbleSort(int vetor[], int tamanho){
    int i, j, temp;
    for(i=0; i<tamanho; i++){
        for(j=0; j<tamanho-1; j++){
            if(vetor[j]>vetor[j+1]){
                temp=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=temp;
            }
        }
    }
}
