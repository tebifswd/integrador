#include <iostream>
#include "MenuManager.h"
#include "ArchivoEstados.h"
using namespace std;



int main(){

//ArchivoEstados arcEst;
//Estados estado,obj;
//obj=estado.cargar();
//arcEst.altaEstados(obj);
/*for(int y=0;y<5;y++){
    estado=arcEst.leerRegistro(y);
    estado.mostrar(estado);
}*/
MenuManager menuManager;

menuManager.menuPrincipal();

return 0;
}
