void seleccionDirecta(int v[], int n, int *comp, int *inter);


int main (void){


    
    return 0;
}



void seleccionDirecta(int v[], int n, int *comp, int *inter){
    *comp = 0;
    *inter = 0;

    // primer bucle, suponemos que el menor esta en la posicion i
    for(int i = 0; i < n; i++){
        //k es la posicion del menor encontrado entre los elementos
        int k = i;
        int aux = v[i];

        //segundo bucle, recorremos todo el array, su proposito es encontrar el menor elemento de entre los elementos restantes no ordenados
        for(int j = i + 1; j < n; j++){
            //aumenta el numero de comparaciones
            (*comp)++;
            // si el numero que estamos comparando es menor que el que tenemos guardado:
            if(v[j] < aux){
                // anotamos su posicion
                k = j;
                // guardamos el valor como menor actual (aux)
                aux = v[j];
            }
        }
        // al terminar el bucle, en aux estara el valor del menor entre los elementos que faltan
        // y en k estara la posicion de ese valor
        // hacemos que el valor que hay en posicion de la iteracion actual se guarde en la posicion donde estaba el menor
        v[k] = v[i];
        // ahora hacemos que en la posicion de la iteracion actual sea el menor encontrado en el bucle anidado
        v[i] = aux;
        (*inter)++;
    }
}