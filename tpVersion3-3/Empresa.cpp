#include <iostream>
#include <string>
#include <cstring>

#include "Empresa.h"

using namespace std;

        ///CLASE OBRA:
///SETS
void Empresa::setCodEmpresa(int cod){
    if(cod > 0){
        _codEmpresa = cod;
    }
}
void Empresa::setNombre(string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}
void Empresa::setTelefono(int tel){
    if(tel > 0){
        _telefono = tel;
    }
}
void Empresa::setDireccion(string dire){
    strncpy(_direccion, dire.c_str(), sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
}
void Empresa::setProvincia(int pro){
    if(pro > 0 && pro < 25){
        _provincia = pro;
    }
}
void Empresa::setActivo(bool act){
    _activo = act;
}
///GETS
int Empresa::getCodEmpresa(){
    return _codEmpresa;
}
string Empresa::getNombre(){
    return _nombre;
}
int Empresa::getTelefono(){
    return _telefono;
}
string Empresa::getDireccion(){
    return _direccion;
}
int Empresa::getProvincia(){
    return _provincia;
}
bool Empresa::getActivo(){
    return _activo;
}
///CONSTRUCTOR
Empresa::Empresa(){
    _codEmpresa = 0;
    strcpy(_nombre, "");
    _telefono = 0;
    strcpy(_direccion, "");
    _provincia = 0;
    _activo = false;

}
Empresa::Empresa(int cod, string nombre, int tel, string dire, int prov, bool act){
    setCodEmpresa(cod);
    setNombre(nombre);
    setTelefono(tel);
    setDireccion(dire);
    setProvincia(prov);
    setActivo(act);
}
