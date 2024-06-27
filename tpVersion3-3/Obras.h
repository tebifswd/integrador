#pragma once
#include <iostream>
#include <string>
#include <ctime>


class Fecha{
  private:
    int dia;
    int mes;
    int anio;
  public:
    Fecha(int d=0,int m=0,int a=0);
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;}
    void MostrarFecha();
};

class Obras{
    private:
        char _codObra[6];
        char _direccion[31];
        int _provincia; ///(1 a 24)
        Fecha _fechaInicio;
        float _superficie; ///(en metros cuadrados)
        int _estadoEjecucion; ///(1: en proyecto; 2: proyecto aprobado en espera;3: en ejecución; 4: terminada; 5: suspendida:)
        int _codEmpresa;
        bool _activo; ///(si/no)
    public:

        ///SETS
        void setCodObra(std::string cod);
        void setDireccion(std::string dire);
        void setProvincia(int pro);
        void setFecha(Fecha fecha);
        void setSuperficie(float sup);
        void setEstadoEjecucion(int est);
        void setCodEmpresa(int codEmp);
        void setActivo(bool act);
        ///GETS
        std::string getCodObra();
        std::string getDireccion();
        int getProvincia();
        Fecha getFecha();
        float getSuperficie();
        int getEstadoEjecucion();
        int getCodEmpresa();
        bool getActivo();
        ///CONSTRUCTOR
        Obras();
        Obras(std::string co, std::string dire, int pro, Fecha fecha, float sup, int est, int ce, bool act);

};

