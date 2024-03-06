#include <stdio.h>
#include <string.h>

void abertura(){
    printf("*********************\n");
    printf("*   Jogo da Forca   *\n");
    printf("*********************\n");
}

void chuta(char chutes[26], int tentativas){
    char chute;
        printf("\nQual o seu chute ? ");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas ++;
}


int main(){

    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;
    int contar = strlen(palavrasecreta);

    char chutes[26];
    int tentativas = 0;

    abertura();
  
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
        chuta(chutes, tentativas);

    }while(!acertou && !enforcou);

}