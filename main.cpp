#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string phrase = " ";
    int recorrido = 0;
    bool minusk = 1;
    int letra;

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
    return 0;
}
