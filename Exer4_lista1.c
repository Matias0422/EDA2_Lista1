#include <stdio_ext.h>
#include <stdlib.h>

int * Insert(int vector_numbers_main[],int number,int vector_size){

  int index_aux = 0 , number_aux = 0;

  vector_numbers_main = (int *) realloc(vector_numbers_main, vector_size*sizeof(int));
  vector_numbers_main[vector_size - 1] = number;

  index_aux = vector_size - 1;
  while(vector_numbers_main[index_aux] < vector_numbers_main[index_aux-1] && index_aux != 0){
    number_aux = vector_numbers_main[index_aux-1];
    vector_numbers_main[index_aux-1] = vector_numbers_main[index_aux];
    vector_numbers_main[index_aux] = number_aux;
    index_aux--;
  }

  return vector_numbers_main;
}

void Print(int vector_numbers_main[],int vector_size){
  int i = 0;

  for(i = 0; i < vector_size; i++){
    printf("\n%d\n",vector_numbers_main[i]);
  }

}

int * Realloc_vector_index(int vector_index[],int vector_size,int vector_numbers_main[]){
  int index_aux, i;

  if(vector_size/5 == 0){
    return NULL;
  }
  else{
    vector_index = (int *)realloc(vector_index, (vector_size/5)+1 * sizeof(int));

    index_aux = 4;

    for(i = 0; i < (vector_size/5); i++){
      vector_index[i] = index_aux;
      index_aux = index_aux + 5;
    }

    vector_index[(vector_size/5)+1] = vector_size - 1;

    return vector_index;
  }
}

void Search_number(int vector_numbers_main[],int number,int vector_size,int vector_index[]){
  int i = 0, j = 0, find = 0;

  if(vector_index == NULL){
    while(i < vector_size){
      if(vector_numbers_main[i] == number){
        printf("Numero encontrado na posicao %d",i+1);
        find = 1;
        break;
      }
      i++;
    }
    if(find == 0){
      printf("Numero não encontrado!!!");
    }
  }
  else{
    i = 0;
    while(number > vector_numbers_main[vector_index[i]]){
      i++;
    }

    j = vector_index[i];

    while(number < vector_numbers_main[j]){
      j--;
    }

    if(number == vector_numbers_main[j]){
      printf("Numero encontrado na posicao %d",j+1);
    }
    else{
      printf("Numero nao encontrado!!!");
    }
  }
}

int * Remove(int vector_numbers_main[], int number, int * vector_size,int vector_index[]){
  int i = 0, j = 0, find = 0,vector_aux = 0,x = 0;

  if(vector_index == NULL){
    while(i < *vector_size){
      if(vector_numbers_main[i] == number){
        x = i;
        while(x < *vector_size - 1){
          vector_aux = vector_numbers_main[x];
          vector_numbers_main[x] = vector_numbers_main[x + 1];
          vector_numbers_main[x + 1] = vector_aux;
          x++;
        }
        find = 1;
        break;
      }
      i++;
    }
    if(find == 0){
      printf("Numero não encontrado!!!");
    }
    else{
      printf("Numero removido!!!");
      *vector_size = *vector_size - 1;
      vector_numbers_main = (int*)realloc(vector_numbers_main,(*vector_size)*sizeof(int));
    }
  }
  else{
    i = 0;
    while(number > vector_numbers_main[vector_index[i]]){
      i++;
    }

    j = vector_index[i];

    while(number < vector_numbers_main[j]){
      j--;
    }

    if(number == vector_numbers_main[j]){
      while(j < *vector_size - 1){
        vector_aux = vector_numbers_main[j];
        vector_numbers_main[j] = vector_numbers_main[j + 1];
        vector_numbers_main[j + 1] = vector_aux;
        j++;
      }
      printf("Numero removido!!!");
      *vector_size = *vector_size - 1;
      vector_numbers_main = (int*)realloc(vector_numbers_main,(*vector_size)*sizeof(int));
    }
    else{
      printf("Numero nao encontrado!!!");
    }
    return vector_numbers_main;
  }
}

int main(){

  int *vector_numbers_main = NULL;
  int *vector_index = NULL;
  int vector_size = 0;
  int number;
  int choice;
  int index_aux = 0, i = 0;

  while(1){

    printf("\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - Buscar\n");

    __fpurge(stdin);
    scanf("%d",&choice);

    switch (choice) {
      case 1:
        system("clear");
        printf("\nNumero a ser inserido: ");
        __fpurge(stdin);
        scanf("%d",&number);
        vector_size++;
        vector_numbers_main = Insert(vector_numbers_main,number,vector_size);
        vector_index = Realloc_vector_index(vector_index,vector_size,vector_numbers_main);
        break;
      case 2:
        system("clear");
        printf("\nNumero a ser removido: ");
        __fpurge(stdin);
        scanf("%d",&number);
        vector_numbers_main = Remove(vector_numbers_main,number,&vector_size,vector_index);
        vector_index = Realloc_vector_index(vector_index,vector_size,vector_numbers_main);
        break;
      case 3:
        system("clear");
        Print(vector_numbers_main,vector_size);
        break;
      case 4:
        system("clear");
        printf("\nNumero a ser procurado: ");
        __fpurge(stdin);
        scanf("%d",&number);
        Search_number(vector_numbers_main,number,vector_size,vector_index);
        break;
    }
  }
  return 0;
}
