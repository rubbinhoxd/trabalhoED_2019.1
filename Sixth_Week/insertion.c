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


void insertion_sort(int vet[], int size) {

    int aux = 0;

    for(int i = 1; i < size; i++) {
       	 int j = i;
        while ( j > 0 && vet[j - 1] > vet[j]) {
            aux = vet[j];

            vet[j] = vet[j - 1];

            vet[j - 1] = aux;

            j--;
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


  insertion_sort(vet, size);

  show(vet, size);
	
  printf("/n");	
  
  return 0;
}
