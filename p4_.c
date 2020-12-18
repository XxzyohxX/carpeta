/*
1. Teniendo el TDA Conjunto de enteros el cual se representa sobre typedef struct {int *e; size_t n;} conjunto_t;
en donde e es un vector ordenado de longitud n con los elementos contenidos en el conjunto se pide:
a. Implementar la primitiva
conjunto_t *conjunto_interseccion(const conjunto_t *a, const conjunto_t *b);
que compute la intersección entre dos conjuntos. (Asumir que se tiene la primitiva conjunto_t *conjunto_crear();
y la función auxiliar static bool _agregar_al_final(conjunto_t *c, int e); que agrega un elemento al
final sin chequear si esa es su ubicación correcta. Para simplificar: No hace falta chequear fallas de memoria.)
Aclaración: La función debe resolver el problema eficientemente sin llamar a funciones de ordenamiento ni
implementar ningún método de ordenamiento.
*/

typedef struct{
    int *e; //conjunto ordenado de n elementos
    size_t n;
}conjunto_t;

static bool _agregar_al_final(conjunto_t *c, int e);
conjunto_t *conjunto_crear();

// recibe dos conjuntos ordenados sin repeticiones
// devuelve un conjunto ordenado con la interseccion de los conjuntos recibidos
conjunto_t *conjunto_interseccion(const conjunto_t *a, const conjunto_t *b){
    size_t i = 0, j = 0;
    conjunto_t *c = conjunto_crear();
    if(c == NULL){
        return NULL;
    }
    while(i < a->n && j < b->n){ // mientras no se termine ningun conjunto
        if(a->e[i] == b->e[j]){ // si los elementos son iguales
            if(!_agregar_al_final(c, a->e[i])){ // lo agrego al conjunto
                return NULL;
            }
            i++; // incremento ambas posiciones
            j++;
        }
        else if(a->e[i] < b->e[j]){ // si no incremento la posicion adecuada
            i++;
        }
        else{
            j++;
        }
    }
    return c;
}

/*
2. Teniendo una lista de enteros en la cual la lista se representa typedef struct {struct nodo *prim;} lista_t; y
el nodo se representa como struct nodo {struct nodo *sig; int dato;}; implementar la primitiva
void lista_enteros_borrar(lista_t *l, int e);
que borre todas las ocurrencias del dato e en la lista.
*/

struct nodo{
    struct nodo *sig;
    int dato;
};

typedef struct{
    struct nodo *prim;
}lista_t;


void lista_enteros_borrar(lista_t *l, int e){
    struct nodo *actual, *aux;

    // caso particular del 1er nodo:
    while(l->prim != NULL){ // mientras la lista no sea vacía:
        if(l->prim->dato == e){ // si el primer nodo tiene el dato
            aux = l->prim; // guardo una referencia al nodo
            l->prim = l->prim->sig; // adelanto el ppio de la lista
            free(aux); // borro el nodo con el dato
        }
        else{
            break; // si no lo tiene se termina el caso particular
        }
    }

    // caso general:
    if(l->prim == NULL){ // chequeo que la lista no sea vacía
        return;
    }
    actual = l->prim; // puntero para recorrer la lista (ya chequeamos el dato antes)

    while(actual->sig != NULL){ // mientras no se termine la lista:
        if(actual->sig->dato == e){ // pregunto por el dato del siguiente
            aux = actual->sig; // guardo referencia al nodo a eliminar
            actual->sig = actual->sig->sig; // saco de la lista el nodo a eliminar
            free(aux); // borro el nodo
        }
        else{
            actual = actual->sig; // si no hay que eliminarlo, simplemente avanzo
        }
    }
}
