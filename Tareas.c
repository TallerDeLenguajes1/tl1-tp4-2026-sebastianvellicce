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

void interfaz(Nodo **Start, int *id)
{
    

}

int main()
{
    Tarea *TareasPendientes;
    Tarea *TareasRealizadas;
    int cantidTareasIngresadas, opcion, id=1000;

        printf("\n=====================================\n");
        printf("        GESTOR DE TAREAS\n");
        printf("=====================================\n");
        printf("1. Agregar tarea\n");
        printf("2. Eliminar tarea\n");
        printf("3. Buscar tarea\n");
        printf("4. Mostrar todas las tareas\n");
        printf("5. Salir\n");
        printf("=====================================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        do {


            switch(opcion)
            {
                case 1: 
                    Nodo *nuevoNodo = crearNuevoNodo(id);
                    InsertarAlInicio(TareasPendientes , nuevoNodo);
                    printf("Tarea agregada con exito!\n");
                    break;

                case 2: 
                    /* QuitarNodo               */ 
                    break;
                case 3: 
                    /* buscarNodo               */ 
                    break;
                case 4: 
                    /* mostrarLista             */ 
                    break;
                case 5: 
                    printf("Saliendo...\n");
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }
        } while(opcion != 5);    


}