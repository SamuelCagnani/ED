#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__ 
#include <sys/time.h>
#include <time.h>
#elif _WIN32
#include <sys/time.h>
#endif

#define TAM 10000
#define OPCAO 1   // 0 = vetor ordenado e 1 = aleatório

struct pessoa {
	char nome[30];
	int idade;
};

void bubblesort(int vetor[], int n) ;
void bubbleMelhorado ( int *item ,int count );
void bubblesort_plus (int vetor[], int n);
void inserctionSort(int *item ,int count);

int main()
{
	unsigned int i,v, j = 0;
	struct timeval start, stop;
	double secs = 0;
	clock_t inicio, fim;
    double tempo_decorrido;
	srand(time(NULL)); //chama apenas 1 vez*/

	int *vetor = (int *)malloc(TAM * sizeof(int));
	int *vetor1 = (int *)malloc(TAM * sizeof(int));
	int *vetor2 = (int *)malloc(TAM * sizeof(int));
	int *vetor3 = (int *)malloc(TAM * sizeof(int));

	if (vetor == NULL)
	{
		printf("Nao foi possivel alocar o vetor");
		return 0;
	}

	for (i = 0; i < TAM; i++)
	{
		if (OPCAO) //faz se OPCAO 1
		{
			v=rand() % TAM;
			*(vetor + i) = v; // retorna um valor entre 0 e TAM  | *(vetor + 1) = vetor[i]
			*(vetor1 + i) = v;
			*(vetor2 + i) = v;
			*(vetor3 + i) = v;
		}
		else
		{
			*(vetor + i) = i;
		}
	}
//vetor1=vetor;
//vetor2=vetor;
	
    printf("Imprime as 10 ultimas posicoes: ");
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor + j));
		
	}
	
	printf("\n");
	
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor1 + j));
	}

	printf("\n");
	
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor2 + j));
	}

	printf("\n");
	
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor3 + j));
	}

	printf("\n\n");

	gettimeofday(&start, NULL);
	
	bubblesort_plus(vetor2,TAM);
    
	
	gettimeofday(&stop, NULL);
    printf("\nFinaliza funcao plus...");
    //tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    //printf("Tempo decorrido: %f segundos\n", tempo_decorrido);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("\nTempo decorrido %f em segundo(s)\n", secs);

    printf("\nCarrega funcao...");
    gettimeofday(&start, NULL);
	
	bubblesort(vetor,TAM);
    
	
	gettimeofday(&stop, NULL);
    printf("\nFinaliza funcao padrão...");
    //tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    //printf("Tempo decorrido: %f segundos\n", tempo_decorrido);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("\nTempo decorrido %f em segundo(s)\n", secs);
	
	gettimeofday(&start, NULL);
	
	bubbleMelhorado(vetor1,TAM);
    
	
	gettimeofday(&stop, NULL);
    printf("\nFinaliza funcao melhorada...");
    //tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    //printf("Tempo decorrido: %f segundos\n", tempo_decorrido);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("\nTempo decorrido %f em segundo(s)\n", secs);

	gettimeofday(&start, NULL);

	inserctionSort(vetor3, TAM);

	gettimeofday(&stop, NULL);
	printf("\nFinaliza funcao inserction...");
	//tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    //printf("Tempo decorrido: %f segundos\n", tempo_decorrido);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("\nTempo decorrido %f em segundo(s)\n", secs);
	

	printf("\nImprime as 10 ultimas posicoes: ");
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor + j));
	}
	printf("\n");
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor1 + j));
	}
	printf("\n");
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor2 + j));
	}

    free(vetor);
}

void bubblesort (int vetor[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void bubblesort_plus (int vetor[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }n--;
    }
}



void bubbleMelhorado ( int *item ,int count ){
int n=1,i, troca =1, aux;
while (n <= count && troca == 1){
troca = 0;
for(i=0;i<count -1;i ++){
   if( item [i] > item [i +1]){
      troca = 1;
      aux = item [i];
      item [i] = item [i +1];
      item [i+1] = aux ;
             }
   }n=n+1;
}
}

void inserctionSort(int *item ,int count) 
{

	int i, j, eleito;

    for(i = 1; i <= count; i++) 
    {
        eleito = item[i];
        j = i - 1;

        while(j >= 0 && item[j] > eleito) 
        {
            item[j+1] = item[j];
            j--;
        }

        item[j+1] = eleito;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);
    }

}