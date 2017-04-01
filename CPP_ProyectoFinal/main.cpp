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
    
    float getPrecio(){
        return precio;
    }
    
    string getProducto(){
        return nombre;
    }
    
    string getCodigoBarras(){
        return codigoBarras;
    }
    //Mientras
    void imprimirProducto(){
        cout << "************************************************************************************************************************" << endl;
        cout << "\tProducto: "<< nombre << endl;
        cout << "\tMarca: "<< marca;
        cout << "                    precio: "<< precio << endl;
        cout << "************************************************************************************************************************" << endl;
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
int productostotales = 0, noTiket = 0;
Producto *productos = new Producto[20];


//***************************** Funciones ************************************


void ventasV(){
    bool flagV1 = false, flagV2 = false, flagV3 = false;
    int opcionV, productosVendidos=0, opcionBuscar = 0, opcionBuscar2;
    string CodigoBarras, opcionBuscar3;
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
                        productoV[productosVendidos] = compararProductos(CodigoBarras);
                        if(productoV[productosVendidos].getPrecio() != 0){
                            Cobrototal += productoV[productosVendidos].getPrecio();
                            cout << "-----" << productoV[productosVendidos].getProducto() << " Añadido!!" << endl << endl << endl;
                            productosVendidos++;
                        }else{
                            cout << "-----No se encontro el producto, puede que no este dado de alta" << endl << endl << endl;
                        }
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
                            cout << "****** Seleccione el numero de algun producto o ingrese '-1' para salir: ";
                            for(int i= 0; i<productostotales; i++){
                                cout << "\n********************************************************** "<< i << " **********************************************************" << endl;
                                cout << "*                                                                                                                *" << endl;
                                productos[i].imprimirProducto();
                            }
                            
                            cout << "****** Seleccione el numero de algun producto o ingrese '-1' para salir: " << endl;
                            cin >> opcionBuscar2;
                            if(opcionBuscar2 >= 0 && opcionBuscar2 <= productostotales){
                                productoV[productosVendidos] = productos[opcionBuscar2];
                                Cobrototal += productoV[productosVendidos].getPrecio();
                                cout << "-----" << productoV[productosVendidos].getProducto() << " Añadido!!" << endl << endl << endl;
                                productosVendidos++;
                            }
                                
                            break;
                        case 2:
                            cout << "Ingrese el nombre exacto del producto: ";
                            cin >> opcionBuscar3;
                            
                            productoV[productosVendidos] = compararProductos(opcionBuscar3);
                            if(productoV[productosVendidos].getPrecio() != 0){
                                cout << "¿Quieres añadir " << productoV[productosVendidos].getProducto() << "? Teclea 'si' o 'no'"  << endl;
                                string aniadir;
                                cin >> aniadir;
                                if(aniadir == "si"){
                                    Cobrototal += productoV[productosVendidos].getPrecio();
                                    cout << "-----" << productoV[productosVendidos].getProducto() << " Añadido!!" << endl << endl << endl;
                                    productosVendidos++;
                                }

                            }else{
                                cout << "-----No se encontro el producto, puede que no este dado de alta" << endl << endl << endl;
                            }
                            
                            break;
                        case 3:
                            flagV3 = true;
                            break;
                        default:
                            break;
                    }
                }
                
                break;
            case 3:
                int dineroRecibido;
                cout << "Subtotal: $" << Cobrototal << endl;
                cout << "Total: $" << Cobrototal * 1.16 << endl << endl;
                
                cout << "Dinero Recibido: $" << endl;
                cin >> dineroRecibido;
                
                cout << "\nCambio: $" << dineroRecibido - (Cobrototal * 1.16) << endl;
                
                break;
            case 4:
                cout << "************* Tienda R ******************" << endl;
                cout << "************* # Ticket " << noTiket <<" ******************" << endl << endl;
                for(int j = 0; j<productosVendidos;j++ ){
                    productoV[j].imprimirProducto();
                }
                cout << "Subtotal: $" << Cobrototal << endl;
                cout << "Total: $" << Cobrototal * 1.16 << endl << endl;
                cout << "**************************************************\n*\n*\n*" ;
                noTiket++;
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
    int found = -1;
    
    for(int i=0; i<productostotales;i++){
        if(codigo == productos[i].getCodigoBarras()){
            found = i;
        }
    }
    
    if(found >=0){
        return productos[found];
    }else{
        Producto basura;
        return basura;
    }
    

}

Producto compararProductosxNombre(string nombre){
    int found = -1;
    
    for(int i=0; i<productostotales;i++){
        if(nombre == productos[i].getProducto()){
            found = i;
        }
    }
    
    if(found >=0){
        return productos[found];
    }else{
        Producto basura;
        return basura;
    }
    
    
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
