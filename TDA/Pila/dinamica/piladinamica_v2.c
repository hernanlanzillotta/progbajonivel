//PILA DINÁMICA - VERSIÓN 2 - DYNAMIC LIFO
#include<stdio.h>
#include<stdlib.h>
#include "../../funciones.c"

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

//IS_EMPTY
int pilaVacia(struct pila * puntpila)
{
    return puntpila == NULL;
}
//PUSH
void apilar(struct pila ** tope,struct nodo dato)
{   struct pila *nuevo;

    //SOLICITAR MEMORIA PARA CREAR EL NUEVO NODO
    nuevo = (struct pila *)malloc(sizeof(struct pila));

    //VERIFICAR SI EXISTE MEMORIA DISPONIBLE PARA EL NUEVO NODO
    verificarMemoria(nuevo);

    //COPIAR LOS DATOS EN EL NUEVO NODO
    nuevo->datos = dato;
    //EL NUEVO NODO APUNTA AL NODO ANTERIOR
    nuevo->ant = *tope;
    //MODIFICAMOS EL TOPE DE LA PILA CON EL NUEVO NODO
    *tope = nuevo;
}

//POP
struct nodo desapilar(struct pila ** tope)
{
    struct pila * aux;
    struct nodo datos ={-1,-1.0};

    if(!pilaVacia(*tope))
    {
        aux = *tope;
        datos = aux->datos;
        *tope = aux->ant;
        free(aux); //LIBERAR MEMORIA DEL TOPE
    }
    else
        puts("\n Pila vacia !!! \n");

    return datos;
}

//LIST - SAVED
void recorrerSinDesapilar(struct pila * puntpila)
{
    while(!pilaVacia(puntpila))
         {
           printf("\n numero = %d promedio = %.2f\n",puntpila->datos.numero,puntpila->datos.promedio);
           puntpila = puntpila->ant;
         }
}
//LIST - DESTROYED
void recorrerYDesapilar(struct pila ** puntpila)
{
    struct nodo datos;

    while(!pilaVacia(*puntpila))
         {
           datos = desapilar(puntpila);
           printf("\n numero = %d promedio = %.2f\n",datos.numero,datos.promedio);
         }
}

//TOP
struct nodo tope (struct pila * puntpila)
{
    struct nodo datos = {-1,-1.0};

    if(!pilaVacia(puntpila))
        datos = puntpila->datos;
    else
        puts("\n Pila vacia !!! \n");

    return datos;
}

void mostrarMenu()
{
    printf("\n\nMENU PARA PILA DINAMICA\n"
           "1 - Apilar(push)\n"
           "2 - Desapilar(pop)\n"
           "3 - Tope(top)\n"
           "4 - Listar sin desapilar(list-saved)  \n"
           "5 - Listar y desapilar(list-destroyed)  \n"
           "6 - Salir\n");
}

int seleccionarOpcion()
{
    int opcion;

    mostrarMenu();
    printf("\n ingrese su opcion (1-6):\t");
    opcion = ingresaYValidaInt2(1,6);

    return opcion;
}


int main()
{
    struct pila * puntpila = NULL;
    struct nodo nodo;
    int opcion = seleccionarOpcion();

    while(opcion != 6)
    {
        switch(opcion)
        {
            case 1://APILAR (push)
                   printf("Ingrese numero:");
                   scanf("%d",&nodo.numero);
                   printf("Ingrese promedio:");
                   nodo.promedio = ingresaYValidaFloat1(0);
                   apilar(&puntpila,nodo);
                   break;
            case 2://DESAPILAR (pop)
                   nodo = desapilar(&puntpila);
                   if(nodo.numero > -1)
                      printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                   break;
            case 3: //TOP
                    nodo = tope(puntpila);
                    if(nodo.numero > -1)
                        printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                    break;
            case 4: //LIST-SAVED
                    recorrerSinDesapilar(puntpila);
                    break;
                   //LIST-DESTROYED
            case 5:recorrerYDesapilar(&puntpila);

        }

        opcion = seleccionarOpcion();
    }

   return 0;
}
