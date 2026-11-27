#include <stdio.h>
#include <stdlib.h>


// ============================ APARTADO .A) ============================
// constantes
#define MAX 5

typedef struct{
    int data[MAX];
    int top;
}StackVector;

// inicializamos la cima del vector de pila en -1
void initStack(StackVector *s){
    s -> top = -1;
}

// devuelve 1/true si el stack esta vacio (su cima es igual a -1) y 0/false si no
int isEmpty(const StackVector *s){
    return s -> top == -1;
}

// devuelve 1/True si el stack esta lleno (su cima es igual al maximo y el -1 es porque va desde 0, por lo que si la cima esta en la posicion 4 ya hay 5 elementos) y 0/false si no
int isFull(const StackVector *s){
    return s -> top == MAX - 1;
}

// funcion de traza
void stackError(const char *estado)
{
    printf("Pila %s. No se puede realizar la operacion\n", estado);
}


//devuelve 0/false si el stack esta lleno indicando que no se ha podido realizar la operacion. devuelve 1 si la operacion se realizo correctamente
int push(StackVector *s, int value){
    if(isFull(s)){
        stackError("llena");
        return 0;
    }
    s -> top++;
    s -> data[s->top] = value;
    return 1;
}


int pop(StackVector *s, int *popped){
    if(isEmpty(s)){
        stackError("vacia");
        return 0;
    }
    *popped = s -> data[s->top] ;
    s -> top--;
    return 1;
}


int peek(const StackVector *s, int *topValue){
     if(isEmpty(s)){
        stackError("vacia");
        return 0;
    }
    *topValue = s -> data[s->top];
    return 1;
}

int size(const StackVector *s){
    return s->top + 1;
}

int clearStack(StackVector *s){
    s->top = -1;
    return 1;
}