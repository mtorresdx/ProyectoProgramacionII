#ifndef PROYECTO_CLISTASERVICIOSCAFETERIAS_H
#define PROYECTO_CLISTASERVICIOSCAFETERIAS_H

#include "CServicioCafeteria.h"
#include "isnumeric.h"

class CListaServiciosCafeteria{
private:
    vector<CServicioCafeteria*> lista;
public:
    CListaServiciosCafeteria(){};
    ~CListaServiciosCafeteria(){};
    void imprimirCafeterias() {
        int i = 1;
        for (auto it: lista) {
            it->imprimirCafeteria();
        }
    };
    CServicioCafeteria * getCafeteria(string idCafetria){
        for(auto it : lista){
            if(it->getIdServicio() == idCafetria){
                return it;
            }
        }
    }
    void cargarDatos(string nombre) {
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

            auto prod = new CServicioCafeteria(v[0], v[1], v[2], v[3], v[4], stoi(v[5]));
            lista.push_back(prod);
            v.clear();
        }
        in.close();
    };
};


#endif //PROYECTO_CLISTASERVICIOSCAFETERIAS_H
