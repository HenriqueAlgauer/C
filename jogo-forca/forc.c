#include <stdio.h>
#include <string.h>

int main(){

    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;
    int contar = strlen(palavrasecreta);

    char chutes[26];
    int tentativas = 0;
  
    do{

        for(int i = 0; i < contar; i++){

            int achou = 0; 

            for(int j = 0; j < tentativas; j++){
                if(chutes[j] == palavrasecreta[i]){
                    achou = 1;
                    break;
                }
            }
            if(achou){
                printf("%c", palavrasecreta[i]);
            }else{
                printf("_ ");
            }
        }
        char chute;
        printf("\nQual o seu chute ? ");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas ++;

    }while(!acertou && !enforcou);

}