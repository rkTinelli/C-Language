#include <stdio.h>
#include <stdlib.h>

int main()
{
    //inicializa��o da vari�vel de tamanho e inicializa��o
    int tamanho;

    printf("Digite o numero de elementos do array que sera analisado: ");
    scanf("%d", &tamanho);

    // Caso o tamanho seja menor que 2
    // n�o ser� poss�vel ter um par de resultados
    if(tamanho < 2){
        printf("Nao existem elementos suficiente");
        return 0;
    }

    // Inicializa��o do vetor de valores
    int vetor[tamanho];

    // Preenchimento de valores no vetor
    for(int i = 0; i < tamanho; i++){
        printf("Escreva o valor na posicao %d : ", i);
        scanf("%d", &vetor[i]);
    }

    // Inicializa��o de elementos de resultado
    int mult_max_1 = vetor[0];
    int mult_max_2 = vetor[1];

    // Percorrer o vetor analisando 2 elementos por vez
    // sendo o primeiro elemento referenciado pela vari�vel i
    // e o segundo elemento referenciado pela vari�vel j
    for(i = 0; i< tamanho; i++){
        for(int j = i+1; j < tamanho; j++){
            // Verifica se a multiplica��o dos elementos inspecionados
            // � maior que a multiplica��o dos elementos de resultado
            if (vetor[i]*vetor[j] > mult_max_1*mult_max_2){
                //Atribui��o de valores aos elementos de resultado
                mult_max_1 = vetor[i];
                mult_max_2 = vetor[j];
            }
        }
    }

    // Exibi��o de resultados
    printf("\nElementos que resultam na maior multiplicacao: {%d,%d}" , mult_max_1, mult_max_2);

    return 0;
}
