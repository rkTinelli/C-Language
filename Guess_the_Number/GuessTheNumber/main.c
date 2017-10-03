#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void abertura(){
    printf("************************************\n");
    printf("*Bem vindo ao jogo de adivinhacao! *\n");
    printf("************************************\n");
    printf("Chute um numero e direi se voce esta certo...\n\n");
}

int escolhe_dificuldade(){

    int dific;
    int max_tent;

    printf("Escolha o grau de dificuldade do jogo:\n");
    printf("(1) - FACIL \n(2) - MEDIO \n(3) - DIFICIL \n ");
    scanf("%d", &dific);

    switch (dific){
        case 1:
            max_tent = 20;
            break;
        case 2:
            max_tent = 12;
            break;
        case 3:
            max_tent = 6;
            break;
    }
    return max_tent;
}

int def_num_secret(){
    int segundos = time(0);
    srand(segundos);

    int n1 = rand()%100;
    return n1;
}

int main()
{
    int chute;
    int numsecreto;
    int acertou = 0;
    int ind_tent;
    int max_tent;

    abertura(); //print de abertura do jogo

    numsecreto = def_num_secret();

    max_tent = escolhe_dificuldade();

    for (ind_tent = 0; ind_tent <= max_tent ; ind_tent++){

        printf("Tentativa %d de %d\n", ind_tent, max_tent);
        printf("Qual seu chute?\n");
        scanf("%d",&chute);

        if(chute < 0){
            printf("Favor chutar apenas valores positivos!\n");
            ind_tent--;
            continue;
        }

        acertou = ( chute == numsecreto );
        int maior = ( chute > numsecreto );

        if (acertou){
            break;
        } else if (maior){
            printf("Seu chute e MAIOR que o segredo!\n");
        } else {
            printf("Seu chute e MENOR que o segredo!\n");
        }

    }//encerrar laço de repetição aqui

    printf("\n*  FIM DE JOGO!  *\n");
    if(acertou){
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
    } else {
        printf("Voce perdeu... Tente novamente!\n");
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

    return 0;
}
