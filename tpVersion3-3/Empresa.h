#pragma once
#include <iostream>
#include <string>

class Empresa{
    private:
        int _codEmpresa;
        char _nombre[31];
        int _telefono;
        char _direccion[31];
        int _provincia; ///(1 a 24)
        bool _activo; ///(si/no)
    public:
        ///SETS
        void setCodEmpresa(int cod);
        void setNombre(std::string nombre);
        void setTelefono(int tel);
        void setDireccion(std::string direccion);
        void setProvincia(int pro);
        void setActivo(bool act);
        ///GETS
        int getCodEmpresa();
        std::string getNombre();
        int getTelefono();
        std::string getDireccion();
        int getProvincia();
        bool getActivo();
        ///CONSTRUCTOR
        Empresa();
        Empresa(int cod, std::string nombre, int tel, std::string direccion, int prov, bool act);
};
