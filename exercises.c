#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(int i = 1; i <= 10; i++){
     int* x = malloc(sizeof(int));
     *x = i;
     pushFront(L, x);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int sum = 0;
  while(first(L) != NULL){
    sum += *(int*)first(L);
    popFront(L);
  }
   return sum;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
  int* i = first(L);
  while(i != NULL)
    {
      if(*i == elem){
        popCurrent(L);
      }
      i = next(L);
    }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
  Stack* P3 = create_stack();
  void *temp;
  while(top(P1) != NULL){
    temp = top(P1);
    push(P3, temp);
    pop(P1);

  }
  while(top(P3) != NULL)
    {
      temp = top(P3);
      push(P2, temp);
      push(P1, temp);
      pop(P3);
    }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  Stack* stack = create_stack();
    int i = 0;
    void *temp;
    while(cadena[i] != '\0'){
      temp = &cadena[i];
      if(cadena[i] == '('|| cadena[i] == '['|| cadena[i] == '{'){
        push(stack,temp);  

      }else if(cadena[i] == ')'|| cadena[i] == ']'|| cadena[i] == '}'){
        if(stack == NULL) return 1;
        char cierre = top(stack);

        if((cadena[i] == ')' && cierre == '(' ) || (cadena[i] == ']' && cierre == '[') || (cadena[i] == '}' && cierre == '{')){
          pop(stack);
        }else {
            return 0;
        }
        i++;
    }
  }
  if(stack == NULL) return 1;
  else return 0;

}

