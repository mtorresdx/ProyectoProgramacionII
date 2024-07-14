#ifndef PROYECTO_CLISTAPROVEEDORDELIVERY_H
#define PROYECTO_CLISTAPROVEEDORDELIVERY_H

#include "CProveedorDelivery.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class CListaProveedorDelivery{
private:
    vector<CProveedorDelivery*> lista;
public:
    CListaProveedorDelivery(){};
    ~CListaProveedorDelivery(){};
    CProveedorDelivery * getDelivery(string id){
        for(auto it : lista){
            if(it->getId() == id){
                return it;
            };
        };
    };
    CListaProveedorDelivery& operator<<(string nombre) {
        ifstream in;
        in.open(nombre);

        if (!in.is_open()) {
            cout << "Error al abrir el archivo" << endl;
            exit(EXIT_FAILURE);
        }

        string line;
        vector<string> v;

        while (getline(in, line)) {
            string item;
            stringstream ss(line);

            while (getline(ss, item, ',')) {
                v.push_back(item);
            }
            lista.push_back(new CProveedorDelivery(v[0], v[1], v[2],v[3],v[4],v[5],v[6],stof(v[7])));
            v.clear();
        }
        in.close();
        return *this;
    }
};


#endif //PROYECTO_CLISTAPROVEEDORDELIVERY_H
