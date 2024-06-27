#pragma once
#include "ArchivoEmpresas.h"
#include "ArchivoObras.h"

class ConfiguracionManager{
    private:
        void copiaSeguridadEmpresas();
        void copiaSeguridadObras();
        void restaurarEmpresas();
        void restaurarObras();
        ArchivoEmpresas arcEmp;
        ArchivoObras arcOb;
    public:
        void menuConfiguracion();
};

