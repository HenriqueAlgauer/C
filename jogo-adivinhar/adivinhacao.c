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
    int i = 0;
    int num_tentativa = 0;

    while(chute != num_secreto){
        printf("Tentativa %d", num_tentativa+1);
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
        }else{
            printf("Você errou !\nSeu chute foi menor que o numero secreto");
        }
        
        num_tentativa++;
    }

    printf("Você acertou na tentativa numero: %d", num_tentativa);
    printf("Fim de jogo");
    return 0;
}