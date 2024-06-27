#pragma once
#include <cstring>
#include "Empresa.h"


class ArchivoEmpresas{
    private:
        char _nombre[30];
    public:
        bool altaRegistro(Empresa empresa);
        bool bajaRegistro();
        int contarRegistros();
        void modificarRegistro(Empresa obj, int pos);
        int buscarRegistro(int cod);
        void limpiarArchivo();
        bool modificarTelefono();
        Empresa leerRegistro(int pos);
        ArchivoEmpresas(const char *nombre){strcpy(_nombre,nombre);}
        ArchivoEmpresas(){strcpy(_nombre,"empresas.dat");}
};
