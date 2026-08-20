//FUNCIONES GENERICAS DE VALIDACION

//VALIDAR NRO.ENTERO CON LÍMITE INFERIOR
int ingresaYValidaInt1(int liminf)
{
    int dato;

    scanf("%d",&dato);

    while(dato <= liminf )
    {
        printf("\n Fuera de rango, reingresar:");
        scanf("%d",&dato);
    }

    return dato;
}

//VALIDAR NRO.ENTERO CON LÍMITE INFERIOR Y SUPERIOR
int ingresaYValidaInt2(int liminf,int limsup)
{
    int dato;

    scanf("%d",&dato);

    while(dato < liminf || dato > limsup)
    {
        printf("\n Fuera de rango, reingresar:");
        scanf("%d",&dato);
    }

    return dato;
}

/*VALIDAR NRO.ENTERO CON LÍMITE INFERIOR - SUPERIOR
  y UN VALOR FUERA DEL RANGO*/
int ingresaYValidaInt3(int liminf,int limsup,int valorfuera)
{
    int dato;

    scanf("%d",&dato);

    while((dato < liminf || dato > limsup) && dato != valorfuera)
    {
        printf("\n Fuera de rango, reingresar:");
        scanf("%d",&dato);
    }

    return dato;
}

//VALIDAR NRO. DECIMAL CON LÍMITE INFERIOR
float ingresaYValidaFloat1(float liminf)
{
    float dato;

    scanf("%f",&dato);

    while(dato <= liminf )
    {
        printf("\n Fuera de rango, reingresar:");
        scanf("%f",&dato);
    }

    return dato;
}

//VALIDAR NRO. DECIMAL CON LÍMITE INFERIOR Y SUPERIOR
float ingresaYValidaFloat2(float liminf,float limsup)
{
    float dato;

    scanf("%f",&dato);

    while(dato < liminf || dato < limsup)
    {
        printf("\n Fuera de rango, reingresar:");
        scanf("%f",&dato);
    }

    return dato;
}
/*VALIDAR NRO.DECIMAL CON LÍMITE INFERIOR - SUPERIOR
  y UN VALOR FUERA DEL RANGO*/
float ingresaYValidaFloat3(float liminf,float limsup,float valorfuera)
{
    float dato;

    scanf("%f",&dato);

    while((dato < liminf || dato > limsup) && dato != valorfuera)
    {
        printf("\n Fuera de rango, reingresar:");
        scanf("%f",&dato);
    }

    return dato;
}

//FUNCION PARA VERIFICAR ASIGNACIÓN DE MEMORIA
void verificarMemoria(void * puntero)
{
    if(!puntero)
    {
        puts("Espacio de memoria insuficiente para crear nodo");
        system("pause");
        exit(1);
    }
}
