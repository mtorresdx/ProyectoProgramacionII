#ifndef PROYECTO_CSERVICIOCAFETERIA_H
#define PROYECTO_CSERVICIOCAFETERIA_H

#include "isnumeric.h"
#include "CProveedorCafeteria.h"
#include "CListaProductosCafeteria.h"
#include <vector>
#include "CVenta.h"

class CServicioCafeteria{
private:
    string idServicio;
    CProveedorCafeteria * proveedor;
    CListaProductoCafeteria * productos;
public:
    CServicioCafeteria(){};
    CServicioCafeteria(string idS, string idP, string n, string ruc, string rS, int stock){
        idServicio = idS;
        proveedor = new CProveedorCafeteria(idP,n,ruc,rS);
        productos = new CListaProductoCafeteria();
        setProductos(stock);
    }
    void imprimirCafeteria(){
        cout << "ID SERVICIO CAFETERIA: " << idServicio << endl;
        cout << "   Proveedor: " << endl;
        cout << "      ID: " << proveedor->getId() << endl;
        cout << "      Nombre: " << proveedor->getNombre() << endl;
        cout << "      RUC: " << proveedor->getRuc() << endl;
        cout << "      Registro Sanitario: " << proveedor->getRegistroSanitario() << endl;
    }
    ~CServicioCafeteria(){};
    void setIdServicio(string idS_){
        idServicio = idS_;
    }
    void setIdProveedor(CProveedorCafeteria * p){
        proveedor = p;
    }
    CListaProductoCafeteria * getProductos(){
        return productos;
    }
    void setProductos(int n){
        productos->cargarDatos("prodCafeteria.csv",n);
    }
    string getIdServicio(){
        return idServicio;
    }
    CProveedorCafeteria * getProveedor(){
        return proveedor;
    }
};

#endif //PROYECTO_CSERVICIOCAFETERIA_H
