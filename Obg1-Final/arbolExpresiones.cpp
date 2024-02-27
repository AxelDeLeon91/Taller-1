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
        setNumero(a->info,contador);
        /*
        a->info.numero= contador;
        */
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
    setParentesis(a->info,'(');
    a->hder=NULL;
    a->hizq=NULL;
}

void colocarParDer(arbol &a){
    while(a!=NULL){
        colocarParDer(a->hder);
    }
    a= new nodoABB;
    setParentesis(a->info,')');
    a->hder=NULL;
    a->hizq=NULL;
}

void juntarArboles(arbol a, arbol b, datoABB dat, arbol &c){

    c = new nodoABB;
    c->info= dat;
    c->hizq = a;
    c->hder = b;
    colocarParentesis(c);
}

void cargarArbolAtomic(arbol &a, string s){
    setValor(a->info,stringAboolean(s);)
    a->hder=NULL;
    a->hizq=NULL;
}

//Recorro en orden el ABB para mostrar la expresion bien
void mostrarArbolRecu(arbol a){
    if(a!=NULL){
        mostrarArbolRecu(a->hizq);
        mostrarNodoAbb(a->info);
        mostrarArbolRecu(a->hder);
    }
}

datoABB darInfo(arbol a){
    return a->info;
}

//AYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDAAYUDA
boolean evaluarArbol(arbol a){
    if(darDiscriminante(darInfo(a))==VALOR){
        return darDatoBool(darInfo(a));
    }else if(darDiscriminante(darInfo(a))==OPERADOR){
            if(darOperador(darInfo(a))=='A'){
               return (boolean) (evaluarArbol(a->hizq) && evaluarArbol(a->hder));//Aca iria la multiplicacion
            }else if(darOperador(darInfo(a))== 'O'){
                    return (boolean) (evaluarArbol(a->hizq) || evaluarArbol(a->hder)); //Aca iria la suma topeada en 1
                     }
            else//CASO NOT
                return (boolean) !evaluarArbol(a->hder);
    }
}


