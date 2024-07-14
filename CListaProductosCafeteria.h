#ifndef PROYECTO_CLISTAPRODUCTOSCAFETERIA_H
#define PROYECTO_CLISTAPRODUCTOSCAFETERIA_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "CProductoCafeteria.h"

class CListaProductoCafeteria {
private:
    vector<CProductoCafeteria *> lista;
public:
    CListaProductoCafeteria() {};
    ~CListaProductoCafeteria() {};
    void imprimirProductos() {
        int i = 1;
        for (auto it: lista) {
            it->imprimirProducto();
        }
    };
    void actualizarStock(string name,int n){
        for(auto p : lista){
            if(p->getNombre() == name){
                p->cambioStock(n);
            }
        }
    }
    CProductoCafeteria * getProductoCafeteria(string nombre){
        for(auto it : lista){
            if(it->getNombre() == nombre){
                return it;
            }
        }
        return nullptr;
    }

    void cargarDatos(string nombre, int n) {
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

            auto prod = new CProductoCafeteria(v[0], v[1], stof(v[2]), n);
            lista.push_back(prod);
            v.clear();
        }
        in.close();
    };
};

#endif //PROYECTO_CLISTAPRODUCTOSCAFETERIA_H
