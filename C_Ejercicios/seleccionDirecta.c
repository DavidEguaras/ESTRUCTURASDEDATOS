void seleccion_directa(int v[], int n, int *comp, int *inter)
{
    *comp = 0;      // contador de comparaciones, empieza en 0
    *inter = 0;     // contador de intercambios, empieza en 0

    // i = la posición que vamos a rellenar en esta vuelta (0, 1, 2...)
    // Hasta n-1 porque, cuando quedan dos, al colocar el penúltimo el último ya queda en su sitio
    for (int i = 0; i < n - 1; i++) {

        // De momento suponemos que el menor es el que está en la posición i
        int k = i;            // k = DÓNDE está el menor encontrado hasta ahora
        int aux = v[i];       // aux = CUÁNTO vale ese menor

        // Recorremos lo que queda a la derecha de i buscando uno más pequeño
        for (int j = i + 1; j < n; j++) {
            (*comp)++;              // contamos una comparación
            if (v[j] < aux) {       // ¿este es más pequeño que el menor que tenía?
                k = j;              // sí: apunto su posición
                aux = v[j];         // y su valor
            }
        }
        // Al salir del bucle: aux = el menor de todos, k = dónde estaba

        // INTERCAMBIO entre la posición i y la posición k:
        v[k] = v[i];    // lo que había en i se va al sitio donde estaba el menor
        v[i] = aux;     // el menor se pone en i (ya es su sitio definitivo)
        (*inter)++;     // contamos un intercambio

        printf("i=%d: ", i);
        mostrar_vector(v, n);   // vector después de esta vuelta
    }
}