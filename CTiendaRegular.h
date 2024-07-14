#ifndef PROYECTO_CTIENDAREGULAR_H
#define PROYECTO_CTIENDAREGULAR_H

#include "CListaProveedorDelivery.h"
#include "CTienda.h"

class CTiendaRegular : public CTienda{
    protected:
        CProveedorDelivery * delivery;
    public:
        CTiendaRegular() : CTienda(){};
        CTiendaRegular(string idT, string tt, string nG, string dir, string z, int cj, int cg, string h) : CTienda(idT,tt,nG,dir,z,cj,cg,h){}
        void setDelivery(string id, CListaProveedorDelivery * del){
            delivery = del->getDelivery(id);
        }
        CProveedorDelivery * getDelivery() override{
            return delivery;
        }
        CServicioCafeteria * getCafeteria() override{
            return nullptr;
        }
        CVenta * pedidoDelivery() override{
            string n;
            cout << "  <La comisión por Servicio de Delivery es de " << delivery->getComision() << "%>\n";
            cout << "   Ingrese el nombre del producto que desea pedir por Delivery: ";
            getline(cin >> ws,n);

            auto prod = productos->getProductoTienda(n);

            if(prod == nullptr) {
                do {
                    cout << "   Producto no disponible, ingrese otro producto: ";
                    getline(cin, n);
                    prod = productos->getProductoTienda(n);
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
            cout << "   " << prod->getNombreProd() << " (x" << stoi(n) << ") .................. S/" << prod->getPrecio() * stoi(n) << endl;
            cout << "   Costo Delivery" << " ...................... S/" << prod->getPrecio() * stoi(n) * delivery->getComision() * (1/100.0) << endl;
            float total = prod->getPrecio() * stoi(n) * (1 + delivery->getComision() * (1/100.0));
            cout << "   TOTAL " << " ................................. S/" << total << endl;

            productos->actualizarStock(prod->getNombreProd(),stoi(n));

            cout << "\nSTOCK RESTANTE:\n";
            cout << "   Tienda: " << idTienda << endl;
            cout << "   ID Delivery: " << delivery->getId() << endl;
            cout << "   Producto: " << prod->getNombreProd() << endl;
            cout << "       Stock: " << prod->getStock() << endl;

            auto v = new CVenta("Pedido Delivery", idTienda, prod->getNombreProd(), stoi(n), total);
            v->setExtra(delivery->getId());
            return v;
        }
};

#endif //PROYECTO_CTIENDAREGULAR_H
