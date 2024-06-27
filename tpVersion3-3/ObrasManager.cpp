#include <iostream>
#include <string>
#include <limits>
#include "ObrasManager.h"
#include "ArchivoEstados.h"

using namespace std;


Obras ObrasManager::crearObra(){
    string co, dire;
    int pr, ee, ce;
    float sup;
    int dia, mes, anio;
    Fecha fecha;
    cout<<"CODIGO DE OBRA: "<<endl;
    cin.ignore();
    getline(cin, co);
    cout<<"DIRECCION: "<<endl;
    cin.ignore();
    getline(cin, dire);
    cout<<"PROVINCIA: "<<endl;
    cin>>pr;
    cout<<"FECHA DE INICIO: "<<endl;
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    cout<<endl;
    cout<<"SUPERFICIE DE LA OBRA: "<<endl;
    cin>>sup;
    cout<<"ESTADO DE LA OBRA (1: en proyecto. 2: proyecto aprobado en espera. 3: en ejecucion. 4: terminada. 5: suspendida): "<<endl;
    cin>>ee;
    cout<<"CODIGO DE LA EMPRESA: "<<endl;
    cin>>ce;

    return Obras(co, dire, pr, (Fecha(dia, mes, anio)), sup, ee, ce, true);

}
void ObrasManager::mostrar(Obras obra){
    if(obra.getActivo() == true){
        Fecha aux;
        ArchivoEstados arcEst;
        //string descripcion;
        cout<<"CODIGO DE OBRA: "<<obra.getCodObra()<<endl;
        cout<<"DIRECCION: "<<obra.getDireccion()<<endl;
        cout<<"PROVINCIA: "<<obra.getProvincia()<<endl;
        cout<<"FECHA DE INICIO: "<<endl;
        aux = obra.getFecha();
        aux.MostrarFecha();
        cout<<"SUPERFICIE DE LA OBRA: "<<obra.getSuperficie()<<" MTS CUADRADOS"<<endl;
        //strcpy(descripcion.c_str(),arcEst.mostrarDescripcion(obra.getEstadoEjecucion()).c_str());
        cout<<"ESTADO DE LA OBRA : ";
        arcEst.mostrarDescripcion(obra.getEstadoEjecucion());
    }

}

void ObrasManager::cargarObra(){
    Obras obra;
    obra = crearObra();
    if(archivoObra.altaRegistro(obra)){
        cout<<"OBRA GUARDADA CON EXITO!"<<endl;
    }
    else{
        cout<<"NO SE PUDO GUARDAR LA OBRA"<<endl;
    }
}

void ObrasManager::listarObras(){
    Obras obra;
    int cant = archivoObra.contarRegistros();
    for(int i=0; i<cant; i++){
        cout<<endl;
        obra = archivoObra.leerRegistro(i);
        mostrar(obra);
        cout<<endl;
        cout<<"------------------------------"<<endl;
    }
}

void ObrasManager::bajaLogica(){
    if(archivoObra.bajaRegistro()){
        cout<<"BAJA REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
    }
}

void ObrasManager::modificarObra(){
    if(archivoObra.modificarEstado()){
        cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
    }

}

void ObrasManager::menuObras(){
    int opc;
    while(true){
        system("cls");
        cout<<"------------- MENU OBRAS -------------"<<endl;
        cout<<endl;
        cout<<"1. ALTA OBRA"<<endl;
        cout<<"2. LISTAR OBRAS"<<endl;
        cout<<"3. BAJA OBRA"<<endl;
        cout<<"4. MODIFICAR ESTADO DE LA OBRA"<<endl;
        cout<<endl;
        cout<<"0. SALIR DEL MENU"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"SELECCIONE UNA OPCION"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    cargarObra();
                break;
            case 2:
                    listarObras();
                break;
            case 3:
                    bajaLogica();
                break;
            case 4:
                    modificarObra();
                break;
            case 0:
                    return;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;

        }
    }

}
