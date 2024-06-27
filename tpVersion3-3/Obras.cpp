#include <iostream>
#include <string>
#include <cstring>

#include "Obras.h"

using namespace std;

        /// FUNCIONES DE LA CLASE FECHA

Fecha::Fecha(int d,int m,int a){//El constructor asigna los valores recibidos, si le son pasados como parámetros
  if(d!=0){
  dia=d;mes=m;anio=a;//¿Qué modificación habría que hacerle al constructor para
  }                   // garantizar que no se asignen valores absurdos? Ej.:65/65/-12
  else  //si no recibe valores asigna por defecto la fecha actual
  {
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio=tmPtr->tm_year+1900;
    mes=tmPtr->tm_mon+1;
    dia=tmPtr->tm_mday;
  }
}

void Fecha::MostrarFecha(){
  cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
            ///CLASE OBRA:
///SETS
void Obras::setCodObra(string cod){
    strncpy(_codObra, cod.c_str(), sizeof(_codObra) - 1);
    _codObra[sizeof(_codObra) - 1] = '\0';
}
void Obras::setDireccion(string dire){
    strncpy(_direccion, dire.c_str(), sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
}
void Obras::setProvincia(int pro){
    if(pro > 0 && pro < 25){
        _provincia = pro;
    }
}
void Obras::setFecha(Fecha fecha){
    _fechaInicio = Fecha(fecha.getDia(), fecha.getMes(), fecha.getAnio());
}
void Obras::setSuperficie(float sup){
    if(sup > 0){
        _superficie = sup;
    }
}
void Obras::setEstadoEjecucion(int est){
    if(est > 0 && est < 6){
        _estadoEjecucion = est;
    }
}
void Obras::setCodEmpresa(int codEmp){
    if(codEmp > 0){
        _codEmpresa = codEmp;
    }
}
void Obras::setActivo(bool act){
    _activo = act;
}
///GETS
string Obras::getCodObra(){
    return _codObra;
}
string Obras::getDireccion(){
    return _direccion;
}
int Obras::getProvincia(){
    return _provincia;
}
Fecha Obras::getFecha(){
    return _fechaInicio;
}
float Obras::getSuperficie(){
    return _superficie;
}
int Obras::getEstadoEjecucion(){
    return _estadoEjecucion;
}
int Obras::getCodEmpresa(){
    return _codEmpresa;
}
bool Obras::getActivo(){
    return _activo;
}
///CONSTRUCTOR
Obras::Obras(){
    strcpy(_codObra, "");
    strcpy(_direccion, "");
    _provincia = 0;
    _fechaInicio = Fecha();
    _superficie = 0;
    _estadoEjecucion = 0;
    _codEmpresa = 0;
    _activo = false;

}
Obras::Obras(string co, string dire, int pro, Fecha fecha, float sup, int est, int ce, bool act){
    setCodObra(co);
    setDireccion(dire);
    setProvincia(pro);
    setFecha(fecha);
    setSuperficie(sup);
    setEstadoEjecucion(est);
    setCodEmpresa(ce);
    setActivo(act);
}

