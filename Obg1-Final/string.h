#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>
#include "boolean.h"

const int MAX = 80;
typedef char * string;

void strcrear(string &s);
void strdestruir(string &s);
int strlar(string s);
void strcop(string &s1, string s2);
void scan(string &s);
void strcon(string &s1, string s2);
void strswp(string &s1, string &s2);
void print(string s);
boolean strmen(string s1, string s2);
boolean streq(string s1, string s2);
char reconocerComando(string lStr);

//Pasa las letras mayusculas a minuscula
void mayusMinus(string &str);

//Segun el string, te dice que Operador es, retorna la Inicial o E en caso de error
char saberOperador(string palabra);

boolean stringAboolean(string s);
void charAString(char c, string &s);
void booleanAString(boolean b, string &s);
int stringAentero(string s);
boolean validarBool(string s);
boolean validarFormatoArchivo(string s);
boolean validarEntero(string s);
char obtenerRespuestaValida(char &c);
boolean validarOrAnd(string s);
boolean validarNOT(string s);
boolean existeArchivo(string s);
#endif // STRING_H_INCLUDED
