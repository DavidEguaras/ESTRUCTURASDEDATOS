/*Ejercicio 1 (fácil)
Escribe un programa con dos enteros, a = 5 y b = 10, y dos punteros, p y q, que apunten a a y a b respectivamente.
Usando solo los punteros (sin escribir a ni b en las operaciones):

Suma a a el valor de b.
Haz que p apunte también a b.
Pon un 3 en la variable a la que apunta p.
Duplica el valor de la variable a la que apunta q.
*/

#include <stdio.h>



int main(){
    int a = 5;
    int b = 10;
    int *p = &a;
    int *q = &b;
    printf("a=%d b=%d\n", a, b);
    printf("a=%d b=%d p=%d q=%d\n", a, b, p, q);


    *p += *q;
    printf("a=%d b=%d\n", a, b);
    p = &b;
    printf("*p=%d\n", *p);
    *p = 3;
    printf("a=%d b=%d\n", a, b);

    *q = 2 * *q;
    printf("a=%d b=%d *p=%d *q=%d\n", a, b, *p, *q);


    return 0;
}
