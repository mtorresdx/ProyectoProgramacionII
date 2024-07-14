#ifndef PROYECTO_CEMPRESAFABRICANTE_H
#define PROYECTO_CEMPRESAFABRICANTE_H

#include <string>
using namespace std;


class CEmpresaFabricante{
    private:
        string idEmpresa;
        string nombre;
        string direccion;
        string ruc;
    public:
        CEmpresaFabricante(){};
        CEmpresaFabricante(string n, string id, string d, string r){
            idEmpresa = id;
            nombre = n;
            direccion = d;
            ruc = r;
        }
        ~CEmpresaFabricante(){};
        string getId(){
            return idEmpresa;
        }
        string getNombre(){
            return nombre;
        }
        string getDireccion(){
            return direccion;
        }
        string getRuc(){
            return ruc;
        }
};

#endif //PROYECTO_CEMPRESAFABRICANTE_H
