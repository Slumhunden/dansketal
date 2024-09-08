#ifndef DANSKETAL_H
#define DANSKETAL_H

#include <stdbool.h>

typedef enum {
    NEVER,
    EVERY,
    LAST
} occurence; //definerer hvor ofte et tal skal vises som string, afhængig af hvor mange tal er i strengen

typedef struct {
    occurence og;
    occurence e; // om 'e' skal visses i et tal, eller ikke f.eks. 100 = ethundredE eller 100 = et hundrede
    bool et_prefix;
} NumberFormat; //definerer hvordan et tal skal vises i en streng - som hvor ofte 'og' skal vises, og hvor ofte 'et' skal vises, afhængig af talets størrelse

void dansketal(int n, char *buffer, NumberFormat format); //formaterer et tal til en streng - bruger en pointer til et char-array som buffer, der skal indeholde strengen

#endif // DANSKETAL_H