#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

struc Persona {
    char nombre[45] = "";
    char apellido[45] = "";
    long cedula = 0;
};

int menu () {
    int x = 0;
    cout << "1. Agregar" << endl;
    cout << "2. Listar" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Eliminar" << endl;
    cout << "5. Modificar" << endl;
    cout << "6. Salir" << endl;
    cout << "Ingresar opcion: ";
    cout >> x;
    return x;
}

int main() {
    int x = 0;
    do {
        x = menu();
    } while(x != 6);
    return 0;
}