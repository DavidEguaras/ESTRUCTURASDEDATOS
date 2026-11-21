/*
Ejercicio 3 (difícil)
Define un nodo de lista enlazada que guarde un entero. Escribe estas funciones, todas recibiendo la cabeza de la lista como Node **:

insertarInicio: añade un valor al principio.
insertarFinal: añade un valor al final.
borrarPrimero: quita el primer nodo, devuelve su dato por un parámetro y libera la memoria. Debe indicar si la lista estaba vacía.
liberarLista: libera todos los nodos y deja la cabeza a NULL.

En el main: crea una lista vacía, inserta 3 y 8 al principio y 1 al final, muéstrala, borra el primero, vuelve a mostrarla y libérala.
*/


#include <stdio.h>


insertarInicio();
insertarFinal();
borrarPrimero();
borrarFinal();



typedef struct Node
{
    int dato;
    struct Node *sig;
}Node;





int main (){


    return 0;
}