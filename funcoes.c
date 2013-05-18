
int a_esta_fila_vazia(personagem **fila,int tamanho){
    int i;
    for(i=0;i<tamanho;i++)
        if(fila[i] != NULL) return 0;
    return 1;
}

void espera_o_forno(personagem *p){
    fila[p->id] = p;
    // printf("%s entro na fila e ta esperando\n",p->nome);

    pthread_mutex_lock(&mutex);
        printf("%s eh o proximo a entrar\n", p->nome );
        pthread_cond_wait(&forno, &mutex); 
    pthread_mutex_unlock(&mutex);
}

void esquenta_comida(personagem *a){

    
        
    // pthread_mutex_lock(&mutex);
        
        fila_vazia--;

        printf("%s ,ESTA USANDO O FORNO\n",a->nome);  
        sleep(3); 
        printf("%s Finalizo\n",a->nome);
        pthread_cond_broadcast(&forno);

        fila_vazia++;

    // pthread_mutex_unlock(&mutex);
    
    
}

void *usar_forno(void *vargp)
{
    int i;
    personagem *a = (personagem *) vargp; 
    
    if(fila_vazia == 1){
        esquenta_comida(a);
    }else{
        espera_o_forno(a);
        
        if(fila_vazia == 1){
            esquenta_comida(a);
        }else{
            espera_o_forno(a);
        } 
    } 
     
    pthread_exit((void *)NULL);
}
