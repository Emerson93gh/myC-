#include <iostream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "funciones.h"

using namespace std;

int menu() {
    int x = 0;
    cout << "1. Agregar" << endl;
    cout << "2. Listar" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Eliminar" << endl;
    cout << "5. Modificar" << endl;
    cout << "6. Salir" << endl;
    cout << "Ingresar opcion: ";
    cin >> x;
    return x;
}

int main() {
    //int x = 0;
    int x = menu();
    if(x >=1 && x <= 6) {
        //x = menu();

        switch(x) {
            case 1:
                agregarRegistro();
                break;
            case 2:
                listarRegistro();
                break;
            case 3:
                buscarRegistro();
                break;
            case 4:
                eliminarRegistro();
                break;
            case 5:
                modificarRegistro();
                break;
            case 6:
                //salir();
                break;
        }
    } else {
        cout << "Error! Ingrese un numero entre 1 y 6" << endl;
        main();
    }
    return 0;
}