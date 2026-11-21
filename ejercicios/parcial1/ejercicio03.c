#include <stdio.h>

typedef struct
{
    char nombre[30];
    char dni [10];
    float nota;
}
Alumno;

//Definimos un array de alumnos con capacidad para 20 alumnos. Nuestra "clase"
Alumno clase [20];

//introducir por consola los datos de un alumno
//retorna el alumno que se ha introducido
Alumno leer_alumno(){
    Alumno a;
    printf("Nombre: ");
    scanf(" %29[^\n]", a.nombre);
    printf("DNI: ");
    scanf("%9s", a.dni);
    printf("Nota: ");
    scanf("%f", &a.nota);

    return a;
}

void mostrar_alumno(Alumno a){
    printf("Nombre: %s\n", a.nombre);
    printf("DNI: %s\n", a.dni);
    printf("Nota: %.2f\n", a.nota);
}

float nota_media(Alumno c[], int n){
    float totalNotas = 0;
    float notaMedia = 0;

    for (int i = 0; i < n; i++) {
        totalNotas += c[i].nota;
    }

    notaMedia = totalNotas / n;
    return notaMedia;
}

int mejor_alumno(Alumno c[], int n){
    int mejor = 0;                      // posicion del mejor visto hasta ahora
    for (int i = 1; i < n; i++) {
        if (c[i].nota > c[mejor].nota) {
            mejor = i;
        }
    }
    return mejor;                       // un solo return, despues del bucle
}

int main (void){
    int n;

    printf("Numero de alumnos (maximo 20): ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Numero no valido\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Alumno %d ---\n", i + 1);
        clase[i] = leer_alumno();
    }

    printf("\n===== LISTADO =====\n");
    for (int i = 0; i < n; i++) {
        mostrar_alumno(clase[i]);
        printf("\n");
    }

    printf("Nota media: %.2f\n", nota_media(clase, n));

    int pos = mejor_alumno(clase, n);
    printf("Mejor alumno: %s (%.2f)\n", clase[pos].nombre, clase[pos].nota);

    return 0;
}