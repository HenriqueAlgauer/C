#include <stdio.h>

int soma(int a, int b){
	int s;
	
	s = a + b;
	printf("Soma = %d", s);
	return s;
}

int main(){
	int a,b;
	
	printf("Digite um numero: ");
	scanf("%d", &a);
	printf("Digite outro numero: ");
	scanf("%d", &b);
	
	soma(a,b);
}
