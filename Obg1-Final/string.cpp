#include <stdio.h>
#include "string.h"


void strcrear(string &s) {
    s = new char[1];
    s[0] = '\0';
}

void strdestruir(string &s) {
    delete[] s;
    s = NULL;
}

int strlar(string s) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strcop(string &s1, string s2) {
    int i = 0, largo = strlar(s2) + 1;
    strcrear(s1);
    delete[] s1;
    s1 = new char[largo];
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan(string &s) {
    string aux = new char[MAX];
    int i = 0;
    char c;
    fflush(stdin);
    scanf("%c", &c);
    while (c != '\n' && i < MAX - 1) {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }
    aux[i] = '\0';
    strcop(s, aux);
    strdestruir(aux);
}

void strcon(string &s1, string s2) {
    string aux;
    strcrear(aux);
    strcop(aux, s1);
    int largo = strlar(s1) + strlar(s2) + 1;
    if (largo > MAX)
        largo = MAX;
    delete[] s1;
    s1 = new char[largo];
    int i = 0;
    while (aux[i] != '\0') {
        s1[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX - 1) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    strdestruir(aux);
}

void strswp(string &s1, string &s2) {
    string aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}

void print(string s){
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
}

boolean strmen(string s1, string s2) {
    boolean encontre = FALSE, menor = FALSE;
    int i = 0;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i] != '\0'))
        menor = TRUE;
    return menor;
}

boolean streq(string s1, string s2) {
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

char saberOperador(string palabra) {
    char resultado = 'E';
    if(streq(palabra, "AND") == TRUE) {
        resultado = 'A';
    }else if(streq(palabra, "NOT") == TRUE) {
        resultado = 'N';
    }else if(streq(palabra, "OR") == TRUE) {
        resultado = 'O';
    }else{
        resultado = 'E'; //ERROR
    }
    return resultado;
}

char reconocerComando(string palabra) {
    char resultado='X';

    if (streq(palabra, "atomic")==TRUE){
        resultado= 'A';
    }else if(streq(palabra,"compound")==TRUE){
        resultado= 'C';
    }else if(streq(palabra,"show")==TRUE){
        resultado=  'S';
    }else if(streq(palabra,"evaluate")==TRUE){
        resultado=  'E';
    }else if(streq(palabra,"save")==TRUE){
        resultado=  'S';
    }else if(streq(palabra,"load")==TRUE){
        resultado=  'L';
    }else if(streq(palabra,"exit")==TRUE){
        resultado=  'E';
    }
    return resultado;
}


void charAString(char c, string &s){
    switch(c){
        case 'A':
                strcop(s,"AND");
                break;
        case 'O':
                strcop(s,"OR");
                break;
        case 'N':
                strcop(s,"NOT");
                break;
        case '(':
                strcop(s,"(");
                break;
        case ')':
                strcop(s,")");
                break;
        default:
                break;
    }
}

void booleanAString(boolean b, string &s){
    if(b==TRUE){
        strcop(s,"TRUE");
    }else if(b==FALSE){
        strcop(s,"FALSE");
    }
}

//Sirve solo para POSITIVOS, esto lo tendria que chequear antes??
int stringAentero(string s){
    int resu=0;
    int i=0;

    while(s[i]!='\0'){
        if(s[i]>='0' && s[i]<='9'){
            resu = resu * 10+(s[i]-48);
        }
    }
    return resu;
}

boolean validarBool(string s){
    boolean valida=FALSE;
    if(streq(s,"false")==TRUE){
       valida=TRUE;
       }else if(streq(s,"true")==TRUE){
                valida=TRUE;
       }
    return valida;
    }

boolean validarFormatoArchivo(string s){
    boolean valida=FALSE;
    int largo = strlar(s);
    if(largo>=5){//ES 5 O ES 4?
        if(s[largo-3]=='.' && s[largo-2]=='d' && s[largo-1]=='a' && s[largo]=='t')
            valida=TRUE;
    }
    return valida;
}

