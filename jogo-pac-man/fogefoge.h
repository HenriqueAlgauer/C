void liberamapa();
void alocamapa();
void lermapa();
void imprimemapa();
int acabou();
void move(char direcao);

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};