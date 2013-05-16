
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
    
    _fila_vazia++;

    if(_fila_vazia == 0){
            
        pthread_mutex_lock(&mutex);

            printf("%s ,ESTA USANDO O FORNO\n",a->nome);  
            
            sleep(10); 

           _fila_vazia--;

            printf("%s ,Foi comer\n",a->nome); 


        pthread_mutex_unlock(&mutex);
        

        pthread_cond_broadcast(&cond);
    }else{
        
        fila[a->id] = a;
        
        printf("%s entro na fila e ta esperando\n",a->nome);
        
        pthread_cond_wait(&cond, &mutex); 
        
        printf("%s Cabo de Esperar\n",a->nome);
    }

    

    // pthread_mutex_unlock(&mutex);
    

    pthread_exit((void *)NULL);
}
