#include <stdio.h>
#include "arbolExpresiones.h"
//FUNCIONALIDADES
void crear(arbol &a){
    a=NULL;
}

boolean vacio(arbol a){
    return (boolean)(a == NULL);
}

void numerarArbol(arbol &a){
    int contador=1;
    numerarRecursivo(a,contador);
}

void numerarRecursivo(arbol a, int &contador){
    if(a!=NULL){
        numerarRecursivo(a->hizq,contador);
        setNumero(a->info,contador);
        contador++;
        numerarRecursivo(a->hder,contador);
    }
}

void colocarParentesis(arbol &a){
    arbol aux=a;
    colocarParIzq(aux);
    colocarParDer(aux);
}

void colocarParIzq(arbol &a){
    if(a!= NULL){
        if(a->hizq != NULL){
            colocarParIzq(a->hizq);
            }else{
                a->hizq = new nodoABB;
                setParentesis(a->hizq->info, '(');
                a->hizq->hizq = NULL;
                a->hizq->hder = NULL;
            }
    }
}

void colocarParDer(arbol &a){
    if(a!= NULL){
        if(a->hder != NULL){
            colocarParDer(a->hder);
        }else{
            a->hder = new nodoABB;
            setParentesis(a->hder->info,')');
            a->hder->hizq = NULL;
            a->hder->hder = NULL;
        }
    }
}

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
    return FALSE;
}

arbol copiarArbol(arbol original) {
    if (original == NULL) {
        return NULL;
    }

    arbol nuevo = new nodoABB;
    nuevo->info = original->info;
    nuevo->hizq = copiarArbol(original->hizq);
    nuevo->hder = copiarArbol(original->hder);

    return nuevo;
}

void insertarNodo(arbol &a, datoABB dato) {
    if (a == NULL){
        a = new nodoABB;
        a->info = dato;
        a->hizq = NULL;
        a->hder = NULL;
    }else{
        if(darNumero(dato)<darNumero(a->info)) {
            insertarNodo(a->hizq,dato);
        }else{
            insertarNodo(a->hder,dato);
        }
    }
}

void juntarArboles(arbol a, arbol b, datoABB dat, arbol &c) {
    c = new nodoABB;
    c->info = dat;
    c->hizq = a;
    c->hder = b;
    colocarParentesis(c);
}

//DAR
arbol darRaiz(arbol a){
    return a;
}

arbol hijoIzq(arbol a){
    return a->hizq;
}

arbol hijoDer(arbol a){
    return a->hder;
}

datoABB darInfo(arbol a){
    return a->info;
}

//MOSTRAR
void mostrarArbolRecu(arbol a){
    if(a!=NULL){
        mostrarArbolRecu(a->hizq);
        mostrarNodoAbb(a->info);
        mostrarArbolRecu(a->hder);
    }
}

//CARGAR
void cargarArbolAtomic(arbol &a, string s){
    a=new nodoABB;
    setValor(a->info,stringAboolean(s));
    a->hder=NULL;
    a->hizq=NULL;
}

void cargarArbolCompoundNOT(arbol &a,arbol abb){
    a = new nodoABB;
    setNOT(a->info);
    a->hder=abb;
    a->hizq=NULL;
    colocarParentesis(a);
}

//GUARDAR Y LEVANTAR
void guardarArbol(arbol a, FILE * f){
    if(a!=NULL){
        guardarNodo(a->info,f);
        guardarArbol(a->hizq,f);
        guardarArbol(a->hder,f);
    }
}


void levantarArbol(arbol &a, FILE *f) {
    datoABB dat;
    levantarNodo(dat, f);
    while (!feof(f)){
        insertarNodo(a, dat);
        levantarNodo(dat, f);
    }
}


