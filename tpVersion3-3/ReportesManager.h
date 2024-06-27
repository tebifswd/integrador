#pragma once
#include "ArchivoEmpresas.h"
#include "ArchivoObras.h"

class ReportesManager{
    private:
        void informe1();
        void informe2();
        void informe3();
        ArchivoEmpresas arcEmp;
        ArchivoObras arcOb;
    public:
        void menuReportes();
        int filtrarRegion();
        int contarObrasTerminadas(int anio1, int anio2);
        int contarObrasSuspendidas(int anio1, int anio2);
};
