#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#define NUM_PERSONAGENS 7

#include "funcoes.h"



int main() {

    //Variaveis
    int i;
    personagem *p[NUM_PERSONAGENS];
    //Variavel só para setar os nomes
    char *nome_personagens[NUM_PERSONAGENS] = { "Raj" ,"Sheldon" , "Amy" , "Howard" ,  "Bernadete" , "Leonard" ,  "Penny"  }; 

    for(i=0;i<NUM_PERSONAGENS;i++)
        p[i] = inicializa_personagem(i,nome_personagens[i]); // Inicializa Os Personagens

    
    for(i=1;i<NUM_PERSONAGENS;i++)
        if(i%2 == 1) seta_prioridade(p[i],p[(i+2)%6]); 
        else seta_prioridade(p[i],p[i]);

    seta_namorado(p[1],p[2]);
    seta_namorado(p[3],p[4]);
    seta_namorado(p[5],p[6]);

    for(i = 0; i < NUM_PERSONAGENS; i++) 
        fila[i] = NULL; // Inicializa a fila de espera dos personagens
    
    pthread_t tid[NUM_PERSONAGENS];

    // Cria o mutex
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&casais[0], NULL); 
    pthread_cond_init(&casais[1], NULL); 
    pthread_cond_init(&casais[2], NULL); 
    
    //Cria as threads
    // for(i=3; i<num_threads; i++)
        // pthread_create(&(tid[i]), NULL, usar_forno, (void *)(p[i]));

    pthread_create(&(tid[0]), NULL, quebra_o_galho_raj, (void *)(p[0]));
    pthread_create(&(tid[1]), NULL, usar_forno, (void *)(p[1]));
    pthread_create(&(tid[4]), NULL, usar_forno, (void *)(p[4]));
    pthread_create(&(tid[5]), NULL, usar_forno, (void *)(p[5]));
    sleep(5);
    pthread_create(&(tid[2]), NULL, usar_forno, (void *)(p[2]));
    sleep(3);
    pthread_create(&(tid[5]), NULL, usar_forno, (void *)(p[6]));
    pthread_create(&(tid[3]), NULL, usar_forno, (void *)(p[3]));

    
    
    // Espera que as threads terminem
    for(i=0; i< num_threads; i++){
        pthread_join(tid[i], NULL);
    }


    // Destroi o mutex
    pthread_mutex_destroy(&mutex); 
    pthread_cond_destroy(&casais[0]);
    pthread_cond_destroy(&casais[1]);
    pthread_cond_destroy(&casais[2]);

    pthread_exit((void *)NULL);
}
