#include <stdio.h>



void show(int vet[], int size){

  printf("[ ");

  for(int i = 0; i < size; i++){
    printf("%d", vet[i]);
    if(i < size - 1){
	printf(" ");
    }
  }
  printf("] ");
}

void bubble_sort(int vet[], int size){
	
  int aux = 0;

  for(int i = 0; i < size - 1; i++){
      for(int j = 0; j < size - 1; j++){
	    if(vet[j] > vet[j+1]){
		aux = vet[j];
		vet[j] = vet[j+1];
		vet[j+1] = aux;
	    }
      }
  }

}

int main(){

  int size = 0;

  printf("Digite o tamanho do seu vetor:\n");

  scanf("%d", &size);

  int vet[size];

  printf("Agora, digite os valores do seu vetor: \n");

  for(int i = 0; i< size; i++){
	scanf("%d", &vet[i]);
  }


  bubble_sort(vet, size);

  show(vet, size);

  printf("\n");

  return 0;
}
