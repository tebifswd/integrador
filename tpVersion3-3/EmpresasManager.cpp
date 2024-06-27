#include <iostream>
#include <string>
#include "EmpresasManager.h"

using namespace std;


Empresa EmpresasManager::crearEmpresa(){
    int cod;
    string nombre;
    int tel;
    string dire;
    int prov;
    cout<<"CODIGO DE EMPRESA: "<<endl;
    cin>>cod;
    cout<<"NOMBRE DE EMPRESA: "<<endl;
    cin.ignore();
    getline(cin, nombre);
    cout<<"TELEFONO: "<<endl;
    cin>>tel;
    cout<<"DIRECCION: "<<endl;
    cin.ignore();
    getline(cin, dire);
    cout<<"PROVINCIA: "<<endl;
    cin>>prov;
    return Empresa(cod, nombre, tel, dire, prov, true);

}
void EmpresasManager::mostrar(Empresa empresa){
    if(empresa.getActivo() == true){
        cout<<"CODIGO DE EMPRESA: "<<empresa.getCodEmpresa()<<endl;
        cout<<"NOMBRE DE LA EMPRESA: "<<empresa.getNombre()<<endl;
        cout<<"TELEFONO: "<<empresa.getTelefono()<<endl;
        cout<<"DIRECCION: "<<empresa.getDireccion()<<endl;
        cout<<"PROVINCIA: "<<empresa.getProvincia()<<endl;
    }
}

void EmpresasManager::cargarEmpresa(){
    Empresa empresa;
    empresa = crearEmpresa();
    if(archivoEmpresas.altaRegistro(empresa)){
        cout<<"EMPRESA GUARDADA CON EXITO!"<<endl;
    }
    else{
        cout<<"NO SE PUDO GUARDAR LA EMPRESA"<<endl;
    }
}

void EmpresasManager::listarEmpresas(){
    Empresa empresa;
    int cant = archivoEmpresas.contarRegistros();
    for(int i=0; i<cant; i++){
        cout<<endl;
        empresa = archivoEmpresas.leerRegistro(i);
        mostrar(empresa);
        cout<<endl;
        cout<<"------------------------------"<<endl;
    }
}

void EmpresasManager::bajaLogica(){
    if(archivoEmpresas.bajaRegistro()){
        cout<<"BAJA REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
    }
}

void EmpresasManager::modificarEmpresa(){
    if(archivoEmpresas.modificarTelefono()){
        cout<<"MODIFICACION REALIZADA CON EXITO"<<endl;
    }
    else{
        cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
    }
}

void EmpresasManager::menuEmpresas(){
    int opc;
    while(true){
        system("cls");
        cout<<"------------- MENU EMPRESAS -------------"<<endl;
        cout<<endl;
        cout<<"1. ALTA EMPRESA"<<endl;
        cout<<"2. LISTAR EMPRESAS"<<endl;
        cout<<"3. BAJA EMPRESA"<<endl;
        cout<<"4. MODIFICAR TELEFONO DE UNA EMPRESA"<<endl;
        cout<<endl;
        cout<<"0. SALIR DEL MENU"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"SELECCIONE UNA OPCION"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    cargarEmpresa();
                break;
            case 2:
                    listarEmpresas();
                break;
            case 3:
                    bajaLogica();
                break;
            case 4:
                    modificarEmpresa();
                break;
            case 0:
                    return;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;

        }
    }

}
