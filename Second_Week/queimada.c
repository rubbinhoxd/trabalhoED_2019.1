//Queimada aleatoria
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const char BURNED = 'x';

//Deslocamentos possiveis
int moveL[] = {0, -1, 0, 1};//Baixo e Cima
int moveC[] = {-1, 0, 1, 0};//Esquerda e Direita
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

int pay_fire(int nl, int nc,char mat[nl][nc], int l, int c){
    if((l < 0) ||(l >= nl) ||(c <  0) ||(c >= nc)){
        return 0;
    }
    if(mat[l][c] != TREE){
        return 0;
    }
    mat[l][c] = FIRE;//taca fogo
    show(nl, nc, mat);
    int cont = 1;
    int viz[] = {0, 1, 2, 3};
    shuffle(viz, sides);
    for(int v = 0; v < sides; v++){
        int i = viz[v];
        cont += pay_fire(nl, nc, mat, l + moveL[i], c + moveC[i]);//recursiva
    }
    mat[l][c] = BURNED;//marca o x
    show(nl, nc, mat);
    return cont;
}

int main(){
    srand(time(NULL));//Gera uma nova seed de aleatoriedade
    int nl = 0;
    int nc = 0;
    printf("Digite o tamanho da floresta:\n");
    scanf("%d%d", &nl, &nc);
    printf("Digite a porcentagem de arvores 0-100:\n");
    int taxa = 0;
    scanf("%d", &taxa);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            //Gera arvores aleatoriamente
            if(rand() % 101 <= taxa){
                mat[l][c] = TREE;
            }else{
                mat[l][c] = EMPTY;
            }
        }
    }
    show(nl, nc, mat);
    printf("Onde iniciar o incendio?\n");
    int i = 0;//linha escolhida para queimar
    int j = 0;//coluna escolhida para queimar
    scanf("%d%d", &i, &j);
    int total = pay_fire(nl, nc, mat, i, j);
    show(nl, nc, mat);
    printf("total do estrago: %d\n", total);
}
