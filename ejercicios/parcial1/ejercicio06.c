#include <stdio.h>
#include <stdbool.h>

int intInput(void)
{
    int number;
    scanf("%d", &number);
    return number;
}

int linearSearch(int array[], int arrayLength, int numberToFind)
{
    int i = 0;
    while (array[i] != numberToFind && i < arrayLength - 1)
    {
        i++;
    }

    if (array[i] == numberToFind)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

// en principio parece que son iguales la diferncia esta en que si se esta buscando un elemento que NO ESTA, este es mucho mas eficiente
int orderedLinearSearch(int array[], int arrayLength, int numberToFind)
{
    int i = 0;
    while (array[i] != numberToFind && i < arrayLength - 1 && array[i] < numberToFind)
    {
        i++;
    }

    if (array[i] == numberToFind)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void showResult(int numberToFind, int position)
{
    if (position != -1)
    {
        printf("Number %d found in position %d\n", numberToFind, position + 1);
    }
    else
    {
        printf("Number %d not found\n", numberToFind);
    }
}

int main(void)
{
    int v[8] = {15, 18, 7, 75, 14, 13, 43, 40};
    int rep[5] = {5, 3, 5, 8, 5};
    int ord[9] = {7, 13, 14, 15, 18, 26, 40, 43, 51};

    printf("Choose a number to find in array1: ");
    int numberToFind = intInput();
    showResult(numberToFind, linearSearch(v, 8, numberToFind));
    printf("Choose a number to find in array2: ");
    numberToFind = intInput();
    showResult(numberToFind, linearSearch(rep, 5, numberToFind));

    // comprabacion para vector ordenado
    printf("Choose a number to find in the ordered array (array3): ");
    numberToFind = intInput();
    showResult(numberToFind, linearSearch(ord, 9, numberToFind));

    return 0;
}