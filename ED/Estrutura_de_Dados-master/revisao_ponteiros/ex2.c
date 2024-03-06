#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a = 4, b = 3;
    int *p1, *p2;

    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;

    printf("p1 = %d\np2 = %d\n", *p1, *p2); 
    printf("a = %d\nb = %d\n", a, b);

    return 0;
}