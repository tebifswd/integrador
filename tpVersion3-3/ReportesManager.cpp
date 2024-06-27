#include <iostream>
#include "ReportesManager.h"
using namespace std;

int ReportesManager::contarObrasTerminadas(int anio1, int anio2){
    Obras obra;
    int contador=0;
    int cant = arcOb.contarRegistros();
    for(int i=0;i<cant;i++){
        obra=arcOb.leerRegistro(i);
        if(obra.getFecha().getAnio()>=anio1 && obra.getFecha().getAnio()<=anio2){
                if(obra.getEstadoEjecucion()==4 && obra.getActivo()){
                    contador++;
                }
        }
    }
    return contador;
}

int ReportesManager::contarObrasSuspendidas(int anio1, int anio2){
    Obras obra;
    int contador=0;
    int cant = arcOb.contarRegistros();
    for(int i=0;i<cant;i++){
        obra=arcOb.leerRegistro(i);
        if(obra.getFecha().getAnio()>=anio1 && obra.getFecha().getAnio()<=anio2){
                if(obra.getEstadoEjecucion()==5 && obra.getActivo()){
                    contador++;
                }
        }
    }
    return contador;
}

int ReportesManager::filtrarRegion(){
    Obras obra;
    int region[5]={0};
    int mayor=0, regionmayor=0;
    int cant = arcOb.contarRegistros();
    for(int i=0;i<cant;i++){
        obra=arcOb.leerRegistro(i);
        if(obra.getEstadoEjecucion()==3){
            if(obra.getProvincia()>=1 && obra.getProvincia()<=5){
                region[0]++;
            }
            if(obra.getProvincia()>=6 && obra.getProvincia()<=9){
                region[1]++;
            }
            if(obra.getProvincia()>=10 && obra.getProvincia()<=15){
                region[2]++;
            }
            if(obra.getProvincia()>=16 && obra.getProvincia()<=21){
                region[3]++;
            }
            if(obra.getProvincia()>=22 && obra.getProvincia()<=24){
                region[4]++;
            }
        }
    }
    for(int j=0;j<5;j++){
        if(region[j]>mayor){
            mayor=region[j];
            regionmayor=j+1;
        }
    }
    return regionmayor;
}

int buscarSuperficie(int e){
    Obras obra;
    ArchivoObras arcOb;
    int cant = arcOb.contarRegistros();
    for(int i=0;i<cant;i++){
        obra=arcOb.leerRegistro(i);
        if(obra.getCodEmpresa()==e){
            if(obra.getEstadoEjecucion()==4 && obra.getActivo()){
                return obra.getSuperficie();
            }
        }
    }
    return 0;
}

void ReportesManager::informe1(){
    int anio1, anio2;
    int contTerminadas=0, contSuspendidas=0;
    cout<<"INGRESE EL PRIMER AÑO: "<<endl;
    cin>>anio1;
    cout<<"INGRESE EL SEGUNDO AÑO: "<<endl;
    cin>>anio2;

    contTerminadas=contarObrasTerminadas(anio1,anio2);
    contSuspendidas=contarObrasSuspendidas(anio1,anio2);

    cout<<"LA CANTIDAD DE OBRAS TERMINADAS ENTRE "<<anio1<<" Y "<<anio2<<" SON: "<<contTerminadas<<endl;
    cout<<"LA CANTIDAD DE OBRAS SUSPENDIDAS ENTRE "<<anio1<<" Y "<<anio2<<" SON: "<<contSuspendidas<<endl;
}
void ReportesManager::informe2(){
    int regmay;
    cout<<"--------------------REGIONES--------------------"<<endl;
    cout<<"1. NORTE: Jujuy, Salta, Tucuman, Santiago del Estero y Catamarca"<<endl;
    cout<<"2. CUYO: La Rioja, San Luis, San Juan y Mendoza"<<endl;
    cout<<"3. LITORAL: Santa Fe, Entre Rios, Corrientes, Misiones, Chaco y Formosa"<<endl;
    cout<<"4. PATAGONIA: La Pampa, Neuquen, Rio Negro, Chubut, Santa Cruz y Tierra del Fuego"<<endl;
    cout<<"5. CENTRO: Cordoba, Buenos Aires y CABA"<<endl;
    cout<<endl;
    regmay=filtrarRegion();
    if(regmay!=0){
    cout<<"LA REGION CON MAS OBRAS EN EJECUCION ES: "<<regmay<<endl;
    }
    else{
    cout<<"NINGUNA REGION TIENE OBRAS EN EJECUCION"<<endl;
    }
}
void ReportesManager::informe3(){
    Empresa empresa, obj;
    int mayorsuperficie=0;
    int superficie=0;
    int cant = arcEmp.contarRegistros();
    for(int i=0;i<cant;i++){
        empresa=arcEmp.leerRegistro(i);
        superficie=buscarSuperficie(empresa.getCodEmpresa());
        if(superficie>mayorsuperficie){
            mayorsuperficie=superficie;
            obj=empresa;
        }
    }
    cout<<"LA EMPRESA CON MAS SUPERFICIE DE OBRAS TERMINADAS ES: "<<obj.getNombre()<<endl;
}

void ReportesManager::menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"------------- MENU REPORTES -------------"<<endl;
        cout<<endl;
        cout<<"1. INFORME 1: obras terminadas y suspendidas entre dos años seleccionados"<<endl;
        cout<<"2. INFORME 2: mostrar la region con mas obras en ejecucion"<<endl;
        cout<<"3. INFORME 3: la empresa con mas superficie de obras terminadas"<<endl;
        cout<<endl;
        cout<<"0. SALIR DEL MENU"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"SELECCIONE UNA OPCION"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    informe1();
                break;
            case 2:
                    informe2();
                break;
            case 3:
                    informe3();
                break;
            case 0:  return;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        system("pause");
    }
}
