#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include "funcoes.h"

#define NUM_PERSONAGENS 7


int main() {

    //Variaveis
    int i;
    personagem *p[NUM_PERSONAGENS];
    char *nome_personagens[NUM_PERSONAGENS] = { "Raj" ,"Sheldon" , "Amy" , "Leonard" ,  "Penny"  , "Howard" ,  "Bernadete"}; //Variavel só para setar os nomes


    fila = malloc(sizeof(monitor*));
    inicializa_monitor(fila);   

    for(i=0;i<NUM_PERSONAGENS;i++){
        p[i] = inicializa_personagem(i,nome_personagens[i]);
        seta_prioridade(p[i],i);
    }  
    
    pthread_t tid[NUM_PERSONAGENS];

    // Cria o mutex
    pthread_mutex_init(&mutex, NULL);
 
    //Cria as threads
    for(i=1; i<NUM_PERSONAGENS; i++){
        pthread_create(&(tid[i]), NULL, usar_forno, (void *)(p[i]));
    }

    // Espera que as threads terminem
    for(i=1; i<NUM_PERSONAGENS; i++){
        pthread_join(tid[i], NULL);
    }
    // printf("todos personagens\n");

    // mostra_personagens(fila);

    // Destroi o mutex
    pthread_mutex_destroy(&mutex);

    pthread_exit((void *)NULL);
}
