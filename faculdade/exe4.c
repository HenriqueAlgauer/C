#include <stdio.h>

int soma(int a, int b){
	int i,s, menor, maior;
	s = 0;
	
	menor = a;
	maior = b;
	
	if(menor > b){
		menor = b;
		maior = a;
	}
	
	for(i= menor + 1;i < maior; i++){
		printf("|%d|", i);
		s += i;
	}
	printf("-%d-", s);

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
