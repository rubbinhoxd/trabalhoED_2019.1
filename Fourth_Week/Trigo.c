#include <stdio.h>
#include <stdlib.h>
#include "xpaint.h"


void trigo(int x, int y, float ang, int size){
    if(size < 1){
        return;
    }

    //int xf = x + size * xm_cos(ang);
    //int yf = y - size * xm_sin(ang);
    xs_color((XColor){xm_rand(0 , 255), xm_rand(0 , 255), xm_rand(0 , 255)});
    //xd_thick_line(x, y, xf, yf, 3);
    //  x_step("trigo");
    
    int x1 = x;
    
    int y1 = y;

    for(int i = 0; i < 4; i++){
   

            int yfinal = y1 - size * xm_sin(ang);
	    
	    int xfinal = x1 + size * xm_cos(ang);
        
            xd_thick_line(x, y, xfinal, yfinal, 5);
        
            trigo(xfinal, yfinal, ang - 45, size/3); //galhos da esquerda
        
            trigo(xfinal, yfinal, ang + 45, size/3); //galhos da direita
        
            x1 = xfinal;
        
            y1 = yfinal;
            //trigo(xf, yf, ang, size - xm_rand(5 , 15));
            x_step("trigo");
    }

}

int main(){
	

int largura = 800, altura = 800;

    x_open(largura, altura);

    x_clear(BLACK);

    float ang = 90;

    int x = largura/2;

    int y = altura - 5;

    float size = 140;

    trigo(x, y, ang, size);

    x_save("Trigo");

    x_close();



}
