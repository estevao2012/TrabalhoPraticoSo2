#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "personagens.h"  
#include "monitor.h"

pthread_mutex_t mutex;

monitor *fila;

void *usar_forno(void *vargp);

#include "funcoes.c"