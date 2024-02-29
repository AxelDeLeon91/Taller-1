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
        printf("\nIngrese el comando a ejecutar: ");
        scan(s);
        separarStringEnLista(s,lStr);

        c=reconocerComando(lStr->str);
        ejecutarComando(lStr,lExp,c);

    }while(c!= 'X');

}
