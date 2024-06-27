#include <iostream>
#include <string>
#include "ConfiguracionManager.h"


using namespace std;

void ConfiguracionManager::copiaSeguridadEmpresas(){
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

void ConfiguracionManager::copiaSeguridadObras(){
    ArchivoObras arcOb("obras.dat");
    ArchivoObras bkpOb("obras.bkp");
    Obras obj;
    bkpOb.limpiarArchivo();
    int cant = arcOb.contarRegistros();
    for (int i=0; i<cant; i++){
        obj = arcOb.leerRegistro(i);
        bkpOb.altaRegistro(obj);
    }
}

void ConfiguracionManager::restaurarEmpresas(){
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

void ConfiguracionManager::restaurarObras(){
    ArchivoObras arcOb("obras.dat");
    ArchivoObras bkpOb("obras.bkp");
    Obras obj;
    arcOb.limpiarArchivo();
    int cant = bkpOb.contarRegistros();
    for (int i=0; i<cant; i++){
        obj = bkpOb.leerRegistro(i);
        arcOb.altaRegistro(obj);
    }

}

void ConfiguracionManager::menuConfiguracion(){
   while(true){
        int opc;
        system ("cls");
        cout<<"------------- MENU CONFIGURACION -------------"<<endl;
        cout<<endl;
        cout<<"1. COPIA DE SEGURIDAD DEL ARCHIVO DE EMPRESAS"<<endl;
        cout<<"2. COPIA DE SEGURIDAD DEL ARCHIVO DE OBRAS"<<endl;
        cout<<"3. RESTAURAR EL ARCHIVO DE EMPRESAS"<<endl;
        cout<<"4. RESTAURAR EL ARCHIVO DE OBRAS"<<endl;
        cout<<endl;
        cout<<"0. SALIR DEL MENU"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"SELECCIONE UNA OPCION"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            copiaSeguridadEmpresas();
            break;
        case 2:
            copiaSeguridadObras();
            break;
        case 3:
            restaurarEmpresas();
            break;
        case 4:
            restaurarObras();
            break;
        case 0:
            return;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;
    }
}
}
