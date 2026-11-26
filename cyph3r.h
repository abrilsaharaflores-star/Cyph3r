#ifndef CYPH3R_H_INCLUDED
#define CYPH3R_H_INCLUDED
#include <string>

using namespace std;

namespace cyph3r {

//Encargado: Alef Luna
int printMenu(string &user, int &usuario);

//Encargado: Yulehimy Martinez
int printMetod(int &metod);

//Encargado: Abril Flores
void cifrcesar(string phrase, int recorrido, bool minusk, int letra);

//Encargado: Alef Luna
void codeMorse(const string &cifrado);

//Encargado: Yulehimy Martinez
void metTranspo(string mensaje, string cifrado);

//Encargado: Gabriel Ibarra
string cifrarA1Z26(const string& txt);
string descifrarA1Z26(const string& code);

//Encargado: Abril Flores
void cifratbash (string palabra, string cifrado, bool minusc, int &contC, int &contD, string s);

}

#endif // CYPH3R_H_INCLUDED
