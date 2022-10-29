#include <stdio.h>
#include <stdlib.h>
#include "garbage.h"

Memoria*mem = NULL;

void *malloc2(int size){
    Memoria *novo = (Memoria *)malloc(sizeof(Memoria));
    novo->end = malloc(size);
    novo->cont=1;
    if(mem!=NULL) //verifica se a lista não está vazia
        novo->prox = mem; //se não estiver vazia, o prox é o primeiro elemento da lista
    else
        novo->prox = NULL; //se estiver, o prox é NULL
    mem = novo;
    return novo->end;
}

void atrib2(void **end1, void *end2){
    Memoria *aux = mem;
    while(aux->end!=*end1) //percorre a lista procurando por end1
        aux=aux->prox;
    if(aux!=NULL){
        aux->cont--; //reduz o contador de end1
        aux = mem;
        while(aux->end!=end2) //procura por end2
            aux=aux->prox;
        if(aux!=NULL){
            aux->cont++; //aumenta o contador de end2

            *end1 = end2; //end1 recebe end2
        }
    }
}

void dump(){
    Memoria *aux = mem;
    if(aux==NULL)
        return;
    Memoria *aux2= mem->prox; //auxiliares para percorrer a lista

    if(aux->cont==0){ //verifica se o primeiro elemento precisa ser apagado
        mem = aux2;
        free(aux->end);
        free(aux);
    }
    while(aux2!=NULL){ //percorre a lista apagando todos os elementos com contador 0
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
        if(aux->cont==0){ //verifica se o elemento atual está com contador 0 e chama dump para excluir
            aux = aux->prox;
            dump();
        }
        else{
            printf("Endereco: %d Contador de Ponteiros: %d\n",(int)aux->end,aux->cont); //printa todos os elementos da lista
            aux = aux->prox;
        }
    }
}

void Imprimir_Int(int *v){
    if(v!=NULL){
        printf("\nEndereco %d = %d\n",v, *v); //função para imprimir int alocado na lista
    }
}

void Imprimir_Char(char *v){
    if(v!=NULL){
        printf("\nEndereco %d = %c\n",v, *v); //função para imprimir char alocado na lista
    }
}

