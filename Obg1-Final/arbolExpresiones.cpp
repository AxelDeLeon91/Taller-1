#include <stdio.h>
#include "arbolExpresiones.h"
//FUNCIONALIDADES
void crear(arbol &a){ //Crea el arbol
    a=NULL;
}

boolean vacio(arbol a){ //Booleano que dice si el arbol esta vacio
    return (boolean)(a == NULL);
}

void numerarArbol(arbol &a){ //Numera el arbol en orden
    int contador=1;
    numerarRecursivo(a,contador);
}

void numerarRecursivo(arbol a, int &contador){ //Recorre el abb en orden, llamando a SetNumero para setear el contador como numero para el nodo
    if(a!=NULL){
        numerarRecursivo(a->hizq,contador);
        setNumero(a->info,contador);
        contador++;
        numerarRecursivo(a->hder,contador);
    }
}

void colocarParentesis(arbol &a){ //Coloca los parentesis en los arboles
    arbol aux=a;
    colocarParIzq(aux);
    colocarParDer(aux);
}

void colocarParIzq(arbol &a){ //Coloca el par izq
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

void colocarParDer(arbol &a){ //Coloca el par der
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

boolean evaluarArbol(arbol a){ //Evalua el arbol en postorden.
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

arbol copiarArbol(arbol original){ //Copia el arbol original y retorna un arbol nuevo.
    if (original == NULL) {
        return NULL;
    }
    arbol nuevo = new nodoABB;
    nuevo->info = original->info;
    nuevo->hizq = copiarArbol(original->hizq);
    nuevo->hder = copiarArbol(original->hder);
    return nuevo;
}

void insertarNodo(arbol &a, datoABB dato){ //Inserta los nodos en el arbol, usando el numero como base para su orden
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

void juntarArboles(arbol a, arbol b, datoABB dat, arbol &c){ //Crea el arbol C, le asigna dat como raiz, a como hizq y b como hder
    c = new nodoABB;
    c->info = dat;
    c->hizq = a;
    c->hder = b;
    colocarParentesis(c);
}

//DAR
arbol darRaiz(arbol a){ //Devuelve la raiz de a
    return a;
}

arbol hijoIzq(arbol a){ //Devuelve el hizq de a
    return a->hizq;
}

arbol hijoDer(arbol a){ //Devuelve hder de a
    return a->hder;
}

datoABB darInfo(arbol a){ //Devuelve la info de a
    return a->info;
}

//MOSTRAR
void mostrarArbolRecu(arbol a){ //Muestrea el arbol mediante su recorrida en orden
    if(a!=NULL){
        mostrarArbolRecu(a->hizq);
        mostrarNodoAbb(a->info);
        mostrarArbolRecu(a->hder);
    }
}

//CARGAR
void cargarArbolAtomic(arbol &a, string s){ // Carga el arbol con su unico nodo de tipo valor
    a=new nodoABB;
    setValor(a->info,stringAboolean(s));
    a->hder=NULL;
    a->hizq=NULL;
}

void cargarArbolCompoundNOT(arbol &a,arbol abb){//Utilizada en la funcion compound en su variante NOT
    a = new nodoABB;
    setNOT(a->info);
    a->hder=abb;
    a->hizq=NULL;
    colocarParentesis(a);
}

//GUARDAR Y LEVANTAR
void guardarArbol(arbol a, FILE * f){//Guarda el arbol a en el file f
    if(a!=NULL){
        guardarNodo(a->info,f);
        guardarArbol(a->hizq,f);
        guardarArbol(a->hder,f);
    }
}


void levantarArbol(arbol &a, FILE *f){//Levanta el arbol desde el file f
    datoABB dat;
    levantarNodo(dat,f);
    while (!feof(f)){
        insertarNodo(a,dat);
        levantarNodo(dat,f);
    }
}


