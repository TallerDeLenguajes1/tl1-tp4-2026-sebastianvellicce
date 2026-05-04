#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea
{
    int TareaID;//Numerico autoincremenmtal comenzando en 100
    char *Descripcion;
    int Duracion;//entre 10-100
}Tarea;

typedef struct Nodo
{
    Tarea T;
    Nodo *Siguiente;
} Nodo;

Nodo * crearListaVacia()
{
    return NULL;
}

Nodo *crearNuevoNodo(int *puntID)
{
    char *Buff;
    Buff = (char *) malloc (sizeof(char)*100);
    Nodo *nuevoNodo =(Nodo*)malloc(sizeof(Nodo));
    printf("Ingrese la descripcion de la tarea\n");
    getchar();
    gets(Buff);
    nuevoNodo->T.Descripcion=(char*) malloc (sizeof(char)*(strlen(Buff)+1));
    strcpy(nuevoNodo->T.Descripcion,Buff);
    free(Buff);
    
    nuevoNodo->T.Duracion=0;
    while(nuevoNodo->T.Duracion>100 || nuevoNodo->T.Duracion< 10)
    {
        printf("Ingrese la duracion de su tarea (Debe estar entre 10 y 100 incluidos)\n");
        scanf("%d",&nuevoNodo->T.Duracion);
    }
    nuevoNodo->T.TareaID=*puntID;
    (*puntID)++;
    return nuevoNodo;
}

Nodo *QuitarNodo (int Id,Nodo **Start)
{
    Nodo *nodoAux = *Start;
    Nodo *nodoAnt = NULL;
    while(nodoAux!=NULL && nodoAux->T.TareaID != Id)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->Siguiente;
    }
    if(nodoAux != NULL)
    {
        if(nodoAux == (*Start))
        {
            (*Start) = nodoAux->Siguiente;
        }
        else
        {
            nodoAnt->Siguiente = nodoAux->Siguiente;
        }
        nodoAux->Siguiente = NULL;
    }
    return (nodoAux);
}

void InserarNodo(Nodo **Start, Nodo *Nodo)
{
    Nodo->Siguiente=*Start;
    *Start = Nodo;
}

void listarTareas (Nodo **Start)
{
    int i=1;
    if (*Start == NULL)
    {
        printf("La lista está vacia.\n");
        return;
    }
    Nodo *NodoAuxiliar = *Start; 
    while (NodoAuxiliar != NULL)
    {
        printf("%d) ID: %d\n",i,NodoAuxiliar->T.TareaID);
        printf("Descripcion: %s\n", NodoAuxiliar->T.Descripcion);
        printf("Duracion : %d horas\n",NodoAuxiliar->T.Duracion );
        i++;
        NodoAuxiliar = NodoAuxiliar->Siguiente;
    }
}

void mostrarMenu ()
{
    printf("\n=====================================\n");
    printf("        GESTOR DE TAREAS\n");
    printf("=====================================\n");
    printf("1. Agregar tarea\n");
    printf("2. Pasar tarea de pendiente a realizada\n");
    printf("3. Mostar tareas pendientes\n");
    printf("4. Mostrar tareas realizadas\n");
    printf("5. Buscar tarea\n");
    printf("6. Salir\n");
    printf("=====================================\n");
}

int main()
{
    Nodo *TareasPendientes;
    Nodo *TareasRealizadas;
    int cantidTareasIngresadas, opcion, id=1000;

    TareasPendientes=crearListaVacia;
    TareasRealizadas=crearListaVacia;


    mostrarMenu();
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    do {
        switch(opcion)
        {
            case 1: 
                int IdCambioARealizado;
                Nodo *nuevoNodo = crearNuevoNodo(id);
                    InsertarAlInicio(TareasPendientes , nuevoNodo);
                    printf("Tarea agregada con exito!\n");
                    break;

                case 2: 
                    Nodo *NodoATransferir;
                    printf("Ingresa el ID de la tarea que quieres pasar a realizada\n");
                    scanf("%d",&IdCambioARealizado);
                    NodoATransferir = QuitarNodo(IdCambioARealizado,&TareasPendientes);

                    if(NodoATransferir != NULL)
                    {
                        InserarNodo(&TareasRealizadas, NodoATransferir);
                    }
                    else
                    {
                        printf("No se encontro la tarea pendiente.\n");
                    }

                    break;
                case 3:
                    printf("Estas son las tareas pendientes:\n");
                    listarTareas(&TareasPendientes);
                    break;
                case 4: 
                    printf("Estas son las tareas realizadas:\n");
                    listarTareas(&TareasRealizadas);
                    break;
                case 5:

                case 6: 
                    printf("Saliendo...\n");
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }
        mostrarMenu();    
        } while(opcion != 5);    


}