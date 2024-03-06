#include <stdio.h>
#include <stdlib.h>

// Implementação da função strcpy
void strcpy_custom(char *destino, char *origem) {
    while (*origem) {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0'; // Adiciona o caractere nulo de terminação no final da string de destino
}

// Implementação da função strcat
void strcat_custom(char *destino, char *origem) {
    // Percorre até o final da string de destino
    while (*destino) {
        destino++;
    }

    // Copia a string de origem para o final da string de destino
    while (*origem) {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0'; // Adiciona o caractere nulo de terminação no final da string de destino
}

int main() {
    char destino[50] = "Hello, ";
    char origem1[] = "world!";
    char origem2[] = " Welcome to the C programming world!";

    // Teste da função strcpy_custom
    printf("Copiando a string 'world!' para 'destino':\n");
    strcpy_custom(destino, origem1);
    printf("Resultado: %s\n\n", destino);

    // Teste da função strcat_custom
    printf("Anexando a string ' Welcome to the C programming world!' em 'destino':\n");
    strcat_custom(destino, origem2);
    printf("Resultado: %s\n", destino);

    return 0;
}
