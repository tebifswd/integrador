#pragma once
#include <string>

class Estados{
    private:
        int _idEstado;
        char _descripcion[30];
        bool _activo;
    public:
        void setID(int id);
        std::string setDescripcion(std::string descripcion);
        void setActivo(bool activo);
        int getID();
        std::string getDescripcion();
        bool getActivo();
        Estados cargar();
        void mostrar(Estados estado);

        Estados(int id,std::string descripcion,bool activo);
        Estados();
};
