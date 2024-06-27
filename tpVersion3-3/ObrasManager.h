#pragma once
///#include "Obras.h"
#include "ArchivoObras.h"

class ObrasManager{
    private:
        void cargarObra();
        void listarObras();
        void bajaLogica();
        void modificarObra();
        ArchivoObras archivoObra;
    public:
        Obras crearObra();
        void mostrar(Obras obra);
        void menuObras();

};
