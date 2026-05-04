#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creamos un nodo

typedef struct 
{
    int valor; //dato, puere variar el tipo
    Tnodo *siguiente; //puntero al siguiente nodo
}Tnodo;

//Creamos lista vacia
Tnodo * CrearListaVacia()
{
    return NULL;
}

//Creamos un nodo nuevo
Tnodo * CrearNodo(int valor)
{
    Tnodo * NNodo= (Tnodo *) malloc(sizeof(Tnodo));
    NNodo->valor= valor;
    NNodo->siguiente= NULL;
    return NNodo;
}

//Insercion al inicio de la lista
void InserarNodo(Tnodo **Start, Tnodo *Nodo)
{
    Nodo->siguiente=*Start;
    *Start = Nodo;
}


//Insercion al final de la lista
void InsertarAlFinal(Tnodo **Start, Tnodo * Nodo)
{
    if (*Start == NULL) {
        *Start = Nodo;
        return;
    }

    Tnodo *aux= Start;
    while(aux->siguiente)
    {
        aux=aux->siguiente;
    }
    aux->siguiente = Nodo;
}


//Buscar un elemento en la lista
Tnodo * buscarNodo(Tnodo * Start, int IdBuscado)
{
    Tnodo * aux= Start;
    while (aux!= NULL &&aux->valor !=IdBuscado)
    {
        aux= aux->siguiente;
    }
    return aux;
}


//Eliminamos un nodo de la lista
Tnodo * QuitarNodo(Tnodo **Start, int dato)
{
    Tnodo *nodoAux = *Start;
    Tnodo *nodoAnt = NULL;
    while(nodoAux!=NULL && nodoAux->valor != dato)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->siguiente;
    }
    if(nodoAux != NULL)
    {
        if(nodoAux == (*Start))
        {
            (*Start) = nodoAux->siguiente;
        }
        else
        {
            nodoAnt->siguiente = nodoAux->siguiente;
        }
        nodoAux->siguiente = NULL;
    }
    return (nodoAux);
}

//Borramos al nodo de memoria
void EliminarNodo(Tnodo *Nodo)
{
    if(Nodo)
    {
        free(Nodo);
    }
}

int main()
{
    Tnodo *Start;
    Start = CrearListaVacia();
}