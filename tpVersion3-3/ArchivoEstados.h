#pragma once
#include "Estados.h"

class ArchivoEstados{
    private:

    public:
        bool altaEstados(Estados estado);
        Estados leerRegistro(int pos);
        void mostrarDescripcion(int id);
};
