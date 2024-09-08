#include "dansketal.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tal;
    char buffer[256];
    NumberFormat format = {LAST, NEVER, true}; // Standard format, tilpasses efter behov

    printf("Indtast et tal: ");
    if(scanf("%d", &tal) != 1) {
        fprintf(stderr, "Ugyldigt input. Lukker programmet.\n");
        return 1;
    }

    dansketal(tal, buffer, format);
    printf("Resultat: %s\n", buffer);

    return 0;
}