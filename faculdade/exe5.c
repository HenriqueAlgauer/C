#include <stdio.h>

int verMaior(int a, int b){
	int menor, maior;
	
	
	menor = a;
	maior = b;
	
	if(menor > b){
		menor = b;
		maior = a;
	}
	
	printf("\nMaior: %d", maior);

	
}

int main(){
	int a,b;
	
	printf("Digite um numero: ");
	scanf("%d", &a);
	printf("Digite outro numero: ");
	scanf("%d", &b);
	
	verMaior(a,b);

}
