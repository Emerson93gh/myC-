#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "funciones"

using namespace std;

struc Persona {
    char nombre[45] = "";
    char apellido[45] = "";
    long dui = 0;
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

long getLong(string mjs) {
    long m;
    cout << mjs << endl;
    cin >> m;
    return m;
}
string getString(string mjs) {
    string m;
    cout << mjs << endl;
    getline(cin, m);
    return m;
}
Persona getPersona(long dui) {
    fstream e("archivo.txt", ios::out | ios::in | ios::binary);
    Persona aux;

    if(e.is_open()) {
        e.seekg((dui-1) * sizeof(Persona));
        e.read((char*) &aux, sizeof(Persona));
        e.close();
    }
    return aux;
}

int main() {
    int x = 0;
    do {
        x = menu();

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
                salir();
                break;
        }
    } while(x != 6);
    return 0;
}