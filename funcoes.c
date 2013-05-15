
int fila_vazia(personagem **fila,int tamanho){
    int i;
    for(i=0;i<tamanho;i++)
        if(fila[i] != NULL) return 0;
    return 1;
}

void *usar_forno(void *vargp)
{
    // Converte a estrutura recebida
     
    int i;
    personagem *a = (personagem *) vargp; 
    // pthread_mutex_lock(&mutex);
    sleep(3);
    printf("%s Chegou\n",a->nome );
    _fila_vazia++;
    if(_fila_vazia == 0){
            
        // pthread_mutex_lock(&mutex);

            printf("%s ,ESTA USANDO O FORNO\n",a->nome); 
        
            // for(i=1;i<7;i++)
            //     if(fila[i] != NULL)
            //         printf("Ta na fila: %s\n", fila[i]->nome);
            //     else printf("Posicao %d vazia\n",i);
            
            sleep(10); 
            _fila_vazia--;
            printf("%s ,Finalizo no forno\n",a->nome); 
            pthread_cond_signal(&cond);
        // pthread_mutex_unlock(&mutex);
        
    }else{
        fila[a->id] = a;
        printf("%s entro na fila\n",a->nome);
        pthread_cond_wait(&cond, &mutex);            
        printf("FOI NAO\n");
    }

    

    // pthread_mutex_unlock(&mutex);
    printf("%s esta comendo\n", a->nome ); 

    pthread_exit((void *)NULL);
}
