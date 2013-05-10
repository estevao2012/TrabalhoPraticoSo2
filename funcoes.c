void *usar_forno(void *vargp)
{
    // Converte a estrutura recebida
     

    personagem *a = (personagem *) vargp; 
    
    incluir_personagem(fila,a);
    
    // sleep(1);
    
    printf("%s esta esperando o forno\n",a->nome);

    pthread_mutex_lock(&mutex);

    printf("%s ,Comeco a usar o forno\n",a->nome); 
    sleep(10);
    printf("%s ,Finalizo no forno\n",a->nome); 

    pthread_mutex_unlock(&mutex);

    sleep(3);
    // printf("%s esta comendo\n", a->nome );
   

    pthread_exit((void *)NULL);
}
