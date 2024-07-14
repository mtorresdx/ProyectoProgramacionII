#ifndef PROYECTO_CSEGUROSALUD_H
#define PROYECTO_CSEGUROSALUD_H

#include <string>
using namespace std;


class CSeguroSalud{
    private:
        string idSeguro;
        string nombreEmpresa;
        string ruc;
    public:
        CSeguroSalud(){}
        CSeguroSalud(string i, string n, string r){
            idSeguro = i;
            nombreEmpresa = n;
            ruc = r;
        }
        ~CSeguroSalud(){};
        string getId(){
            return idSeguro;
        }
        string getEmpresa(){
            return nombreEmpresa;
        }
        string getRuc(){
            return ruc;
        }
};

#endif //PROYECTO_CSEGUROSALUD_H
