#ifndef PROYECTO_CLISTAPRODUCTOSTIENDA_H
#define PROYECTO_CLISTAPRODUCTOSTIENDA_H

#include <sstream>
#include <fstream>
#include "CProductoTienda.h"
#include "CListaOctogonos.h"

class CListaProductoTienda{
private:
    vector<CProductoTienda*> lista;
public:
    CListaProductoTienda(){};
    ~CListaProductoTienda(){};
    void imprimirProductos() {
        for (auto it : lista) {
            it->imprimirProducto();
            cout << endl << endl;
        }
    };
    CProductoTienda * getProductoTienda(string name){
        for(auto p : lista){
            if(p->getNombreProd() == name){
                return p;
            }
        }
        return nullptr;
    }
    void actualizarStock(string name,int n){
        for(auto p : lista){
            if(p->getNombreProd() == name){
                p->cambioStock(n);
            }
        }
    }
    void setStock(int n){
        for(auto p : lista){
            p->setStock(n);
        }
    }
    void cargarDatos(CListaOctogonos * oct, string nombre, int st){
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
            while (getline(ss, item, ';')) {
                v.push_back(item);
            }
            auto prod = new CProductoTienda(v[0], v[1], v[2], v[3], v[4], v[5], stof(v[6]), v[7], stof(v[8]), v[9], st);
            (*prod).setOctogno(oct->getOctogonos(stoi(v[10]),stoi(v[11]),stoi(v[12]),stoi(v[13])));
            lista.push_back(prod);
            v.clear();
        }
        in.close();
    }
};


#endif //PROYECTO_CLISTAPRODUCTOSTIENDA_H
