#include <stdio.h>
#include <stdlib.h>

int absnum(int num){
	printf("Absoluto de: [%d] eh = [%d]", num, abs(num));
	return 0;
}
int main(){
	absnum(-20);
}
