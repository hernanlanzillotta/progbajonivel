//PILA ESTÁTICA - STATIC LIFO -
#include<stdio.h>
#include<stdlib.h>
#include "../funciones.c"

#define TAM 3 //CANTIDAD MAXIMA DE NODOS

struct nodo
{
    int numero;
    float promedio;
};

struct pila
{
    struct nodo datos[TAM];
    int tope;
};

//INIT
void inicializarPila(struct pila * pila)
{
    pila->tope = -1;
}

//IS_EMPTY
int pilaVacia(struct pila * pila)
{
    return pila->tope == -1;
}
//IS_FULL
int pilaLlena(struct pila * pila)
{
    return pila->tope == TAM - 1;
}

//PUSH
void apilar(struct pila * puntpila,struct nodo dato)
{
    if(!pilaLlena(puntpila))
    {
        puntpila->tope++;
        puntpila->datos[puntpila->tope] = dato;
    }
    else
        puts("\n Pila llena !!!!");
}

//TOP
struct nodo cima (struct pila * pila)
{
    struct nodo datos = {-1,-1.0};

    if(!pilaVacia(pila))
        datos = pila->datos[pila->tope];
    else
        puts("\n Pila vacia !!! \n");

    return datos;
}

//POP
struct nodo desapilar(struct pila * puntpila)
{
    struct nodo datos = {-1,-1.0};

    if(!pilaVacia(puntpila))
      {
        datos = cima(puntpila);
        puntpila->tope--;
      }
    else
        puts("\n Pila vacia !!! \n");

    return datos;
}

//LIST - SAVED
void recorrerSinDesapilar(struct pila * pila)
{   int i;

    if(!pilaVacia(pila))
       for(i = pila->tope;i > -1 ;i--)
           printf("\n numero = %d promedio = %.2f\n",pila->datos[i].numero,pila->datos[i].promedio);
}

//LIST - DESTROYED
void recorrerYDesapilar(struct pila * pila)
{   int i;
    struct nodo datos;

    while(!pilaVacia(pila))
          {datos = desapilar(pila);
           printf("\n numero = %d promedio = %.2f\n",datos.numero,datos.promedio);
          }
}

void mostrarMenu()
{
    printf("MENU PARA PILA ESTATICA \n\n"
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
    struct pila puntpila;
    struct nodo nodo;
    int opcion;

    inicializarPila(&puntpila);
    opcion = seleccionarOpcion();

    while(opcion != 6)
    {
        switch(opcion)
        {
            case 1://APILAR (push)
                   printf("Ingrese numero entero:");
                   scanf("%d",&nodo.numero);
                   printf("Ingrese promedio (positivo):");
                   nodo.promedio = ingresaYValidaFloat1(0.0);
                   apilar(&puntpila,nodo);
                   break;
            case 2://DESAPILAR (pop)
                   nodo = desapilar(&puntpila);
                   if(nodo.numero != -1)
                      printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                   break;
            case 3: //TOPE (TOP)
                    nodo = cima(&puntpila);
                    if(nodo.numero != -1)
                       printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                    break;
                    //LISTAR SIN DESAPILAR (LIST-SAVED)
            case 4: recorrerSinDesapilar(&puntpila);
                    break;
                    //LISTAR SIN DESAPILAR (LIST-DESTROYED)
            case 5: recorrerYDesapilar(&puntpila);
                    break;
        }

        opcion = seleccionarOpcion();
    }

   return 0;
}
