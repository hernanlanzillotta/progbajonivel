//COLA DINÁMICA - DYNAMIC FIFO -
#include<stdio.h>
#include<stdlib.h>
#include"../../funciones.c"

struct nodo
{
    int numero;
    float promedio;
};

struct cola
{
    struct nodo datos;
    struct cola *sig;
};

//IS_EMPTY
int colaVacia(struct cola * puntcola)
{
    return puntcola == NULL;
}
//PUSH
void acolar(struct cola ** puntcola,struct nodo dato)
{
    struct cola *nuevoNodo,*aux = *puntcola;

    //SOLICITAR MEMORIA PARA CREAR UN NUEVO NODO
    nuevoNodo = (struct cola *)malloc(sizeof(struct cola));

    verificarMemoria(nuevoNodo);

    //COPIAR LOS DATOS EN EL NUEVO NODO
    nuevoNodo->datos = dato;
    //EL SIGUIENTE DEL NUEVO NODO APUNTA A NULL.
    nuevoNodo->sig = NULL;

    if(!colaVacia(*puntcola))
        //EL SIGUIENTE DEL NODO ANTERIOR APUNTA AL NODO ACUTAL
        aux->sig = nuevoNodo;

    //EL NODO ACTUAL COPIA LA DIRECCION DEL NUEVO NODO
    *puntcola = nuevoNodo;
}

//POP
struct nodo desencolar(struct cola ** puntcola)
{
    struct cola * aux;
    struct nodo datos={-1,-1.0};

    if(!colaVacia(*puntcola))
    {
        aux = *puntcola;
        datos = aux->datos;
        aux = aux->sig;
        free(*puntcola); //LIBERAR MEMORIA DEL PRIMERO
        *puntcola = aux; //ASIGNAR EL NUEVO PRIMERO
    }
    else
        puts("\n Cola vacia !!! \n");

    return datos;
}

//LIST - DESTROYED
void recorrerYDesencolar(struct cola ** puntcola)
{
   struct cola * aux = *puntcola;
   struct nodo datos;

   while(!colaVacia(aux))
   {
        datos = desencolar(&aux);
        printf("\n numero = %d promedio = %.2f\n",datos.numero,datos.promedio);
   }
}

//LIST - SAVED
void recorrerSinDesencolar(struct cola * puntcola)
{
   struct cola * aux = puntcola;

   while(!colaVacia(aux))
   {
        printf("\n numero = %d promedio = %.2f\n",aux->datos.numero,aux->datos.promedio);
        aux = aux->sig;
   }
}

//TOP
struct nodo tope (struct cola * puntcola)
{
    struct nodo datos = {-1,-1.0};

    //printf("\n !cola vacia = %d\n",!colaVacia(puntcola));

    if(!colaVacia(puntcola))
        datos = puntcola->datos;

    return datos;
}

void mostrarMenu()
{
    printf("\n\nMENU PARA COLA DINAMICA\n"
           "1 - Acolar(push)\n"
           "2 - Desacolar(pop)\n"
           "3 - Primero(top)\n"
           "4 - Listar sin desacolar(list-saved)  \n"
           "5 - Listar y desacolar(list-destroyed)  \n"
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
    struct cola * primero = NULL,*actual = NULL;
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
                   acolar(&actual,nodo);
                   if(!primero)
                       primero = actual;
                   break;
            case 2://DESACOLAR (pop)
                   nodo = desencolar(&primero);
                   if(nodo.numero > -1)
                      printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                   break;
            case 3: //TOP
                    nodo = tope(primero);
                    if(nodo.numero > -1)
                        printf("\n numero = %d promedio = %.2f\n",nodo.numero,nodo.promedio);
                    break;
            case 4: //LIST-SAVED
                    recorrerSinDesencolar(primero);
                    break;
                   //LIST-DESTROYED
            case 5:recorrerYDesencolar(&primero);

        }

        opcion = seleccionarOpcion();
    }

    return 0;
}
