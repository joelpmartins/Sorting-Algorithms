#define min(a,b) (a)<(b)?(a):(b)

void timSort(int vetor[], int tamanho){
    int i, n, esquerda, meio, direita, RUN=32;
    for(i=0; i<tamanho; i+=RUN){
        insertionSort_2(vetor, i, min((i+31), (n-1)));
    }
    for(i=RUN; i<tamanho; i=2*i){
        for(esquerda=0; esquerda<tamanho; esquerda+=2*i){
            meio=esquerda+i-1;
            direita=min((esquerda+2*i-1), (n-1));
            merge(vetor, esquerda, meio, direita);
        }
    }
}
