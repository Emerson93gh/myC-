#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;

// estructura
struct Persona {
    char nombre[45] = "";
    char apellido[45] = "";
    long dui = 0;
};

// metodos
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


// funcion para agregar registro
void agregarRegistro(){
    Persona p;
    
    cin.ignore();
    // obtenemos el nombre y convertimos el string a char
    strcpy(p.nombre, getString("Ingresar Nombre: ").c_str());
    strcpy(p.apellido, getString("Ingresar Apellido: ").c_str());
    p.dui = getLong("Ingresar numero de DUI: ");

    Persona aux = getPersona(p.dui);

    if(aux.dui != 0) {
        cout << "Registro ya existe" << endl;
    } else {
        fstream e("archivo.txt", ios::out | ios::in | ios::binary);

        if(e.is_open()) {
            e.seekp((p.dui-1) * sizeof(Persona)); //cambia a seekp
            e.write((char*) &p, sizeof(Persona));
            e.close();
        }
    }
}