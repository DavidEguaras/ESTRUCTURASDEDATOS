/*
 * Listas enlazadas en C - makigas, "Estructuras de datos 3"
 * Todo en un solo archivo. Compilar: gcc -Wall -o listas listas.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Libro ---------- */
typedef struct Libro {
    char titulo[50];
    char autor[50];
    char isbn[13];
} Libro;

/* ---------- Estructuras de la lista ---------- */
typedef struct Nodo {
    Libro libro;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
    Nodo* cabeza;
    int longitud;
} Lista;

void InsertarPrincipio(Lista* lista, Libro* libro);
void InsertarFinal(Lista* lista, Libro* libro);
void InsertarDespues(int n, Lista* lista, Libro* libro);
Libro* Obtener(int n, Lista* lista);
int Contar(Lista* lista);
int EstaVacia(Lista* lista);
void EliminarPrincipio(Lista* lista);
void EliminarUltimo(Lista* lista);
void EliminarElemento(int n, Lista* lista);

/* ---------- Operaciones ---------- */
Nodo* CrearNodo(Libro* libro) {
    Nodo* nodo = (Nodo *) malloc(sizeof (Nodo));
    strncpy(nodo->libro.titulo, libro->titulo, 50);
    strncpy(nodo->libro.autor, libro->autor, 50);
    strncpy(nodo->libro.isbn, libro->isbn, 13);
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo) {
    free(nodo);
}

void InsertarPrincipio(Lista* lista, Libro* libro) {
    Nodo* nodo = CrearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void InsertarFinal(Lista* lista, Libro* libro) {
    Nodo* nodo = CrearNodo(libro);
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
    } else {
        Nodo* puntero = lista->cabeza;
        while (puntero->siguiente) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

void InsertarDespues(int n, Lista* lista, Libro* libro) {
    Nodo* nodo = CrearNodo(libro);
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
    } else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

Libro* Obtener(int n, Lista* lista) {
    if (lista->cabeza == NULL) {
        return NULL;
    } else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        if (posicion != n) {
            return NULL;
        } else {
            return &puntero->libro;
        }
    }
}

int Contar(Lista* lista) {
    return lista->longitud;
}

int EstaVacia(Lista* lista) {
    return lista->cabeza == NULL;
}

void EliminarPrincipio(Lista* lista) {
    if (lista->cabeza) {
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(eliminado);
        lista->longitud--;
    }
}

void EliminarUltimo(Lista* lista) {
    if (lista->cabeza) {
        if (lista->cabeza->siguiente) {
            Nodo* puntero = lista->cabeza;
            while (puntero->siguiente->siguiente) {
                puntero = puntero->siguiente;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}

void EliminarElemento(int n, Lista* lista) {
    if (lista->cabeza) {
        if (n == 0) {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else if (n < lista->longitud) {
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while (posicion < (n - 1)) {
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}

/* ---------- Programa de prueba (no aparece en el video) ---------- */
int main(void) {
    Lista lista = { NULL, 0 };   /* importante: inicializar la lista */

    Libro a = { "El Quijote", "Cervantes", "111" };
    Libro b = { "La Celestina", "Fernando de Rojas", "222" };
    Libro c = { "Lazarillo de Tormes", "Anonimo", "333" };

    InsertarFinal(&lista, &a);
    InsertarPrincipio(&lista, &b);
    InsertarDespues(0, &lista, &c);   /* b, c, a */

    for (int i = 0; i < Contar(&lista); i++)
        printf("%d: %s\n", i, Obtener(i, &lista)->titulo);

    EliminarElemento(1, &lista);
    EliminarUltimo(&lista);
    EliminarPrincipio(&lista);
    printf("Vacia: %d\n", EstaVacia(&lista));
    return 0;
}
