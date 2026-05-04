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
    struct Nodo *Siguiente;
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
    fgets(Buff, 100, stdin);
    Buff[strcspn(Buff, "\n")] = '\0';
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
    nuevoNodo->Siguiente = NULL;
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

void InsertarNodo(Nodo **Start, Nodo *Nodo)
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

void listarTarea(Nodo *Start)
{
    if(Start == NULL)
    {
        printf("Tarea vacia\n");
        return; 
    }
    Nodo *NodoAuxiliar = Start;
    printf("ID: %d\n",NodoAuxiliar->T.TareaID);
    printf("Descripcion: %s\n", NodoAuxiliar->T.Descripcion);
    printf("Duracion : %d horas\n",NodoAuxiliar->T.Duracion );
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

Nodo *BuscarPorId(Nodo *Start,int id)
{
    Nodo *nodoAuxiliar = Start;
    while(nodoAuxiliar != NULL && nodoAuxiliar->T.TareaID != id){
        nodoAuxiliar = nodoAuxiliar->Siguiente;
    }
    return nodoAuxiliar;
}

void BuscarPorPalabras(Nodo *Start, char *palabraBuscada)
{
    char *resultado;
    Nodo *nodoAuxiliar = Start;
    while(nodoAuxiliar != NULL)
    {
        resultado = strstr(nodoAuxiliar->T.Descripcion, palabraBuscada);
        if(resultado)
        {
            listarTarea(nodoAuxiliar);
        }
        nodoAuxiliar = nodoAuxiliar->Siguiente;
    }

}

void liberarListas(Nodo **Start)
{
    Nodo *aux;

    while(*Start != NULL)
    {
        aux = *Start;

        *Start = (*Start)->Siguiente;

        free(aux->T.Descripcion);

        free(aux);
    }
}

void EliminarNodo(Nodo *Nodo)
{
    if(Nodo)
    {
        free(Nodo);
    }
}

int main()
{
    Nodo *TareasPendientes;
    Nodo *TareasRealizadas;
    int  opcion, id=1000, opcionBusqueda=0,IdBuscar,IdCambioARealizado;
    char *palabraClave;
    palabraClave= (char*)malloc(sizeof(char)*100);

    TareasPendientes = crearListaVacia();
    TareasRealizadas = crearListaVacia();


    mostrarMenu();
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    do {
        switch(opcion)
        {
            case 1:
            {
                Nodo *nuevoNodo = crearNuevoNodo(&id);
                    InsertarNodo(&TareasPendientes , nuevoNodo);
                    printf("Tarea agregada con exito!\n");
                    break;
            }

                case 2:
                {
                    Nodo *NodoATransferir;
                    printf("Ingresa el ID de la tarea que quieres pasar a realizada\n");
                    scanf("%d",&IdCambioARealizado);
                    NodoATransferir = QuitarNodo(IdCambioARealizado,&TareasPendientes);

                    if(NodoATransferir != NULL)
                    {
                        InsertarNodo(&TareasRealizadas, NodoATransferir);
                    }
                    else
                    {
                        printf("No se encontro la tarea pendiente.\n");
                    }

                    break;
                } 
                case 3:
                    printf("Estas son las tareas pendientes:\n");
                    listarTareas(&TareasPendientes);
                    break;
                case 4: 
                    printf("Estas son las tareas realizadas:\n");
                    listarTareas(&TareasRealizadas);
                    break;
                case 5:
                {
                    opcionBusqueda = 0;
                    while(opcionBusqueda != 1 && opcionBusqueda!=2)
                    {
                        printf("1-Buscar por ID.\n2-Buscar por palabra clave\n");
                        scanf("%d",&opcionBusqueda);
                    }

                    if(opcionBusqueda == 1)
                    {
                        printf("Ingrese el ID de la tarea que quiere buscar");
                        scanf("%d",&IdBuscar);

                        Nodo *auxBusquedaIdPendientes=BuscarPorId(TareasPendientes,IdBuscar);
                        Nodo *auxBusquedaIdRealizadas=BuscarPorId(TareasRealizadas,IdBuscar);

                        if(auxBusquedaIdPendientes)
                        {
                            listarTarea(auxBusquedaIdPendientes);
                            printf("La tarea esta pendiente.\n");
                        }
                        else if(auxBusquedaIdRealizadas)
                        {
                            listarTarea(auxBusquedaIdRealizadas);
                            printf("La tarea esta realizada.\n");
                        }
                        else
                        {
                            printf("No se encontro una tarea asignada al ID.\n");
                        }
                    }

                    else if(opcionBusqueda == 2)
                    {
                        printf("Ingrese la palabra clave\n");
                        getchar();
                        fgets(palabraClave,100,stdin);
                        palabraClave[strcspn(palabraClave,"\n")] = '\0';

                        printf("Las tareas pendientes con esa palabra clave:\n");
                        BuscarPorPalabras(TareasPendientes, palabraClave);

                        printf("Las tareas realizadas con esa palabra clave:\n");
                        BuscarPorPalabras(TareasRealizadas, palabraClave);
                    }
                    else
                    {
                        printf("No se encontraron tareas con la palabra clave.\n");
                    }
                    break;
                }
                case 6: 
                    printf("Saliendo...\n");
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);    
        } while(opcion != 6);    
        
        liberarListas(&TareasPendientes);
        liberarListas(&TareasRealizadas);
        free(palabraClave);
        return 0;
}