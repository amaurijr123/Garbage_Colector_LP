#ifndef GARBAGE_H
#define GARBAGE_H

typedef struct memoria{
    void *end;
    int cont;
    struct memoria *prox;
}Memoria;

void *malloc2(int size);

void atrib2(void **end1, void*end2);

void dump();

void Imprimir_Mem();

void Imprimir_Var(void *v);

void Imprimir_Char(char *v);
#endif // GARBAGE_H
