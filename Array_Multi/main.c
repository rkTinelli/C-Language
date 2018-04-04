#include <stdio.h>
#include <stdlib.h>

int main()
{
    //inicialização da variável de tamanho e inicialização
    int tamanho;

    printf("Digite o numero de elementos do array que sera analisado: ");
    scanf("%d", &tamanho);

    // Caso o tamanho seja menor que 2
    // não será possível ter um par de resultados
    if(tamanho < 2){
        printf("Nao existem elementos suficiente");
        return 0;
    }

    // Inicialização do vetor de valores
    int vetor[tamanho];

    // Preenchimento de valores no vetor
    for(int i = 0; i < tamanho; i++){
        printf("Escreva o valor na posicao %d : ", i);
        scanf("%d", &vetor[i]);
    }

    // Inicialização de elementos de resultado
    int mult_max_1 = vetor[0];
    int mult_max_2 = vetor[1];

    // Percorrer o vetor analisando 2 elementos por vez
    // sendo o primeiro elemento referenciado pela variável i
    // e o segundo elemento referenciado pela variável j
    for(i = 0; i< tamanho; i++){
        for(int j = i+1; j < tamanho; j++){
            // Verifica se a multiplicação dos elementos inspecionados
            // é maior que a multiplicação dos elementos de resultado
            if (vetor[i]*vetor[j] > mult_max_1*mult_max_2){
                //Atribuição de valores aos elementos de resultado
                mult_max_1 = vetor[i];
                mult_max_2 = vetor[j];
            }
        }
    }

    // Exibição de resultados
    printf("\nElementos que resultam na maior multiplicacao: {%d,%d}" , mult_max_1, mult_max_2);

    return 0;
}
