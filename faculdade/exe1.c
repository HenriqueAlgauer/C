#include <stdio.h>
#include <stdlib.h>

void linha(int num){
	int i;
	
	for(i=0;i<num;i++){
		printf("*");
	}
}

void numero(int num){
	int i;
	
	for(i=1;i<num;i++){
		printf("%d\n", i);
	}
}

int main(){
	int i;
	
	linha(20);
	
	printf("\n");
	
	printf("Numeros entre 1 e 5 :");
	
	printf("\n");
	linha(20);
	
	printf("\n");

	numero(7);
	linha(20);
}