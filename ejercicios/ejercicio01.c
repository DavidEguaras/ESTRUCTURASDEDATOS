#include <stdio.h>
#include <stdbool.h>

/**/
void readTwoIntegers(int *a, int *b)
{
    printf("Please, enter two int numbers: \n");
    scanf("%d %d", a, b);
}

int addTwoIntegers(int a, int b)
{
    return a + b;
}

int substractTwoIntegers(int a, int b)
{
    return a - b;
}

int multiplyTwoIntegers(int a, int b)
{
    return a * b;
}

float divideTwoIntegers(int a, int b)
{
    return (float)a / b;
}

int maxOfTwoIntegers(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

bool isEven(int n)
{
    return n % 2 == 0;
}

int main(void)
{
    int x, y;

    printf("Exercise1: Automatic Calculator\n");
    // call the necessary functions
    readTwoIntegers(&x, &y);
    int addition = addTwoIntegers(x, y);
    int substraction = substractTwoIntegers(x, y);
    int product = multiplyTwoIntegers(x, y);
    float division = divideTwoIntegers(x, y);
    int max = maxOfTwoIntegers(x, y);
    bool evenNumber = isEven(x);

    printf("You entered %d and %d\n", x, y);
    printf("Addition: %d\n", addition);
    printf("Substraction: %d\n", substraction);
    printf("Product: %d\n", product);
    printf("Division: %.2f\n", division);
    printf("Max: %d\n", max);

    if (evenNumber == 0)
    {
        printf("%d Is not even\n", x);
    }
    else
    {
        printf("%d Is even", x);
    }

    return 0;
}
