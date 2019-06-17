#include "xpaint.h"
#include "xmat.h"
#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

struct Pos{
    int l, c;
    Pos(int _l, int _c){
        this->l = _l;
        this->c = _c;
    }
};

vector<Pos> get_neibs(int l, int c){
    return vector<Pos> {Pos(l, c - 1), Pos(l - 1, c), Pos(l, c + 1), Pos(l + 1, c)};
}
 
bool has_value(vector<string> &mat, int l, int c, char value){ //saber se a posição é valida
    if(l < 0 || l >= (int) mat.size())
        return false;
    if(c < 0 || c >= (int) mat[0].size())
        return false;
    return mat[l][c] == value;
}

void pintar(vector<string> &mat,int l, int c, char cor_base, char cor_final){
    if(!has_value(mat, l, c, cor_base))
        return;
    mat[l][c] = cor_final;
    xmat_draw(mat);
    x_step("mat");
    for(auto viz : get_neibs(l, c)){
        pintar(mat, viz.l, viz.c, cor_base, cor_final);
    }
}


void mostrar(vector<vector<int>>& mat_int, vector<string>& mat, queue<Pos> fila){
    xmat_draw(mat);
    while(!fila.empty()){
        xmat_put_circle(fila.front().l, fila.front().c, WHITE);
        fila.pop();
    }
    for(int l = 0; l < (int) mat.size(); l++){
        for(int c = 0; c < (int) mat[0].size(); c++){
            xmat_put_number(l, c, BLACK, mat_int[l][c]);
        }
    }
    x_step("mat"); 

}

void floodfill(vector<vector<int>>& mat_int, vector<string>& mat, int l, int c, char cor_base, char cor_final, int lfinal, int cfinal){
    queue<Pos> fila;
    fila.push(Pos(l, c)); //onde comeca
    mat[l][c] = cor_final;
    vector<string>mat_reserva = mat;
    bool achou = false;
    while(!fila.empty()){
        Pos ref = fila.front();
        int atual = mat_int[ref.l][ref.c];
        fila.pop();
        for(auto viz : get_neibs(ref.l, ref.c)){
            if(has_value(mat, viz.l, viz.c, cor_base)){
                mat[viz.l][viz.c] = cor_final;
                mat_int[viz.l][viz.c] = atual + 1;
                fila.push(viz);
                mostrar(mat_int, mat, fila);
                if(viz.l == lfinal && viz.c == cfinal){
                    achou = true; //tem um caminho
                    break;
                }
            }
        }
        if(achou){
            break;
        }
    }
    
    if(achou){
        bool terminou = false;
        queue<Pos>fila2;
        fila2.push(Pos(lfinal, cfinal));
        while(!terminou){
            Pos ref = fila2.back(); // teve que alterar para pegar o back, ja que nao estamos removendo ninguem
            int atual2 = mat_int[ref.l][ref.c];    
            for(auto viz : get_neibs(ref.l, ref.c)){
                if(has_value(mat, viz.l, viz.c, cor_final)){
                    if(mat_int[viz.l][viz.c] == 0){
                        fila2.push(viz);
                        terminou = true;
                        break;
                    }
                    if(mat_int[viz.l][viz.c] == atual2 - 1){
                        fila2.push(viz);
                        break;
                    }
                }
            } 
        }
        mat = mat_reserva;
        while(!fila2.empty()){
            Pos ref = fila2.front();
            mat[ref.l][ref.c] = cor_final;
            fila2.pop();
        }
        
    }
    
}


int main(){
    int nl = 20, nc = 20;
    xmat_init(nl, nc);
    vector<string> mat(nl, string(nc, 'w'));
    vector<vector<int>> mat_int(nl, vector<int>(nc, 0));
    for(int l = 0; l < (int) mat.size(); l++){
        for(int c = 0; c < (int) mat[0].size(); c++){
            if(xm_rand(0, 100) < 30)
                mat[l][c] = 'r'; 
        }
    }
    xmat_draw(mat);
    x_save("mat");
    int l = 0, c = 0;
    puts("Digite o ponto de inicio l e c");
    scanf("%d %d", &l, &c);
    getchar();//remove \n after numbers
    puts("Agora, digite um ponto final l e c");
    int lfinal;
    int cfinal;
    scanf("%d %d", &lfinal, &cfinal);
//  pintar(mat, l, c, mat[l][c], 'b');
    floodfill(mat_int, mat, l, c, mat[l][c], 'b', lfinal, cfinal);
    xmat_draw(mat);
    x_save("mat");
    x_close();
}
