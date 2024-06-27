#include <iostream>
#include <string>
#include "ArchivoEstados.h"
using namespace std;

bool ArchivoEstados::altaEstados(Estados estado){
    FILE *pFile;
    int grabo;
    pFile = fopen("estados.dat", "ab");
    if(pFile == nullptr){
        return false;
    }
    grabo = fwrite(&estado, sizeof(Estados), 1, pFile);
    fclose(pFile);
    return grabo;
}

Estados ArchivoEstados::leerRegistro(int indice){
    Estados estado;
    FILE *pFile;
    pFile = fopen("estados.dat", "rb");
    if(pFile == nullptr){
        return estado;
    }
    fseek(pFile, indice * sizeof(Estados), SEEK_SET);
    fread(&estado, sizeof(Estados), 1, pFile);
    fclose(pFile);
    return estado;
}

void ArchivoEstados::mostrarDescripcion(int id){
    Estados estado;
    ArchivoEstados arcEst;
    for(int i=0;i<5;i++){
        estado=arcEst.leerRegistro(i);
        if(estado.getID()==id){
            cout<<estado.getDescripcion();
        }
    }
}
