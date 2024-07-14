#ifndef PROYECTO_CPROVEEDORCAFETERIA_H
#define PROYECTO_CPROVEEDORCAFETERIA_H

#include <iostream>
#include <string>
using namespace std;

class CProveedorCafeteria{
private:
    string id;
    string nombre;
    string ruc;
    string registroSanitario;
public:
    CProveedorCafeteria(){};
    CProveedorCafeteria(string id_, string nombre_, string ruc_, string registroSanitario_){
        id = id_;
        nombre = nombre_;
        ruc = ruc_;
        registroSanitario = registroSanitario_;
    }
    ~CProveedorCafeteria(){};
    // Setters
    void setId(string id_){
        id = id_;
    };
    void setNombre(string nombre_){
        nombre = nombre_;
    }
    void setRuc(string ruc_){
        ruc = ruc_;
    }
    void setRegistroSanitario(string registroSanitario_){
        registroSanitario = registroSanitario_;
    }
    //Getters
    string getId(){
        return id;
    }
    string getNombre(){
        return nombre;
    }
    string getRuc(){
        return ruc;
    }
    string getRegistroSanitario(){
        return registroSanitario;
    }
};

#endif //PROYECTO_CPROVEEDORCAFETERIA_H
