#ifndef PROYECTO_CVENTA_H
#define PROYECTO_CVENTA_H

#include <string>
using namespace std;


class CVenta{
    private:
        string tipo;
        string idTienda;
        string idCafeteria;
        string idDelivery;
        string producto;
        int cantidad;
        float costo;
    public:
        CVenta(){};
        CVenta(string t, string tienda, string prod, int cant, float cost){
            tipo = t;
            idTienda = tienda;
            producto = prod;
            cantidad = cant;
            costo = cost;
        }
        ~CVenta(){};
        void setExtra(string extra){
            if(tipo == "Pedido Delivery") {
                idDelivery = extra;
            }else if(tipo == "Venta Cafeteria") {
                idCafeteria = extra;
            }
        }
        string getTipo(){
            return tipo;
        }
        string getIdTienda(){
            return idTienda;
        }
        string getProducto(){
            return producto;
        }
        string getIdCaff(){
            return idCafeteria;
        }
        string getIdDel(){
            return idDelivery;
        }
        int getCantidad(){
            return cantidad;
        }
        float getCosto(){
            return costo;
        }

};

#endif //PROYECTO_CVENTA_H
