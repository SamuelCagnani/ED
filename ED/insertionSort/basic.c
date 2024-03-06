#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j, eleito;
    int count = 5;
    int vetor[] {5,2,8,9,1};
    int * item = vetor;

    for(i = 1; i <= cont; i++) 
    {
        eleito = item[i];
        j = i - 1;

        while(j >= 0 && item[j] > eleito) 
        {
            item{j+1} = item[j];
            j--;
        }

        item[j+1] = eleito;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);
    }


    return 0;
}