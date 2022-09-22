#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = malloc2(sizeof(int));
    *a = 13;
    int *b = malloc2(sizeof(int));
    *b = 15;
    char *c = malloc2(sizeof(char));
    *c = 'a';
    Imprimir_Int(a);
    Imprimir_Int(b);
    Imprimir_Char(c);
    atrib2(&a,b);
    Imprimir_Mem();
    return 0;
}
