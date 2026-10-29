#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void mostrar_vector(const int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4d", v[i]);
    }
    printf("\n");
}

void insercion_directa(int v[], int n, int *comp, int *desp)
{
    *comp = 0; // contador de comparaciones, empieza en 0
    *desp = 0; // contador de desplazamientos, empieza en 0

    // i = el número que toca colocar en esta vuelta.
    // Empieza en 1 porque el primero (posición 0), él solo, ya está "ordenado"
    for (int i = 1; i < n; i++)
    {

        int aux = v[i]; // guardo el número a colocar: su casilla se va a pisar
        int j = i;      // j = el HUECO; empieza donde estaba ese número
        int seguir = 1; // 1 mientras haya que seguir moviendo el hueco
        // Mientras no llegue al principio (j > 0) y tenga que seguir...
        // j > 0 va primero: así nunca se lee v[-1]
        while (j > 0 && seguir)
        {
            (*comp)++; // cuento una comparación
            if (v[j - 1] > aux)
            {                    // ¿el de la izquierda del hueco es mayor?
                v[j] = v[j - 1]; // sí: lo paso una casilla a la derecha
                // traza
                int traza = v[j];

                j--;       // y el hueco se mueve una a la izquierda
                (*desp)++; // cuento un desplazamiento
            }
            else
            {
                seguir = 0; // no: ya he encontrado el sitio, paro
            }
        }

        v[j] = aux; // meto el número guardado en el hueco

        printf("i=%d:   ", i);
        mostrar_vector(v, n); // vector después de esta vuelta
    }
}

void mostrar_vector_f(const float v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", v[i]);
    }
    printf("\n");
}

int main(void)
{
    int v[8] = {15, 18, 7, 75, 14, 13, 43, 40};
    int comp, desp;

    printf("inicio: ");
    mostrar_vector(v, 8);
    insercion_directa(v, 8, &comp, &desp);
    printf("Comparaciones: %d  Desplazamientos: %d\n", comp, desp);
    return 0;
}