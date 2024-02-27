#include <stdio.h>
#include "comando.h"

int main()
{
    ListaExp lExp;
    crearLista(lExp);
    listaString lStr;
    crearListaString(lStr);
    do{
        limpiarLista(lStr);
        string s;
        strcrear(s);
        printf("\nIngrese el comando a ejecutar: ");
        scan(s);
        separarStringEnLista(s,lStr);
        imprimirLista(lStr); //PRUEBA
        if(cantStrings(lStr)>=1 && cantStrings(lStr)<=4){
           ejecutarComando(lStr,lExp);
        }else
            printf("\nComando invalido");

    }while(reconocerComando(lStr->str)!='E');

}
