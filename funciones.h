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