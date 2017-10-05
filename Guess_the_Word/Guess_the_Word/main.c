#include <stdio.h>
#include <stdlib.h>
#include "forca.h"

char secreta [20];
char let_chut[26];
int rodada = 0;
int erros = 0;
int max_tent = 5;

void abertura(){
    printf("************************************\n");
    printf("*  Bem vindo ao jogo de de forca!  *\n");
    printf("************************************\n");
}

void define_secreta(){

    FILE* f;
    f = fopen("palavras.txt","r"); // abertura do arquivo
        if(f == 0) { // ZERO representa qualuqer erro na abertura do arquivo
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int quant;
    fscanf(f,"%d",&quant); //leitura de dados

    srand(time(0));
    int ind_pala = rand() % quant;
    int i;
    for (i = 0; i <= ind_pala;i++){
        fscanf(f,"%s",secreta);
    }
}

void desenha_forca(){

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1 ? '(' : ' '),(erros>=1 ? '_' : ' ' ),(erros>=1 ? ')' : ' ' ));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '),    (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");


    int j;
    for(j=0;j<=strlen(secreta);j++){
        if (existe_letra(secreta[j],let_chut)){
            printf("%c ",secreta[j]);
        } else {
            printf("_ ");
        }
    }
    printf("\n"); // Apenas para separar o texto
}

void recebe_chute(){

    printf("Qual seu chute?  ");
    scanf(" %c",&let_chut[rodada]);

    if (existe_letra(let_chut[rodada],secreta)){
        printf("Voce acertou! A palavra contem a letra %c\n\n", let_chut[rodada]);
    } else {
        printf("Voce errou! A palavra nao tem essa letra...\n\n");
        erros++;
    }

    /*
    printf("Chute: %c\n",let_chut[rodada]); // Apenas Debug
    printf("Rodada: %d\n", rodada); // Apenas Debug
    printf("Letras Chutadas: %s\n", let_chut); // Apenas Debug
    printf("Erros : %d\n", erros); // Apenas Debug
    */

    rodada++;
}

int existe_letra(char chute, char vetor[]){

    /*
    * Verifica se a LETRA esta dentro do ARRAY passado
    * para saber se ja foi chutada, procurar dentro do "let_chute"
    * para saber se o chute foi correto, procurar dentro de "secreta"
    */

    int i;
    for (i=0;i<=strlen(vetor);i++){
        if (chute == vetor[i]){
            return 1;
        }
    }
    return 0;
}

int enforcou(){
    return erros >= max_tent;
}

int ganhou(){

    int j;
    for(j=0;j<=strlen(secreta);j++){
        if (existe_letra(secreta[j],let_chut)){
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

void text_ganha(){
    printf("\nParabens, voce ganhou!\n\n");

    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
}

void text_perde(){
    printf("\nPuxa, voce foi enforcado!\n");
    printf("A palavra era **%s**\n\n", secreta);

    printf("    _______________         \n");
    printf("   /               \\       \n");
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" |                   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("     \\_         _/         \n");
    printf("       \\_______/           \n");
}

void add_palara(){

    printf("Deseja adicionar um nova palavras? (S / N)\n");
    char op;
    scanf(" %c",&op);
        if (op == 'S'){

            printf("Digite a nova palavra, tudo em letras maiusculas:\n");
            char nov_pala[26];
            scanf("%s",&nov_pala);

            FILE* f;
            f = fopen("palavras.txt","r+");
                if(f == 0) { // ZERO representa qualuqer erro na abertura do arquivo
                    printf("Banco de dados de palavras não disponível\n\n");
                    exit(1);
                }

            int quant;
            fscanf(f,"%d",&quant);
            quant++;
            fseek(f,0,SEEK_SET);
            fprintf(f,"%d",quant);

            fseek(f,0,SEEK_END);
            fprintf(f,"%s",nov_pala);
            fclose(f);
        }
}


int main(){

    abertura();

    define_secreta();

    do {
        desenha_forca();
        recebe_chute();

    } while (!ganhou() && !enforcou());

    if (ganhou()){
        text_ganha();
    } else {
        text_perde();
    }

    add_palara();
}
