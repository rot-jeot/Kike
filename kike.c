#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 30
struct NODO
{
	//int tam;
    char nombre[30];
    struct NODO *siguiente;
};

struct LISTA
{
    struct NODO *Head;
    struct NODO *Tail;
};

void Inicializa(struct LISTA *lista)
{
    lista->Head=NULL;
    lista->Tail=NULL;
}
void Muestra(struct LISTA *lista);
int Insertar(struct LISTA *lista, char *a);
char *Eliminar(struct LISTA *lista);
void Modo(struct LISTA *lista);


int main ()
{

    struct LISTA mi_lista;    //Estructura mi lista
    struct LISTA *l;     //Puntero a mi lista
    int Exito;
    l=&mi_lista;    //El puntero l guarda la direccion de memoria de mi lista

    Inicializa(l);

    printf("Estado inicial de la lista: ");
    Muestra(l);

    int OpcionMenu;
    char cancion[TAM];



	do{

    printf("\nOpciones:\n1 Insertar nueva canción\n2 Eliminar canción\n3 Modo de Reproducción\n4 Salir\n\nDame una opcion: ");
    scanf("%d",&OpcionMenu);

		if(OpcionMenu==1){


            printf("Ingresa el nombre de la canción: ");
            scanf("%s", cancion);


            if(Insertar(l,cancion)==1)
            {
                printf("\nSe puso la canción %s en la cabeza de la lista",cancion);

            }
            else
            {
                printf("\nNo se agrego la canción %s porque la lista esta llena",cancion);
            }
            Muestra(l);
        }

    	if(OpcionMenu==2){

            cancion[TAM]=*Eliminar(l);
            if(cancion[TAM]!='\0')
            {
                printf("\nSe eliminó la canción %s de la cabeza de la lista",cancion[TAM]);
            }
            else
            {
                printf("\nNo se sacó ningun elemento de la lista porque esta vacia");
            }
            Muestra(l);
        }

}while(OpcionMenu!=4);


    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Muestra(struct LISTA *lista)
{
     struct NODO *actual;
    if(lista->Head==NULL && lista->Tail==NULL)
    {
        printf("\nLista de reproducción vacia\n");//no tiene elementos
        return;
    }
    actual=lista->Tail;
    if(lista->Head == lista->Tail)//Cuando es de un solo elemento
    {
        printf("\n Por reproducir: ");
        printf("%s",actual->nombre);
        return;
    }
//cuando es de mas de un elemento
    do
    {
            printf("%s",actual->nombre);
            actual=actual->siguiente;
    }
    while(actual!=lista->Head);


        printf("\n");
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Insertar(struct LISTA *lista, char *a)
{

    //Crea un nuevo nodo

    struct NODO *nodo;

    nodo = (struct NODO*)malloc(sizeof(nodo));

    if(nodo!=NULL)
    {
        if( lista->Head==NULL && lista->Tail==NULL)
        {
          lista->Tail=nodo;
          lista->Head=nodo;
          strcpy( nodo->nombre,a);
          nodo->siguiente=NULL;
        }
        else
        {
        nodo->siguiente=lista->Head;
        strcpy( nodo->nombre,a);
        lista->Head=nodo;
        }

        return 1;

    }
    else
        {
        return 0;
        }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Quita el elemento de la lista
//Si tiene Ã©xito devuelve el valor que estaba en la cabeza, de lo contrario regresa null
char *Eliminar(struct LISTA *lista)
{
    if(lista->Head!=NULL)
    {

        //Almacena en variables temporales datos de interes
        char *ctemporal;
        ctemporal=lista->Head->nombre;

        struct NODO *stTemporal;
        stTemporal=lista->Head;

        if(lista->Head==lista->Tail){
            Inicializa(lista);
        }else{
            //Saca el elemento que apunta la lista
            lista->Head = lista->Head->siguiente;

            lista->Tail->siguiente=lista->Head;

            //Libera el espacio del dato que se sacó de la lista
            free(stTemporal);

            return ctemporal;
        }
    }
    else
    {
        return '\0';
    }
}
void Modo(struct LISTA *lista)
{
	printf("Reproduciendo: %s",lista->Head->nombre);
}
