#include <iostream> // Permite usar std::cin y std::coutpara la consola (entrada y salida)
#include <string> // Permite manejar cadenas de texto (std::string)
#include <sstream> // Permite tratar un texto como un flujo (stream) para separar letras o numeros por espacios
#include <cctype> // Contiene funciones utiles para verificar caracteres, como isalpha() (si es letra) o isdigit() (si es numero)
#include <algorithm>
#include <vector>
#include "cyph3r.h"
using namespace std;

int cyph3r::printMenu(string &user, int &usuario){
    cout << " " << endl;
    cout << "--- CYPH3R (programa de cifrado y descifrado de mensajes) ---" << endl;
    cout << "Menu" << endl;
    cout << "1. Informacion sobre los metodos de cifrado" << endl;
    cout << "2. Cifrar/Descifrar mensaje" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione el numero de la opcion que desea visualizar: ";
    getline(cin, user);

    //validar y rechazar entradas invalidas. Volver a pedir
    while(user != "1" && user != "2" && user != "3"){ //si lo pongo en default, me vuelve a imprimir el menu. No quiero eso
        cout << "Dato invalido. Ingrese nuevamente: ";
        getline(cin, user);
    }

    //convertir strings a enteros (para usarlos en switch)
    usuario = stoi(user);
    return usuario;
}

int cyph3r::printMetod(int &metod){
    string metodos;
    cout << "\n---Metodos de cifrado disponibles---" << endl;
    cout << "1. Cifrado Cesar " << endl;
    cout << "2. Codigo Morse" << endl;
    cout << "3. Cifrado por Transposicion" << endl;
    cout << "4. Cifrado A1Z26" << endl;
    cout << "5. Cifrado Atbash" << endl;
    cout << "6. Atras" << endl;
    cout << "Seleccione el metodo que desea utilizar: ";
    getline(cin, metodos);

    while (metodos != "1" && metodos != "2" && metodos != "3" &&
          metodos != "4" && metodos != "5" && metodos != "6"){
            cout << "Dato invalido.Ingrese nuevamente: ";
            getline(cin, metodos);
    }
    metod = stoi(metodos);
    return metod;
}

void cyph3r::cifrcesar (string phrase,int recorrido, bool minusk, int letra) {
    cout << "Ingrese mensaje a cifrar en minusculas: ";
    getline(cin,phrase);

    do {
        minusk = true;
        //Se recorre todo el string mediante indices, para corroborar que solo se ingresaron minusculas
        for(int i = 0; i < phrase.length(); i ++) {
            if (phrase[i] < 'a' || phrase[i] > 'z'){
                if (phrase[i]!=' ') {
                    minusk = false; // si algún carácter es diferente de una letra minuscula se asigna valor falso
                    break; // al detectar un solo carácter diferente de una letra minuscula, se sale del ciclo for
        }
            }
    }

        if (minusk == false){
        cout << "Ingrese un mensaje en minusculas: " << endl; // Solicita nuevamente el mensaje
        getline(cin,phrase);
        }
      } while (minusk == false);

    cout << "Ingrese numero de caracteres a recorrer (de 1 a 25): ";
    cin >> recorrido;

    while (recorrido < 1 || recorrido > 25){
        cout << "Ingrese un numero en el rango: ";
        cin >> recorrido;
      }

    for (int i = 0; i < phrase.length(); i ++) {
        if (phrase[i] != ' ') {
            letra = phrase[i] + recorrido;

            if (letra > 122) {
                letra = letra - 26;
            }

        phrase[i] = letra;
      }
      cout << phrase[i];
    }


    cin.ignore();
}

void cyph3r::codeMorse(const string &cifrado){
    string morse[26];
    morse[0]=".-"; morse[1]="-..."; morse[2]="-.-."; morse[3]="-.."; morse[4]=".";
    morse[5]="..-."; morse[6]="--."; morse[7]="...."; morse[8]=".."; morse[9]=".---";
    morse[10]="-.-"; morse[11]=".-.."; morse[12]="--"; morse[13]="-."; morse[14]="---";
    morse[15]=".--."; morse[16]="--.-"; morse[17]=".-."; morse[18]="..."; morse[19]="-";
    morse[20]="..-"; morse[21]="...-"; morse[22]=".--"; morse[23]="-..-"; morse[24]="-.--";
    morse[25]="--..";

    //Arreglo de letras
    char abc[26];
    for(int i = 0; i < 26; i++){
        int last = i;
        abc[i] = 'a' + static_cast<char>(last);
    }

    if(cifrado == "1"){
        string msj;
        string texto;
        char letra;
        bool pass = false;
        cout << "CODIGO MORSE" << endl;
        cout << "INSTRUCCIONES" << endl;
        cout << "Escriba el texto que desee cifrar utilizando solo minusculas. " << endl;
        cout << "No se aceptan acentos simbolos o cualquier otro signo de puntuacion." << endl;
        cout << "Ingrese mensaje a cifrar: ";
        getline(cin,msj);
        while(pass == false){
            pass = true;
            for(int i = 0; i < msj.size(); i++){
                if(msj[i] != ' ' && (msj[i] < 'a' || msj[i] > 'z')){
                    pass = false;
                    break;
                }
            }
            if(pass == false) {
                cout << "Dato invalido. Recuerde utilizar solo minusculas: ";
                getline(cin,msj);
            }
        }

        for(int i = 0; i < msj.size(); i++){
            letra = msj[i];
            for(int j = 0; j < 26; j++){
                if(letra == abc[j]){
                    texto = texto + morse[j];
                    texto.push_back(' ');
                    break;
                }
                if(letra == ' '){
                    if(texto.size() >= 2 && texto[texto.size() - 2] != '/'){
                        texto = texto + "/ ";
                        break;
                    }
                }
            }
        }
        cout << "Mensaje descifrado: " << texto;
    } else {
        string tken;
        vector<string> msjD;
        vector<string>msjC;
        string temp;
        bool invalid = true;

        //Opcion de cifrado
        cout << "CODIGO MORSE" << endl;
        cout << "INSTRUCCIONES" << endl;
        cout << "Escriba el mensaje cifrado en Codigo Morse. " << endl;
        cout << "Recuerde dejar espacio entre cada letra y use ( / ) entre cada palabra" << endl;
        cout << "Ejemplo: hola mundo" << endl << "[.... --- .-.. .- / -- ..- -. -.. ---]" << endl;
        cout << "Ingrese mensaje a descifrar: ";
        getline(cin,temp);

        while(invalid == true){
            stringstream ss(temp);

            while(ss >> tken){
                msjC.push_back(tken);
            }

            if(msjC.empty()){
            cout << "Entrada vacia. Ingrese el mensaje nuevamente: ";
            getline(cin, temp);
            continue;
        }

        for(int i = 0; i < msjC.size(); i++){ //token de mensaje
            invalid = true;
            if(msjC[i] == "/" && i != 0){
                msjD.push_back(" ");
                invalid = false;
            } else {
                for(int j = 0; j < 26; j++){ //revisa el arreglo Morse
                    if(msjC[i] == morse[j]){
                        msjD.push_back(string(1, abc[j]));
                        invalid = false;
                        break;
                    }
                }
            }

            if(invalid == true){
                msjC.clear();
                msjD.clear();
                cout << "Mensaje invalido. No se aceptan letras, numeros o simbolos y compruebe que el codigo morse sea correcto" << endl;
                cout << "Ingrese el mensaje nuevamente: ";
                getline(cin, temp);
                break;
            }
        }
    }

    cout << "Mensaje descifrado: ";
    for(int i = 0; i < msjD.size(); i++){
        cout << msjD[i];
    }
    cout << endl;

    }
}

void cyph3r::metTranspo(string frase, string cifrado){
    vector<string> lista;
    stringstream ss(frase);
    string word;

    //Se separa la frase en palabras
    while (ss >> word){
        lista.push_back(word);

    }

    if(cifrado == "1" ){
        cout << "\ncifrado: ";
        }else{
            cout << "\ndescifrado: ";
        }

    //invierte palabras del vector
    for (int i = 0; i < lista.size(); i++){
        reverse(lista[i].begin(), lista[i].end());
        cout << lista[i] << " ";
    }
    cout << " " << endl;
    lista.clear();
}

string cyph3r::cifrarA1Z26(const string& txt) {
    string result = ""; // Aqui guardamos el resultado final cifrado

    // Recorremos cada letra del texto recibido usando el indice i
    for (size_t i = 0; i < txt.length(); ++i) {
        char c = txt[i]; // 'c' es el caracter actual que estamos analizando

        // Si es una lera (mayuscula o minuscula)
        if (isalpha(c)) {
            // Determinamos si la base es 'A' (65 en ASCII) o 'a' (97 en ASCII)
            char base = isupper(c) ? 'A' : 'a';

            // Calculamos su posicion numerica> 'a' - 'a' + 1 = 1, 'b' - 'b' + 1 = 2, etc
            int num = (c - base) + 1;

            // Convertimos ese numero a texto y le anadimos un espaciopara separarlos
            result += to_string(num) + " ";

        // Si es un numero (digito) lo protegemos con la etiqueta [num: ]
        } else if (isdigit(c)) {
            result += "[num:" + string(1, c) + "] ";

        // Si es un espacio o un simbolo especial se queda igual
        } else {
            result += c;
            if (c != ' ') {
                result += " "; // Devolvemos la cadena cifrada completa
            }
        }
    }
    return result;
}

string cyph3r::descifrarA1Z26(const string& code) {

    string result = "";
    // std::stringstream nos permite partir la cadena de texto usando los espacios como separadores
    stringstream ss(code);
    string token;

    // Leemos elemento por elemento (token por token) separado por espacios
    while (ss >> token) {
        // Si el token es nuestra etiqueta de numero protegido para descifrarlo de forma segura
        if (token.rfind("[num:", 0) == 0) {
            char dig = token[5]; // Extraemos el numero original que se estaba guardando adentro
            result += dig;

        // Si es un numero cifrado normal
        } else {
            bool esNum = true;
            for (char c : token) {
                if (!isdigit(c)) {
                    esNum = false; // Comprobamos que todos los caracteres del token sean numeros
                    break;
                }
            }

            if (esNum) {
                int num = stoi(token); // Convertimos el exto a numero entero (por ejemplo: "12" a 12)

                // Si esta en el rago de del abecedario (1 al 26)
                if (num >= 1 && num <= 26) {
                    // Convertimos el numero de vuelta a letra sumandoselo a 'A'
                    result += (char)('A' + num - 1);
                } else {
                    result += token; // Si esta fuera del rango, pasa igual
                }
            } else {
                // Si es un simbolo suelto pasa igual, si es un guion bajo imprimir un espacio
                if (token == "_") {
                    result += " ";
                } else {
                    result += token;
                }
            }
        }
    }
    return result;
}

void cyph3r::cifratbash (string palabra, string cifrado, bool minusc, int &contC, int &contD, string s) {
vector<string> fila;
string ms;

// Se evalua que todos los caracteres del string palabra sean minusculas
    cout << " " << endl;
    cout << "---Cifrado y Descifrado Atbash---" << endl;
    s = "s";
    // Se utiliza para imprimir, si "cifrar" o "descifrar", segun el metodo ingresado por el usuario
    while (s == "s") {
        if (cifrado == "1") {
            cout << "Ingrese mensaje a cifrar en minusculas: ";
    }   else {
            cout << "Ingrese mensaje a descifrar en minusculas: ";
    }
    getline(cin, palabra);

    do {
        minusc = true;
        // Se recorre todo el string mediante indices, para corroborar que solo se ingresaron minusculas
        for(int i = 0; i < palabra.length(); i++) {
        if (palabra[i] < 'a' || palabra[i] > 'z'){
        if (palabra[i] != ' ') {
        minusc = false;
        // Si algun caracter es diferente de una letra minuscula se asigna valor falso
        break; // Al detectar un solo caracter diferente a una letra minuscula, se sale del ciclo for
        }
             }
                  }
        if (palabra.find_first_not_of(' ') == string::npos) {
            minusc = false;
        }
        if (minusc == false){
            cout << "Ingrese un mensaje en minusculas, no dejes espacios vacios: " << endl;
            // Solicita nuevamente el mensaje
            getline(cin, palabra);
            }

            } while (minusc == false);



            // Personaliza el mensaje segun el metodo elegido
                if (cifrado == "1"){
                    cout << "Mensaje cifrado: ";
                    contC ++;
            }   else {
                    cout << "Mensaje descifrado: ";
                    contD ++;
                            }
        stringstream ss(palabra);
        fila.clear();

        while (ss >> ms){
            fila.push_back(ms);
        }
            // Se utiliza el codigo ASCII para imprimir la letra contraria
            //fila.size es cuantas palabras hay en el vector
            for (int i = 0; i < fila.size(); i++) {
                for (int j = 0; j < fila[i].length(); j++) {
                    fila[i][j] = 'z' - (fila[i][j] - 'a');
                }
                cout << fila[i] << " ";
            }
                cout << "  " << endl;

            if (cifrado == "1") {
                cout << "Si desea cifrar alguna otra palabra con Atbash ingrese s, sino ingrese cualquier otro caracter: ";
        }   else {
                cout << "Si desea descifrar alguna otra palabra con Atbash ingrese s, sino ingrese cualquier otro caracter: ";
        }
        getline(cin, s);

        cout << " "<< endl;
}

}
