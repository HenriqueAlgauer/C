#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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


    int num_secreto = 20;
    int chute;
    int num_tentativa = 0;
    int pontos = 1000;
    int pontos_perdidos = 0;

    while(chute != num_secreto){
        printf("\nTentativa %d", num_tentativa+1);
        printf("\nQual é o seu chute ? ");
        scanf("%d", &chute);
        
        if(chute < 0){
            printf("Voce nao pode chutar numero negativos");
            continue;
        }

        if(chute == num_secreto){
            printf("Parabéns! Você acertou !");
        }else if(chute > num_secreto){
            printf("Você errou !\nSeu chute foi maior que o numero secreto");
            pontos_perdidos =  (chute - num_secreto) / 2;
            pontos -= pontos_perdidos;
        }else{
            printf("Você errou !\nSeu chute foi menor que o numero secreto");
            pontos_perdidos =  (num_secreto - chute) / 2;
            pontos -= pontos_perdidos;
        }
        
        num_tentativa++;
    }

    printf("\nVocê acertou na tentativa numero: %d", num_tentativa);
    printf("\nSua pontuação foi: %d", pontos);
    printf("\nFim de jogo");
    return 0;
}