

void lista_reducir(lista_t *l, int (*f)(int a, int b)) {
    if(l->prim == NULL || l->prim->sig == NULL)
        return;

    while(l->prim->sig != NULL) {
        int resu = f(l->prim->dato, l->prim->sig->dato);
        l->prim->dato = resu;   // Guardo en el primero

        // Mato el segundo:
        struct nodo *segundo = l->prim->sig;
        l->prim->sig = segundo->sig;
        free(segundo);
    }
}

