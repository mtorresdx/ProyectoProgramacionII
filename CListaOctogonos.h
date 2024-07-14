#ifndef PROYECTO_CLISTAOCTOGONOS_H
#define PROYECTO_CLISTAOCTOGONOS_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "COctogono.h"

class CListaOctogonos{
private:
    vector<COctogono*> lista;
public:
    CListaOctogonos(){};
    ~CListaOctogonos(){};
    void imprimirOctogonos() {
        int i = 1;
        for (auto it = lista.begin(); it != lista.end(); it++) {
            cout << "OCTOGONO " << i << endl;
            cout << "   ID: " << (*it)->getId() << endl;
            cout << "   Alto en: " << (*it)->getAlto() << endl;
            i++;
        }
    };
    vector<COctogono*> getOctogonos(int n1, int n2, int n3, int n4){
        vector<COctogono*> v;
        if(n1 == 1){
            v.push_back(lista[0]);
        }
        if(n2 == 1){
            v.push_back(lista[1]);
        }
        if(n3 == 1){
            v.push_back(lista[2]);
        }
        if(n4 == 1){
            v.push_back(lista[3]);
        }
        return v;
    };
    CListaOctogonos& operator<<(string nombre) {
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
            lista.push_back(new COctogono(v[0], v[1]));
            v.clear();
        }
        in.close();
        return *this;
    }
};

#endif //PROYECTO_CLISTAOCTOGONOS_H
