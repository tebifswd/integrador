#pragma once
#include <cstring>
#include "Obras.h"

class ArchivoObras{
    private:
        char _nombre[30];
    public:
        bool altaRegistro(Obras obra);
        bool bajaRegistro();
        int contarRegistros();
        void modificarRegistro(Obras obj, int pos);
        int buscarRegistro(std::string cod);
        void limpiarArchivo();
        bool modificarEstado();
        Obras leerRegistro(int pos);
        ArchivoObras(const char *nombre){strcpy(_nombre,nombre);}
        ArchivoObras(){strcpy(_nombre,"obras.dat");}
};

