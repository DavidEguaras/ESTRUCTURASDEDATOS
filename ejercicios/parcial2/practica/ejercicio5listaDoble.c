#include <stdio.h>
#include <stdlib.h>


typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
}DNode;

typedef struct{
    DNode *head;
    DNode *tail;
}DoublyLinkedList;


void initList (DoublyLinkedList *list){
    list->head = NULL;
    list->tail = NULL;
}


int append( DoublyLinkedList *list, int value){
    DNode *newNode = malloc(sizeof(DNode));
    if(newNode == NULL) return 0;

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if(list->head == NULL){
        list->head = newNode;
    }else{
        list->tail->next = newNode;
    }

    list->tail = newNode;

    return 1;
}


int pushFront (DoublyLinkedList *list, int value){
    DNode *newNode = malloc(sizeof(DNode));
    if (newNode == NULL) return 0;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = list->head;
    
    if(list->head == NULL){
        list->tail = newNode;
    }else{
        list->head->prev = newNode;
    }

    list->head = newNode;
    return 1;
}


int insertBefore(DoublyLinkedList *list, DNode *node, int value){
    if(node == NULL)return 0;
    
    DNode *newNode = malloc(sizeof(DNode));
    if (newNode == NULL) return 0;

    newNode->data = value;
    newNode->next = node;
    newNode->prev = node->prev;

    if(node->prev != NULL){
        node->prev->next = newNode;
    }else{
        list->head = newNode;
    }

    node->prev = newNode;
    return 1;
}


int removeNode (DoublyLinkedList *list, DNode *node){
    if(node == NULL) return 0;

    if (node->prev!=NULL){
        node->prev->next = node->next;
    }else{
        list->head = node->next;
    }

    if(node->next != NULL){
        node->next->prev = node->prev;
    }else{
        list->tail = node->prev;
    }
    free(node);
    return 1;
}


void printForward (const DoublyLinkedList *list){
    DNode *actual = list->head;
    while (actual != NULL)
    {
        printf("%d", actual->data);
        actual = actual->next;
    }  
}


//====================================== parte b lista doble circular ======================================


typedef struct
{
    DNode *head;
    DNode *tail;

}CircularDoublyList;


void initCircular(CircularDoublyList *list){
    list->head = list->tail = NULL;
}

int appendCircular(CircularDoublyList *list, int value){
    DNode *newNode = malloc(sizeof(DNode));
    if(newNode == NULL) return 0;

    newNode->data = value;
    if(list->head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
        list->tail = newNode;
    }else{
        newNode->prev = list->tail;
        newNode->next = list->head;
        list->tail->next = newNode;
        list->head->prev = newNode;
        list->tail = newNode;
    }
    return 1;

}

void mostrarCircular (const CircularDoublyList *list){
 
    if(list->head == NULL){
        printf("Vacia");
    }else{
        DNode *actual = list->head;
        do
        {
            printf("%d", actual->data);
            actual = actual->next;
        } while (actual != list->head);   
    }
}


int removeCircular (CircularDoublyList *list, DNode *node){
    if(node == NULL || list->head == NULL) return 0;

    if(list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    }else{
        node->prev->next = node->next;
        node->next->prev = node->prev;

        if(node == list->head){
            list->head = node->next;
        }

        if(node == list->tail){
            list->tail = node->prev;
        }
        free(node);
        return 1;
    }
}


void clearCircular (CircularDoublyList *list){
    while(list->head != NULL){
        removeCircular(list, list->head);
    }
}