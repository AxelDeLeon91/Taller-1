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
        contador++;
        numerarRecursivo(a->hder,contador);
    }
}

void colocarParentesis(arbol &a){
    printf("\nEntre colocarPar");
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

void juntarArboles(arbol a, arbol b, datoABB dat, arbol &c) {
    printf("\nEntre Juntar Arboles");
    c = new nodoABB;
    c->info = dat;
    c->hizq = a;
    c->hder = b;
    colocarParentesis(c);
}

void cargarArbolAtomic(arbol &a, string s){
    a=new nodoABB;
    setValor(a->info,stringAboolean(s));
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

void guardarArbolAux(arbol a, FILE * f){
    if(a!=NULL){
        guardarNodo(a->info,f);
        guardarArbolAux(a->hizq,f);
        guardarArbolAux(a->hder,f);
    }
}

void guardarArbol(arbol a, FILE * f) {
    guardarArbolAux(a, f);
}

void insertarNodo(arbol &a, nodoABB nuevoNodo) {
    if (a == NULL){
        a = new nodoABB;
        a->info = nuevoNodo.info;
        a->hizq = NULL;
        a->hder = NULL;
    }else{
        if(darNumero(nuevoNodo.info)<darNumero(a->info)) {
            insertarNodo(a->hizq,nuevoNodo);
        }else{
            insertarNodo(a->hder,nuevoNodo);
        }
    }
}

void levantarArbol(arbol &a, FILE *f) {
    datoABB dat;

    fread(&dat, sizeof(datoABB), 1, f);
    while (!feof(f)){
        nodoABB nuevoNodo;
        nuevoNodo.info = dat;
        nuevoNodo.hizq = NULL;
        nuevoNodo.hder = NULL;

        levantarNodo(nuevoNodo.info, f);
        insertarNodo(a, nuevoNodo);

        fread(&dat, sizeof(datoABB), 1, f);
    }
}


