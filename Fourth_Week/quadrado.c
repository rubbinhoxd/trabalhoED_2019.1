#include <stdio.h>
#include <stdlib.h>
#include "xpaint.h"


void quadrado(int x, int y, float ang, int tamanho){
    if(tamanho <= 10){
        return;
    }

    //int xf = x + size * xm_cos(ang);
    //int yf = y - size * xm_sin(ang);
    //xs_color((XColor){xm_rand(0 , 255), xm_rand(0 , 255), xm_rand(0 , 255)});
    //xd_thick_line(x, y, xf, yf, 3);
    //  x_step("trigo");


    
    
    int x1 = x - tamanho * xm_cos(ang);
    
    int y1 = y - tamanho * xm_sin(ang);
    
    int x2 = x + tamanho * xm_cos(ang);
    
    int y2 = y + tamanho * xm_sin(ang);
        
    xd_thick_line(x1, y1, x1, y2, 1);
    
    xd_thick_line(x1, y2, x2, y2, 1);

    xd_thick_line(x2, y2, x2, y1, 1);

    xd_thick_line(x2, y1, x1, y1, 1);


    quadrado(x1, y1, ang, tamanho/2); //galhos da esquerda
        
    quadrado(x2, y1, ang, tamanho/2); //galhos da direita
        
    quadrado(x1, y2, ang, tamanho/2);

    quadrado(x2, y2, ang, tamanho/2);

    //x1 = xfinal;
        
    //y1 = yfinal;
    //trigo(xf, yf, ang, size - xm_rand(5 , 15));
    x_step("quadrado");
    

}

int main(){
	

int largura = 800, altura = 800;

    x_open(largura, altura);

    x_clear(BLACK);

    float ang = 45;

    int x = largura/2;

    int y = altura/2;

    float size = 280;

    quadrado(x, y, ang, size);

    x_save("Quadrado");

    x_close();



}
