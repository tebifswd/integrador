#pragma once
#include "Empresa.h"
#include "ArchivoEmpresas.h"

class EmpresasManager{
    private:
        void cargarEmpresa();
        void listarEmpresas();
        void bajaLogica();
        void modificarEmpresa();
        ArchivoEmpresas archivoEmpresas;
    public:
        Empresa crearEmpresa();
        void mostrar(Empresa empresa);
        void menuEmpresas();
};
