#include <stdio.h>
#include "comando.h"

int main()
{
    ListaExp lExp;
    crearLista(lExp);
    listaString lStr;
    crearListaString(lStr);
    char c;
    do{
        limpiarLista(lStr);
        string s;
        strcrear(s);
        printf("Ingrese el comando a ejecutar: ");
        scan(s);
        separarStringEnLista(s, lStr);
        if(!listaVacia(lStr)){
            c = reconocerComando(lStr->str);
            ejecutarComando(lStr, lExp, c);
        }else
            printf("\nNo ingresa nada");
        printf("\n\n");
    } while (c != 'X');
    return 0;
}
