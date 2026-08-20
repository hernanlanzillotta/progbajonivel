//LISTA SIMPLEMENTE ENLAZADA
#include<stdio.h>
#include<stdlib.h>

struct nodo
{
    int id;
    char nombre[51];
    float promedio;
};

struct lista
{
    struct nodo datos;
    struct lista *sig;
};

int listaVacia(struct lista * puntlista)
{
    return puntlista == NULL;
}


