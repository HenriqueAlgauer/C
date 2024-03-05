#include <stdio.h>

int main(){
	int num_1;
	int num_2;
	
	printf("Digite um numero: ");
	scanf("%d", &num_1);
	
	printf("Digite outro numero: ");
	scanf("%d", &num_2);
	
	int soma = num_1 + num_2;
	
	printf("Soma %d", soma);
}