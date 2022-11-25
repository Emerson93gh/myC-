#include <iostream>
using namespace std;
/*
OPERADOR DE FLECHA EN ESTRUCTURA
*/
// creamos la estructura
struct estudiante {
    char nombre[80];
    int edad;
    float porcetaje;
};

// creamos el objeto de la estructura
struct estudiante* emp = NULL;

int main() {
    // asignamos memoria a la variable de la estructura emp
    emp = (struct estudiante*)malloc(sizeof(struct estudiante));

    // asignamos valor a la variable edad usando la flecha
    emp->edad = 18;

    // imprimimos el valor asignado de la variable
    cout << "Edad: " << emp->edad;

    return 0;
}