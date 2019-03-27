#include <stdio.h>
#include <stdlib.h>
#include "xpaint.h"



void tree(int x, int y, float ang, int size){
    if(size < 10){
        return;
    }

    int xf = x + size * xm_cos(ang);
    int yf = y - size * xm_sin(ang);
    xs_color((XColor){xm_rand(0 , 255), xm_rand(0 , 50), xm_rand(0 , 50)});
    xd_thick_line(x, y, xf, yf, 3);
    x_step("tree");


    tree(xf, yf, ang - 30, size - xm_rand(5 , 15)); //galhos da direita
    tree(xf, yf, ang + 60, size - xm_rand(5 , 15)); //galhos da esquerda
    tree(xf, yf, ang + 30, size - xm_rand(5 , 15));
    tree(xf, yf, ang - 60, size - xm_rand(5 , 15));

  }
    







int main(){

    int largura = 600, altura = 600;

    x_open(largura, altura);

    x_clear(BLACK);

    float ang = 90;

    int x = largura/2;

    int y = altura - 10;

    float size = 80;

    tree(x, y, ang, size);






}
