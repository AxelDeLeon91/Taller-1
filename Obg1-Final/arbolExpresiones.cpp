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
        a->numero= contador;
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
    a->numero=0;
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
    a->numero=0;
    a->info.discriminante=PARENTESIS;
    a->info.datos.par=')';
    a->hder=NULL;
    a->hizq=NULL;
}

void juntarArboles(arbol a, arbol b, nodoABB Raiz, arbol &c){
    c = Raiz;
    c->hizq = a;
    c->hder = b;
}

//Muestra la expresion
void mostrarArbol(arbol a){
    mostrarArbolRecu(a);
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
//AYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDA
int evaluarOperador(char op, boolean izq, boolean der){
    int valor;
    switch(op){
        case 'A':
                return ;//Multiplicacion
                break;
        case 'O':
                return ; //Suma capeada en 1
                break;
        case 'N':
                return ; // Opuesto
                break;
        default:
                break;
                //Y ACA?
    }
    return valor;
}

//AYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDA
//AYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDA
int evaluarArbol(arbol a){
    if(a == NULL){
        return 0;
    }
    if((darDiscriminante(a->hizq)==PARENTESIS) && (darDiscriminante(a->hder)==PARENTESIS)){
    }
}


