#ifndef PROYECTO_CPRODUCTOTIENDA_H
#define PROYECTO_CPRODUCTOTIENDA_H

#include <iostream>
#include <string>
#include <vector>
#include "COctogono.h"
#include "CEmpresaFabricante.h"
using namespace std;

class CProductoTienda{
private:
    string sku;
    string nombre;
    CEmpresaFabricante * fabricante;
    float peso;
    string fecha_vencimiento;
    float precio;
    vector<COctogono*> octogonos;
    string tipo_producto;
    int stock;
public:
    CProductoTienda(){};
    CProductoTienda(string s, string n, string ne, string idf, string de, string ruc, float pe, string f, float pr, string t, int sto){
        sku = s;
        nombre = n;
        fabricante = new CEmpresaFabricante(ne, idf, de, ruc);
        peso = pe;
        precio = pr;
        tipo_producto = t;
        fecha_vencimiento = f;
        stock = sto;
    }
    void cambioStock(int n){
        stock -= n;
    }
    void setStock(int n){
        stock = n;
    }
    string getFecha() {
        return fecha_vencimiento;
    }
    void setOctogno(vector<COctogono*> v){
        octogonos = v;
    }
    CEmpresaFabricante * getEmpresa(){
        return fabricante;
    }
    void imprimirProducto(){
        cout << "   Nombre Producto: " << nombre << endl;
        cout << "      SKU: " << sku << endl;
        cout << "      Stock: " << stock << endl;
        cout << "      Fabricante:\n";
        cout << "         ID: " << fabricante->getId() << endl;
        cout << "         Nombre: " << fabricante->getNombre() << endl;
        cout << "         RUC: " << fabricante->getRuc() << endl;
        cout << "         Direccion: " << fabricante->getDireccion() << endl;
        cout << "      Peso (g): " << peso << endl;
        cout << "      Fecha Vencimiento: " << fecha_vencimiento << endl;
        cout << "      Precio: " << precio << endl;
        cout << "      Octogonos: " << endl;
        if(octogonos.empty()){
            cout << "         Este producto no tiene octogonos.\n";
        }
        for(auto it : octogonos){
            it->imprimirOct();
        }
        cout << "      Tipo de Producto: " << tipo_producto;
    }
    string getSku(){
        return sku;
    }
    string getNombreProd(){
        return nombre;
    }
    float getPeso(){
        return peso;
    }
    float getPrecio(){
        return precio;
    }
    string getTipo(){
        return tipo_producto;
    }
    int getStock(){
        return stock;
    }
};

#endif //PROYECTO_CPRODUCTOTIENDA_H
