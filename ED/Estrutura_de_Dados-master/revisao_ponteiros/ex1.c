#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int * px, int * py);

int main() 
{
    int x = 3, y = 4;
    func(&x, &y);
    printf(" x = %d\n y = %d\n", x, y);

    return 0;
}

void func(int * px, int * py)
{
    px = py;
    *py = (*py) * (*px);
    *px+=2;
}