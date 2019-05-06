//Queimada aleatoria
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const char BURNED = 'x';

//Deslocamentos possiveis
int moveL[] = {0, -1, 0, 1};
int moveC[] = {-1, 0, 1, 0};
int sides = sizeof(moveL)/sizeof(int);

//Embaralha o vetor
void shuffle(int vet[], int size){
    for(int i = 0; i < size; i++){
        int esc = rand() % size;
        int temp = vet[i];
        vet[i] = vet[esc];
        vet[esc] = temp;
    }
}

void show(int linha, int coluna, char mat[linha][coluna]){
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            printf("%c", mat[l][c]);
        }
        printf("\n");
    }
    getchar();
}

int queima(int nl, int nc,char mat[nl][nc + 2], int l, int c){
    if((l < 0) ||(l >= nl) ||(c <  0) ||(c >= nc)){
        return 0;
    }
    if(mat[l][c] != TREE){
        return 0;
    }
    mat[l][c] = FIRE;
    show(nl, nc, mat);
    int cont = 1;
    int viz[] = {0, 1, 2, 3};
    shuffle(viz, sides);
    for(int v = 0; v < sides; v++){
        int i = viz[v];
        cont += queima(nl, nc, mat, l + moveL[i], c + moveC[i]);
    }
    mat[l][c] = BURNED;
    show(nl, nc, mat);
    return cont;
}

int main(){
    srand(time(NULL));//Gera uma nova seed de aleatoriedade
    int linha = 0;
    int coluna = 0;
    printf("Digite o tamanho da floresta:\n");
    scanf("%d%d", &linha, &coluna);
    printf("Digite a porcentagem de arvores 0-100:\n");
    int taxa = 0;
    scanf("%d", &taxa);
    char mat[linha][coluna];
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            //Gera arvores aleatoriamente
            if(rand() % 101 <= taxa){
                mat[l][c] = TREE;
            }else{
                mat[l][c] = EMPTY;
            }
        }
    }
    show(linha, coluna, mat);
    printf("Onde iniciar o incendio?\n");
    int i = 0;//linha escolhida para queimar
    int j = 0;//coluna escolhida para queimar
    scanf("%d%d", &i, &j);
    int total = queima(linha, coluna, mat, i, j);
    show(linha, coluna, mat);
    printf("total do estrago: %d\n", total);
}
