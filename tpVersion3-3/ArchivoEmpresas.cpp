#include <string>
#include <cstring>
#include "ArchivoEmpresas.h"

using namespace std;

bool ArchivoEmpresas::altaRegistro(Empresa empresa){
    FILE *pFile;
    int grabo;
    pFile = fopen(_nombre, "ab");
    if(pFile == nullptr){
        return false;
    }
    grabo = fwrite(&empresa, sizeof(Empresa), 1, pFile);
    fclose(pFile);
    return grabo;
}

int ArchivoEmpresas::contarRegistros(){
    FILE *pFile;
    pFile = fopen(_nombre, "rb");
    if(pFile == nullptr){
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);
    int cantRegistros = tam / sizeof(Empresa);
    return cantRegistros;
}

Empresa ArchivoEmpresas::leerRegistro(int indice){
    Empresa empresa;
    FILE *pFile;
    pFile = fopen(_nombre, "rb");
    if(pFile == nullptr){
        return empresa;
    }
    fseek(pFile, indice * sizeof(Empresa), SEEK_SET);
    fread(&empresa, sizeof(Empresa), 1, pFile);
    fclose(pFile);
    return empresa;
}

int ArchivoEmpresas::buscarRegistro(int cod){
    int cant=contarRegistros();
    Empresa obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(cod==obj.getCodEmpresa()){
            return i;
        }
    }
    return -1;
}

void ArchivoEmpresas::modificarRegistro(Empresa obj, int pos){
    FILE *pFile;
    pFile = fopen(_nombre, "rb+");
    if(pFile == NULL){return;}
    fseek(pFile, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);
}

bool ArchivoEmpresas::bajaRegistro(){
    ArchivoEmpresas archiEmpresas;
    Empresa empresa;
    int opc;
    cout<<"INGRESE CODIGO DE EMPRESA A DAR DE BAJA: "<<endl;
    cin>>opc;
    int pos = archiEmpresas.buscarRegistro(opc);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return false;
    }
    empresa = archiEmpresas.leerRegistro(pos);
    empresa.setActivo(false);
    archiEmpresas.modificarRegistro(empresa, pos);
    return true;
}

bool ArchivoEmpresas::modificarTelefono(){
    ArchivoEmpresas archiEmpresa;
    Empresa empresa;
    int cod, numero;
    cout<<"INGRESE CODIGO DE EMPRESA: "<<endl;
    cin>>cod;
    int pos = archiEmpresa.buscarRegistro(cod);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return false;
    }
    cout<<"INGRESE NUEVO TELEFONO DE LA EMPRESA: "<<endl;
    cin>>numero;
    empresa = archiEmpresa.leerRegistro(pos);
    empresa.setTelefono(numero);
    archiEmpresa.modificarRegistro(empresa, pos);
    return true;
}

void ArchivoEmpresas::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}
