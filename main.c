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
    int i,id_amigo;
    personagem *p[NUM_PERSONAGENS];
    //Variavel só para setar os nomes
    char *nome_personagens[NUM_PERSONAGENS] = { "Raj" ,"Sheldon" , "Amy" , "Howard" ,  "Bernadete" , "Leonard" ,  "Penny"  }; 

    for(i=0;i<NUM_PERSONAGENS;i++) p[i] = inicializa_personagem(i,nome_personagens[i]); // Inicializa Os Personagens

    for(i=1;i<NUM_PERSONAGENS;i++) //Determina as prioridades de cada personagem
        if(i%2 == 1) seta_prioridade(p[i],p[(i+2)%6]);
        else seta_prioridade(p[i],p[i]);
 
    for(i = 0; i < NUM_PERSONAGENS; i++) fila[i] = NULL; // Inicializa a fila de espera dos personagens
    
    pthread_t tid[NUM_PERSONAGENS];

    // Cria o mutex
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    
    //Cria as threads
    for(i=1; i<NUM_PERSONAGENS; i++)
        pthread_create(&(tid[i]), NULL, usar_forno, (void *)(p[i]));
    
    
    // Espera que as threads terminem
    for(i=1; i<NUM_PERSONAGENS; i++){
        pthread_join(tid[i], NULL);
    }


    // Destroi o mutex
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    pthread_exit((void *)NULL);
}
