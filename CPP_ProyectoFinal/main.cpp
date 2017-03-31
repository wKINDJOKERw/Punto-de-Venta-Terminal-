//
//  main.cpp
//  CPP_ProyectoFinal
//
//  Created by Antony Morales on 3/31/17.
//  Copyright © 2017 Antony999k. All rights reserved.
//

#include <iostream>
using namespace std;

//****************************** Clases ***************************************

class Producto {
    friend istream& operator>>(istream& entrada, Producto& num);
public:
    Producto(){
        nombre = "null";
        marca = "null";
        precio = 0;
        codigoBarras = "null";
    }
    
    string getCodigoBarras(){
        return codigoBarras;
    }
    //Mientras
    void imprimirProducto(){
        cout << "\tProducto: "<< nombre << endl;
        cout << "\tMarca: "<< marca << endl;
        cout << "\tprecio: "<< precio << endl;
    }
    
private:
    string nombre;
    string marca;
    float precio;
    string codigoBarras;
};

istream& operator >>(istream& entrada, Producto& num){
    cout << "Nombre: " << endl;
    entrada >> num.nombre;
    cout << "Marca: " << endl;
    entrada >> num.marca;
    cout << "Precio: " << endl;
    entrada >> num.precio;
    cout << "Código de barras: " << endl;
    entrada >> num.codigoBarras;
    return entrada;
}

//Inicializar funciones
void ventasV();
void almacen();
Producto compararProductos(string codigo);
//Variables globales
float Cobrototal;
int productostotales = 0;
Producto *productos = new Producto[20];


//***************************** Funciones ************************************


void ventasV(){
    bool flagV1 = false, flagV2 = false, flagV3 = false;
    int opcionV, productosVendidos=0, opcionBuscar = 0;
    string CodigoBarras;
    Producto *productoV = new Producto[20];
    
    cout << "************************************************************\n";
    cout << "************** Sección de ventas **************\n";
    cout << "************************************************************\n\n";
    
    while (!flagV1) {
        flagV2 = false;
        flagV3 = false;
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
                        compararProductos(CodigoBarras);
                    }
                }
                
                break;
            case 2:
                while (!flagV3) {
                    cout << "* Selecciona una opcion *" << endl;
                    cout << "\t1)Ver todos los productos" << endl;
                    cout << "\t2)Buscar por nombre" << endl;
                    cout << "\t3)Salir" << endl;
                    cin >> opcionBuscar;
                    
                    switch (opcionBuscar) {
                        case 1:
                            for(int i= 0; i<productostotales; i++){
                                productos[i].imprimirProducto();
                            }
                            break;
                        case 2:
                            break;
                        case 3:
                            flagV3 = true;
                            break;
                        default:
                            break;
                    }
                }
                
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

void almacen(){
    cin >> productos[productostotales];
    productostotales++;
}

Producto compararProductos(string codigo){
    string codigo2;
    
    for(int i=0; i<productostotales;i++){
        codigo2 = productos[0].getCodigoBarras();
        if(!codigo.compare(codigo2)){
            cout << " Encontrado!" << endl;
            productos[i].imprimirProducto();
        }else{
            cout << "No Encontrado :(" << endl;
        }
    }
    
    return productos[0];
}

//***********************************************************************************************************************
//**************************************** Main **********************************************************************
//************************************************************************************************************************

int main() {
    int opcion = 0;
    bool flag = false, flag2 =false;
    
    cout << "************************************************************\n";
    cout << "************** Bienvenido a la tienda virtual **************\n";
    cout << "************************************************************\n\n";
    
    
    while (!flag) {
        flag2 = false;
        cout << "* Elije una opción *\n";
        cout << "\t1)Seccion de ventas\n";
        cout << "\t2)Agregar productos\n";
        cout << "\t3)Salir\n";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                ventasV();
                break;
            case 2:
                almacen();
                cout << "Producto agregado exitosamente" << endl;
                break;
            case 3:
                cout << "Regresa pronto!" << endl;
                return -1;
                break;
                
            default:
                cout << "ERROR: Opcion no valida, intentalo de nuevo" << endl;
                break;
        }
    }
   return 0;
}
