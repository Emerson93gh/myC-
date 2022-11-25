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
    long telefono = 0;
};

// metodos
// obtenemos un valor ingresado por teclado de tipo long
long getLong(string mjs) {
    long m;
    cout << mjs << endl;
    cin >> m;
    return m;
}
// obtenemos un valor ingresado por teclado de tipo string
string getString(string mjs) {
    string m;
    cout << mjs << endl;
    getline(cin, m);
    return m;
}
Persona getPersona(long dui) {
    fstream e("directorio.txt", ios::out | ios::in | ios::binary);
    Persona aux;

    if(e.is_open()) {
        e.seekg((dui-1) * sizeof(Persona));
        e.read((char*)&aux, sizeof(Persona));
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
    p.telefono = getLong("Ingresar el numero de telefono: ");

    Persona aux = getPersona(p.dui);

    if(aux.dui != 0) {
        cout << "Registro ya existe" << endl;
    } else {
        fstream e("directorio.txt", ios::out | ios::in | ios::binary);

        if(e.is_open()) {
            e.seekp((p.dui-1) * sizeof(Persona)); //cambia a seekp
            e.write((char*) &p, sizeof(Persona));
            e.close();
        }
    }
}
// metodo para mostrar persona
void mostrar(Persona p) {
    cout << "Nombre: " << p.nombre << endl;
    cout << "Apellido: " << p.apellido << endl;
    cout << "# DUI: " << p.dui << endl;
    cout << "Telefono: " << p.telefono << endl;
    cout << "___________________________________" << endl;
}

// funcion para listar registros
void listarRegistro() {
    fstream e("directorio.txt", ios::out | ios::in | ios::binary);
    Persona aux;

    if(e.is_open()) {
        e.read((char*)&aux, sizeof(Persona));
        while(!e.eof()) {
            if(aux.dui != 0)
                mostrar(aux);
            e.read((char*)&aux, sizeof(Persona));
        }
        e.close();
    }
}

// funcion para buscar registros
void buscarRegistro() {
    int long dui = getLong("Digite el numero de DUI: ");
    Persona aux = getPersona(dui);
    if(aux.dui == 0) {
        cout << "No existe el registro!" << endl;
    } else {
        mostrar(aux);
    }
}

// funcion para eliminar registro
void eliminar(int long dui) {
    fstream e("directorio.txt", ios::out | ios::in | ios::binary);
    Persona aux;
    if(e.is_open()) {
            e.seekp((dui-1) * sizeof(Persona)); //cambia a seekp
            e.write((char*) &aux, sizeof(Persona));
            e.close();
        }
}
void eliminarRegistro() {
    int long dui = getLong("Digite el numero de DUI: ");
    Persona aux = getPersona(dui);
    if(aux.dui == 0) {
        cout << "No existe el registro!" << endl;
    } else {
        cout << "Registro eliminado!" << endl;
        eliminar(aux.dui);
    }
}

// funcion para modificar registros
void modificarRegistro() {
    int long dui = getLong("Digite el numero de DUI: ");
    Persona aux = getPersona(dui);
    cin.ignore();
    if(aux.dui == 0) {
        cout << "No existe el registro!" << endl;
    } else {
        mostrar(aux);
        strcpy(aux.nombre, getString("Ingresar Nombre: ").c_str());
        strcpy(aux.apellido, getString("Ingresar Apellido: ").c_str());
        aux.telefono = getLong("Ingresar Telefono: ");
        
        fstream e("directorio.txt", ios::out | ios::in | ios::binary);

        if(e.is_open()) {
            e.seekp((aux.dui-1) * sizeof(Persona)); //cambia a seekp
            e.write((char*) &aux, sizeof(Persona));
            e.close();
        }
    }
}