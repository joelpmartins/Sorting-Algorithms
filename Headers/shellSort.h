void shellSort(int vetor[], int tamanho){
    int h=1, i, j, temp;
    while(h<tamanho){
        h=3*h+1;
    }
    while(h>0){
        for(i=h; i<tamanho; i++){
            temp=vetor[i];
            j=i;
            while(j>h-1 && temp<vetor[j-h]){
                vetor[j]=vetor[j-h];
                j=j-h;
            }
            vetor[j]=temp;
        }
        h=h/3;
    }
}
