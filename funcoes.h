#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "personagens.h"   

pthread_mutex_t mutex; 
pthread_cond_t cond; 

personagem *fila[7];
int _fila_vazia = -1;

void *usar_forno(void *vargp);

int fila_vazia(personagem **fila,int tamanho);

#include "funcoes.c"