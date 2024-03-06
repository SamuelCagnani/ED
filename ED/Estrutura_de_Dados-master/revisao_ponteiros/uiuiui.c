#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int victor[] = {4,2,1,3,5};
    int numeroPosicao = 5;
    int aux;
    int test = 0;

    for(int n = 1; n <= numeroPosicao; n++)
    {
        for(int i = 0; i < numeroPosicao; i++)
        {
            aux = victor[i];
            victor[i] = victor[i+1];
            victor[i+1] = aux;
            for(int h = 0; h < (numeroPosicao-1); h++) 
            {
                if(victor[h] > victor[h+1]) 
                {
                    test = 1;
                } else {
                    test = 0;
                }
                if(test = 0) {

                    for(int y = 0; y < numeroPosicao; y++) 
                    {
                        printf("%d\n", victor[y]);
                    }
                    return 5;
                }
            }
        }
    }

    for(int y = 0; y < numeroPosicao; y++) 
                    {
                        printf("%d\n", victor[y]);
                    }

    return 0;
}