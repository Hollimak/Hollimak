#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // imprime cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int segundos = time (0);
    srand(segundos);

    int numerogrande = rand ();
    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int numerodetentivas;
    int acertou = 0;
    int nivel;
    printf("Qual eh o nivel de dificuldade:\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha uma dificuldade:\n");
    scanf("%d", &nivel);
    
    switch (nivel)
    {
    case 1:
        numerodetentivas = 20;
        break;
    case 2:
        numerodetentivas = 15;
        break;
    default:
        numerodetentivas = 6;
        break;
    }
    for (int i= 1; i<=numerodetentivas; i++)
    {

        printf("Tentativa %d\n", tentativas);
        printf("Qual eh o seu chute? \n");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você nao pode chutar numeros negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Parabens! Voce acertou!\n");
            printf("Jogue de novo, voce eh um bom jogador!\n");

            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o numero secreto\n");
        } 

        else {
            printf("Seu chute foi menor que o numero secreto\n");
        }

        tentativas++;
        
        double pontosperdidos = abs (chute - numerosecreto) / (double) 2;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!\n");
    printf("Voce acertou em %d tentativas!", tentativas);
}