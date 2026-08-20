//PILA DINÁMICA - LIFO
#include<stdio.h>
#include<stdlib.h>

struct nodo
{
    int numero;
    float promedio;
};

struct pila
{
    struct nodo datos;
    struct pila *ant;
};


void verificarMemoria(struct pila * nodo)
{
    if(nodo == NULL)
    {
        puts("Espacio de memoria insuficiente para crear nodo");
        system("pause");
        exit(1);
    }
}

//IS_EMPTY
int pilaVacia(struct pila * nodo)
{
    return nodo == NULL;
}
//PUSH
struct pila * apilar(struct pila * pila,struct nodo dato)
{   struct pila *nodo;

    //SOLICITAR MEMORIA PARA CREAR EL NODO
    nodo = (struct pila *)malloc(sizeof(struct pila));

    verificarMemoria(nodo);

    if(pilaVacia(pila))
       {
           //PRIMER NODO
           pila = nodo;
           pila->ant = NULL;
       }
    else
        {
           //2° HASTA EL N-ÉSIMO NODO.
           nodo->ant = pila;
           pila = nodo;
        }

    pila->datos = dato;

    return nodo;
}

//POP
struct pila * desapilar(struct pila * pila)
{
    struct pila * aux;

    if(!pilaVacia(pila))
    {
        aux = pila;
        pila = pila->ant;
        free(aux); //LIBERAR MEMORIA DEL TOPE
    }
    else
        puts("\n Pila vacia !!! \n");

    return pila;
}

//LIST
//struct pila *
void * recorrer(struct pila * pila)
{
   if(!pilaVacia(pila))
        while(pila)
           {
                printf("\n numero = %d promedio = %.2f\n",pila->datos.numero,pila->datos.promedio);
                pila = desapilar(pila);
           }
    else
        puts("\n Pila vacia !!! \n");

    return NULL;
}

//TOP
void tope (struct pila * pila)
{
    if(!pilaVacia(pila))
        printf("\n numero = %d promedio = %.2f\n",pila->datos.numero,pila->datos.promedio);
    else
        puts("\n Pila vacia !!! \n");
}


int main()
{
    struct pila *puntpila = NULL;
    struct nodo nodo;
    int i;

    printf("Ingrese numero (0 - FIN):");
    scanf("%d",&nodo.numero);

    while(nodo.numero != 0)
    {
        printf("Ingrese promedio:");
        scanf("%f",&nodo.promedio);

        puntpila = apilar(puntpila,nodo);

        printf("Ingrese numero (0 - FIN):");
        scanf("%d",&nodo.numero);
    }


    /*puntpila = desapilar(puntpila);
    puntpila = desapilar(puntpila);
    puntpila = desapilar(puntpila);*/
    puntpila = desapilar(puntpila);
    tope(puntpila);

    return 0;
}
