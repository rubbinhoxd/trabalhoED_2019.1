#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



#define pega_vizinhos(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}


typedef struct{

	int l;
	int c;

} Pos;

/*typedef struct{

	Pos vet[4];

	
} Neibs;
*/


void embaralha(Pos vet[], int size){
	
	for(int i = 0; i < size; i++){
		int pos = rand() % size;
		Pos aux = vet[i];
		vet[i] = vet[pos];
		vet[pos] = aux;
	}
}


bool equals(int nl, int nc, char mat [nl][nc], int l, int c, char value){
	if((l < 0) || (l >= nl) || (c <0) || (c >= nc)){
		return false;
	}
	
	return mat[l][c] == value;
}




bool eh_furavel(int nl, int nc, char mat [nl][nc], int l, int c){

	if(!equals(nl, nc, mat, l, c, '#')){
		return false;
	}

	int cont = 0;

	Pos neibs[] = pega_vizinhos(l, c);

	for(int i = 0; i < 4; i++){
		if(equals(nl, nc, mat, neibs[i].l, neibs[i].c, '#')){
			cont++;
		}
	}

	if(cont < 3 ){
		return false;
	}


	return true;


}
			



	

void furar(int nl, int nc, char mat [nl][nc], int l, int c){

	if(!eh_furavel(nl, nc, mat, l, c)){
		return;
	}	
	mat[l][c] = ' ';

	Pos neibs[] = pega_vizinhos(l, c);
	
	embaralha(neibs, 4);

	for(int i = 0; i < 4 ; i++){
		furar(nl, nc, mat, neibs[i].l, neibs[i].c);
	}
}

void mostrar(int nl, int nc, char mat[nl][nc]){

	for(int l = 0; l < nl; l++){
		for(int c = 0; c < nc; c++){
			if(mat[l][c] == '#'){
				printf("█");
			}
			else{
				printf("%c", mat[l][c]);
			}
		}	
		printf("\n");
	}
		
}
	//printf(" ");

bool procurar_saida(int nl, int nc, char mat[nl][nc], bool mat2[nl][nc], int l, int c, int lsaida, int csaida){
	if(!equals(nl, nc, mat, l, c, ' '))
        return false;
    if(mat[l][c] != ' ')
        return false;
    if(mat[l][c] == true)
        return false;
    mat2[l][c] = true;
    mat[l][c] = '.';
    if(l == lsaida && c == csaida)
        return true;
    if((procurar_saida(nl,nc,mat,mat2,l+1,c,lsaida,csaida))||(procurar_saida(nl,nc,mat,mat2,l-1,c,lsaida,csaida))||
    	(procurar_saida(nl,nc,mat,mat2,l,c-1,lsaida,csaida))||(procurar_saida(nl,nc,mat,mat2,l,c+1,lsaida,csaida)))
        return true;
    mat[l][c] = ' ';
        return false;
}




int main(int argc, char * argv[]){
	
	srand(time(NULL));

	int nl = 0;
	
	int nc = 0;

	scanf("%d %d", &nl, &nc);

	if(argc > 2){
		nl = atoi(argv[1]);
		nc = atoi(argv[2]);
	}
	
	char mat[nl][nc];
	bool mat2[nl][nc];

	//char *p = &mat[nl][nc];

	for(int i = 0; i< nl; i++){
		for(int j = 0; j < nc; j++){
			mat[i][j] = '#';
		}
	} 

	furar(nl, nc, mat, 1, 1);

	mostrar(nl, nc, mat);

	printf("Digite uma linha e uma coluna para a saida\n");

	int ls, cs;


	scanf("%d %d", &ls, &cs);

	bool achou = procurar_saida(nl, nc, mat, mat2, 1, 1, ls, cs);

	mostrar(nl, nc, mat);

	if(mat2[ls][cs] == 0){
		printf("A posicao nao e valida\n\n");
	}

	return 0;
} 
