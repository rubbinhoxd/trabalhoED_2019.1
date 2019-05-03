#include <stdio.h>
#include <stdbool.h>

const int MORTO = 0;

int andarLado(int vet[], int esc, int size){
	int pos = esc;
	int casas;
	
	if(vet[esc] >0){
		casas = vet[esc];
	}
	else{
		casas = vet[esc] * (-1);
	}
	while(casas > 0){
		if(vet[esc] > 0){
			pos = (pos+1) % size;
		}
		else{
			if(pos == 0){
				pos = size - 1;
			}
			else{
				pos--;
			}
		}
		if(vet[pos] != 0){
			casas--;
		}
	}
	return pos;
}



int achar_vivo(int vet[], int size, int esc){
	
	int pos = esc;
	
	if(vet[pos] > 0){
		pos = (pos+1) % size;
	}
	else{
		if(pos == 0){
			pos = size - 1;
		}
		else{
			pos--;
		}
	}
	
	while(vet[pos] == 0){
		if(vet[esc] > 0){
			pos = (pos+1) % size;
		}
		else{
			if(pos == 0){
				pos = size - 1;
			}
			else{
				pos--;
			}
		}
	}
	return pos;
}


void mostrar_vetor(int vet[], int size){
	
	int i;
	
	bool eh_o_primeiro = true;
	
	printf("[");
	
	for(i=0;i<size;i++){
		if(vet[i] != MORTO){
			if(eh_o_primeiro)
				eh_o_primeiro = false;
			else
				printf(" ");
			printf("%d", vet[i]);
		}
	}
	printf("]\n");
	
}

int main(){
	
	int size = 0;
	int i;
	int esc = 0; //o escolhido
	int sinal = 0; //sinal do primeiro elemento
		
	scanf("%d", &size);
	scanf("%d", &sinal);
	scanf("%d", &esc);
	
	int vet[size];

    vet[0] = sinal;
	
	for(i=1;i<size;i++){
		if(vet[i-1] <0){
			vet[i] = (-vet[i-1] + 1);
		}
		else{
			vet[i] = (vet[i-1] + 1) * (-1);
		}
	}
	
	esc = esc - 1;//pra nao ter que escolher o indice
	
	mostrar_vetor(vet, size);
	
	int qtd = size - 1;
	printf("\n");
	
	while(qtd--){
		int vai_morrer = achar_vivo(vet, size, esc);
		vet[vai_morrer] = 0;
        esc = andarLado(vet, esc, size);
        mostrar_vetor(vet, size);
	}		
	return 0;
}
