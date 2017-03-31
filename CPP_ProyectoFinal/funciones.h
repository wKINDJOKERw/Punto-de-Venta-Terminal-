//
//  funciones.h
//  CPP_ProyectoFinal
//
//  Created by Antony Morales on 3/31/17.
//  Copyright © 2017 Antony999k. All rights reserved.
//

#ifndef funciones_h
#define funciones_h
using namespace std;

//Variables globales
float CobroTotal;
int productosTotales = 0;
Producto *producto = new Producto[20];


void ventas(){
    bool flagV1 = false;
    bool flagV2 = false;
    int opcionV;
    string CodigoBarras;
    Producto *productoV = new Producto[20];
    
    cout << "************************************************************\n";
    cout << "************** Sección de ventas **************\n";
    cout << "************************************************************\n\n";

    while (!flagV1) {
        cout << "* Selecciona una opcion *" << endl;
        cout << "\t1)Añador productos con Escaneadora de codigos de barra" << endl;
        cout << "\t2)Buscar productos" << endl;
        cout << "\t3)Cobrar" << endl;
        cout << "\t4)Obtener ticket" << endl;
        cout << "\t5)Cerrar seccion de ventas" << endl;
        cin >> opcionV;
        
        switch (opcionV) {
            case 1:
                while (!flagV2) {
                    cout << "!!!!! Si deseas salir, teclea salir\n Esperando codigo de barras: " << endl;
                    cin >> CodigoBarras;
                    if(CodigoBarras == "salir"){
                        flagV2 = true;
                    }else{
                        
                    }
                }
                
                break;
            case 2:
                
                break;
            case 5:
                cout << "^^ Cerrando seccion de ventas ^^\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*" << endl;
                flagV1 = true;
                break;
                
            default:
                cout << "ERROR: Opcion no valida, intentalo de nuevo" << endl;
                break;
        }
    }
    
    
}

//Almacen
void almacen(){
    cin >> producto[productosTotales];
    productosTotales--;
}


#endif /* funciones_h */
