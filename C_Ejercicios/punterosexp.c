#include <stdio.h>
#include <stdbool.h>



void swap(int *a, int *b);

int main(void){

    int x = 10;
    int y = 20;

    swap(&x, &y);

    printf("x: %d, y: %d", x, y);
    return 0;
}

//& -> direccion de memoria de
//int *a -> declaramos un puntero que se llama a que apuntara a una direccion de memoria de tipo entero
//*a -> es el valor de la variable almacenada en la direccion de memoria del puntero
//a -> direccion de memoria


void swap(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
