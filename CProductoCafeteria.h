#ifndef PROYECTO_CPRODUCTOCAFETERIA_H
#define PROYECTO_CPRODUCTOCAFETERIA_H

#include <iostream>
#include <string>
using namespace std;

class CProductoCafeteria{
private:
    string id;
    string nombre;
    float precio;
    int stock;
public:
    CProductoCafeteria(){};
    CProductoCafeteria(string id_, string nombre_, float precio_, int stock_){
        id = id_;
        nombre = nombre_;
        precio = precio_;
        stock = stock_;
    }
    ~CProductoCafeteria(){};
    void imprimirProducto(){
        cout << "   Nombre Producto: " << nombre << endl;
        cout << "       ID: " << id << endl;
        cout << "       Precio: " << precio << endl;
        cout << "       Stock: " << stock << endl;
    }
    void cambioStock(int n){
        stock -= n;
    }
    // Setters
    void setId(string id_){
        id = id_;
    };
    void setNombre(string nombre_){
        nombre = nombre_;
    }
    void setPrecio(float precio_){
        precio = precio_;
    }
    void setStock(int stock_){
        stock = stock_;
    }
    //Getters
    string getId(){
        return id;
    }
    string getNombre(){
        return nombre;
    }
    float getPrecio(){
        return precio;
    }
    int getStock(){
        return stock;
    }
};

#endif //PROYECTO_CPRODUCTOCAFETERIA_H
