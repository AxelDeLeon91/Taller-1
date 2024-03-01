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

boolean strmen(string s1, string s2){
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

boolean streq(string s1, string s2){ //analiza si s1 y s2 son iguales
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i]!= '\0') && (s2[i]!= '\0')) {
        if (s1[i]!= s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i]!= '\0') || (s2[i]!= '\0'))
        iguales = FALSE;
    return iguales;
}

char saberOperador(string palabra){ //recibe el string y devuelve su operador
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

void mayusMinus(string &str){//Recibe un string str y lo pasa a minuscula:  AtOmiC -> atomic
    for (int i=0; str[i]!='\0';i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i]+32;
        }
    }
}

char reconocerComando(string palabra){ //Utilizado para reconocer el comando ingresado por consola
    mayusMinus(palabra);
    char resultado;
    if (streq(palabra, "atomic")){
        resultado= 'A';
    }else if(streq(palabra,"compound")){
        resultado= 'C';
    }else if(streq(palabra,"show")){
        resultado=  'H';
    }else if(streq(palabra,"evaluate")){
        resultado=  'E';
    }else if(streq(palabra,"save")){
        resultado=  'S';
    }else if(streq(palabra,"load")){
        resultado=  'L';
    }else if(streq(palabra,"exit")){
        resultado=  'X';
    }
    return resultado;
}

void charAString(char c, string &s){//Recibe un char y devuelve un string
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

void booleanAString(boolean b, string &s){//Recibe un valor booleano y lo devuelve en un string
    if(b==TRUE){
        strcop(s,"TRUE");
    }else if(b==FALSE){
        strcop(s,"FALSE");
    }
}

int stringAentero(string s){//Recibe un string y devuelve su valor entero
    int resu=0;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='0' && s[i]<='9'){
            resu = resu * 10+(s[i]-48);
        }
        i++;
    }
    return resu;
}

boolean esNumero(string s){
    boolean es=TRUE;
    int i = 0;
    while (s[i] != '\0'){
        if (!(s[i] >= '0' && s[i] <= '9')) {
            es=FALSE;
        }
        i++;
    }
    return es;
}

boolean validarBool(string s){//Valida que el boolean este bien escrito
    boolean valida=FALSE;
    if(streq(s,"false")==TRUE){
       valida=TRUE;
       }else if(streq(s,"true")==TRUE){
                valida=TRUE;
       }
    return valida;
    }

boolean validarEntero(string s){ //Valida que en el string S solo exitan numeros enteros, nada de caracteres
    boolean valida= TRUE;
    if (s[0] == '\0') {
        valida= FALSE;
    }
    if(valida==TRUE){
        for (int i=0;s[i]!='\0';i++) {
            if (!(s[i]>='0' && s[i]<='9')) {
                valida= FALSE;
            }
        }
    }
    return valida;
}

boolean esLetra(char c){//Chequea que el char sea una letra.
    boolean es = FALSE;
    if((c>='a' && c<='z') || (c>='A' && c<='Z')){
        es = TRUE;
    }
    return es;
}

boolean validarFormatoArchivo(string s){//Utilizada en ValidarLoad y validarSave para saber si el archivo se encuentra bien escrito.
    boolean valida = FALSE;
    int largo = strlar(s);
    if(largo>4) {
        if (s[largo-4]=='.' && s[largo-3]=='d' && s[largo-2]=='a' && s[largo-1]=='t'){
            for (int i = 0; i < largo - 4; i++) {
                if (esLetra(s[i])==TRUE){
                    valida=TRUE;
                }
              }
            }
        }
    return valida;
}

boolean stringAboolean(string s){ //Recibe el string s y devuelve su valor boolean
    boolean b= FALSE;
    if(streq(s,"false")){
        b=FALSE;
    }else if(streq(s,"true")){
            b=TRUE;
    }
    return b;
}

char obtenerRespuestaValida(char &c){ //Utilizada en EjecutarSave para recibir una respuesta valida sobre soobresscribir
    do{
        scanf(" %c", &c);
        if(c!= 'S' && c!= 's' && c!= 'N' && c!= 'n'){
            printf("Por favor, ingrese una respuesta valida ('S' o 'N'): ");
        }
    } while(c!= 'S' && c!= 's' && c!= 'N' && c!= 'n');
    return c;
}

//HACER VALIDAR AND OR Y VALIDAR NOT
boolean validarOrAnd(string s){ //Valida que el string ingresado este en mayuscula y sea OR o AND
    boolean valida=FALSE;
    if(streq(s,"AND") || streq(s,"OR")){
        valida=TRUE;
    }
    return valida;
}
boolean validarNOT(string s){ //Valida que el string ingresado este en mayuscula y sea NOT
    boolean valida=FALSE;
    if(streq(s,"NOT")){
        valida=TRUE;
    }
    return valida;
}

boolean existeArchivo(string s) { //Chequea la existencia del archivo en disco.
    boolean existe=FALSE;
    FILE *f = fopen(s, "r");

    if (f != NULL){
        existe=TRUE;
    }
    return existe;
}
