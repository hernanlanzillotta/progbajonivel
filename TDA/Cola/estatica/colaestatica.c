//PILA ESTÁTICA - STATIC FIFO -
#include<stdio.h>
#include<stdlib.h>
#include "../funciones.c"

#define TAM 3 //CANTIDAD MAXIMA DE NODOS

struct nodo
{
    int numero;
    float promedio;
};

struct cola
{
    struct nodo datos[TAM];
    int primero;
    int ultimo;
};

//INIT
void inicializarCola(struct cola * puntcola)
{
    puntcola->primero = puntcola->ultimo = 0;
}

//IS_EMPTY
int colaVacia(struct cola * puntcola)
{
    return puntcola->primero == puntcola->ultimo;
}
//IS_FULL
int colaLlena(struct cola * puntcola)
{
    return puntcola->ultimo == TAM;
}

//PUSH
void encolar(struct cola * puntcola,struct nodo dato)
{
    if(!colaLlena(puntcola))
    {
        if(colaVacia(puntcola))
        {   puntcola->primero = 0;
            puntcola->datos[puntcola->primero] = dato;

        }
        else
            puntcola->datos[puntcola->ultimo] = dato;

        puntcola->ultimo++;
    }
    else
        puts("\n Cola llena !!!!");
}

//TOP
struct nodo cima (struct cola * puntcola)
{
    struct nodo datos = {-1,-1.0};

    if(!colaVacia(puntcola))
        datos = puntcola->datos[puntcola->primero];
    else
        puts("\n Cola vacia !!! \n");

    return datos;
}

//POP
struct nodo desencolar(struct cola * puntcola)
{
    struct nodo datos = {-1,-1.0};

    if(!colaVacia(puntcola))
      {
        datos = cima(puntcola);
        puntcola->primero++;
        if(colaVacia(puntcola))
           inicializarCola(puntcola);
      }
    else
        puts("\n Cola vacia !!! \n");

    return datos;
}

//LIST - SAVED
void recorrerSinDesencolar(struct cola * puntcola)
{   int i;

    if(!colaVacia(puntcola))
       for(i = puntcola->primero;i < puntcola->ultimo  ;i++)
           printf("\n numero = %d promedio = %.2f\n",puntcola->datos[i].numero,puntcola->datos[i].promedio);
}

//LIST - DESTROYED
void recorrerYDesencolar(struct cola * puntcola)
{   int i;
    struct nodo datos;

    while(!colaVacia(puntcola))
          {datos = desencolar(puntcola);
           printf("\n numero = %d promedio = %.2f\n",datos.numero,datos.promedio);
          }
}

void mostrarMenu()
{
    printf("MENU PARA COLA ESTATICA \n\n"
           "1 - Acolar/Encolar(push)\n"
           "2 - Desacolar/Desencolar(pop)\n"
           "3 - Tope(top)\n"
           "4 - Listar sin desencolar(list-saved)  \n"
           "5 - Listar y desencolar(list-destroyed)  \n"
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
    struct cola puntcola;
    struct nodo nodo;
    int opcion;

    inicializarCola(&puntcola);
    opcion = seleccionarOpcion();

    while(opcion != 6)
    {
        switch(opcion)
        {
            case 1://ACOLAR (push)
                   printf("Ingrese numero entero:");
                   scanf("%d",&nodo.numero);
                   printf("Ingrese promedio (positivo):");
                   nodo.promedio = ingresaYValidaFloat1(0.0);
                   encolar(&puntcola,nodo);
                   break;
            case 2://DESENCOLAR (pop)
                   nodo = desencolar(&puntcola);
                   if(nodo.numero != -1)
                      printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                   break;
            case 3: //TOPE (TOP)
                    nodo = cima(&puntcola);
                    if(nodo.numero != -1)
                       printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                    break;
                    //LISTAR SIN DESENCOLAR (LIST-SAVED)
            case 4: recorrerSinDesencolar(&puntcola);
                    break;
                    //LISTAR SIN DESENCOLAR (LIST-DESTROYED)
            case 5: recorrerYDesencolar(&puntcola);
                    break;
        }

        opcion = seleccionarOpcion();
    }

   return 0;
}
