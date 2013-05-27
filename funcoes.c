
int a_esta_fila_vazia(personagem **fila){
    int i;
    for(i=0;i<num_threads;i++)
        if(fila[i] != NULL) return i;
    return 0;
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
        printf("%s quer usar o forno\n", p->nome );

        if(p->id == 1 || p->id == 2)
            pthread_cond_wait(&casais[0], &mutex);  
        else if(p->id == 3 || p->id == 4)
            pthread_cond_wait(&casais[1], &mutex);  
        else if(p->id == 5 || p->id == 6)
            pthread_cond_wait(&casais[2], &mutex); 

    pthread_mutex_unlock(&mutex);
}

int qual_casal_liberar(int id){
    
    int casal_id = 0;
    
    if(id == 1 || id == 2)
        casal_id = 0;
    else if(id == 3 || id == 4 )
        casal_id = 1;
    else if(id == 5 || id == 6)
        casal_id = 2;
    

    return casal_id;
}

int libera_o_que_sobrou(){
    
    int i,casal_id;

    while(a_esta_fila_vazia(fila) > 0){

        if(fila[i] != NULL && fila[i] != usando){
            casal_id = qual_casal_liberar(i);                    
            pthread_cond_signal(&casais[casal_id]); 
            return 1;
        }

        i++;
    }
    return 0;
}

void me_recola_na_fila(personagem *p){
    sleep(3);
    entra_na_fila(p);     
    p->qntsVezesUsoOForno++; 
}

int libera(personagem *atual){
    
    int casal_id;
    int tem_gente = 0;

    int tem_mais_prioridade = 0;
    personagem *homem; 
    
    
    if(atual->id % 2 == 0) homem = atual->namorado; //Quer dizer que é a namorada
    else homem = atual;
    
    if(fila[ homem->TemMaiorPrioridade->id ] != NULL || fila[ homem->TemMaiorPrioridade->namorado->id ] != NULL){
        
        while( fila[ homem->TemMaiorPrioridade->id ] != NULL || fila[ homem->TemMaiorPrioridade->namorado->id ] != NULL){
            
            homem = homem->TemMaiorPrioridade;
            
            if( tem_mais_prioridade > 6 ) deadlock=1;
            tem_mais_prioridade++;

        }
        tem_gente = 1;

    }else if( fila[ homem->id ] != NULL || fila[ homem->namorado->id ] != NULL ){
        tem_gente = 1;
    }

    if(tem_gente == 1){
        casal_id = qual_casal_liberar( homem->id  );                    
        pthread_cond_signal(&casais[casal_id]); 
        return 1;
    }else {
        libera_o_que_sobrou();
        return 1;
    }

    return 0;

}

void fui_comer(personagem *p){

    fila[p->id] = NULL;

    printf("%s foi comer\n", p->nome );

    libera(p); 


    sleep(3);

    if(vezes_entra_fila > p->qntsVezesUsoOForno){
        me_recola_na_fila(p);   
    }
}

void esquenta_comida(personagem *p){
    
    usando_forno--;

    printf("%s ,ESTA USANDO O FORNO\n",p->nome);  

    usando = p;

    sleep(1);  

    usando_forno++;

    fui_comer(p);

} 
int verifica_deadlock(){
    if(deadlock == 1) return 1;
    else return 0;
}

void *quebra_o_galho_raj(void *vargp){
    personagem *a = (personagem *) vargp; 
    while(a_esta_fila_vazia(fila) > 0){
        
        sleep(5);

        if(verifica_deadlock() == 1){
            printf("Quebra nosso galho raj\n");
            deadlock = 0;
            libera_o_que_sobrou();
        }
    }
}

void *usar_forno(void *vargp)
{
    int i;
    personagem *a = (personagem *) vargp; 

    entra_na_fila(a);

    while(a_esta_fila_vazia(fila) > 0){      
        if(usando_forno == 1 && fila[ a->id ] != NULL)
            esquenta_comida(a);
        else if(fila[a->id] != NULL)
            espera_o_forno(a);      
    }
    
    printf("%s foi embora\n", a->nome );
    pthread_exit((void *)NULL);
}
