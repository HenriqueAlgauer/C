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
    int num_tentativas = 5;

    while(i < num_tentativas && chute != num_secreto){
        printf("\nTentativa %d de %d", i+1, num_tentativas);
        printf("\nQual é o seu chute ? ");
        scanf("%d", &chute);
        if(chute == num_secreto){
            printf("Parabéns! Você acertou !");
        }else if(chute > num_secreto){
            printf("Você errou !\nSeu chute foi maior que o numero secreto");
        }else{
            printf("Você errou !\nSeu chute foi menor que o numero secreto");
        }
        
        i++;
    }
    return 0;
}