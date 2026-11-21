#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void generar_vector(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100 + 1;
    }
}

void mostrar_vector(const int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

/* inserción directa en el sentido indicado */
void ordenar(int v[], int n, int ascendente)
{
    for (int i = 1; i < n; i++)
    {
        int aux = v[i];
        int j = i;
        while (j > 0 && (ascendente ? v[j - 1] > aux : v[j - 1] < aux))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }
}

/* binaria para los dos sentidos: en descendente se invierte el recorte */
int busqueda_binaria(const int v[], int n, int x, int ascendente)
{
    int izq = 0;
    int der = n - 1;
    int cen = (izq + der) / 2;

    while (v[cen] != x && izq < der)
    {
        if (ascendente ? v[cen] > x : v[cen] < x)
        {
            der = cen - 1;
        }
        else
        {
            izq = cen + 1;
        }
        cen = (izq + der) / 2;
    }
    if (v[cen] == x)
    {
        return cen;
    }
    return -1;
}

int main(void)
{
    int v[TAM];
    int asc, x;

    srand((unsigned)time(NULL));
    generar_vector(v, TAM);
    /* para probar sin aleatorios, usa en su lugar:
       int v[TAM] = {42, 7, 30, 3, 50, 18, 25, 12, 34, 21}; */

    printf("Vector generado: ");
    mostrar_vector(v, TAM);

    printf("Orden (1 = menor a mayor, 0 = mayor a menor): ");
    scanf("%d", &asc);
    ordenar(v, TAM, asc);
    printf("Vector ordenado: ");
    mostrar_vector(v, TAM);

    printf("Valor a buscar: ");
    scanf("%d", &x);
    int pos = busqueda_binaria(v, TAM, x, asc);
    if (pos != -1)
    {
        printf("%d esta en la posicion %d\n", x, pos);
    }
    else
    {
        printf("%d no esta en el vector\n", x);
    }
    return 0;
}