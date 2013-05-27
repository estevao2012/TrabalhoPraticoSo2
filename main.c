#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#define NUM_PERSONAGENS 7

#include "monitor.h"

int main(int argc , char **argv) {

    //Variaveis
    int i;
    pthread_t tid[NUM_PERSONAGENS];
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
    

    if(argv[1]) vezes_entra_fila = (int)atoi(argv[1]);
    
    zera_uso_forno_casais();

    // Cria o mutex
    pthread_mutex_init(&mutex, NULL);
    //Cria variaveis de condição
    pthread_cond_init(&casais[0], NULL); 
    pthread_cond_init(&casais[1], NULL); 
    pthread_cond_init(&casais[2], NULL); 
    
    //Inicia o Raj
    pthread_create(&(tid[0]), NULL, quebra_o_galho_raj, (void *)(p[0]));

    //Cria as threads
    for(i=1; i<num_threads; i++)
        pthread_create(&(tid[i]), NULL, usar_forno, (void *)(p[i])); 
    
    // Espera que as threads terminem
    for(i=0; i < num_threads; i++){
        pthread_join(tid[i], NULL);
    }

    // Destroi o mutex
    pthread_mutex_destroy(&mutex); 
    //Destroi as variaveis de condição
    pthread_cond_destroy(&casais[0]);
    pthread_cond_destroy(&casais[1]);
    pthread_cond_destroy(&casais[2]);

    pthread_exit((void *)NULL);
}
