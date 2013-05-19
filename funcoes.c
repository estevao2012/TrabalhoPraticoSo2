
int a_esta_fila_vazia(personagem **fila){
    int i;
    for(i=0;i<num_threads;i++)
        if(fila[i] != NULL) return 0;
    return 1;
}

void entra_na_fila(personagem *p){
    fila[p->id] = p;
}

void mostra_fila(){
    int i;
    for(i=1;i<num_threads;i++)
        if(fila[i] != NULL)
            printf("%s Esta na fila \n", fila[i]->nome );
}

void espera_o_forno(personagem *p){
    pthread_mutex_lock(&mutex);
        pthread_cond_wait(&forno, &mutex);  
    pthread_mutex_unlock(&mutex);
}

void esquenta_comida(personagem *a){
    
    fila_vazia--;

    printf("%s ,ESTA USANDO O FORNO\n",a->nome);  
    sleep(1); 
    printf("%s Finalizo\n",a->nome);
    usando = a;
    fila_vazia++;

    fila[a->id] = NULL;

    pthread_cond_broadcast(&forno);
}

void libera_personagem(personagem *p){
    // int i;
    // for(i=1;i<num_threads; i++){

    // }
    
    if(p->id != 1){
        sleep(5);
    }else{

    }
}

void *usar_forno(void *vargp)
{
    int i;
    personagem *a = (personagem *) vargp; 

    printf("%s entra na fila\n", a->nome );
    entra_na_fila(a);

    while(a_esta_fila_vazia(fila) == 0){
        
        if(fila_vazia == 1 && fila[a->id] != NULL){
            esquenta_comida(a);
        }else{
            espera_o_forno(a);
        } 
        libera_personagem(a);
    }
     
    pthread_exit((void *)NULL);
}
