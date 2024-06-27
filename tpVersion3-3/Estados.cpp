#include <iostream>
#include <cstring>
#include "Estados.h"
using namespace std;

void Estados::setID(int id){
    _idEstado=id;
}
string Estados::setDescripcion(string descripcion){
    strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
}
void Estados::setActivo(bool activo){
    _activo=activo;
}
int Estados::getID(){
    return _idEstado;
}
string Estados::getDescripcion(){
    return _descripcion;
}
bool Estados::getActivo(){
    return _activo;
}
Estados Estados::cargar(){
    string des;
    int id;
    cout<<"ID DEL ESTADO: "<<endl;
    cin>>id;
    setID(id);
    cout<<"DESCRIPCION DEL ESTADO: "<<endl;
    cin.ignore();
    getline(cin, des);
    return Estados(id,des,true);
}

void Estados::mostrar(Estados estado){
    if(estado.getActivo() == true){
        cout<<"ID DEL ESTADO: "<<estado.getID()<<endl;
        cout<<"DESCRIPCION DEL ESTADO: "<<estado.getDescripcion()<<endl;
    }
}

Estados::Estados(int id,string descripcion,bool activo){
    setID(id);
    setDescripcion(descripcion);
    setActivo(activo);
}

Estados::Estados(){
    _idEstado = 0;
    strcpy(_descripcion,"");
    _activo = false;
}
