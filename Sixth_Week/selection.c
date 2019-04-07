#include <stdio.h>

int show(int vet[], int size){

	printf("[ ");

	for(int i = 0; i < size; i++){
		printf("%d", vet[i]);
		if(i < size - 1){
			printf(" ");
		}
	}

	printf("] ");

}

void selection_sort(int vet[], int size) { 
  
	int aux = 0;

  	for (int i = 0; i < (size-1); i++){ 
  
     	int min = i;

    	for (int j = (i+1); j < size; j++) {
       		if(vet[j] < vet[min]) 
         		min = j;
    }
     	if (vet[i] != vet[min]) {
       		aux = vet[i];

       		vet[i] = vet[min];

       		vet[min] = aux;
     	}

  }

}


int main(){
	
	int size = 0;

	printf("Digite o tamanho do seu vetor:\n");

	scanf("%d", &size);

	int vet[size];

	printf("Agora, digite os valores do seu vetor: \n");

	for(int i = 0; i < size; i++){
		scanf("%d", &vet[i]);
	}

	selection_sort(vet, size);

	show(vet, size);



	return 0;
}
