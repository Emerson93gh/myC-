// Punteros a estructuras
#include <iostream>
#include <conio.h>
using namespace std;

// creamos estructura
struct Persona {
    char nombre[30];
    int edad;
}persona, *puntero_persona = &persona; //variable de tipo estructura con la posicion en memoria donde se almacena

void pedirDatos(); // prototipo de funcion
void mostrarDatos(Persona *); // con parametros de tipo puntero

int main() {
    pedirDatos();
    mostrarDatos(puntero_persona);

    getch();
    return 0;
}

// funcion para pedir datos
void pedirDatos() {
    cout << "Digita tu nombre: " << endl;
    cin.getline(puntero_persona->nombre,30,'\n');
    cout << "Digita tu edad: " << endl;
    cin >> puntero_persona->edad;
}

// funcion para mostrar datos
void mostrarDatos(Persona *puntero_persona) {
    cout << "\nSu nombre: " << puntero_persona->nombre << endl;
    cout << "\nSu edad: " << puntero_persona->edad << endl;

}