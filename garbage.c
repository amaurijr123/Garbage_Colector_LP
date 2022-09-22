#include <stdio.h>
#include <stdlib.h>
#include "garbage.h"

Memoria*mem = NULL;

void *malloc2(int size){
    Memoria *novo = (Memoria *)malloc(sizeof(Memoria));
    novo->end = malloc(size);
    novo->cont=1;
    if(mem!=NULL)
        novo->prox = mem;
    else
        novo->prox = NULL;
    mem = novo;
    return novo->end;
}

void atrib2(void **end1, void *end2){
    Memoria *aux = mem;
    while(aux->end!=*end1)
        aux=aux->prox;
    if(aux!=NULL){
        aux->cont--;
        aux = mem;
        while(aux->end!=end2)
            aux=aux->prox;
        if(aux!=NULL){
            aux->cont++;

            *end1 = end2;
        }
    }
}

void dump(){
    Memoria *aux = mem;
    if(aux==NULL)
        return;
    Memoria *aux2= mem->prox;

    if(aux->cont==0){
        mem = aux2;
        free(aux->end);
        free(aux);
    }
    while(aux2!=NULL){
        if(aux2->cont==0){
            aux->prox = aux2->prox;
            free(aux2->end);
            free(aux2);
        }
        aux=aux2;
        aux2=aux2->prox;
    }
}

void Imprimir_Mem(){
    printf("\nMemoria:\n");
    Memoria *aux = mem;
    while(aux!=NULL){
        if(aux->cont==0)
            dump();
        else{
            printf("Endereco: %d Contador de Ponteiros: %d\n",(int)aux->end,aux->cont);
        }
        aux = aux->prox;
    }
}

void Imprimir_Int(void *v){
    if(v!=NULL){
        printf("\nEndereco %d = %d\n",v, *((int*)v));
    }
}

void Imprimir_Char(char *v){
    if(v!=NULL){
        printf("\nEndereco %d = %c\n",v, *v);
    }
}

