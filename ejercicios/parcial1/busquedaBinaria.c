#include <stdio.h>
#define TAM 10
int busqueda_Binaria(int v[], int n, int x);

int main(void) {
    // Declaramos un vector de tamaño 11. 
    // Dejamos el índice 0 vacío (con un 0) para que los elementos 
    // comiencen en la posición 1 tal como espera tu código.
    int v[TAM] = {0, 3, 7, 12, 18, 21, 25, 30, 34, 42, 50};
    int x;

    printf("Vector de prueba: [3, 7, 12, 18, 21, 25, 30, 34, 42, 50]\n");
    printf("Introduce el numero que deseas buscar: ");
    scanf("%d", &x);

    // Llamamos a la función para probarla
    busqueda_Binaria(v, TAM, x);

    return 0;
}


int busqueda_Binaria(int v[], int n, int x){

    int i,izq,der,cen;

    izq= 0;
    der = n-1;
    cen = (izq+der)/2;

    while ((v[cen]!=x) && (izq<der)){
        
        if (v[cen] > x) {
            int traza = v[cen];
            der=cen-1;
        }
        else{
            izq=cen+1;
        }

        cen=(izq+der)/2;
    
    }

    if(v[cen]==x ){
        printf("Se ha encontrado en la posicion %d", cen);
    }
    else{
        printf("No existe el valor buscado");
    }

    }

