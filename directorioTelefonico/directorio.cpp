#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "miDirectorio.h"
using namespace std;

int menu() {
    int seleccion = 0;
    cout << "<---------------------------------------------------------------------->" << endl;
    cout << "<|      Bienvenido administrador al menu del directorio el mundo      |>" << endl;
    cout << "<|                                                                    |>" << endl;
    cout << "<|       Opcion 1: Mostrar todos los registros del directorio         |>" << endl;
    cout << "<|                   Opcion 2: Agregar registro                       |>" << endl;
    cout << "<|                 Opcion 3: Actualizar registro                      |>" << endl;
    cout << "<|                   Opcion 4: Buscar registro                        |>" << endl;
    cout << "<|                   Opcion 5: Elimanr registro                       |> " << endl;
    cout << "<|                        Opcion 6: Salir                             |>" << endl;
    cout << "<---------------------------------------------------------------------->" << endl;
    cin >> seleccion;
    return seleccion;
}
char rep;

int main() {
    do {
        //code
        int x = menu();
        if(x >=1 && x <= 6) {
            switch(x) {
            case 1:
                listarRegistro();
                break;
            case 2:
                agregarRegistro();
                break;
            case 3:
                modificarRegistro();
                break;
            case 4:
                buscarRegistro();
                break;
            case 5:
                eliminarRegistro();
                break;
            case 6:
                //salir();
                break;
            }

        }
        cout << "<--- Desea continuar en el directorio telefonico? coloque S, de lo contrario coloque n --->" << endl;
        cin >> rep;
    }while(rep == 'S' || rep == 's');

    return 0;
}
