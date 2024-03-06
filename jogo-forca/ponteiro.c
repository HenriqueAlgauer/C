#include <stdio.h>

void calcula(int* x){
    printf("Calcula %d %d\n", (*x), x);
    (*x)++;
    printf("Calcula %d %d\n", (*x), x);
}

int main(){
    int c = 10;

    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);

}