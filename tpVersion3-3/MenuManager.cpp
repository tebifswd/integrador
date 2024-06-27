#include <iostream>

#include "MenuManager.h"
#include "ObrasManager.h"
#include "EmpresasManager.h"
#include "ConfiguracionManager.h"
#include "ReportesManager.h"

using namespace std;

void MenuManager::menuPrincipal(){
    int opc;
    ObrasManager obrM;
    EmpresasManager empM;
    ConfiguracionManager conM;
    ReportesManager repM;
    while(true){
        system("cls");
        cout<<"------------- MENU PRINCIPAL -------------"<<endl;
        cout<<endl;
        cout<<"1. MENU OBRAS"<<endl;
        cout<<"2. MENU EMPRESAS"<<endl;
        cout<<"3. MENU CONFIGURACION"<<endl;
        cout<<"4. MENU REPORTES"<<endl;
        cout<<endl;
        cout<<"0. SALIR DEL MENU"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"SELECCIONE UNA OPCION"<<endl;
        cin>>opc;

        switch(opc){
            case 1:
                    system("cls");
                    obrM.menuObras();
                break;
            case 2:
                    system("cls");
                    empM.menuEmpresas();
                break;
            case 3:
                    system("cls");
                    conM.menuConfiguracion();
                break;
            case 4: system("cls");
                    repM.menuReportes();
            case 0:
                    return;
                break;

        }
    }

}
