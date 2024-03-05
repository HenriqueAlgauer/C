#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h> 

void linha(){
    int i;

    for(i=0;i<20;i++){
        printf("*");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    linha();
    printf("\nBem Vindo ao jogo da adivinhação\n");
    linha();

    int segundos = time(0);
    srand(segundos);

    int numero_grande = rand();
    
    int num_secreto = numero_grande % 100;
    int chute;
    float pontos = 1000;
    int nivel;
    int tentativas;

    printf("\nQual o nível de dificulade ? \n (1)Fácil | (2)Médio | (3)Difícil \n\n");
    scanf("%d", &nivel);
    switch (nivel){
        case 1: tentativas = 20; break;
        case 2: tentativas = 15; break;
        case 3: tentativas = 6; break;
    }
   

    for(int i =0; i < tentativas; i++){
        printf("\nTentativa %d", i+1);
        printf("\nQual é o seu chute ? ");
        scanf("%d", &chute);
        
        if(chute < 0){
            printf("Voce nao pode chutar numero negativos");
            continue;
        }

        if(chute == num_secreto){
            printf("Parabéns! Você acertou !");
            break;
        }else if(chute > num_secreto){
            printf("Você errou !\nSeu chute foi maior que o numero secreto");
        }else{
            printf("Você errou !\nSeu chute foi menor que o numero secreto");
        }
        
        float pontos_perdidos = abs(num_secreto - chute) / 2.0;
        pontos -= pontos_perdidos;
    }

    printf("\nVocê acertou !");
    printf("\nSua pontuação foi: %.1f", pontos);
    printf("\nFim de jogo");
    return 0;
}