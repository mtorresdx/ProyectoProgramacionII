#include "CListaProductosTienda.h"
#include "CListaServiciosCafeterias.h"
#include "CListaTiendas.h"
#include "isnumeric.h"

int main() {
    vector<CVenta*> ventas;
    auto cafeterias = new CListaServiciosCafeteria();
    auto delivery = new CListaProveedorDelivery();
    auto octogonos = new CListaOctogonos();

    *delivery << "delivery.csv";
    cafeterias->cargarDatos("cafeteria.csv");
    *octogonos << "octogonos.csv";

    auto tiendas = new CListaTiendas();

    tiendas->cargarDatos("tiendas.csv",octogonos,cafeterias,delivery);

    delete cafeterias;
    delete delivery;
    delete octogonos;

    string menu;

    do {
        cout << "------------------SISTEMA DE LA CADENA ONE-ELEVEN------------------\n";
        cout << " <Seleccione una operación>" << endl;
        cout << "   [1] Revisión de Tienda\n";
        cout << "   [2] Realizar una Venta de Producto Tienda\n";
        cout << "   [3] Realizar un Pedido de Delivery\n";
        cout << "   [4] Realizar una Venta de Producto Cafeteria\n";
        cout << "   [5] Imprimir Total de Ventas\n";
        cout << "   [0] Cerrar programa\n";

        do {
            do {
                cout << "   Ingrese su elecccion: ";
                cin >> menu;
            } while (not isnumeric(menu));
        } while (stoi(menu) < 0 || stoi(menu) > 6);

        switch (stoi(menu)) {
            case 1: {
                string id;
                cout << "\n----------------REVISION DE TIENDA---------------\n";
                do {
                    cout << "Ingrese el ID de la Tienda: ";
                    cin >> id;
                } while (tiendas->getTienda(id) == nullptr);
                auto tt = tiendas->getTienda(id);

                if (tt->getTipoTienda() == "Premium") {
                    cout << "\nEsta revisando una TIENDA PREMIUM\n";
                    cout << " <Seleccione que desea revisar>\n";
                    cout << "   [1] Datos Generales de Tienda\n";
                    cout << "   [2] Productos y Stock de Tienda\n";
                    cout << "   [3] Datos Generales de Servicio Cafeteria\n";
                    cout << "   [4] Productos y Stock de Servicio Cafeteria\n";
                    do {
                        do {
                            cout << "   Ingrese su elecccion: ";
                            cin >> menu;
                        } while (not isnumeric(menu));
                    } while (stoi(menu) < 1 || stoi(menu) > 4);

                    switch (stoi(menu)) {
                        case 1:
                            cout << "\nDatos Generales de Tienda:\n";
                            cout << "   Nombre de gerente: " << tt->getGerente() << endl;
                            cout << "   Direccion: " << tt->getDireccion() << endl;
                            cout << "   Zona: " << tt->getDireccion() << endl;
                            cout << "   ID Cafeteria: " << tt->getCafeteria()->getIdServicio() << endl;
                            cout << "   Cantidad de Cajas: " << tt->getCajas() << endl;
                            cout << "   Cantidad de congeladoras: " << tt->getCongeladoras() << endl;
                            cout << "   Horario de Atención: " << tt->getHorario() << endl;
                            break;
                        case 2:
                            cout << "\nProductos y Stock de Tienda:\n";
                            tt->getProductos()->imprimirProductos();
                            break;
                        case 3:
                            cout << "\nDatos Generales de Servicio Cafeteria:\n";
                            cout << "   ID Servicio Cafeteria: " << tt->getCafeteria()->getIdServicio() << endl;
                            cout << "   Proveedor Cafeteria:\n";
                            cout << "       ID: " << tt->getCafeteria()->getProveedor()->getId() << endl;
                            cout << "       Nombre: " << tt->getCafeteria()->getProveedor()->getNombre() << endl;
                            cout << "       RUC: " << tt->getCafeteria()->getProveedor()->getRuc() << endl;
                            cout << "       Registro Sanitario: " << tt->getCafeteria()->getProveedor()->getRegistroSanitario() << endl;
                            break;
                        case 4:
                            cout << "\nProductos y Stock de Cafeteria:\n";
                            tt->getCafeteria()->getProductos()->imprimirProductos();
                            break;
                        default:
                            break;
                    }

                } else {
                    cout << "\nEsta revisando una TIENDA REGULAR\n";
                    cout << " <Seleccione que desea revisar>\n";
                    cout << "   [1] Datos Generales\n";
                    cout << "   [2] Productos y Stock de Tienda\n";
                    cout << "   [3] Datos Generales de Servicio Delivery\n";

                    do {
                        do {
                            cout << "   Ingrese su elecccion: ";
                            cin >> menu;
                        } while (not isnumeric(menu));
                    } while (stoi(menu) < 1 || stoi(menu) > 3);

                    switch (stoi(menu)) {
                        case 1:
                            cout << "\nDatos Generales de Tienda:\n";
                            cout << "   Nombre de gerente: " << tt->getGerente() << endl;
                            cout << "   Direccion: " << tt->getDireccion() << endl;
                            cout << "   Zona: " << tt->getDireccion() << endl;
                            cout << "   ID Delivery: " << tt->getDelivery()->getId() << endl;
                            cout << "   Cantidad de Cajas: " << tt->getCajas() << endl;
                            cout << "   Cantidad de congeladoras: " << tt->getCongeladoras() << endl;
                            cout << "   Horario de Atención: " << tt->getHorario() << endl;
                            break;
                        case 2:
                            cout << "\nProductos y Stock de Tienda:\n";
                            tt->getProductos()->imprimirProductos();
                            break;
                        case 3:
                            cout << "\nDatos Generales de Servicio Delivery:\n";
                            cout << "   ID Delivery: " << tt->getDelivery()->getId() << endl;
                            cout << "   Nombre: " << tt->getDelivery()->getNombre() << endl;
                            cout << "   RUC: " << tt->getDelivery()->getRuc() << endl;
                            cout << "   Tipo Transporte: " << tt->getDelivery()->getTransporte() << endl;
                            cout << "   Seguro Salud:\n";
                            cout << "      ID: " << tt->getDelivery()->getSeguro()->getId() << endl;
                            cout << "      Empresa: " << tt->getDelivery()->getSeguro()->getEmpresa() << endl;
                            cout << "      RUC: " << tt->getDelivery()->getSeguro()->getRuc() << endl;
                            cout << "   Comisión (%): " << tt->getDelivery()->getComision() << endl;
                            break;
                        default:
                            break;
                    }
                }
                break;
            }
            case 2: {
                string id;
                cout << "\n----------------VENTA DE PRODUCTO TIENDA---------------\n";
                cout << "Ingrese el ID de la Tienda: ";
                do {
                    cin >> id;
                } while (tiendas->getTienda(id) == nullptr);
                auto tt = tiendas->getTienda(id);
                ventas.push_back(tt->venta());
                break;
            }
            case 3: {
                string id;
                cout << "\n----------------PEDIDO DELIVERY---------------\n";
                cout << "  <Solo TIENDAS REGULARES tienen delivery>\n";
                do {
                    do {
                        cout << "Ingrese el ID de la Tienda [T1006 - T1015]: ";
                        cin >> id;
                    } while (tiendas->getTienda(id) == nullptr);
                } while (tiendas->getTienda(id)->getTipoTienda() == "Premium");

                auto tt = tiendas->getTienda(id);

                ventas.push_back(tt->pedidoDelivery());
                break;
            }
            case 4: {
                string id;
                cout << "\n----------------VENTA DE PRODUCTO CAFETERIA---------------\n";
                cout << "  <Solo TIENDAS PREMIUM tienen cafeteria>\n";
                cout << "Ingrese el ID de la Tienda [T1001 - T1005]: ";
                do {
                    cin >> id;
                } while (tiendas->getTienda(id) == nullptr);
                auto tt = tiendas->getTienda(id);
                ventas.push_back(tt->ventaCafeteria());
                break;
            }
            case 5: {
                cout << "\n----------------RESUMEN DE VENTAS---------------\n";
                int i = 1;
                for(auto v : ventas){
                    cout << "Venta " << i << endl;
                    cout << "   Tipo: " << v->getTipo() << endl;
                    cout << "   Tienda: " << v->getIdTienda() << endl;
                    if(v->getTipo() == "Pedido Delivery"){
                        cout << "   ID Delivery: " << v->getIdDel() << endl;
                    }else if(v->getTipo() == "Venta Cafeteria"){
                        cout << "   ID Servicio Cafeteria: " << v->getIdCaff() << endl;
                    }
                    cout << "   Nombre Producto: " << v->getProducto() << endl;
                    cout << "   Cantidad: " << v->getCantidad() << endl;
                    cout << "   Costo: " << v->getCosto() << endl;
                    i++;
                }
                if(ventas.empty()){
                    cout << "No se ha realizado ninguna venta.\n";
                }
                break;
            }
        }
        cout << endl << endl;
    }while(stoi(menu) != 0);

    delete tiendas;
}

