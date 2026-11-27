#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int id;
    char owner[30];
    int pages;
}PrintJob;

typedef struct Node{
    PrintJob data;
    struct Node *next;
}Node;

typedef struct{
    // primero en salir
    Node *front;
    // ultimo que ha entrado
    Node *rear;
} Queue;


void initQueue(Queue *q){
    q -> front = NULL;
    q -> rear = NULL;
}

int isEmpty(const Queue *q){
    return q -> front == NULL;
}

// devuelve un node y se le pasa un nuevo elemento como parametro (que se insertara en el nodo devuelto)
Node *createNode(PrintJob job)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("No hay memoria\n");
        return NULL;
    }
    // se establece que el data es igual al elemento y que el next es null ya que siempre que creemos un node sera el ultimo
    newNode->data = job;
    newNode->next = NULL;
    return newNode;
}

int enqueue(Queue *q, PrintJob job){
    //creamos un nuevo nodo a partir del elemento
    Node *newNode = createNode(job); 
    if (newNode == NULL){
        return 0; 
    }         
    // si la cola esta vacia ponemos que el nuevo nodo es la salida de la cola (el proximo en salir, el primero de la cola)
    if (isEmpty(q)) {
        q->front = newNode;    
    // si la cola no esta vacia ponemos que el siguiente de la entrada de la cola sea el nuevo nodo (es decir, que el siguiente del actual ultimo de la cola sera el nuevo nodo introducido)
    } else {
        q->rear->next = newNode;   
    }
    // hacemos que el ultimo de la cola/ entrada de la cola sea el nuevo nodo introducido
    q->rear = newNode;             
    return 1;
}


int dequeue (Queue *q, PrintJob *job){
    if(isEmpty(q)){
        return 0;
    }

    // copiamos el dato del que esta primero actualmente (el elemento que vamos a desencolar) en la variable del main a la que apunta job
    *job = q->front->data;

    // creamos un puntero auxiliar/temporal en el que apunta al Nodo que esta primero en la cola ahora mismo
    Node *temp = q->front;

    // hacemos que el primero de cola pase a ser el siguiente del primero (el que estaba segundo). para esto hemos creado la varible temporal
    q->front = q->front->next;

    // caso especial: al desencolar se ha desencolado el ultimo elemento de la lista (el siguiente elemento era null)
    if(q->front == NULL){
        /*
            rear que es la cola no se ha actualizado por como son las colas (hemos tocado el front pero el rear no tenia porque actulizarse).
            En este caso rear seguiria apuntando al nodo desencolado (ya que en este caso rear y front habrian estado apuntando al mismo elemento)
            asi que para evitar errores hacemos que rear sea null tambien
            */ 
        q->rear = NULL;
    }
    free(temp);
    return 1;
}


/*usamos un puntero porque en el pseudo nos dicen que TRANSFORMA + LUEGO PONE ELEMENTO ← SALIDA↑.DATO. 
job es elemento asi que job debe ser una direccion de variable del main (un puntero) donde se guarde el dato del elemento que se vea en peek */     
int peek(const Queue *q, PrintJob *job){
    if(isEmpty(q)){
        return 0;
    }
    *job = q -> front -> data;
    return 1;
}

// no hay ningun parametro que diga transforma por lo que el dato no puede salir de un puntero, hay que hacerlo con el return, en este caso de un entero
int size (const Queue *q){
    int n = 0;

    // puntero auxiliar que apuntara al nodo de la iteracion en la que estemos en ese momento para recorrer la cola
    Node *actual = q -> front;

    // mientras el elemento actual no sea nulo:
    while(actual != NULL){
        n++;
        // hacemos que actual sea igual al siguiente
        actual = actual->next;
    }
    return n;
}


int contains(const Queue *q, int id){
    Node *actual = q -> front;
    while(actual != NULL && actual -> data.id != id){
        actual = actual->next;
    }
    // si encuentra un elemento que sea igual el bucle hara que actual se quede con ese valor y por lo tanto sea distinto de nulo, por lo que esta condicion devolveria true -> queue contiene el elemento
    // si no lo encuentra actual no se pararia hasta llega al siguiente de rear que es null y por tanto esta condicion devolveria false -> queue no contiene el elemento
    return actual != NULL;
}


int totalPages (const Queue *q){
    int total = 0;
    Node *actual = q -> front;
    while(actual != NULL){
        total += actual->data.pages;
        actual = actual->next;
    }
    return total;
}


int bigJobs (const Queue *q, int minimo){
    int n = 0;
    Node *actual = q -> front;
    while(actual != NULL){
        if(actual->data.pages >= minimo){
            n++;
        }
        actual = actual->next;
    }

    return n;
}


void clearQueue (Queue *q){
    // el unico proposito de esta variable es que dequeue pueda almacenar el nodo que se saca en algun sitio
    PrintJob job;
    while (dequeue(q, &job));
}