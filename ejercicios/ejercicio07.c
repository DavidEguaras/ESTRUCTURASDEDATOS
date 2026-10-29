#include <stdio.h>
#define TAM 10



int busqueda_binaria(const int v[], int n, int x);



int main (void){
    int v[TAM] = {3, 7, 12, 18, 21, 25, 30, 34, 42, 50};
    int x;
    printf("Introduce el valor que quieres buscar: ");
    scanf("%d", &x);

    int posicionEncontrado = busqueda_binaria(v, TAM, x);
    if(posicionEncontrado != -1){
        printf("Numero encontrado en la posicion: %d \n", posicionEncontrado);
    }else{
        printf("El valor no existe en la lista \n");
    }

    return 0;
}


// v = vector ORDENADO de menor a mayor, n = número de elementos, x = valor a buscar
// Devuelve la posición de x, o -1 si no está
int busqueda_binaria(const int v[], int n, int x){
    int izq = 0;                 // inicio de la zona donde puede estar x
    int der = n - 1;             // final de la zona (última posición válida)
    int cen = (izq + der) / 2;   // posición central de esa zona

    // Repetir mientras el del centro NO sea x
    // y la zona tenga más de un elemento (izq < der)
    while((v[cen] != x ) && (izq < der)){
        if (v[cen] > x){
            // El del centro es MAYOR que x → x solo puede estar a su izquierda
            der = cen - 1;       // descarto el centro y toda la mitad derecha
        }else{
            // El del centro es MENOR que x → x solo puede estar a su derecha
            izq = cen + 1;       // descarto el centro y toda la mitad izquierda
        }
        cen = (izq + der) / 2;   // nuevo centro de la zona que queda
    }

    // Al salir: o lo he encontrado, o la zona se ha quedado en un solo elemento
    if(v[cen] == x){
        return cen;              // encontrado: devuelvo su posición
    }
    return -1;                   // no está en el vector
}
