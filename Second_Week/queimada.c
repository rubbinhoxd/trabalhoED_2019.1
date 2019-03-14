#include <stdio.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.'; 

void mostrar_matriz(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        printf("");
    }
}

void pay_fire(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;
    if(mat[l][c] != TREE)
        return;
    mat[l][c] = FIRE;
    pay_fire(nl, nc, mat, l, c + 1);
    pay_fire(nl, nc, mat, l, c - 1);
    pay_fire(nl, nc, mat, l - 1, c);
    pay_fire(nl, nc, mat, l + 1, c);
}

int main(){
    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &l, &c);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            scanf(" %c", &mat[l][c]);
    pay_fire(nl, nc, mat, l, c);
    mostrar_matriz(nl, nc, mat);

}
