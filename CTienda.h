#ifndef PROYECTO_CTIENDA_H
#define PROYECTO_CTIENDA_H

#include "isnumeric.h"
#include "CListaProductosTienda.h"
#include "CListaOctogonos.h"
#include "CServicioCafeteria.h"
#include "CProveedorDelivery.h"
#include "CVenta.h"

class CTienda{
    protected:
        string idTienda;
        string nombreGerente;
        string direccion;
        string zona;
        CListaProductoTienda * productos = new CListaProductoTienda();
        int cantidadCajas;
        int cantidadCongeladoras;
        string horarioAtencion;
        string tipoTienda;
    public:
        CTienda(){};
        CTienda(string idT, string tt, string nG, string dir, string z, int cj, int cg, string h){
            idTienda = idT;
            tipoTienda = tt;
            nombreGerente = nG;
            direccion = dir;
            zona = z;
            cantidadCajas = cj;
            cantidadCongeladoras = cg;
            horarioAtencion = h;
        }
        void setProductos(CListaOctogonos * oct, string nombre, int ss){
            productos->cargarDatos(oct,nombre,ss);
        }
        virtual CServicioCafeteria * getCafeteria(){};
        virtual CProveedorDelivery * getDelivery(){};
        virtual CVenta * pedidoDelivery(){};
        virtual CVenta * ventaCafeteria(){};
        string getIdTienda(){
            return idTienda;
        }
        string getGerente(){
            return nombreGerente;
        }
        string getDireccion(){
            return direccion;
        }
        string getZona(){
            return zona;
        }
        string getHorario(){
            return horarioAtencion;
        }
        string getTipoTienda(){
            return tipoTienda;
        }
        int getCajas(){
            return cantidadCajas;
        }
        int getCongeladoras(){
            return cantidadCongeladoras;
        }
        CListaProductoTienda * getProductos(){
            return productos;
        }
        CVenta * venta(){
            string n;

            cout << "   Ingrese el nombre del producto que desea comprar: ";
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

            productos->actualizarStock(prod->getNombreProd(),stoi(n));

            cout << "\nSTOCK RESTANTE:\n";
            cout << "   Tienda: " << idTienda << endl;
            cout << "   Producto: " << prod->getNombreProd() << endl;
            cout << "       Stock: " << prod->getStock() << endl;

            auto v = new CVenta("Venta Tienda", idTienda, prod->getNombreProd(), stoi(n), prod->getPrecio() * stoi(n));
            return v;
        }
        ~CTienda(){};

};

#endif //PROYECTO_CTIENDA_H
