#include <string>
#include <cstring>
#include "ArchivoObras.h"

using namespace std;

bool ArchivoObras::altaRegistro(Obras obra){
    FILE *pFile;
    int grabo;
    pFile = fopen(_nombre, "ab");
    if(pFile == nullptr){
        return false;
    }
    grabo = fwrite(&obra, sizeof(Obras), 1, pFile);
    fclose(pFile);
    return grabo;
}

int ArchivoObras::contarRegistros(){
    FILE *pFile;
    pFile = fopen(_nombre, "rb");
    if(pFile == nullptr){
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);
    int cantRegistros = tam / sizeof(Obras);
    return cantRegistros;
}

Obras ArchivoObras::leerRegistro(int indice){
    Obras obra;
    FILE *pFile;
    pFile = fopen(_nombre, "rb");
    if(pFile == nullptr){
        return obra;
    }
    fseek(pFile, indice * sizeof(Obras), SEEK_SET);
    fread(&obra, sizeof(Obras), 1, pFile);
    fclose(pFile);
    return obra;
}

int ArchivoObras::buscarRegistro(string cod){
    int cant = contarRegistros();
    Obras obra;
    for(int i=0; i<cant; i++){
        obra = leerRegistro(i);

        if(strcmp(cod.c_str(), obra.getCodObra().c_str()) == 0){
            return i;
        }
    }
    return -1;
}

void ArchivoObras::modificarRegistro(Obras obj, int pos){
    FILE *pFile;
    pFile = fopen(_nombre, "rb+");
    if(pFile == NULL){return;}
    fseek(pFile, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

}

bool ArchivoObras::bajaRegistro(){
    ArchivoObras archiObra;
    Obras obra;
    string opc;
    cin.ignore();
    cout<<"INGRESE CODIGO DE OBRA A DAR DE BAJA: "<<endl;
    getline(cin, opc);
    int pos = archiObra.buscarRegistro(opc);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return false;
    }
    obra = archiObra.leerRegistro(pos);
    obra.setActivo(false);
    archiObra.modificarRegistro(obra, pos);
    return true;
}

void ArchivoObras::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoObras::modificarEstado(){
    ArchivoObras archiObra;
    Obras obra;
    string opc;
    int nEntero;
    cin.ignore();
    cout<<"INGRESE CODIGO DE OBRA: "<<endl;
    getline(cin, opc);
    int pos = archiObra.buscarRegistro(opc);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return false;
    }
    cout<<"INGRESE NUEVO ESTADO DE LA OBRA: "<<endl;
    cin>>nEntero;
    obra = archiObra.leerRegistro(pos);
    obra.setEstadoEjecucion(nEntero);
    archiObra.modificarRegistro(obra, pos);
    return true;
}
