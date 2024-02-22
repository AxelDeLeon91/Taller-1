#include <stdio.h>

#include "arbolExpresiones.h"

void crear(arbol &a){
    a=NULL;
}

boolean vacio(arbol a){
    return (boolean)(a == NULL);
}

arbol darRaiz(arbol a){
    return a;
}

arbol hijoIzq(arbol a){
    return a->hizq;
}

arbol hijoDer(arbol a){
    return a->hder;
}

void numerarArbol(arbol &a){
    int contador=1;
    numerarRecursivo(a,contador);
}

void numerarRecursivo(arbol a, int &contador){
    if(a!=NULL){
        numerarRecursivo(a->hizq,contador);
        a->info.numero= contador;
        contador++;
        numerarRecursivo(a->hder,contador);
    }
}

void colocarParentesis(arbol &a){
    arbol aux=a;
    colocarParIzq(aux);
    aux=a;
    colocarParDer(aux);
}

void colocarParIzq(arbol &a){
    while(a!=NULL){
        colocarParIzq(a->hizq);
    }
    a= new nodoABB;
    /* Esto deberia cambiarse por un procedimiento de datosArbol*/
        a->info.numero=0; //numero deberia ser parte de datoABB
        a->info.discriminante=PARENTESIS;
        a->info.datos.par='(';

    a->hder=NULL;
    a->hizq=NULL;
}

void colocarParDer(arbol &a){
    while(a!=NULL){
        colocarParDer(a->hder);
    }
    a= new nodoABB;
    /* Esto deberia cambiarse por un procedimiento de datosArbol*/
        a->info.numero=0; //numero deberia ser parte de datoABB
        a->info.discriminante=PARENTESIS;
        a->info.datos.par=')';

    a->hder=NULL;
    a->hizq=NULL;
}

/*Deberia recibir lo que va dentro de la parte info del nodo (es decir datoABB).*/
void juntarArboles(arbol a, arbol b, datoABB dat, arbol &c){

    c = new nodoABB;
    c->info= dat;

    c->hizq = a;
    c->hder = b;
}


//Recorro en orden el ABB para mostrar la expresion bien
void mostrarArbolRecu(arbol a){
    if(a!=NULL){
        mostrarArbolRecu(a->hizq);
        mostrarNodoAbb(a->info);
        mostrarArbolRecu(a->hder);
    }
}



//AYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDA
int evaluarArbol(arbol a){
    if(a == NULL){
        return 0;
    }

}

/* Para mi aca deberias tener....
* En datosArbol esta la función que obtiene el discriminante para saber que tiene el nodo que tenes enfrente.
* En arbolExpresiones podrias tener una funcion entera que recorra en "preorden", donde
    * Evaluas el discriminante.
        * Si es de tipo valor, retornas 1 si es TRUE o 0 si es FALSE (este retorno deberia ser una funcion entera de datosABB donde como precondicion se sabe que es de tipo Valor)
        * Sino, si es de tipo Operador:
            * Si es AND
                se retorna llamado recursivo por izq * llamado recursivo por der
            * Si es OR
                se retorna llamado recursivo por izq + llamado recursivo por der
            * Si es NOT
                se retorna inverso a llamado recursivo por der.

En definitiva los pasos base se dan cuando se llega a un nodo de tipo valor, a los nodos de parentesis no se llega al evaluar.
Es una idea, a revisarla, pero creo que por ahi puede andar*/


