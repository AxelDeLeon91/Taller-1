#include <stdio.h>
#include "listaString.h"

void crearListaString(listaString &lStr){
    lStr = NULL;
}

void insBack(listaString &lista, string s) {

    if (lista == NULL) {
        lista = new nodoString;
        strcop(lista->str, s);
        lista->sig = NULL;
    } else {
        listaString aux = lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new nodoString;
        strcop(aux->sig->str, s);
        aux->sig->sig = NULL;
    }
}
void avanzarLstr(listaString &lStr){
    lStr=lStr->sig;
}

// Función para separar el string en una lista de strings
void separarStringEnLista(string original, listaString &lstr) {
    listaString listaAux = NULL;
    string palabra;
    strcrear(palabra);
    int i = 0;

    while (original[i] != '\0') {
        // Busco el inicio de alguna palabra
        while (original[i] == ' ' && original[i] != '\0') {
            i++;
        }

        // Cuento su largo
        int j = 0;
        while (original[i + j] != ' ' && original[i + j] != '\0') {
            j++;
        }

        // Copio la palabra de original en una palabra aux
        if (j > 0){
            palabra = new char [j+1];

            //La copio
            for (int k = 0; k < j; k++) {
                palabra[k] = original[i + k];
            }
            palabra[j] = '\0';

            // INSBACK en listaAux
            insBack(listaAux, palabra);
        }

        // Avanzar al próximo caracter en string Original
        i += j;
    }

    // Asignar la listaAux a lstr
    lstr = listaAux;
}

// Función para imprimir la lista de strings
void imprimirLista(listaString lStr){
    while (lStr != NULL) {
        printf("\n");
        print(lStr->str);
        lStr = lStr->sig;
    }
}

// Función para liberar la memoria de la lista de strings
void limpiarLista(listaString &lstr){
    while(lstr != NULL){
        listaString aux = lstr;
        lstr = aux->sig;
        delete aux;
    }
}

int cantStrings(listaString lStr){
    int cant=0;
    while(lStr!=NULL){
        cant++;
        lStr=lStr->sig;
    }
    return cant;
}


