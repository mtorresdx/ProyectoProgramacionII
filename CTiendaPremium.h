#ifndef PROYECTO_CTIENDAPREMIUM_H
#define PROYECTO_CTIENDAPREMIUM_H

#include "CListaServiciosCafeterias.h"
#include "CTienda.h"

class CTiendaPremium : public CTienda{
protected:
    CServicioCafeteria * cafeteria;
public:
    CTiendaPremium() : CTienda(){};
    CTiendaPremium(string idT, string tt, string nG, string dir, string z, int cj, int cg, string h) : CTienda(idT,tt,nG,dir,z,cj,cg,h){}
    void setCafeteria(string id, CListaServiciosCafeteria * caff){
        cafeteria = caff->getCafeteria(id);
    }
    CProveedorDelivery * getDelivery() override{
        return nullptr;
    }
    CServicioCafeteria * getCafeteria() override{
        return cafeteria;
    }
    CVenta * ventaCafeteria(){
        string n;

        cout << "   Ingrese el nombre del producto que desea comprar: ";
        getline(cin >> ws,n);

        auto prod = cafeteria->getProductos()->getProductoCafeteria(n);

        if(prod == nullptr) {
            do {
                cout << "   Producto no disponible, ingrese otro producto: ";
                getline(cin, n);
                prod = cafeteria->getProductos()->getProductoCafeteria(n);
            } while (prod == nullptr);
        }

        int u = prod->getStock();

        cout << "  <El precio unitario del producto es S/" << prod->getPrecio() << ">\n";
        cout << "  <Hay " << u << " unidades disponibles>\n";
        do {
            do {
                cout << "   Ingrese la cantidad que desea del producto: ";
                getline(cin, n);
            } while (not isnumeric(n));
        }while(stoi(n) > u);

        cout << "\nRESUMEN DE VENTA:\n";
        cout << "   " << prod->getNombre() << " (x" << stoi(n) << ") .................. S/" << prod->getPrecio() * stoi(n) << endl;

        cafeteria->getProductos()->actualizarStock(prod->getNombre(),stoi(n));

        cout << "\nSTOCK RESTANTE:\n";
        cout << "   ID Tienda: " << idTienda << endl;
        cout << "   ID Servicio Cafeteria: " << cafeteria->getIdServicio() << endl;
        cout << "   Producto: " << prod->getNombre() << endl;
        cout << "       Stock: " << prod->getStock() << endl;

        auto v = new CVenta("Venta Cafeteria", idTienda, prod->getNombre(), stoi(n), prod->getPrecio() * stoi(n));
        v->setExtra(cafeteria->getIdServicio());
        return v;
    }
};
#endif //PROYECTO_CTIENDAPREMIUM_H
