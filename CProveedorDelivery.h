#ifndef PROYECTO_CPROVEEDORDELIVERY_H
#define PROYECTO_CPROVEEDORDELIVERY_H

#include "CSeguroSalud.h"

class CProveedorDelivery{
    private:
        string idProveedor;
        string nombreProveedor;
        string ruc;
        CSeguroSalud * seguroSalud;
        string tipoTransporte;
        float comision;
    public:
        CProveedorDelivery(){};
        CProveedorDelivery(string i, string n, string r, string is, string ns, string rs, string tt, float c){
            idProveedor = i;
            nombreProveedor = n;
            ruc = r;
            tipoTransporte = tt;
            seguroSalud = new CSeguroSalud(is, ns, rs);
            comision = c;
        }
        string getId(){
            return idProveedor;
        }
        string getNombre(){
            return nombreProveedor;
        }
        string getRuc(){
            return ruc;
        }
        CSeguroSalud * getSeguro(){
            return seguroSalud;
        }
        string getTransporte(){
            return tipoTransporte;
        }
        float getComision(){
            return comision;
        }
};

#endif //PROYECTO_CPROVEEDORDELIVERY_H
