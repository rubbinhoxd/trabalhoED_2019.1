#include <stdio.h>
#include <stdlib.h>
#include "xpaint.h"


void ball(int x, int  y, int raio){
  
    xs_color((XColor){xm_rand(0, 50), xm_rand(0, 50), xm_rand(0, 255)});
   	
   	int ang = 0;
    
    if(raio < 1){
        return;
    }
    
    for(int i =  0; i < 6; i++){
        
        xd_circle(x, y, raio);

        int xfinal = x + raio * xm_cos(ang);

       	int yfinal = y - raio * xm_sin(ang);

        xd_circle(xfinal, yfinal, raio/3);

        ball(xfinal, yfinal, raio/3);
        
        ang = ang + 60;

        //x_step("circulo");

    }
}

int main(){
    int largura = 800, comprimento = 800;
    
    x_open(largura, comprimento);

    int x = largura / 2;

    int y = comprimento / 2;
    
    
    x_clear(BLACK);

    ball(x, y, 200);

    x_save("Circulo");
    
    x_close();

    return 0;
}
