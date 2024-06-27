#include <iostream>
#include <string>
#include <cstring>

#include "Configuracion.h"
#include "ArchivoEmpresas.h"
#include "ArchivoObras.h"

using namespace std;

void Configuracion::copiaSeguridadEmpresas(){
    ArchivoEmpresas arcEmp("empresas.dat");
    ArchivoEmpresas bkpEmp("empresas.bkp");
    Empresa obj;
    bkpEmp.limpiarArchivo();
    int cant = arcEmp.contarRegistros();
    for (int i=0; i<cant; i++){
        obj = arcEmp.leerRegistro(i);
        bkpEmp.altaRegistro(obj);
    }
}

void Configuracion::copiaSeguridadObras(){
    ArchivoObras arcOb("obras.dat");
    ArchivoObras bkpOb("obras.bkp");
    Obras obj;
    bkpOb.limpiarObra();
    int cant = arcOb.contarRegistros();
    for (int i=0; i<cant; i++){
        obj = arcOb.leerRegistro(i);
        bkpOb.altaRegistro(obj);
    }
}

void Configuracion::restaurarEmpresas(){
    ArchivoEmpresas arcEmp("empresas.dat");
    ArchivoEmpresas bkpEmp("empresas.bkp");
    Empresa obj;
    arcEmp.limpiarArchivo();
    int cant = bkpEmp.contarRegistros();
    for (int i=0; i<cant; i++){
        obj = bkpEmp.leerRegistro(i);
        arcEmp.altaRegistro(obj);
    }
}

void Configuracion::restaurarObras(){
    ArchivoObras arcOb("obras.dat");
    ArchivoObras bkpOb("obras.bkp");
    Municipio obj;
    arcOb.limpiarMunicipio();
    int cant = bkpOb.contarRegistros();
    for (int i=0; i<cant; i++){
        obj = bkpOb.leerRegistro(i);
        arcOb.altaRegistro(obj);
    }

}

/*void establecerDatosInicio(){
    ArchivoEmpresas arcEmp("empresas.dat");
    altaEmpresa();
    ArchivoObras arcOb("obras.dat");
    altaObra();
} */
