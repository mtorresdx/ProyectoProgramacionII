#ifndef PROYECTO_CLISTATIENDAS_H
#define PROYECTO_CLISTATIENDAS_H

#include "CTiendaPremium.h"
#include "CTiendaRegular.h"

class CListaTiendas{
    private:
        vector<CTienda*> tiendas;
    public:
        CListaTiendas(){};
        ~CListaTiendas(){};
        CTienda * getTienda(string id){
            for(auto t : tiendas){
                if(t->getIdTienda() == id){
                    return t;
                }
            }
            return nullptr;
        }
        void cargarDatos(string file, CListaOctogonos * oct, CListaServiciosCafeteria * caffs, CListaProveedorDelivery * dels){
            ifstream in;
            in.open(file);

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

                if(v[1] == "Premium"){
                    auto premium = new CTiendaPremium(v[0],v[1],v[2],v[3],v[4],stoi(v[5]),stoi(v[6]),v[9]);
                    premium->setProductos(oct,"prodTPremium.csv",stoi(v[10]));
                    premium->setCafeteria(v[8],caffs);
                    tiendas.push_back(premium);
                }else{
                    auto regular = new CTiendaRegular(v[0],v[1],v[2],v[3],v[4],stoi(v[5]),stoi(v[6]),v[9]);
                    regular->setProductos(oct,"prodTRegular.csv",stoi(v[10]));
                    regular->setDelivery(v[7],dels);
                    tiendas.push_back(regular);
                }

                v.clear();
            }
            in.close();
        }
};

#endif //PROYECTO_CLISTATIENDAS_H
