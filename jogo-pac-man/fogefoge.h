#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

int acabou();
void move(char direcao);
int verificadirecao(char direcao);
int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
