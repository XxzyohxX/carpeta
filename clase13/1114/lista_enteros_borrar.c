

struct nodo {
    struct nodo *sig;
    int dato;
};

typedef struct {
    struct nodo *prim;
} lista_t;
//         forma de puntero a nodo  (se usa el caso particular del primero)
void lista_enteros_borrar(lista_t *l, int e) {
    while(l->prim != NULL && l->prim->dato == e) { //
        struct nodo *actual = l->prim;             // caso particular
        l->prim = actual->sig;			   //
        free(actual);				   //
    }

    if(l->prim == NULL)
        return;

    struct nodo *anterior = l->prim;
    while(anterior->sig != NULL) {		   //
        struct nodo *actual = anterior->sig;       //
					  	   // caso general 
        if(actual->dato == e) {			   //
            anterior->sig = actual->sig;	   //
            free(actual);		           //
        }
        else
            anterior = actual;
    }

}

// forma de puntero doble a nodo
void lista_enteros_borrar(lista_t *l, int e) {
    struct nodo **anterior = &l->prim;
    while(*anterior != NULL) {
        struct nodo *actual = *anterior;

        if(actual->dato == e) {
            *anterior = actual->sig;
            free(actual);
        }
        else
            anterior = &actual->sig;
    }
}
