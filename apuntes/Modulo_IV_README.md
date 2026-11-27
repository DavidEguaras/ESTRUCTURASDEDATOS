# Módulo IV — Estructuras de Datos No Lineales

> Contenido completo del Módulo IV del curso (Studium · USAL, material de Solórzano), extraído de las páginas HTML del curso.
> Las imágenes/figuras del original no se incluyen: se indican como `[Figura: archivo]`. El pseudocódigo usa `**` como marcador de comentario.

Este módulo presenta las estructuras de datos internas no lineales más comunes: **grafos** y **árboles**.

## Índice

- **Tema 7 — Grafos: representación, recorrido y gestión**
  - 7.1 Definición
  - 7.2 Representación: Matriz de adyacencia
  - 7.3 Representación: Listas de adyacencia
  - 7.4 Operaciones con representación matricial
    - 7.4.1 Creación
    - 7.4.2 Añadir arco
    - 7.4.3 Añadir arista
    - 7.4.4 Comprobar vértice
    - 7.4.5 Comprobar arco
    - 7.4.6 Comprobar arista
    - 7.4.7 Eliminar arco
    - 7.4.8 Eliminar arista
  - 7.5 Operaciones con representación mediante listas
    - 7.5.1 Creación
    - 7.5.2 Comprobar vértice
    - 7.5.3 Comprobar arco
    - 7.5.4 Comprobar arista
    - 7.5.5 Añadir vértice
    - 7.5.6 Añadir arco
    - 7.5.7 Añadir arista
    - 7.5.8 Eliminar vértice
    - 7.5.9 Eliminar arco
    - 7.5.10 Eliminar arista
    - 7.5.11 Eliminar listas
  - 7.6 Recorridos
    - 7.6.1 Recorrido en anchura
    - 7.6.2 Recorrido en profundidad
- **Tema 8 — Árboles**
  - 8.1 Definición
  - 8.2 Operaciones básicas
  - 8.3 Representación
    - 8.3.1 Representación vectorial
      - 8.3.1.1 Caso particular (representación vectorial)
    - 8.3.2 Representación con memoria dinámica
  - 8.4 Operaciones en representación vectorial
    - 8.4.1 Creación del árbol
    - 8.4.2 Comprobación de árbol vacío
    - 8.4.3 Comprobación de árbol lleno
    - 8.4.4 Inserción de un nodo
    - 8.4.5 Eliminación de un nodo
    - 8.4.6 Modificación del valor de un nodo
  - 8.5 Operaciones en representación con memoria dinámica
    - 8.5.1 Creación del árbol
    - 8.5.2 Comprobación de árbol vacío
    - 8.5.3 Inserción de un nodo
    - 8.5.4 Eliminación de un nodo
    - 8.5.5 Modificación del valor de un nodo
  - 8.6 Recorrido
    - 8.6.1 Recorrido en representación vectorial
    - 8.6.2 Recorrido en representación con memoria dinámica
  - 8.7 Árboles binarios de búsqueda (ABB)
    - 8.7.1 Construcción del árbol
    - 8.7.2 Búsquedas
  - 8.8 Montículos binarios
    - 8.8.1 Construcción del árbol
      - 8.8.1.1 Restauración de un montículo de máximos
    - 8.8.2 Algoritmo HeapSort

---

# Tema 7 — Grafos

## 7.1 Definición

**Definición**

Un **grafo** viene dado por un par de conjuntos, G = {V, A}, siendo V un conjunto no vacío denominado conjunto de **vértices** o **nodos** del grafo y A un subconjunto de pares de elementos de V, denominado conjunto de **conexiones**, formado por pares (i, j), donde i y j son elementos de V.

Los nodos de un grafo pueden tener asociados nombres y diferentes propiedades. Las conexiones entre vértices pueden incluir o no incluir orientación, dando lugar a dos tipos de grafos: **grafos orientados** y **grafos no orientados**, respectivamente. Las conexiones no orientadas se denominan **aristas** y las orientadas se denominan **arcos**.

[Figura: image001.gif]

Dada una arista que une los nodos i y j, i y j se denominan **extremos** de la arista. Si dichos nodos están unidos por un arco que va desde i hasta j, i se denomina **origen** del arco y j se denomina **extremo** del arco.

Si las conexiones tienen asociado algún valor, denominado **coste** o **peso**, se dice que el grafo es **ponderado**.

Se denomina **orden** del grafo al número de vértices del mismo y **tamaño** del grafo al número de aristas o arcos.

Se dice que un **grafo** es **simple** cuando cada par de vértices están unidos a lo sumo por una arista, en el caso de grafos no orientados, o por dos arcos, uno en cada sentido, en el caso de grafos orientados; en caso contrario se dice que el **grafo** es **múltiple**.

En este tema nos centraremos en el trabajo con grafos simples.

Dado un *grafo no orientado*, una **cadena** es una secuencia de aristas consecutivas del grafo. La **longitud** **de una** **cadena** es el número de aristas que la componen, si el grafo no es ponderado, y la suma de los costes de las mismas, si el grafo es ponderado. Si la cadena empieza y termina en el mismo vértice se denomina **ciclo**. Un ciclo que incluye una sola arista se denomina **bucle**. Si el *grafo* es *orientado*, el concepto de cadena se sustituye por el de **camino** y el de ciclo por el de **circuito**.

Un grafo no dirigido es **conexo** si existe una cadena entre cualquier par de nodos, siendo **no conexo** o inconexo en caso contrario. Un grafo dirigido es conexo si existe una cadena entre cualquier par de nodos y es **fuertemente** **conexo** si existe un camino entre cualquier par de nodos. Cuando un grafo es conexo consta de una sola **componente**; cuando es no conexo consta de dos o más componentes conexas. Si un grafo dirigido no es fuertemente conexo, incluirá dos o más componentes fuertemente conexas.

## 7.2 Representación: Matriz de adyacencia

**Representación mediante Matriz de Adyacencia**

Dado un grafo con N nodos, la **matriz de adyacencia** que representa el grafo es una matriz cuadrada de orden N. El elemento (i, j) almacenará un 0 si no existe conexión desde el nodo i al j y un 1 en caso contrario (grafo simple).

**ADY(N, N) de enteros**

Si existe un arco desde el nodo i al j, se almacenará un uno en la posición (i, j) de la matriz. Si ambos nodos están conectados por una arista, se almacenará un uno en las posiciones (i, j) y (j, i) de la matriz.

Si el grafo es ponderado, además de la información sobre las conexiones existentes, es necesario almacenar los pesos asociados a éstas. La **matriz de costes** tendrá los mismos elementos que la matriz de adyacencia, pudiendo almacenar reales o enteros.

**COSTES(N, N) de reales**

El elemento (i, j) de la matriz de costes almacenará el peso asociado a la conexión existente entre los vértices i y j, siendo infinito si no existe conexión. Si el grafo es no dirigido, los elementos (i, j) y (j, i) de la matriz almacenarán el mismo valor.

**EJEMPLO**: grafo con 5 nodos

[Figura: image003.gif] [Figura: image004.gif]

## 7.3 Representación: Listas de adyacencia

**Representación mediante Listas de Adyacencia**

La representación de un grafo mediante **listas de adyacencia** se basa en la utilización de listas enlazadas. Para cada vértice del grafo se almacena en una lista la información sobre los vértices a los que está conectado. Esta representación sólo almacena información sobre las conexiones existentes.

Para simplificar, los nodos del grafo se identifican mediante enteros diferentes. En primer lugar se define una lista enlazada que almacenará información sobre los vértices del grafo. El nodo de la lista relacionado con el vértice I del grafo dará acceso a la lista de adyacencia de dicho vértice. Los nodos de la lista de vértices incluyen como mínimo tres campos: uno para identificar el vértice del grafo (**ID_VERTICE**), otro para dar acceso a la lista de adyacencia del vértice (**P_LISTA**) y otro para enlazar entre sí los nodos de la lista de vértices:

```
NODO_V es registro compuesto por
  ID_VERTICE entero
  P_LISTA puntero a NODO_L
  ENLACE puntero a NODO_V
fin-registro
```

Si los vértices tienen asociado un nombre u otro parámetro, se pueden añadir campos para almacenar esta información.

Los nodos de una lista de adyacencia incluyen como mínimo dos campos: uno para almacenar el identificador del vértice conectado (mediante un arco o una arista) con el vértice asociado a la lista (**ID_VERTICE**), y otro para enlazar entre sí los nodos de la lista. Si el grafo es ponderado, se incluye un tercer campo para almacenar el peso de una conexión cuyo extremo es el vértice identificado en el nodo (**COSTE**):

```
NODO_L es registro compuesto por
  ID_VERTICE entera
  COSTE real
  ENLACE puntero a NODO_L
fin-registro
```

Llamaremos **ADY** al puntero que da acceso a la información que define el grafo. Dicho puntero apuntará a la lista de vértices:

**ADY puntero a NODO_V**

Inicialmente el puntero se hace nulo, para indicar que el grafo no incluye ni vértices ni conexiones.

**ADY ← NULO**

La siguiente figura muestra una representación gráfica de las listas de adyacencia que definen un grafo.

[Figura: image001.gif]

**Esquema de listas de adyacencia**

Representación mediante listas de adyacencia del grafo de la siguiente figura (en los nodos de las listas de adyacencia se omite el peso asociado a la conexión, para simplificar el esquema):

[Figura: image002.gif]

[Figura: image003.gif]

## 7.4 Operaciones con representación matricial

**Operaciones en la representación mediante Matriz de Adyacencia**

En la representación mediante matriz de adyacencia consideramos un grafo con N nodos, por lo que se reserva espacio para una matriz cuadrada de orden N. Por tanto, en esta representación no se consideran las operaciones de adición y eliminación de nodos del grafo. Los nodos se numeran de 1 a N, de forma que coincidan con las filas y columnas de la matriz.

- Creación
- Comprobación de la existencia de un vértice
- Comprobación de la existencia de un arco
- Comprobación de la existencia de una arista
- Añadir un arco
- Añadir una arista
- Eliminar un arco
- Eliminar una arista

## 7.4.1 Creación

**Creación**

Para crear el grafo, se reserva espacio para la matriz de adyacencia del mismo, con tantas filas y columnas como nodos incluya el grafo, N:

**ADY(N, N) de enteros**

Además, se deben poner a cero todas las posiciones de la matriz, para indicar que inicialmente no se ha definido ninguna conexión entre los vértices del grafo.

Si el grafo es ponderado, también se debe definir la matriz de costes, que supondremos de tipo real para que sea más general:

**COSTES(N, N) de reales**

y darle valor inicial a sus componentes.

## 7.4.2 Añadir arco

**Añadir un Arco**

Para añadir un arco entre los vértices V1 y V2, se debe poner a 1 la componente (V1, V2) de la matriz de adyacencia. Si el grafo es ponderado, será necesario añadir el coste del nuevo arco a la matriz de costes.

```
MÓDULO Añadir_arco
DATOS
  PARÁMETROS
    Transforma ADY(N, N) de enteros
    Transforma COSTES(N, N) de reales
    Recibe V1, V2 enteros ** origen y extremo del arco
    Recibe C real ** coste del arco
INICIO
  ADY(V1, V2) ← 1
  COSTES(V1, V2) ← C
FIN
```

## 7.4.3 Añadir arista

**Añadir una Arista**

Para añadir una arista entre los nodos V1 y V2, se pondrán a uno las componentes (V1, V2) y (V2, V1) de la matriz de adyacencia. Si el grafo es ponderado, se almacenará el coste de la arista en las componentes (V1, V2) y (V2, V1) de la matriz de costes.

```
MÓDULO Añadir_arista
DATOS
  PARÁMETROS
    Transforma ADY(N, N) de enteros
    Transforma COSTES(N, N) de reales
    Recibe V1, V2 enteros ** extremos de la arista
    Recibe C real ** coste de la arista
INICIO
  ADY(V1, V2) ← 1
  ADY(V2, V1) ← 1
  COSTES(V1, V2) ← C
  COSTES(V2, V1) ← C
FIN
```

## 7.4.4 Comprobar vértice

**Comprobación de la existencia de un Vértice**

Para un grafo de N vértices representado mediante su matriz de adyacencia, los vértices se numerarán de 1 a N, de forma que correspondan con filas/columnas de la matriz. Por tanto, para comprobar si existe un vértice VI, se comprobará si el valor VI está entre 1 y N.

```
MÓDULO Existe_vertice devuelve lógico
  PARÁMETROS
    Recibe VI entera
    Recibe N entera
INICIO
  Si ( (VI ≥ 1) Y (VI ≤ N) ) entonces
    DEVOLVER Verdadero
  sino
    DEVOLVER Falso
  fin-si
FIN
```

## 7.4.5 Comprobar arco

**Comprobación de la existencia de un Arco**

Para comprobar si existe un arco desde el vértice V1 al V2, se comprueba si no hay un cero en la posición (V1, V2) de la matriz de adyacencia.

```
MÓDULO Existe_arco devuelve lógico
DATOS
  PARÁMETROS
    Recibe ADY(N, N) de enteros
    Recibe V1, V2 enteros
INICIO
  Si (ADY(V1, V2) ≠ 0) entonces
    DEVOLVER Verdadero ** existe arco
  sino
    DEVOLVER Falso ** no existe arco
  fin-si
FIN
```

## 7.4.6 Comprobar arista

**Comprobación de la existencia de una Arista**

Para comprobar si existe una arista entre los vértices V1 y V2, se comprueba si no hay un cero en las posiciones (V1, V2) y (V2, V1) de la matriz de adyacencia.

```
MÓDULO Existe_arista devuelve lógico
DATOS
  PARÁMETROS
    Recibe ADY(N, N) de enteros
    Recibe V1, V2 enteros
INICIO
  Si ( (ADY(V1, V2) ≠ 0) Y (ADY(V2, V1) ≠ 0) ) entonces
    DEVOLVER Verdadero ** existe arista
  sino
    DEVOLVER Falso ** no existe arista
  fin-si
FIN
```

## 7.4.7 Eliminar arco

**Eliminar un Arco**

Para eliminar un arco existente entre los vértices V1 y V2, se pone a 0 la componente de la matriz de adyacencia que representa dicha conexión. Si el grafo es ponderado se debe eliminar el coste asociado al arco.

```
MÓDULO Eliminar_arco
DATOS
  PARÁMETROS
    Transforma ADY(N, N) de enteros
    Transforma COSTES(N, N) de enteros
    Recibe V1, V2 enteros
INICIO
  ADY(V1, V2) ← 0
  COSTES(V1, V2) ← INFINITO
FIN
```

## 7.4.8 Eliminar arista

**Eliminar una Arista**

Para eliminar una arista existente entre los vértices V1 y V2, se pondrán a cero las posiciones (V1, V2) y (V2, V1) de la matriz de adyacencia. Si el grafo es ponderado se debe eliminar también el coste asociado a la arista.

```
MÓDULO Eliminar_arista
DATOS
  PARÁMETROS
    Transforma ADY(N, N) de enteros
    Transforma COSTES(N, N) de enteros
    Recibe V1, V2 enteros
INICIO
  ADY(V1, V2) ← 0
  ADY(V2, V1) ← 0
  COSTES(V1, V2) ← INFINITO
  COSTES(V2, V1) ← INFINITO
FIN
```

## 7.5 Operaciones con representación mediante listas

**Operaciones en la representación mediante Listas de Adyacencia**

En la representación mediante listas de adyacencia, la memoria que ocupa la estructura que almacena el grafo se debe liberar cuando deje de ser necesaria, por lo que se añade una operación de eliminación de las listas.

- Creación
- Comprobación de la existencia de un vértice
- Comprobación de la existencia de un arco
- Comprobación de la existencia de una arista
- Añadir un vértice
- Añadir un arco
- Añadir una arista
- Eliminar un vértice
- Eliminar un arco
- Eliminar una arista
- Eliminar las listas

## 7.5.1 Creación

**Creación**

Para crear el grafo, en primer lugar se define la estructura de los nodos de las listas de adyacencia:

```
NODO_L es registro compuesto por
  ID_VERTICE entera
  COSTE real
  ENLACE puntero a NODO_L
fin-registro
```

Si el grafo no es ponderado, se elimina el segundo campo.

En segundo lugar, se define la estructura de los nodos de la lista de vértices:

```
NODO_V es registro compuesto por
  ID_VERTICE entera
  P_LISTA puntero a NODO_L
  ENLACE puntero a NODO_V
fin-registro
```

A continuación, se define el puntero que dará acceso a la lista de vértices:

**ADY puntero a NODO_V**

Inicialmente no existirá ningún vértice en el grafo y todas las listas estarán vacías, por lo que el puntero ADY se hace nulo:

**ADY ← NULO**

## 7.5.2 Comprobar vértice

**Comprobación de la existencia de un Vértice**

Para comprobar si existe un vértice VI se busca éste en la lista de vértices.

```
MÓDULO Existe_vertice devuelve lógico
  PARÁMETROS
    Recibe ADY puntero a NODO_V
    Recibe VI entero
INICIO
  Si (Buscar_vertice(ADY, VI) != NULO) entonces
    DEVOLVER Verdadero ** vértice encontrado
  sino
    DEVOLVER Falso ** vértice no encontrado
  fin-si
FIN
```

Para realizar esta comprobación se utiliza un módulo auxiliar (**Buscar_vertice**), que también se utilizará en operaciones posteriores. Busca un vértice V en la lista de vértices asociada al grafo. Retorna NULO si el vértice no aparece en la lista de vértices (lo que significa que no forma parte del grafo), y un puntero no NULO si ha encontrado el vértice. En este segundo caso el puntero apuntará al nodo de la lista de vértices que identifica al vértice buscado.

```
MÓDULO Buscar_vertice devuelve puntero a NODO_V
DATOS
  PARÁMETRO
  Recibe P puntero a NODO_V
  Recibe V entero
  VARIABLES
    P_V puntero a NODO_V
INICIO
  P_V ← P
  Mientras (P_V != NULO) hacer
    Si (P_V↑.ID_VERTICE = V) entonces
      DEVOLVER P_V ** vértice encontrado
    fin-si
    P_V ← P_V↑.ENLACE
  fin-mientras
  DEVOLVER NULO ** vértice no encontrado
FIN
```

## 7.5.3 Comprobar arco

**Comprobación de la existencia de un Arco**

Para comprobar si existe un arco desde el vértice V1 al V2, se buscará un nodo con valor V2 en la lista de adyacencia de V1.

```
MÓDULO Existe_arco devuelve lógico
  PARÁMETROS
    Recibe ADY puntero a NODO_V
    Recibe V1 entera
    Recibe V2 entera
  VARIABLES
    P_V1 puntero a NODO_V
    P_V2 puntero a NODO_L
INICIO
  P_V1 ← Buscar_vertice(ADY, V1)
  Si( P_V1 ≠ NULO) entonces
    P_V2 ← P_V1↑.P_LISTA
    Mientras ( (P_V2 ≠ NULO) Y (P_V2↑.ID_VERTICE ≠ V2) ) hacer
      P_V2 ← P_V2↑.ENLACE
    fin-mientras
    Si (P_V2 ≠ NULO) entonces
      DEVOLVER Verdadero ** encontrado
    fin-si
  fin-si
  DEVOLVER Falso ** no encontrado
FIN
```

## 7.5.4 Comprobar arista

**Comprobación de la existencia de una Arista**

Para comprobar si existe una arista entre los vértices V1 y V2, se debe buscar el vértice V2 en la lista de adyacencia de V1 y el vértice V1 en la lista de adyacencia de V2.

```
MÓDULO Existe_arista devuelve lógico
DATOS
  PARÁMETROS
    Recibe ADY puntero a NODO_V
    Recibe V1, V2 enteros
INICIO
  Si ( (Existe_arco(ADY, V1, V2) = Verdadero) Y
  (Existe_arco(ADY, V2, V1) = Verdadero) ) entonces
  DEVOLVER Verdadero ** encontrado
  sino
  DEVOLVER Falso ** no encontrado
  fin-si
FIN
```

## 7.5.5 Añadir vértice

**Añadir un Vértice**

Para añadir un vértice VI al grafo, se debe insertar un nuevo nodo en la lista de vértices y hacer que referencie a VI. El nuevo nodo almacenará el identificador del nuevo vértice, tendrá a nulo el puntero a la lista de adyacencia de VI (pues inicialmente está vacía) y se enlazará con el primer nodo de la lista de vértices.

```
MÓDULO Añadir_vertice devuelve lógico
DATOS
  PARÁMETROS
    Transforma ADY puntero a NODO_V
    Recibe VI entera
  VARIABLES
    NUEVO puntero a NOVO_V
INICIO
  NUEVO ← RESERVAR_MEMORIA(tamaño(NODO_V))
  Si (NUEVO = NULO) entonces
    Escribir "Error al solicitar memoria"
    DEVOLVER Falso ** inserción no realizada
  sino
    NUEVO↑.ID_VERTICE ← VI
    NUEVO↑.P_LISTA ← NULO
    NUEVO↑.ENLACE ← ADY
    ADY ← NUEVO
    DEVOLVER Verdadero ** inserción realizada
  fin-si
FIN
```

[Figura: image001.gif]

## 7.5.6 Añadir arco

**Añadir un Arco**

Para añadir un arco desde el vértice V1 a V2, se debe añadir un nodo a la lista de adyacencia de V1 que identifique a V2 como extremo del arco. V1 ya debe formar parte del grafo, para que exista su lista de adyacencia. El nuevo nodo se inserta al principio de dicha lista.

```
MÓDULO Añadir_arco devuelve lógico
DATOS
  PARÁMETRO
  Recibe ADY puntero a NODO_V
  Recibe V1 entera
  Recibe V2 entera
  Recibe C real
  VARIABLES
    NUEVO puntero a NODO_L
    P_V1 puntero a NODO_V
INICIO
  P_V1 ← Buscar_vertice(ADY, V1)
  Si (P_V1 = NULO) entonces
    ESCRIBIR "El primer vértice no existe"
    DEVOLVER Falso ** inserción no realizada
  sino
    NUEVO ← RESERVAR_MEMORIA(tamaño(NODO_L))
    Si (NUEVO = NULO) entonces
      Escribir "Error al solicitar memoria"
      DEVOLVER Falso ** inserción no realizada
    sino
      NUEVO↑.ID_VERTICE ← V2
      NUEVO↑.COSTE ← C
      NUEVO↑.ENLACE ← P_V1↑.P_LISTA
      P_V1↑.P_LISTA ← NUEVO
      DEVOLVER Verdadero ** inserción realizada
    fin-si
  fin-si
FIN
```

[Figura: image001.gif]

**Esquema de listas enlazadas tras añadir un arco de I a J**

## 7.5.7 Añadir arista

**Añadir una Arista**

Para añadir una arista entre dos vértices, V1 y V2, se pueden hacer dos llamadas al módulo que inserta un arco, solicitando en una de ellas la creación del arco (V1, V2) y en la otra la creación del arco (V2, V1). Los vértices V1 y V2 ya deben formar parte del grafo.

```
MÓDULO Añadir_arista devuelve lógico
DATOS
  PARÁMETRO
  Recibe ADY puntero a NODO_V
  Recibe V1 entera
  Recibe V2 entera
  Recibe C real
  VARIABLES
    P_V1, P_V2 punteros a NODO_V
INICIO
  P_V1 ← Buscar_vertice(ADY, V1)
  P_V2 ← Buscar_vertice(ADY, V2)
  Si ( (P_V1 = NULO) O (P_V2 = NULO) ) entonces
    ESCRIBIR "No existe alguno de los extremos"
    DEVOLVER Falso ** inserción no realizada
  sino
    Si (Añadir_arco(ADY, V1, V2, C) = Verdadero) entonces
      DEVOLVER Añadir_arco(ADY, V2, V1, C)
    sino
      DEVOLVER Falso ** inserción no realizada
    fin-si
  fin-si
FIN
```

[Figura: image001.gif]

**Esquema de listas enlazadas tras añadir una arista entre I y J**

## 7.5.8 Eliminar vértice

**Eliminar un Vértice**

Para eliminar un vértice, se debe eliminar el nodo de la lista de vértices que lo identifica, junto con la lista de adyacencia que tiene asociado este vértice. Además, se deben recorrer las listas de adyacencia de los restantes vértices del grafo para eliminar cualquier referencia al vértice que va a desaparecer del grafo.

```
MÓDULO Eliminar_vertice devuelve lógico
DATOS
  PARÁMETROS
    Transforma ADY puntero a NODO_V
    Recibe VI entera
  VARIABLES
    P1, PREVIO_P1 punteros a NODO_V
INICIO
  Si (Existe_vertice(ADY, VI) = Falso) entonces
    ESCRIBIR "El vértice no forma parte del grafo"
    DEVOLVER Falso
  fin-si
  PREVIO_P1 ← NULO
  P1 ← ADY
  Mientras (P1 ≠ NULO) hacer
    ** si el nodo actual referencia al vértice que se debe eliminar
    Si (P1↑.ID_VERTICE = VI) entonces
      Si (P1↑.P_LISTA ≠ NULO) entonces
        Vaciar_lista(P1↑.P_LISTA)
      fin-si
      Eliminar(ADY, P1)
      Si (PREVIO_P1 = NULO) entonces
        P1 ← ADY
      sino
        P1 ← PREVIO_P1↑.ENLACE
      fin-si
      ** si no referencia al vértice que se debe eliminar
    sino
      Eliminar_todos(P1, VI)
      PREVIO_P1 ← P1
      P1 ← P1↑.ENLACE
    fin-si
  fin-mientras
  DEVOLVER Verdadero
FIN
```

El módulo **Vaciar_lista** elimina la lista de adyacencia de un vértice. El módulo **Eliminar** elimina de la lista de vértices el nodo apuntado por el puntero P1. Estas operaciones se describieron en el tema referente a listas. El módulo **Eliminar_todos** recorre una lista de adyacencia y elimina todos los nodos que hagan referencia al vértice pasado como argumento.

```
MÓDULO Eliminar_todos
DATOS
  PARÁMETROS
    Recibe P puntero a NODO_V
    Recibe VI entera
  VARIABLES
    P2, PREVIO_P2 punteros a NODO_L
INICIO
  P2 ← P↑.P_LISTA
  PREVIO_P2 ← NULO
  Mientras(P2 ≠ NULO) hacer
    Si (P2↑.ID_VERTICE = VI) entonces
      Si (P2 = P↑.P_LISTA) entonces
        P↑.P_LISTA ← P2↑.ENLACE
      sino
        PREVIO_P2↑.ENLACE ← P2↑.ENLACE
      fin-si
      LIBERAR(P2)
    fin-si
    PREVIO_P2 ← P2
    P2 ← P2↑.ENLACE
  fin-mientras
FIN
```

## 7.5.9 Eliminar arco

**Eliminar un Arco**

Para eliminar un arco desde el vértice V1 hasta el V2, se debe eliminar el nodo que contenga el valor V2 en la lista de adyacencia asociada a V1, siempre y cuando exista el vértice V1 y esté conectado con V2.

```
MÓDULO Eliminar_arco devuelve lógico
DATOS
  PARÁMETROS
    Recibe ADY puntero a NODO_V
    Recibe V1 entera
    Recibe V2 entera
  VARIABLES
    P_V1 puntero a NODO_V
    RET lógica
INICIO
  P_V1 ← Buscar_vertice(ADY, V1)
  Si (P_V1 ≠ NULO) entonces
    RET ← Eliminar_valor(P_V1↑P_LISTA, V2)
    DEVOLVER RET
  sino
    ESCRIBIR "No existe el primer vértice"
    DEVOLVER Falso
  fin-si
FIN
```

Si existe un arco desde V1 hasta V2, el módulo **Eliminar_valor** eliminará de la lista de adyacencia del vértice V1 el nodo que contenga la referencia al vértice V2. El módulo recibe como argumentos el puntero que da acceso a la lista de adyacencia de un vértice del grafo y el identificador de otro vértice. Se describió en el tema referente a listas, aunque en este caso incluimos un valor de retorno que informa del éxito o el fracaso de la operación de eliminación.

## 7.5.10 Eliminar arista

**Eliminar una Arista**

Para eliminar una arista entre dos vértices V1 y V2, se debe eliminar de la lista de adyacencia de V1 el nodo que haga referencia a V2, y de la lista de adyacencia de V2 el nodo que referencie a V1. Por tanto, la eliminación se puede realizar haciendo dos llamadas al módulo que elimina un arco, invirtiendo el orden de los vértices en ambas llamadas.

```
MÓDULO Eliminar_arista devuelve lógico
DATOS
  PARÁMETROS
    Recibe ADY puntero a NODO_V
    Recibe V1 entera
    Recibe V2 entera
INICIO
  Si (Existe_arista(ADY, V1, V2) = Verdadero) entonces
    Eliminar_arco (ADY, V1, V2)
    Eliminar_arco(ADY, V2, V1)
    DEVOLVER Verdadero
  sino
    ESCRIBIR "No existe la arista"
    DEVOLVER Falso
  fin-si
FIN
```

En primer lugar se comprueba que exista la arista que se desea eliminar. En caso afirmativo, se elimina la conexión en ambos sentidos.

## 7.5.11 Eliminar listas

**Eliminar las Listas de Adyacencia**

Cuando la estructura grafo deje de ser necesaria, debe liberarse la memoria asociada a las listas de adyacencia. Esta eliminación supone borrar las N listas asociadas a los N vértices del grafo y, además, borrar la lista de vértices.

Se recorrerá la lista de vértices, eliminando en primer lugar la lista de adyacencia asociada al vértice y, a continuación, el nodo de la lista de vértices que daba acceso a dicha lista enlazada.

```
MÓDULO Borrar_listas_adyacencia
DATOS
  PARÁMETROS
    Transforma ADY puntero a NODO_V
  VARIABLES
    P puntero a NODO_V
INICIO
  Mientras ( ADY ≠ NULO) hacer
    Vaciar_lista (ADY↑.P_LISTA )
    P ← ADY
    ADY ← ADY↑.ENLACE
    LIBERAR(P)
  fin-mientras
FIN
```

El módulo **Vaciar_lista**, que vacía una lista dinámica lineal con enlace simple, se comentó en el tema referente a listas.

## 7.6 Recorridos

**Recorrido de un Grafo**

Recorrer un grafo supone intentar alcanzar todos los vértices que estén relacionados con uno dado, que tomaremos como vértice inicial del recorrido. Existen dos técnicas básicas para recorrer un grafo: el **recorrido** **en anchura** y el **recorrido en profundidad**. Ambas técnicas se pueden aplicar tanto a grafos dirigidos como no dirigidos.

Dado que un vértice del grafo normalmente está conectado con varios, al realizar un recorrido podemos alcanzar un mismo vértice por varios caminos. Para evitar visitar varias veces un mismo vértice, se deben marcar de algún modo los vértices ya visitados. Para ello utilizaremos un vector de N elementos, en el que la posición i-ésima indique si el vértice i-ésimo ya ha sido visitado (Verdadero) o no (Falso):

**VISITADO(N) de tipo lógico**

Antes de comenzar el recorrido del grafo se pondrán a Falso todos los elementos del vector (mediante un módulo que llamaremos **Iniciar_vector_visitados**) y, a medida que se vayan visitando vértices, se pondrá la posición correspondiente del vector a Verdadero.

Para hacer una descripción más general de los algoritmos de recorrido, la variable G representa el grafo de N vértices que se desea recorrer, que puede estar representado bien mediante su matriz de adyacencia o mediante listas de adyacencia. El vértice de partida del recorrido será el V0. Se supone que el objetivo del recorrido del grafo es aplicar algún tratamiento a todos los vértices, que representaremos por la operación, TRATAR() (por ejemplo, visualizar su contenido, acumular su valor en una operación,...).

## 7.6.1 Recorrido en anchura

**Recorrido en Anchura**

El recorrido en anchura supone recorrer el grafo en niveles, partiendo de un vértice dado. El vértice procesado en primer lugar es el de partida del recorrido, a continuación se recorren los vértices que están a una distancia de un arco/arista del vértice de salida, después los que están a dos arcos/aristas de distancia, y así sucesivamente hasta alcanzar todos los vértices a los que se pueda llegar desde el vértice de salida. Por tanto, al visitar el nodo de partida se debe almacenar una referencia a todos sus adyacentes. Cuando se visite un nodo de este conjunto, se deben almacenar también las referencias a los vértices adyacentes al segundo que se ha tratado, teniendo en cuenta que tales vértices deben ser procesados sólo cuando se hayan procesado los del primer conjunto. El orden en que se debe ir aplicando el tratamiento a los nodos sugiere el uso de una cola para almacenar las referencias a los vértices adyacentes a los que se van visitando.

Para hacer el algoritmo más general, se utilizará una variable del tipo COLA, para representar cualquier implementación de cola. Las operaciones a realizar sobre la cola serán función de la representación elegida.

```
MÓDULO Primero_en_anchura
DATOS
  PARÁMETROS
    Recibe G de tipo GRAFO ** grafo a recorrer
    Recibe V0 entera ** vértice de partida
    Recibe N entera ** vértices del grafo
  VARIABLES
    C de tipo COLA
    V1, V2 enteras
    VISITADO(N) de tipo lógico
INICIO
  Iniciar_vector_visitados(N, VISITADO)
  Crear_Cola(C)
  Encolar(C, V0)
  VISITADO(V0) ← Verdadero
  Mientras (Cola_vacia(C) = Falso) hacer
    V1 ← Desencolar(C)
    TRATAR(V1)
    Para todo vértice, V2, adyacente a V1 hacer
      Si (VISITADO(V2) = Falso) entonces
        Encolar(C, V2)
        VISITADO(V2) ← Verdadero
      fin-si
    fin-para
  fin-mientras
FIN
```

Aunque la variable G no se usa explícitamente en ninguna instrucción, se utilizará para determinar los vértices adyacentes a uno dado, por lo que es necesario incluirla en la lista de parámetros del módulo. Esta operación depende de la forma de representación del grafo.

Si el grafo no es conexo, el módulo propuesto recorrerá la componente conexa a la que pertenece el vértice V0. Para recorrer todo el grafo se debe hacer una nueva llamada al módulo, tomando como vértice de partida alguno que no pertenezca a la componente conexa recorrida. Esta información se puede obtener del vector VISITADO, pasando el vector como parámetro al módulo que realiza el recorrido.

La diferencia al adaptar el algoritmo general para cada una de las implementaciones de la estructura de datos grafo, residirá en la manera de averiguar los diferentes vértices adyacentes a uno dado. Si se utiliza la matriz de adyacencia se tendrán que comprobar las posiciones de la fila de la matriz correspondiente al vértice V1. Si se utilizan listas de adyacencia, los vértices adyacentes a uno dado son los que aparecen en su lista de adyacencia.

## 7.6.2 Recorrido en profundidad

**Recorrido en Profundidad**

El recorrido en profundidad trata de buscar los caminos que parten desde el vértice de salida hasta que ya no es posible avanzar más (no se puede pasar a ningún otro vértice, o todos aquellos a los que se puede pasar ya forman parte del camino). Cuando ya no se puede avanzar más sobre el camino elegido, se vuelve atrás en busca de caminos alternativos que no se analizaron previamente.

En primer lugar se visita el vértice de partida del recorrido, a continuación se visita uno de sus vértices adyacentes, a continuación un vértice no visitado adyacente a este último, y así sucesivamente hasta que se llegue a un vértice para el que no existen vértices adyacentes aún no visitados. En ese momento se vuelve atrás un nivel y se busca un nuevo camino por el que seguir el recorrido. La estructura de datos adecuada para poder avanzar todos los niveles posibles en el recorrido es una pila. Al visitar el primer vértice, se apilan los vértices adyacentes. A continuación, se desapila uno de dichos vértices y se apilan los vértices no visitados adyacentes a él, y así sucesivamente.

Para hacer el algoritmo más general, se utilizará una variable del tipo PILA, para representar cualquier implementación de pila. Las operaciones a realizar sobre la pila serán función de la representación elegida.

```
Módulo Primero_en_profundidad
DATOS
  PARÁMETROS
    Recibe G de tipo GRAFO ** grafo a recorrer
    Recibe V0 entera ** vértice de partida
    Recibe N entera ** vértices del grafo
  VARIABLES
    P de tipo PILA
    V1, V2 enteras
    VISITADO(N) de tipo lógico
INICIO
  Iniciar_vector_visitados(N, VISITADO)
  Crear_pila(P)
  Apilar(P, V0)
  VISITADO(V0) ← Verdadero
  Mientras (Pila_vacia(P) = Falso) hacer
    V1 ← Desapilar(P)
    TRATAR(V1)
    Para todo vértice, V2, adyacente a V1 hacer
      Si (VISITADO(V2) = Falso) entonces
        Apilar(P, V2)
        VISITADO(V2) ← Verdadero
      fin-si
    fin-para
  fin-mientras
FIN
```

Observamos que la estructura del algoritmo es idéntica a la propuesta para el recorrido en anchura. La única diferencia reside en el uso de una pila en lugar de una cola.

El recorrido en profundidad también se puede implementar mediante una función recursiva, lo que hace innecesario el uso de una pila. Se elige un vértice de partida, se marca como visitado y se recorren los vértices no visitados adyacentes al de partida, usando recursivamente la búsqueda primero en profundidad. El primer elemento tratado es el vértice de partida. Una vez aplicado el tratamiento, se marca como visitado. A continuación, se entra en un bucle, que se repite para cada vértice adyacente al de partida. Si se encuentra un vértice adyacente al de partida que aún no haya sido visitado, se realiza una llamada recursiva al módulo, pasando como argumentos el grafo, el vértice adyacente encontrado, el número de vértices del grafo y el vector de visitados. En esta nueva llamada al módulo se repite el proceso, pero partiendo ahora de un nuevo vértice.

```
Módulo Primero_en_profundidad_rec
DATOS
  PARÁMETROS
    Recibe G de tipo GRAFO ** grafo a recorrer
    Recibe V0 entero ** origen del recorrido
    Recibe N entera ** vértices del grafo
    Transforma VISITADO(N) de tipo lógico
  VARIABLES
    V1 entera
INICIO
  VISITADO (V0) ← Verdadero
  TRATAR(V0)
  Para todo vértice, V1, adyacente a V0 hacer
    Si (VISITADO(V1) = Falso ) entonces
      Primero_en_profundidad_rec (G, V1, N, VISITADO)
    fin-si
  fin-para
FIN
```

Por el mismo motivo que se comentó en el recorrido en anchura, para recorrer todos los vértices de un grafo que incluya varias componentes conexas o fuertemente conexas, llamaremos varias veces al módulo que realiza el recorrido.

---

# Tema 8 — Árboles

## 8.1 Definición

**Definición - Árboles binarios**

Un **árbol binario** es un conjunto finito de elementos que o está vacío o dividido en 3 subconjuntos disjuntos. Un subconjunto contiene un elemento denominado raíz del árbol, que es único. Los otros dos subconjuntos, denominados **subárbol izquierdo** y **subárbol** **derecho**, son por si mismos árboles binarios. Las raíces de los subárboles se denominan **hijo** **izquierdo** e **hijo derecho**, respectivamente, de la raíz del árbol inicial.

Dado un grafo G = (V, A) no dirigido, llamaremos **árbol** de G a todo subgrafo de G conexo y sin ciclos. Utilizaremos la notación T = (V, E) para representar un árbol, formado por un conjunto de nodos V y un conjunto de conexiones E (o **ramas**). Los nodos de un árbol se suelen representar gráficamente mediante círculos y las conexiones mediante segmentos que conectan dos círculos.

[Figura: image001.gif]

Un árbol es una estructura jerárquica que permite representar relaciones entre los nodos, siendo la fundamental la relación padre-hijo. Si existe una conexión desde el nodo A al B, se dice que A es el **padre** de B y que B es **hijo** de A. Los hijos del mismo padre se denominan **hermanos**.

Los nodos del árbol se pueden clasificar en tres tipos:

- **raíz** : nodo especial en el árbol, que no tiene padre y es único. Si un árbol no tiene raíz se denomina *árbol libre*.
- **nudos** o **nodos internos** : cualquier nodo del árbol que tiene padre y al menos un hijo.
- **hojas**, **vértices externos** o **colgantes** : nodos que no tiene hijos. Todo árbol debe contener como mínimo 2 hojas.

Una vez fijada la raíz de un árbol, se pueden clasificar los nodos en **niveles**. La raíz estará en el nivel 0, sus hijos en el nivel 1, los hijos de éstos en el nivel 2, y así sucesivamente.

Se puede definir el **nivel** o **profundidad de un nodo** como la longitud del camino que permite ir desde la raíz al nodo.

Se denomina **altura de un árbol** al número de niveles del árbol. La altura de un árbol vacío es 0.

**EJEMPLO**:

[Figura: image002.gif]

Nodos del árbol: {C, A, B, E, D, R}

Ramas del árbol: { (C, A), (C, B), (A, E), (A, D), (B, R) }

Raíz: C

Nodos hoja: E, D, R

Nudos: A, B

Altura del árbol: 3

Hijos de la raíz: A y B

Hijos del nodo B: R

Padre del nodo D: A

Padre del nodo E: A

Nodos hermanos: A y B; E y D

## 8.2 Operaciones básicas

**Operaciones básicas**

Las operaciones fundamentales que nos permiten definir un árbol binario son las siguientes:

- **Crear el árbol**: es la primera operación que se realizará sobre la estructura de datos. Permitirá describir la estructura de la información con la que se representará cada nodo del árbol, reservar memoria para almacenar la información que define el árbol o para un puntero a la estructura. El árbol se crea vacío.
- **Crear un nodo**: permite añadir un nuevo nodo al árbol. Supondremos que para cada nuevo nodo su padre ya forma parte del árbol, salvo para la raíz, lógicamente.
- **Eliminar un nodo**: permite eliminar un nodo del árbol.
- **Modificar el valor asociado a un nodo**: permite modificar el dato asociado a un nodo del árbol.
- **Comprobar si el árbol está vacío**: permite comprobar si el árbol no contiene ningún nodo. Se debe comprobar que el árbol no esté vacío antes de intentar eliminar algún elemento o acceder al mismo.

Si el árbol está representado mediante un vector, se considera además la operación de **comprobación de árbol lleno**, necesario para evitar intentar añadir nodos al árbol cuando el vector ya no puede alojar más.

## 8.3 Representación

**Representación de Árboles binarios**

Los árboles binarios se pueden representar dentro de un programa de dos formas básicas:

- utilizando un vector
- utilizando memoria dinámica

En ambos casos se almacenará información sobre cada nodo:

- un posible *dato* asociado al nodo
- una referencia a los *hijos* de éste
- una referencia a su *padre*

En ocasiones se omite la referencia al padre, ya que se puede localizar el padre de cualquier nodo realizando un recorrido del árbol (como se comentará en apartados posteriores). Con esto se reduce el espacio de memoria necesario para almacenar el árbol.

## 8.3.1 Representación vectorial

**Representación vectorial de árboles**

Se utilizará un vector con tantas posiciones como nodos pueda incluir el árbol. Las operaciones de creación de nodos deben comprobar siempre que no se exceda el espacio reservado para el vector.

**ARBOL(N) de tipo NODO**

Utilizaremos una variable entera, denominada **N_NODOS**, para determinar los nodos que contiene el árbol en cada momento. Dicha variable tomará valores entre 0 (árbol vacío) y N (árbol lleno).

**N_NODOS entero**

Cuando se crea el árbol se da valor 0 al contador de nodos, creando un árbol vacío:

| **ARBOL** | | | | |

| | **1** | **2** | **...** | **N** |

| | | | | |

| | | | **N_NODOS** | 0 |

| | | | | |

**Variables necesarias para trabajar con un árbol representado de forma estática**

Para cada nodo del árbol se almacenará cierta información, de algún tipo T, además de enteros que determinen la posición del padre, el hijo izquierdo y el derecho de dicho nodo dentro del vector que representa el árbol:

```
NODO es registro compuesto por
  DATO de tipo T ** información asociada al nodo
  HIJO_IZQUIERDO entero ** posición del hijo izquierdo
  HIJO_DERECHO entero ** posición del hijo derecho
  PADRE entero ** posición del padre
fin-registro
```

En nuestro caso los campos **HIJO_DERECHO**, **HIJO_IZQUIERDO** y **PADRE** tomarán valores entre 1 y **N**, salvo cuando no exista el elemento al que hacen referencia, en cuyo caso almacenaremos el valor -1 para indicarlo.

EJEMPLO:

[Figura: image001.gif]

Mostramos una posible forma de almacenar los nodos del árbol de la figura dentro del vector **ARBOL**. El orden en que se pueden almacenar los nodos dentro del vector no es único. Para cada nodo se muestran en 4 filas sucesivas su etiqueta, su hijo izquierdo, su hijo derecho y su padre:

| | C | A | B | F | D | R |

| **ARBOL** | 2 | 4 | -1 | -1 | -1 | -1 |

| | 3 | 5 | 6 | -1 | -1 | -1 |

| | -1 | 1 | 1 | 2 | 2 | 3 |

| | **1** | **2** | **3** | **4** | **5** | **6** |

| | | | | | | |

| | | | | **N_NODOS** | 6 |

| | | | | | | |

**Representación vectorial de árboles - un caso especial**

Los árboles binarios llenos o completos se pueden representar de forma eficiente utilizando una forma vectorial simplificada (ver caso particular)

## 8.3.1.1 Caso particular (representación vectorial)

**Árboles Binarios llenos y completos**

Se dice que un **árbol binario** está **lleno** si es un árbol binario de profundidad k que tiene 2k-1 nodos. Es decir, un árbol binario lleno es aquel que contiene el número máximo de posibles nodos en función de su profundidad.

[Figura: image001.gif]

**Ejemplo de árboles binarios llenos**

Un árbol binario de profundidad k es un **árbol binario completo** si cualquier nodo i a un nivel menor que k-2 tiene dos hijos; además, todo nodo i con un descendiente derecho en el nivel k-1 debe tener un hijo izquierdo y cada descendiente izquierdo de i es una hoja en el nivel k-1 o tiene dos hijos.

[Figura: image002.gif]

**Ejemplo de árboles binarios completos**

Estos dos tipos de árbol se pueden representar mediante un vector de forma sencilla. Para ello los **N** nodos del árbol se numeran de 1 a **N** comenzando por la raíz y avanzando por los sucesivos niveles de izquierda a derecha. Los nodos del árbol se pueden almacenar en un vector de **N** elementos, colocando cada uno en la posición que corresponde a su número. No es necesario almacenar referencias a las posiciones del padre o los hijos, dado que se cumplen las siguientes relaciones:

- Si el nodo i tiene padre, estará ubicado en la posición (i div 2) del vector.
- Si el nodo i tiene hijo izquierdo, estará ubicado en la posición (2i).
- Si el nodo i tiene hijo derecho, estará ubicado en la posición (2i+1).

El nodo i, con valores entre 1 y **N**, tendrá:

- padre si no es la raíz del árbol (i>1).
- hijo izquierdo si la posición que debe ocupar éste en el vector, de existir, es menor o igual que el número de nodos del árbol (2i ≤ **N** )
- hijo derecho si la posición que debe ocupar éste en el vector, de existir, es menor o igual que el número de nodos del árbol (2i+1 ≤ **N**).

**EJEMPLOS**:

[Figura: image003.gif]

| *1* | *2* | *3* | *4* | *5* | *6* |

| A | B | C | D | E | F |

Árbol completo y su representación vectorial

[Figura: image004.gif]

| *1* | *2* | *3* | *4* | *5* | *6* | *7* |

| A | B | C | D | E | F | G |

Árbol lleno y su representación vectorial

## 8.3.2 Representación con memoria dinámica

**Representación basada en el uso de memoria dinámica**

También se puede representar un árbol trabajando con memoria dinámica. La información almacenada para cada nodo del árbol es similar a la descrita para la representación vectorial, aunque en este caso el padre y los hijos de cada nodo se identifican mediante punteros. Si existe el elemento correspondiente (el padre o el hijo), el puntero apuntará a un nodo del árbol; en caso contrario el puntero se hará nulo:

```
NODO es registro compuesto por
  DATO de tipo T ** información asociada al nodo
  HIJO_IZQUIERDO puntero a NODO ** puntero al hijo izquierdo
  HIJO_DERECHO puntero a NODO ** puntero al hijo derecho
  PADRE puntero a NODO ** puntero al padre
fin-registro
```

En este caso se definirá un puntero que apuntará permanentemente a la raíz del árbol, a partir de la cual se podrá acceder a todos sus nodos:

**RAIZ puntero a NODO**

Este puntero se hará inicialmente nulo para indicar que el árbol está vacío:

**RAIZ ← NULO**

EJEMPLO:

El esquema del árbol del ejemplo anterior, representado mediante nodos enlazados, se muestra a continuación. Se consideran dos posibilidades: que exista o que no exista el campo PADRE:

[Figura: image001.gif]

Representación de árbol mediante nodos enlazados incluyendo un campo padre

[Figura: image002.gif]

Representación de árbol mediante nodos enlazados sin incluir un campo al padre

En el resto del tema simplificaremos esta representación gráfica, sustituyendo el rectángulo que representa a un nodo de la estructura enlazada por un pequeño círculo del que salen los enlaces a los hijos y al padre, si existe este enlace. Los enlaces nulos no se representan.

## 8.4 Operaciones en representación vectorial

**Operaciones en la representación vectorial**

- Creación del árbol
- Comprobación de árbol vacío
- Comprobación de árbol lleno
- Inserción de un nodo
- Eliminación de un nodo
- Modificación del valor de un nodo

## 8.4.1 Creación del árbol

**Creación de un árbol vacío**

Para crear el árbol, en primer lugar se define la estructura que representa sus nodos:

```
NODO es registro compuesto por
  DATO de tipo T ** información asociada al nodo
  HIJO_IZQUIERDO entero ** posición del hijo izquierdo
  HIJO_DERECHO entero ** posición del hijo derecho
  PADRE entero ** posición del padre
fin-registro
```

A continuación, se define el vector que almacenará el árbol, con capacidad para N nodos como máximo:

**ARBOL(N) de NODO**

se define el contador de nodos y se hace cero:

**N_NODOS entero**

**N_NODOS ← 0**

## 8.4.2 Comprobación de árbol vacío

**Comprobación de árbol vacío**

El árbol estará vacío si el contador de elementos es cero.

```
MÓDULO Arbol_vacio devuelve lógico
DATOS
  PARÁMETROS
    Recibe NUM_NODOS entero
INICIO
  Si (NUM_NODOS = 0) entonces
    DEVOLVER Verdadero
  sino
    DEVOLVER Falso
  fin-si
FIN
```

## 8.4.3 Comprobación de árbol lleno

**Comprobación de árbol lleno**

El árbol estará lleno si el contador de elementos es igual al tamaño del vector que aloja el árbol.

```
MÓDULO Arbol_lleno devuelve lógico
DATOS
  PARÁMETROS
    Recibe NUM_NODOS entero
    Recibe N entero
INICIO
  Si (NUM_NODOS = N) entonces
    DEVOLVER Verdadero
  sino
    DEVOLVER Falso
  fin-si
FIN
```

## 8.4.4 Inserción de un nodo

**Inserción de un nodo**

Para insertar un nuevo nodo en el árbol, su información asociada se almacenará en la primera posición libre al final del vector, siempre que dicho vector no esté lleno. Además, si el nuevo nodo no es la raíz del árbol, se debe modificar la información almacenada en el padre, de modo que pase a hacer referencia a su nuevo hijo.

El módulo de inserción recibe como parámetros el vector que implementa el árbol (**ARBOL**), el número de nodos que contiene actualmente el árbol (**NUM_NODOS**), el número de posiciones del vector (**N**), el índice del elemento del vector que contiene la información referente al padre del nuevo nodo, o -1 si el nuevo nodo va a ser la raíz del árbol (**I_P**), la información a almacenar en el campo de datos del nuevo nodo (**NUEVO_DATO**), y un parámetro que indica si el nuevo nodo debe ser hijo derecho (si **DERECHO** es Verdadero) o izquierdo (si es Falso) de su padre. El módulo retorna un valor lógico informando del éxito o fracaso de la operación de inserción:

```
MÓDULO Insertar_nodo devuelve lógico
DATOS
  PARÁMETROS
    Transforma ARBOL(N) de tipo NODO
    Transforma NUM_NODOS entera
    Recibe N entera
    Recibe I_P entera
    Recibe NUEVO_DATO de tipo T
    Recibe DERECHO de tipo lógico
INICIO
  Si ( NUM_NODOS = N ) entonces
    ESCRIBIR "No hay espacio para más nodos"
    DEVOLVER Falso
  fin-si
  Si (I_P ≠ -1) entonces
    Si (DERECHO = Verdadero) entonces
      Si (ARBOL(I_P).HIJO_DERECHO = -1) entonces
        ARBOL(I_P).HIJO_DERECHO ← NUM_NODOS+1
      sino
        ESCRIBIR "Ya existe el hijo derecho"
        DEVOLVER Falso
      fin-si
    sino
      Si (ARBOL(I_P).HIJO_IZQUIERDO = -1) entonces
        ARBOL(I_P).HIJO_IZQUIERDO ← NUM_NODOS+1
      sino
        ESCRIBIR "Ya existe el hijo izquierdo"
        DEVOLVER Falso
      fin-si
    fin-si
  fin-si
  NUM_NODOS ← NUM_NODOS +1
  ARBOL(NUM_NODOS).HIJO_IZQUIERDO ← -1
  ARBOL(NUM_NODOS).HIJO_DERECHO ← -1
  ARBOL(NUM_NODOS).DATO ← NUEVO_DATO
  ARBOL(NUM_NODOS).PADRE ← I_P
  DEVOLVER Verdadero
FIN
```

**Inserción de un nuevo nodo - representación vectorial**

En primer lugar se comprueba si hay espacio en el vector para un nuevo elemento. Si lo hay y el nuevo nodo no es la raíz del árbol, se comprueba que no exista para el padre un hijo en la misma posición que va a ocupar el nuevo (izquierda o derecha). De existir dicho hijo, el proceso concluye sin completar la inserción. De no existir, se modifica la información almacenada en el padre sobre el hijo correspondiente. A continuación, se incrementa el número de elementos almacenados en el árbol y se almacena la información sobre el nuevo nodo, que pasará a ocupar la primera posición libre dentro del vector que contiene los nodos del árbol. Si los nodos del árbol no almacenan información sobre el padre de un nodo, se eliminará del módulo la última asignación incluida.

## 8.4.5 Eliminación de un nodo

**Eliminación de nodos**

Para mantener consistente la información del árbol, y simplificar las operaciones de eliminación, sólo permitiremos eliminar nodos hoja. Como tales nodos no tienen hijos, la eliminación no requerirá determinar un nuevo padre para ningún nodo.

También es sencillo eliminar la raíz o todo el árbol, provocando ambas operaciones que el árbol quede vacío.

**Eliminación de una hoja**

Al eliminar una hoja del árbol se reduce en uno el número de nodos del árbol. Al eliminar un nodo, además de descartar la información referente al mismo dentro del vector **ARBOL**, se debe modificar la información referente a su padre, de forma que se especifique que el padre ha dejado de tener el hijo que se ha eliminado.

Para mantener la información de los nodos del árbol en las primeras **NUM_NODOS** posiciones del vector **ARBOL**, puede ser necesario realizar desplazamientos de los elementos que permanecen en el vector. Si el nodo a eliminar ocupa la posición **R** dentro del vector **ARBOL**, se deben desplazar una posición hacia el comienzo del vector todos los datos comprendidos entre las posiciones **R**+1 y **NUM_NODOS**. Hay que tener en cuenta que al desplazar un nodo a la izquierda se debe actualizar la información de su padre y la de sus posibles hijos, de forma que hagan referencia correcta a la nueva ubicación del nodo dentro del vector.

Se podría plantear otra posibilidad para eliminar del vector la información del nodo. Para evitar los desplazamientos de información dentro del vector, podemos copiar la información del último elemento en la posición del que se va a eliminar. En este caso ya no garantizamos que la información de un nodo aparezca en el vector en una posición posterior a la de su padre.

```
MÓDULO Eliminar_hoja
DATOS
  PARÁMETROS
    Transforma ARBOL(N) de tipo NODO
    Recibe I_HOJA entera
    Transforma NUM_NODOS entera
  VARIABLES
    PADRE entera
INICIO
  PADRE ← Padre(ARBOL, NUM_NODOS, I_HOJA)
  ARBOL(I_HOJA) ← ARBOL(NUM_NODOS)
  Si (ARBOL(PADRE).HIJO_IZQUIERDO = I_HOJA) entonces
    ARBOL(PADRE).HIJO_IZQUIERDO ← -1
  sino
    ARBOL(PADRE).HIJO_DERECHO ← -1
  fin-si
  Si (I_HOJA ≠ NUM_NODOS) entonces
    PADRE ← Padre(ARBOL, NUM_NODOS, NUM_NODOS)
    Si (ARBOL(PADRE).HIJO_IZQUIERDO = NUM_NODOS) entonces
      ARBOL(PADRE).HIJO_IZQUIERDO ← I_HOJA
    sino
      ARBOL(PADRE).HIJO_DERECHO ← I_HOJA
    fin-si
    Si (ARBOL(I_HOJA).HIJO_IZQUIERDO ≠ -1) entonces
      ARBOL(ARBOL(I_HOJA).HIJO_IZQUIERDO).PADRE ← I_HOJA
    fin-si
    Si (ARBOL(I_HOJA).HIJO_DERECHO ≠ -1) entonces
      ARBOL(ARBOL(I_HOJA).HIJO_ DERECHO).PADRE ← I_HOJA
    fin-si
  fin-si
  NUM_NODOS ← NUM_NODOS -1
FIN
```

**Eliminación de un elemento del vector - implementación vectorial**

Se copia la información del último nodo almacenado sobre el elemento del vector que almacena el nodo a eliminar. Para completar la eliminación correctamente, se deben actualizar los padres de la hoja que se elimina y del nodo cuya información se ha desplazado. El padre de la hoja que desaparece del árbol pasará a almacenar -1 en la posición del hijo representado por dicha hoja. El padre del nodo desplazado debe hacer referencia a la nueva ubicación de su hijo. Además, si existe el campo **PADRE** será necesario actualizar la información de los posibles hijos del nodo desplazado, para que identifiquen correctamente la nueva posición de su padre. Esta última actualización se hace necesaria, aunque el nodo eliminado sea una hoja, ya que sucesivas eliminaciones nos llevarán a que el nodo movido no sea necesariamente una hoja.

Para completar la eliminación, se reduce en uno el contador de nodos del árbol.

El módulo **Padre** retorna la posición del padre del nodo almacenado en la posición del vector indicada como tercer argumento de la llamada. Si los nodos almacenan información sobre el padre, simplemente se consultará dicho campo; en caso contrario, será necesario recorrer el árbol hasta encontrar un nodo que tenga como hijo (izquierdo o derecho) al indicado. Esta última operación se basa en la de recorrido del árbol, que se trata más adelante.

**Eliminación de la raíz**

Dado que para insertar un nodo en el árbol, debe existir ya su padre, el primer nodo insertado será la raíz del árbol. Por tanto, dicho nodo ocupará la primera posición del vector **ARBOL**.

Si se desea eliminar la raíz, eliminaremos todo el árbol, siguiendo el procedimiento descrito en el apartado posterior.

**Eliminación del árbol**

La operación se reduce a poner a cero la variable que determina el número de nodos del árbol.

```
MÓDULO Eliminar_arbol
DATOS
  PARÁMETROS
    Transforma NUM_NODOS entera
INICIO
  NUM_NODOS ← 0
FIN
```

## 8.4.6 Modificación del valor de un nodo

**Modificación de un nodo del árbol**

Permite modificar el campo de datos asociado al nodo. También se podrían modificar los campos que referencian a los hijos o al padre, de existir éste último, pero ello requiere comprobar que la estructura resultante sigue siendo un árbol válido.

```
MÓDULO Modificar_nodo
DATOS
  PARÁMETROS
    Transforma ARBOL(N) de tipo NODO
    Recibe POSICION entero
    Recibe NUEVO_VALOR de tipo T
INICIO
  ARBOL(POSICION).DATO ← NUEVO_VALOR
FIN
```

## 8.5 Operaciones en representación con memoria dinámica

**Operaciones en la representación basada en el uso de memoria dinámica**

- Creación del árbol
- Comprobación de árbol vacío
- Inserción de un nodo
- Eliminación de un nodo
- Modificación del valor de un nodo

## 8.5.1 Creación del árbol

**Creación de un árbol vacío**

Para crear el árbol, en primer lugar se define la estructura que representa sus nodos:

```
NODO es registro compuesto por
  DATO de tipo T ** información asociada al nodo
  HIJO_IZQUIERDO puntero a NODO ** puntero al hijo izquierdo
  HIJO_DERECHO puntero a NODO ** puntero al hijo derecho
  PADRE puntero a NODO ** puntero al padre
fin-registro
```

A continuación, se define el puntero que dará acceso al árbol:

**RAIZ puntero a NODO**

y se hace nulo, indicando que el árbol se crea vacío:

**RAIZ ← NULO**

## 8.5.2 Comprobación de árbol vacío

**Comprobación de árbol vacío**

El árbol estará vacío si el puntero a la estructura es nulo.

```
MÓDULO Arbol_vacio devuelve lógico
DATOS
  PARÁMETROS
    Recibe RAIZ puntero a NODO
INICIO
  Si (RAIZ = NULO) entonces
    DEVOLVER Verdadero
  sino
    DEVOLVER Falso
  fin-si
FIN
```

## 8.5.3 Inserción de un nodo

**Inserción de un nodo**

El módulo que realiza la inserción toma como parámetros el puntero a la raíz del árbol, un puntero al padre del nuevo nodo (será NULO si el nuevo nodo es la raíz del árbol), la información que contendrá el nuevo nodo en el campo de datos, y una indicación de si debe ser hijo derecho (Verdadero) o hijo izquierdo (Falso) del padre. El módulo retorna Verdadero si la inserción se completa con éxito y Falso en caso contrario.

```
MÓDULO Insertar_hijo devuelve lógico
DATOS
  PARÁMETROS
    Transforma RAIZ puntero a NODO
    Recibe PADRE puntero a NODO
    Recibe NUEVO_DATO de tipo T
    Recibe DERECHA de tipo lógico
  VARIABLES
    P_HIJO puntero a NODO
INICIO
  Si ( ( (PADRE ≠ NULO) Y (DERECHA = Verdadero) Y
  (PADRE↑.HIJO_DERECHO ≠ NULO) ) O
  ( (PADRE ≠ NULO) Y (DERECHA = Falso) Y
  (PADRE↑.HIJO_IZQUIERDO ≠ NULO) ) O
  ( (PADRE = NULO) Y (RAIZ ≠ NULO) ) ) entonces
  ESCRIBIR "Ya existe un nodo en la posición indicada"
  DEVOLVER Falso
  fin-si
  P_HIJO ← RESERVAR_MEMORIA(TAMAÑO(NODO))
  Si (P_HIJO = NULO) entonces
    DEVOLVER Falso ** inserción anulada
  fin-si
  P_HIJO↑.HIJO_IZQUIERDO ← NULO
  P_HIJO↑.HIJO_DERECHO ← NULO
  P_HIJO↑.DATO ← NUEVO_DATO
  Si (PADRE = NULO) entonces
    RAIZ ← P_HIJO
    P_HIJO↑.PADRE ← NULO
  sino
    Si (DERECHA = Verdadero) entonces
      PADRE↑.HIJO_DERECHO ← P_HIJO
    sino
      PADRE↑.HIJO_IZQUIERDO ← P_HIJO
    fin-si
    P_HIJO↑.PADRE ← PADRE
  fin-si
  DEVOLVER Verdadero ** inserción completada
FIN
```

En primer lugar se comprueba que no exista ya un nodo en la posición del árbol en la que se debe colocar el nuevo. El nuevo nodo puede ocupar tres lugares:

- la raíz del árbol: la inserción será posible si el árbol está vacío.
- hijo derecho de su padre: la inserción será posible si se ha especificado un padre que aún no tenga hijo derecho.
- hijo izquierdo de su padre: la inserción será posible si se ha especificado un padre que aún no tenga hijo izquierdo.

Si la inserción es posible, se reserva espacio para el nuevo nodo del árbol. Si la solicitud de memoria se ha completado con éxito, se almacena en el nuevo nodo la información correspondiente al campo de datos (contenida en **NUEVO_DATO**), y se hacen nulos los punteros a los hijos.

Si el nuevo nodo va a ser la raíz del árbol, se hace que el puntero a la estructura pase a apuntar a dicho nodo. En caso contrario, se enlaza el padre del nodo con su nuevo hijo, considerando el campo de enlace que corresponda a la posición que debe ocupar.

## 8.5.4 Eliminación de un nodo

**Eliminación de nodos**

La representación del árbol basada en el uso de memoria dinámica hace sencillo eliminar cualquier nodo del árbol. Se pueden eliminar tres tipos de nodos, realizando un tratamiento diferente en cada caso:

- una *hoja*: simplemente se hace nulo el campo de enlace desde el padre a esta hoja y se libera la memoria que ocupa la hoja.
- la *raíz*: se eliminará el árbol completo.
- un nudo: se eliminará el subárbol para el que dicho nodo es raíz.

**Eliminación de una hoja**

Para eliminar una hoja del árbol, apuntada por el puntero **P**, se hace nulo el puntero del padre que apuntaba al nodo que se desea eliminar y se libera la memoria asociada al nodo.

```
MÓDULO Eliminar_hoja
DATOS
  PARÁMETROS
    Recibe P puntero a NODO
    Recibe RAIZ puntero a NODO
  VARIABLES
    PADRE puntero a NODO
INICIO
  PADRE ← Padre(P, RAIZ)
  Si (PADRE↑.HIJO_IZQUIERDO = P) entonces
    PADRE↑.HIJO_IZQUIERDO ← NULO
  sino
    PADRE↑.HIJO_DERECHO ← NULO
  fin-si
  LIBERAR(P)
FIN
```

**Eliminación del árbol**

Para eliminar el árbol se utiliza un procedimiento recursivo que en primer lugar elimina los subárboles y, por último, elimina la raíz. Al concluir el módulo el puntero a la raíz del árbol se habrá hecho nulo.

```
MÓDULO Eliminar_arbol
DATOS
  PARÁMETROS
    Transforma RAIZ puntero a NODO
INICIO
  Si (RAIZ ≠ NULO) entonces
    Eliminar_arbol (RAIZ↑.HIJO_IZQUIERDO)
    Eliminar_arbol (RAIZ↑.HIJO_DERECHO)
    LIBERAR(RAIZ)
    RAIZ ← NULO
  fin-si
FIN
```

## 8.5.5 Modificación del valor de un nodo

**Modificación de un nodo del árbol**

Permite modificar el campo de datos asociado al nodo. También se podrían modificar los campos de enlace, pero ello requiere comprobar que la estructura resultante sigue siendo un árbol válido.

```
MÓDULO Modificar_nodo
DATOS
  PARÁMETROS
    Recibe P puntero a NODO
    Recibe NUEVO_VALOR de tipo T
INICIO
  P↑.DATO ← NUEVO_VALOR
FIN
```

## 8.6 Recorrido

**Recorrido del árbol**

El recorrido de un árbol consiste en procesar cada nodo una vez para aplicar algún tratamiento (visualizar el contenido, consultarlo, modificarlo,...).

Se puede aplicar un **recorrido en anchura** o un **recorrido en profundidad**.

El **recorrido en anchura** parte de la raíz del árbol y visita los nodos por niveles. Este recorrido utiliza una cola como estructura auxiliar, para mantener una referencia a los subárboles izquierdo y derecho de cada nodo procesado.

[Figura: image001.gif]

Esquema de los pasos del recorrido en anchura de un árbol binario

El **recorrido en profundidad** visita cada nodo y sus descendientes. Existen 3 variantes: el **recorrido en orden**, en **orden** **previo** y en **orden** **posterior**. En cualquiera de ellos, si el árbol no está vacío se recorrerá la raíz y los dos subárboles, residiendo la diferencia en el orden en que se procesan estos 3 elementos.

En el recorrido en **preorden** u **orden previo** en primer lugar se procesa la raíz del árbol, luego el subárbol izquierdo y, por último, el subárbol derecho.

[Figura: image002.gif]

Esquema de los pasos del recorrido en orden previo de un árbol binario

En el recorrido en **orden** u **orden** **simétrico** se procesa primero el subárbol izquierdo, luego la raíz y, por último, el subárbol derecho.

[Figura: image003.gif]

Esquema de los pasos del recorrido en orden de un árbol binario

En el recorrido en **posorden** u **orden** **posterior** primero se recorre el subárbol izquierdo, luego el derecho y, por último, se aplica el tratamiento al nodo raíz.

[Figura: image004.gif]

Esquema de los pasos del recorrido en orden posterior de un árbol binario

## 8.6.1 Recorrido en representación vectorial

**Recorrido de un árbol representado mediante un vector**

- Recorrido en anchura
- Recorrido en orden
- Recorrido en orden previo
- Recorrido en orden posterior

**Recorrido en anchura**

El árbol se recorre por niveles, comenzando por la raíz y avanzando hacia las hojas.

El módulo propuesto toma como parámetros el vector que almacena la información de los nodos del árbol y el índice de la posición que ocupa el árbol o subárbol que se va a recorrer.

La operación se apoya sobre una cola de enteros, que representan posiciones de nodos dentro del vector. En este caso se considera una cola lineal e implementada mediante el uso de memoria dinámica. Las operaciones de encolado, desencolado y comprobación de cola vacía se describen en el tema que describe las colas.

```
MODULO Recorrido_anchura
DATOS
  PARÁMETROS
    Recibe ARBOL(N) de tipo NODO
    Recibe RAIZ entero
  VARIABLES
    E_C puntero a NODO_COLA ** punt. a la entrada de la cola
    S_C puntero a NODO_COLA ** punt. a la salida de la cola
    P entero
INICIO
  Si (RAIZ = -1) entonces
    ACABAR
  fin-si
  E_C ← NULO
  S_C ← NULO
  Encolar(RAIZ, E_C, S_C )
  Mientras (Cola_vacia(E_C) = Falso) hacer
    Desencolar(P, E_C, S_C)
    TRATAR (ARBOL(P).DATO)
    Si (ARBOL(P).HIJO_IZQUIERDO ≠ -1) entonces
      Encolar(ARBOL(P).HIJO_IZQUIERDO, E_C, S_C)
    fin-si
    Si (ARBOL(P).HIJO_DERECHO ≠ -1) entonces
      Encolar(ARBOL(P).HIJO_DERECHO, E_C, S_C)
    fin-si
  fin-mientras
FIN
```

**Recorrido en orden**

Se recorre el subárbol izquierdo, se trata la raíz y, por último se recorre el subárbol derecho.

```
MODULO Inorden
DATOS
  PARÁMETROS
    Recibe ARBOL(N) de tipo NODO
    Recibe I_R entero
INICIO
  Si (I_R ≠ -1) entonces
    Inorden(ARBOL, ARBOL(I_R).HIJO_IZQUIERDO)
    TRATAR ( ARBOL(I_R) )
    Inorden(ARBOL, ARBOL(I_R).HIJO_DERECHO)
  fin-si
FIN
```

**Recorrido en orden previo**

Se trata la raíz y, a continuación, los subárboles izquierdo y derecho.

```
MODULO Preorden
DATOS
  PARÁMETROS
    Recibe ARBOL(N) de tipo NODO
    Recibe I_R entero
INICIO
  Si (I_R ≠ -1) entonces
    TRATAR ( ARBOL(I_R) )
    Preorden(ARBOL, ARBOL(I_R).HIJO_IZQUIERDO)
    Preorden(ARBOL, ARBOL(I_R).HIJO_DERECHO)
  fin-si
FIN
```

**Recorrido en orden posterior**

Se recorre el subárbol izquierdo, luego el derecho y, por último, se trata la raíz del árbol.

```
MODULO Posorden
DATOS
  PARÁMETROS
    Recibe ARBOL(N) de tipo NODO
    Recibe I_R entero
INICIO
  Si (I_R ≠ -1) entonces
    Posorden(ARBOL, ARBOL(I_R).HIJO_IZQUIERDO)
    Posorden(ARBOL, ARBOL(I_R).HIJO_DERECHO)
    TRATAR ( ARBOL(I_R) )
  fin-si
FIN
```

## 8.6.2 Recorrido en representación con memoria dinámica

**Recorrido de un árbol representado usando memoria dinámica**

- Recorrido en anchura
- Recorrido en orden
- Recorrido en orden previo
- Recorrido en orden posterior

**Recorrido en anchura**

El árbol se recorre por niveles, comenzando por la raíz y avanzando hacia las hojas.

La operación se apoya sobre una cola de punteros a nodos. En este caso se considera una cola lineal e implementada mediante el uso de memoria dinámica. Las operaciones de encolado, desencolado y comprobación de cola vacía se describen en el tema que describe las colas.

```
MODULO Recorrido_anchura
DATOS
  PARÁMETROS
    Recibe RAIZ puntero a NODO
  VARIABLES
    E_C puntero a NODO_COLA   ** punt. a la entrada de la cola
    S_C puntero a NODO_COLA   ** punt. a la salida de la cola
    P puntero a NODO
INICIO
  Si (RAIZ = NULO) entonces
    ACABAR
  fin-si
  E_C ← NULO
  S_C ← NULO
  Encolar(RAIZ, E_C, S_C)
  Mientras (Cola_vacia(E_C) = Falso) hacer
    Desencolar(P, E_C, S_C)
    TRATAR (P↑.DATO)
    Si(P↑.HIJO_IZQUIERDO ≠ NULO)
      Encolar(P↑.HIJO_IZQUIERDO, E_C, S_C)
    Si(P↑.HIJO_DERECHO ≠ NULO)
      Encolar(P↑.HIJO_DERECHO, E_C, S_C)
  fin-mientras
FIN
```

**Recorrido en orden**

Se recorre el subárbol izquierdo, se trata la raíz y, por último se recorre el subárbol derecho.

```
MODULO Inorden
DATOS
  PARÁMETROS
    Recibe RAIZ puntero a NODO
INICIO
  Si (RAIZ ≠ NULO) entonces
    Inorden(RAIZ↑.HIJO_IZQUIERDO)
    TRATAR (RAIZ)
    Inorden(RAIZ↑.HIJO_DERECHO)
  fin-si
FIN
```

**Recorrido en orden previo**

Se trata la raíz y, a continuación, los subárboles izquierdo y derecho.

```
MODULO Preorden
DATOS
  PARÁMETROS
    Recibe RAIZ puntero a NODO
INICIO
  Si (RAIZ ≠ NULO) entonces
    TRATAR (RAIZ)
    Preorden(RAIZ↑.HIJO_IZQUIERDO)
    Preorden(RAIZ↑.HIJO_DERECHO)
  fin-si
FIN
```

**Recorrido en orden posterior**

Se recorre el subárbol izquierdo, luego el derecho y, por último, se trata la raíz del árbol:

```
MODULO Posorden
DATOS
  PARÁMETROS
    Recibe RAIZ puntero a NODO
INICIO
  Si (RAIZ ≠ NULO) entonces
    Posorden(RAIZ↑.HIJO_IZQUIERDO)
    Posorden(RAIZ↑.HIJO_DERECHO)
    TRATAR (RAIZ)
  fin-si
FIN
```

## 8.7 Árboles binarios de búsqueda (ABB)

**Árboles Binarios de Búsqueda**

Un árbol binario de búsqueda es un árbol binario que puede estar vacío y que, si no lo está, cumple las siguientes propiedades:

- Todos los nodos están identificados por una clave única dentro del árbol.
- Las claves de los nodos del subárbol izquierdo son menores que la clave del nodo raíz.
- Las claves de los nodos del subárbol derecho son mayores que la clave del nodo raíz.
- Los subárboles izquierdo y derecho son por si mismos árboles binarios de búsqueda.

[Figura: image001.gif — Ejemplo de árbol binario de búsqueda con claves enteras]

Para seguir utilizando una estructura de nodo similar a la propuesta en apartados anteriores, supondremos que la clave que identifica cada nodo es un campo contenido en la información general del nodo.

```
T es registro compuesto por
  CLAVE de tipo T1
  ** otros posibles campos de datos
fin-registro
```

Las características de este árbol hacen que las operaciones de inserción, eliminación y búsqueda sean diferentes de las generales sobre árboles binarios.

## 8.7.1 Construcción del árbol

**Construcción de un Árbol Binario de Búsqueda**

- Inserción de un nodo
- Eliminación de un nodo

Las operaciones de inserción y eliminación de nodos del árbol deben realizarse de modo que se mantenga la estructura del mismo (que siga siendo un árbol binario de búsqueda). Para poder insertar un nuevo nodo, su clave no debe aparecen todavía en el árbol. Al eliminar un nodo del árbol será necesario comprobar si los nodos que permanecen en el mismo siguen definiendo un árbol binario de búsqueda, reorganizándolos si es necesario.

**Inserción de un nodo en un ABB**

Para realizar una inserción, en primer lugar se busca la clave del nuevo nodo dentro del árbol. Si la búsqueda no tiene éxito, se insertará el nuevo nodo en el punto donde se ha detenido dicha búsqueda, que será el punto del árbol donde, de existir, debería estar ubicado el nodo con la clave del nuevo. El nodo a insertar siempre será un nodo hoja, lo que facilitará la inserción. Si la búsqueda tuvo éxito, significa que no se puede insertar el nuevo nodo, pues su clave ya aparece en el árbol.

A continuación se muestra el algoritmo de inserción para un árbol binario de búsqueda representado mediante memoria dinámica:

```
MÓDULO Insertar devuelve lógico
DATOS
  PARÁMETROS
    Transforma ARBOL puntero a NODO     ** puntero a la raíz del árbol
    Recibe NUEVO_DATO de tipo T         ** infor. del nuevo nodo
  VARIABLES
    P, Q punteros a NODO
    ENCONTRADO lógico
INICIO
  ** búsqueda de la clave en el árbol
  Q ← NULO
  P ← ARBOL
  ENCONTRADO ← Falso
  Mientras ( (P ≠ NULO) Y (ENCONTRADO = Falso) ) hacer
    Q ← P
    Si (NUEVO_DATO.CLAVE = P↑.DATO.CLAVE) entonces
      ENCONTRADO ← Verdadero
    sino
      Si (NUEVO_DATO.CLAVE < P↑.DATO.CLAVE) entonces
        P ← P↑.HIJO_IZQUIERDO
      sino
        P ← P↑.HIJO_DERECHO
      fin-si
  fin-mientras
  ** inserción, si la búsqueda no tuvo éxito
  Si (ENCONTRADO = Falso) entonces
    Si (Q = NULO) entonces              ** se inserta la raíz
      DEVOLVER Insertar_hijo(ARBOL, NULO, NUEVO_DATO, Falso)
    sino
      ** se inserta un hijo izquierdo
      Si (NUEVO_DATO.CLAVE < Q↑.DATO.CLAVE) entonces
        DEVOLVER Insertar_hijo(ARBOL, Q, NUEVO_DATO, Falso)
      ** se inserta un hijo derecho
      sino
        DEVOLVER Insertar_hijo(ARBOL, Q, NUEVO_DATO, Verdadero)
      fin-si
    fin-si
  fin-si
  DEVOLVER Falso                        ** inserción no completada
FIN
```

Para simplificar el algoritmo, el módulo anterior llama al módulo Insertar_hijo ya descrito, pasando como argumentos un puntero a la raíz del árbol, un puntero al padre del nuevo nodo (NULO si el nuevo nodo va a ser la raíz del árbol), la información asociada al nuevo nodo y un valor que determina si el nuevo nodo será hijo derecho o izquierdo del padre.

**Eliminación de un nodo en un ABB**

Una vez encontrado en el árbol el nodo que contiene la clave que se desea eliminar, se procede a su eliminación, redefiniendo además las conexiones necesarias con sus hijos o con su padre, si los tiene. En este sentido se pueden plantear los siguientes casos:

- Se debe eliminar un ***nodo sin hijos***: si el nodo tiene padre, dicho padre dejará de referenciar al hijo que desaparece; si el nodo a eliminar es la raíz del árbol (no tiene padre), dicho árbol quedará vacío.

  [Figura: image001.gif — Eliminación de un nodo hoja de un ABB]
  [Figura: image002.gif — Eliminación de la raíz de un ABB que no contiene más nodos]

- Se debe eliminar un ***nodo que sólo tiene un hijo***: se conecta el padre de dicho nodo con su único hijo; si no existe el padre, el hijo se convierte en nueva raíz del árbol.

  [Figura: image003.gif — Eliminación de un nodo con un solo hijo de ABB - caso de un nudo]
  [Figura: image004.gif — Eliminación de un nodo con un solo hijo de un ABB - caso de la raíz]

- Se debe eliminar un ***nodo que tiene dos hijos***: en este caso se busca en el subárbol izquierdo del nodo (que contiene claves menores que la que se va a eliminar) la mayor de las claves que contiene. Para ello se toma como punto de partida de la búsqueda la raíz del subárbol izquierdo y, dentro de dicho subárbol se recorren las conexiones a los hijos derechos hasta llegar a un nodo sin hijo derecho, que contendrá la mayor de las claves menores que estamos buscando. En ese momento se copia sobre el nodo que se va a eliminar el valor del nodo localizado. Si dicho nodo era una hoja, se elimina; antes de proceder a esta eliminación, se elimina la conexión a la hoja desde su padre. Si el nodo localizado no era una hoja, tendrá un solo hijo (pues sabemos que no tiene hijo derecho). En este caso, ese hijo del nodo que se va a eliminar se conecta con el padre del nodo que se va a eliminar: como hijo izquierdo, si elimino la raíz del subárbol izquierdo analizado, y como hijo derecho si no se trata de la raíz.

  [Figura: image005.gif — Eliminación de un nodo con dos hijos de un ABB - caso de un nudo]
  [Figura: image006.gif — Eliminación de un nodo con dos hijos de un ABB - caso de la raíz]

A continuación se muestra el algoritmo de eliminación de un nodo para un árbol binario de búsqueda representado mediante memoria dinámica:

```
MÓDULO Eliminar devuelve lógico
DATOS
  PARÁMETROS
    Transforma ARBOL puntero a NODO
    Recibe X de tipo T1
  VARIABLES
    P puntero a NODO          ** puntero al nodo que se va a eliminar
    PADRE puntero a NODO      ** puntero al padre de dicho nodo
    R, S punteros a NODO
    ENCONTRADO lógico
INICIO
  ** búsqueda de la clave en el árbol
  PADRE ← NULO
  P ← ARBOL
  ENCONTRADO ← Falso
  Mientras ( (P ≠ NULO) Y (ENCONTRADO = Falso) ) hacer
    Si (X = P↑.DATO.CLAVE) entonces
      ENCONTRADO ← Verdadero
    sino
      PADRE ← P
      Si (X < P↑.DATO.CLAVE) entonces
        P ← P↑.HIJO_IZQUIERDO
      sino
        P ← P↑.HIJO_DERECHO
      fin-si
    fin-si
  fin-mientras
  ** si la búsqueda no tuvo éxito, se acaba
  Si (ENCONTRADO = Falso) entonces
    DEVOLVER Falso
  fin-si
  ** si se debe eliminar un nodo sin hijos
  Si ( (P↑.HIJO_IZQUIERDO = NULO) Y
       (P↑.HIJO_DERECHO = NULO) ) entonces
    ** si se elimina la raíz de un árbol con un solo nodo
    Si (PADRE = NULO) entonces
      ARBOL ← NULO
    ** si se elimina una hoja
    sino
      ** si la hoja es hijo izquierdo de su padre
      Si ( P = PADRE↑.HIJO_IZQUIERDO) entonces
        PADRE↑.HIJO_IZQUIERDO ← NULO
      ** si la hoja es hijo derecho de su padre
      sino
        PADRE↑.HIJO_DERECHO ← NULO
      fin-si
    fin-si
    LIBERAR (P)
  fin-si
  ** si el nodo a eliminar sólo tiene hijo derecho
  Si ( (P↑.HIJO_IZQUIERDO = NULO) Y
       (P↑.HIJO_DERECHO ≠ NULO) ) entonces
    ** si se elimina la raíz de un árbol con más de un nodo
    Si (PADRE = NULO) entonces
      ARBOL ← P↑.HIJO_DERECHO
    ** si se elimina un nudo
    sino
      ** si el nudo es hijo izquierdo de su padre
      Si ( P = PADRE↑.HIJO_IZQUIERDO) entonces
        PADRE↑.HIJO_IZQUIERDO ← P↑.HIJO_DERECHO
      ** si es hijo derecho de su padre
      sino
        PADRE↑.HIJO_DERECHO ← P↑.HIJO_DERECHO
      fin-si
    fin-si
    LIBERAR(P)
  fin-si
  ** si el nodo a eliminar sólo tiene hijo izquierdo
  Si ( (P↑.HIJO_IZQUIERDO ≠ NULO) Y
       (P↑.HIJO_DERECHO = NULO) ) entonces
    ** si se elimina la raíz de un árbol con más de un nodo
    Si (PADRE = NULO) entonces
      ARBOL ← P↑.HIJO_IZQUIERDO
    ** si se elimina un nudo
    sino
      Si ( P = PADRE↑.HIJO_IZQUIERDO) entonces
        PADRE↑.HIJO_IZQUIERDO ← P↑.HIJO_IZQUIERDO
      sino
        PADRE↑.HIJO_DERECHO ← P↑.HIJO_IZQUIERDO
      fin-si
    fin-si
    LIBERAR(P)
  fin-si
  ** si se debe eliminar un nodo con dos hijos
  Si ( (P↑.HIJO_IZQUIERDO ≠ NULO) Y
       (P↑.HIJO_DERECHO ≠ NULO) ) entonces
    R ← P
    S ← P↑.HIJO_IZQUIERDO
    Mientras (S↑.HIJO_DERECHO ≠ NULO) hacer
      R ← S
      S ← S↑.HIJO_DERECHO
    fin-mientras
    Si (S↑.HIJO_IZQUIERDO ≠ NULO) entonces
      Si (R = P) entonces
        R↑.HIJO_IZQUIERDO ← S↑.HIJO_IZQUIERDO
      sino
        R↑.HIJO_DERECHO ← S↑.HIJO_IZQUIERDO
      fin-si
    sino
      Si (R = P) entonces
        R↑.HIJO_IZQUIERDO ← NULO
      sino
        R↑.HIJO_DERECHO ← NULO
      fin-si
    fin-si
    P↑.DATO ← S↑.DATO
    LIBERAR(S)
  fin-si
  DEVOLVER Verdadero
FIN
```

## 8.7.2 Búsquedas

**Búsquedas en un Árbol Binario de Búsqueda**

Dado que los nodos de un árbol binario de búsqueda están ordenados por la clave, la búsqueda de una clave no requiere recorrer todo el árbol.

Supongamos que se desea buscar un elemento con clave **X**. Si la raíz del árbol contiene la clave buscada, la operación concluirá con éxito; si su clave es menor que **X**, la búsqueda debe continuar por el subárbol derecho ya que, de existir un nodo en el árbol con clave **X**, estará en dicho subárbol; si la clave del nodo es mayor que **X**, la búsqueda deberá continuar por el subárbol izquierdo. El proceso continuará hasta que se encuentre un nodo con clave igual a **X** o se llegue a un subárbol vacío. En este último caso, significa que no existe ningún nodo con clave **X** en el árbol.

A continuación se muestra el algoritmo de búsqueda sobre un árbol representado mediante memoria dinámica. Se incluye un algoritmo recursivo y otro no recursivo. Ambos toman como parámetros el puntero que da acceso al árbol sobre el que se va a realizar la búsqueda y el valor de la clave que se debe buscar. Retornan un puntero al nodo que contiene la clave **X** en caso de éxito, y un puntero nulo si no se ha encontrado ningún nodo con la clave especificada:

*Búsqueda en un ABB - procedimiento recursivo:*

```
MÓDULO Buscar_rec devuelve puntero a NODO
DATOS
  PARÁMETROS
    Recibe ARBOL puntero a NODO
    Recibe X de tipo T1        ** valor a buscar
INICIO
  Si (ARBOL = NULO) entonces
    DEVOLVER NULO
  sino
    Si (X = ARBOL↑.DATO.CLAVE) entonces
      DEVOLVER ARBOL
    sino
      Si (X < ARBOL↑DATO.CLAVE) entonces
        DEVOLVER Buscar_rec(ARBOL↑.HIJO_IZQUIERDO, X)
      sino
        DEVOLVER Buscar_rec(ARBOL↑.HIJO_DERECHO, X)
      fin-si
    fin-si
  fin-si
FIN
```

*Búsqueda en un ABB - procedimiento no recursivo:*

```
MÓDULO Buscar_no_recursivo devuelve puntero a NODO
DATOS
  PARÁMETROS
    Recibe ARBOL puntero a NODO
    Recibe X de tipo T1        ** valor a buscar
  VARIABLE
    P puntero a NODO
    ENCONTRADO lógico          ** indicador de nodo encontrado
INICIO
  P ← ARBOL
  ENCONTRADO ← Falso
  Mientras ( (P ≠ NULO) Y (ENCONTRADO = Falso) ) hacer
    Si (P↑.DATO.CLAVE = X) entonces
      ENCONTRADO ← Verdadero
    sino
      Si (X < P↑.DATO.CLAVE) entonces
        P ← P↑.HIJO_IZQUIERDO
      sino
        P ← P↑.HIJO_DERECHO
      fin-si
  fin-mientras
  DEVOLVER P
FIN
```

## 8.8 Montículos binarios

**Montículos binarios (heaps)**

Los montículos (heaps) son un tipo especial de árboles binarios completos.

Un **árbol binario completo** es un árbol binario de profundidad **k** en el que cualquier nodo a un nivel menor que **k**-2 tienen dos hijos y además todo nodo **i** con un descendiente derecho en el nivel **k**-1 tiene un hijo izquierdo y cada descendiente izquierdo del nodo **i** es una hoja en el nivel **k**-1 o tiene dos hijos.

Existen dos tipos de montículos:

- Un **montículo de máximos** es un árbol binario completo en el cual el valor de la clave de cada nodo es mayor o igual que las claves de sus nodos hijos, si los tiene.
- Un **montículo de mínimos** es un árbol binario completo en el cual el valor de la clave de cada nodo es menor o igual que las claves de sus nodos hijos, si los tiene.

[Figura: image001.gif — Ejemplos de montículo con claves enteras]

La clave contenida en el nodo raíz de un montículo de máximos es la mayor clave del árbol, pero esto no quiere decir que sea la única con ese valor. En los montículos de mínimos la raíz contiene la menor clave del árbol, que puede no ser única.

Dado que los montículos son árboles binarios completos, se pueden representar de forma eficiente mediante un vector. Los nodos del árbol se almacenan en el vector comenzando por la raíz y avanzando por niveles hasta las hojas, considerando en cada nivel los elementos de izquierda a derecha según aparecen en la representación gráfica. Con ello, sabemos que:

- el padre del nodo I, ocupa la posición I div 2, si I > 1. (Si I ≤ 1, el nodo no tiene padre)
- el hijo izquierdo del nodo I, ocupa la posición 2I, si 2I ≤ N. (Si 2I > N, el nodo no tiene hijo izquierdo)
- el hijo derecho del nodo I, ocupa la posición 2I+1, si 2I+1 ≤ N. (Si 2I+1 > N, el nodo no tiene hijo derecho)

Representaremos el árbol mediante un vector de tamaño **N**, siendo **N** el número máximo de nodos que puede incluir el árbol. La variable **NUM_NODOS** indicará el número real de nodos que contiene el árbol en cada momento.

```
NUM_NODOS entero
ARBOL(N) de tipo NODO

NODO es registro compuesto por
  DATO de tipo T     ** información asociada al nodo
fin-registro
```

Supondremos que la información de cada nodo del árbol se almacena en un registro similar al descrito en el apartado referente a árboles binarios de búsqueda:

```
T es registro compuesto por
  CLAVE de tipo T1
  ** otros posibles campos de datos
fin-registro
```

## 8.8.1 Construcción del árbol

**Construcción de un montículo**

Las operaciones de inserción y eliminación de nodos del árbol deben realizarse de modo que se mantenga la estructura del mismo (que siga siendo un montículo), restaurando el montículo si es necesario.

- Restauración del montículo
- Inserción de un nodo
- Eliminación de un nodo

**Restauración de un montículo**

La propiedad que caracteriza a un montículo puede ser restaurada eficazmente tras cualquier modificación de un nodo (cambio de su valor, inserción o eliminación). Supongamos que estamos trabajando con un montículo de máximos (cualquier comentario sobre este tipo de montículos se puede extender fácilmente a los montículos de mínimos), en cuyo caso la clave de cualquier nodo debe ser mayor o igual que las claves de sus hijos. Supongamos ahora que se modifica la clave de un nodo. Dicha modificación puede suponer o un aumento o un decremento en el valor de la clave.

Si se incrementa la clave del nodo, es posible que la propiedad del montículo no se cumpla con respecto a sus nodos antecesores, pero no respecto a sus hijos. Esto hace necesario ir ascendiendo por el árbol y comprobar si el nodo modificado es mayor que su padre; si es así, intercambiarlos y repetir el proceso en el nivel superior, hasta el momento en que ya no sea necesario realizar ningún intercambio o se haya llegado al nodo raíz. En cualquier caso, tras este proceso se habrá restaurado la propiedad del montículo.

Si se reduce la clave del nodo, el problema consistirá en comprobar la condición de montículo respecto a sus descendientes. Si la clave del nodo es mayor que las claves de sus hijos, la condición se sigue cumpliendo; en caso contrario, hay que intercambiar el nodo con el hijo que tenga la clave máxima y repetir el proceso tomando como nuevo punto de partida a dicho hijo. Las comprobaciones proseguirán por sucesivos niveles hasta que no se realice ningún intercambio, o hasta llegar a una hoja.

→ Ver apartado 8.8.1.1 *Restauración de un montículo de máximos*.

**Inserción de un nodo**

Para insertar un nuevo nodo en el montículo se coloca en la posición que permite obtener un nuevo árbol completo y, a continuación, se comprueba si es necesario restaurar el montículo.

En la siguiente figura se muestra con una línea punteada la posición que debe ocupar el siguiente nodo que se inserte en el árbol, independientemente del valor de éste, para que el árbol siga siendo completo:

[Figura: image001.gif — Posición del siguiente nodo que se insertará en el montículo]

Como el nuevo nodo se inserta como una hoja, para mantener la propiedad del montículo bastará con aplicar el algoritmo **Restaurar_arriba** a partir del nodo insertado (ver Restauración de un montículo de máximos).

Por tanto, la operación de inserción consiste en insertar el nodo en la primera posición libre del vector que representa el árbol (siempre que el árbol no esté lleno) y, si el árbol ya no es un montículo válido, restablecer la condición de montículo.

El módulo que realiza la inserción retorna Falso si no se puede insertar el nuevo nodo, porque el vector está lleno:

```
MÓDULO Insertar devuelve lógico
DATOS
  PARÁMETROS
    Transforma ARBOL(N) de tipo T    ** vector que representa el árbol
    Recibe NUEVO_DATO de tipo T      ** inform. nuevo nodo
    Transforma NUM_NODOS entero      ** num. nodos del árbol
    Recibe N entero                  ** tam. del vector
INICIO
  Si (NUM_NODOS < N) entonces
    NUM_NODOS ← NUM_NODOS + 1
    ARBOL(NUM_NODOS) ← NUEVO_DATO
    Restaurar_arriba(ARBOL, NUM_NODOS)
    DEVOLVER Verdadero
  sino
    Escribir "No hay espacio para un nuevo nodo"
    DEVOLVER Falso
  fin-si
FIN
```
*Inserción de un nuevo elemento en un montículo de máximos*

**Eliminación de un nodo**

Al eliminar un nodo del árbol se debe obtener un árbol completo, por lo que el nodo que debe desaparecer realmente del árbol es el último. Además, al eliminar un nodo del árbol se deben reorganizar los hijos de éste y los descendientes de los mismos, de forma que se siga cumpliendo la condición de montículo.

[Figura: image002.gif — Posición del siguiente nodo que se eliminará de un montículo]

Para conseguirlo, intercambiaremos la información del nodo a borrar y la del último nodo del montículo, que es el que realmente debe desaparecer de la estructura para seguir teniendo un árbol completo. Tras dicho intercambio se comprueba si es necesario restablecer el montículo. Se deberá aplicar el módulo Restaurar_arriba (si la nueva clave del nodo I es mayor que la previa) o Restaurar_abajo (si es menor) para restaurar esa propiedad (ver Restauración de un montículo de máximos).

```
MÓDULO Eliminar_nodo
DATOS
  PARÁMETROS
    Transforma ARBOL(N) de tipo T    ** vector que representa el árbol
    Transforma NUM_NODOS entero      ** num. nodos del árbol
    Recibe I entero                  ** posición eliminación
  VARIABLES
    D de tipo T
INICIO
  D ← ARBOL(I)
  ARBOL(I) ← ARBOL(NUM_NODOS)
  NUM_NODOS ← NUM_NODOS - 1
  Si (ARBOL(I).DATO.CLAVE ≠ D.DATO.CLAVE) entonces
    Si (ARBOL(I).DATO.CLAVE > D.DATO.CLAVE) entonces
      Restaurar_arriba(ARBOL, I)
    sino
      Restaurar_abajo(ARBOL, NUM_NODOS, I)
    fin-si
  fin-si
FIN
```
*Eliminación de un elemento de un montículo de máximos que ocupa la posición I*

## 8.8.1.1 Restauración de un montículo de máximos

**Restauración de un montículo**

El siguiente módulo permite restaurar la condición de montículo de máximos partiendo de un nodo I hacia la raíz. El módulo recibe como argumentos el vector que representa el árbol y el índice del elemento del vector a partir del cual comienza la restauración de la condición de montículo.

```
MÓDULO Restaurar_arriba
DATOS
  PARÁMETROS
    Transforma ARBOL(N) de tipo T
    Recibe I entera
INICIO
  Si (I > 1) entonces
    Si (ARBOL(I).DATO.CLAVE > ARBOL(I div 2).DATO.CLAVE) entonces
      Intercambiar(ARBOL, I, I div 2)
      Restaurar_arriba (ARBOL, I div 2)
    fin-si
  fin-si
FIN
```
*Restauración de un montículo de máximos hacia la raíz*

Si la clave del nodo I es mayor que la clave de su padre, se intercambian ambos nodos y se repite la comprobación con el nodo padre. El proceso se detendrá cuando se haya llegado a la raíz del árbol (cuando I sea 1), o cuando el padre analizado tenga una clave válida respecto al hijo considerado (cuando la clave del padre sea mayor o igual que la del hijo, dado que estamos considerando un montículo de máximos).

El módulo **Intercambiar**, como su propio nombre indica, intercambiará los valores de los elementos situados en las posiciones del vector indicadas como argumentos. No se incluye este módulo, ya que es muy sencillo de implementar.

El siguiente módulo permite restaurar la condición de montículo de máximos partiendo de un nodo I hacia las hojas del árbol. Recibe como argumentos el vector que representa el árbol (ARBOL), el índice del elemento del vector sobre el que se desea realizar la comprobación (I) y el número de elementos que contiene el vector (NUM_NODOS).

```
MÓDULO Restaurar_abajo
DATOS
  PARÁMETROS
    Transforma ARBOL(N) de tipo T
    Recibe NUM_NODOS entero
    Recibe I entero
  VARIABLES
    MAX entera
INICIO
  MAX ← I
  Si (2*I ≤ NUM_NODOS) entonces
    Si (ARBOL(2*I).DATO.CLAVE > ARBOL(MAX).DATO.CLAVE) entonces
      MAX ← 2*I
    fin-si
  fin-si
  Si (2*I + 1 ≤ NUM_NODOS) entonces
    Si ( ARBOL(2*I+1).DATO.CLAVE >
         ARBOL(MAX).DATO.CLAVE) entonces
      MAX ← 2*I + 1
    fin-si
  fin-si
  Si (MAX ≠ I) entonces
    Intercambiar(ARBOL, I, MAX)
    Restaurar_abajo(ARBOL, NUM_NODOS, MAX)
  fin-si
FIN
```
*Restauración de un montículo de máximos hacia las hojas*

Se considera inicialmente que el nodo I es mayor que sus hijos, independientemente de que éstos existan. El modulo comienza comprobando si la clave de alguno de los hijos del nodo I es mayor que la de I. Si el nodo tiene hijo izquierdo y su clave es mayor que la del padre, se toma como candidato para intercambiarlo con el padre. Si también tiene hijo derecho y su clave es mayor que la del padre o la del hermano (si éste último se tomó como candidato al intercambio en la comprobación anterior), se toma este segundo hijo como candidato para intercambiar con el padre.

Por último, si se ha encontrado un hijo con clave mayor que el padre, se intercambia con éste y se repite el proceso de comprobación sobre el nodo hijo implicado en el intercambio. Sin embargo, si el padre es mayor que sus hijos, el módulo concluye sin intercambios.

## 8.8.2 Algoritmo HeapSort

**Algoritmo Heapsort**

El algoritmo heapsort permite ordenar un vector trabajando con un montículo.

Dado un vector de elementos, el primer paso consiste en construir un montículo a partir de los datos a ordenar (de máximos si se desea una ordenación ascendente y de mínimos si se desea ordenación descendente). Aquí supondremos que deseamos realizar ordenación ascendente. Una vez formado el montículo, la raíz contiene el mayor de los elementos (aunque puede haber otros con el mismo valor). Por tanto, se intercambia éste con el último elemento del vector, con lo que se habrá colocado en la última posición el valor más grande. A continuación, se considera que el vector (y, por tanto, el árbol) tiene un elemento menos (el que se acaba de llevar al final), y se comprueba si el montículo obtenido tras el intercambio es válido. Si el montículo no es válido, se reorganizan sus nodos hasta obtener un montículo de máximos válido. Una vez restablecido el montículo, se aplica la misma operación, intercambiando la raíz del árbol y su último elemento, y restableciendo después el montículo resultante, que tendrá un elemento menos que el anterior. Si se repite este proceso hasta que se tenga un montículo con un único elemento, se conseguirá ordenar el vector.

```
MÓDULO Heapsort
DATOS
  PARÁMETROS
    Transforma ARBOL() de tipo T
    Recibe N entero            ** elementos del vector
  VARIABLES
    I entero
INICIO
  Para I desde 2 hasta N hacer
    Restaurar_arriba(ARBOL, I)
  fin-para
  I ← N
  Mientras (I > 1) hacer
    Intercambiar(ARBOL(1), ARBOL(I))
    I ← I - 1
    Restaurar_abajo(ARBOL, I, 1)
  fin-mientras
FIN
```
