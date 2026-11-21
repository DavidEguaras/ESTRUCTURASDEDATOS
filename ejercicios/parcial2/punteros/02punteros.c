/*
Ejercicio 2 (medio)
Escribe una función intercambiar que reciba dos enteros y los intercambie de forma que el cambio se vea en el main. 
Después escribe una función estadisticas que reciba un vector de enteros y su tamaño y devuelva por parámetros (sin return)  el mínimo, el máximo y la media. 
En el main, prueba las dos funciones con un vector de 5 números que pidas por teclado con scanf y muestra los resultados.
*/


#include <stdio.h>

void swapTwoIntValues(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void arrayStatistics(int vector[], int n, int *max, int *min, float *avg){
    *max = vector[0];
    *min = vector[0];
    *avg = 0;

    for (int i = 0; i < n; i++){
        if(vector[i] > *max){
            *max = vector[i];
        }
        else if(vector[i] < *min){
            *min = vector[i];
        }
        *avg += vector[i];
    }

    *avg = *avg / n;
}

int main(){
    int a = 5;
    int b = 10;

    printf("Antes:   a=%d b=%d\n", a, b);
    swapTwoIntValues(&a, &b);
    printf("Despues: a=%d b=%d\n", a, b);

    int vector[5];
    int n = sizeof(vector) / sizeof(vector[0]);
    int max;
    int min;
    float avg;

    for (int i = 0; i < n; i++){
        printf("Introduce el numero %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    arrayStatistics(vector, n, &max, &min, &avg);

    printf("max=%d min=%d media=%.2f\n", max, min, avg);

    return 0;
}