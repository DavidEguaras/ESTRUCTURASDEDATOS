#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int codigo;
    char descripcion[40];
    float precio;

} Producto;


typedef struct Node
{
    Producto data;
    struct Node *next;

}Node;

typedef struct 
{
    Node *head;

}LinkedList;


void initList(LinkedList *list){
    list -> head = NULL;
}

int isEmpty(const LinkedList *list){
    if(list->head == NULL){
        return 1;
    }
    return 0;
}

// metemos un elemento, en este caso producto al principio de la lista
int pushFront(Producto product, LinkedList *list){
    Node *newNode  = malloc(sizeof(Node));
    if (newNode  == NULL){
        return 0;
    }
    newNode ->data = product;
    newNode ->next = list->head;
    list->head = newNode ;
    return 1;
}

// metememos un elemento al final de la lista
int append(Producto product, LinkedList *list){
    Node *newNode  = malloc(sizeof(Node));
    if (newNode  == NULL){
        return 0;
    }

    // el elemento que ha sido pasado como parametro se copia en el data del nuevo nodo
    newNode ->data = product;
    newNode ->next = NULL;
    
    // si la lista estaba vacia la cabeza de la lista pasa a ser el nuevo nodo
    if(isEmpty(list)){
        list->head = newNode ;
        return 1;
    }

    // si no recorremos la lista hasta que el siguiente elemento no exista (se null), y metemos el newNode en esa posicion (en el next del actual)
    Node *actual = list->head;
    while (actual->next != NULL)
    {
        actual = actual->next;
    }
    actual->next = newNode;

    return 1;
}


Node* find(LinkedList *list, int codigo){
    Node *actual = list->head;
    while (actual != NULL && actual->data.codigo != codigo){
        if(actual->data.codigo == codigo){
            return actual;
        }
        actual = actual->next;
    }
    return NULL;
}


int insertAfter(Node *node, Producto product){

    if(node == NULL){
        return 0;
    }

    Node *newNode =  malloc(sizeof(Node));
    if (newNode == NULL){
        return 0;
    }
    newNode->data = product;
    newNode->next = node->next;
    node->next = newNode;
    return 1;
}


int popFront(Producto *product, LinkedList *list){
    Node *aux = list->head;

    if(isEmpty(list)) return 0;

    *product = aux->data;
    list->head = aux->next;

    free(aux);
    return 1;
}


int removeCodigo (LinkedList *list, int codigo){
    if(isEmpty(list)) return 0;
    if(list->head->data.codigo == codigo){
        Producto removed;
        return popFront(list, &removed);
    }
    Node *previo = list->head;
    Node *actual = list->head->next;

    while ((actual != NULL) && (actual->data.codigo != codigo))
    {
        previo = actual;
        actual = actual->next;        
    }
    if(actual == NULL){
        return 0;
    }else{
        previo->next = actual->next;
        free(actual);
        return 1;
    }

}