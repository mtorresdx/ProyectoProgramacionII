cmake_minimum_required(VERSION 3.27)
project(proyecto)

set(CMAKE_CXX_STANDARD 23)

add_executable(proyecto main.cpp
        CSeguroSalud.h
        CProveedorDelivery.h
        CTienda.h
        CTiendaRegular.h
        CTiendaPremium.h
        CEmpresaFabricante.h
        CProductoTienda.h
        COctogono.h
        CProductoCafeteria.h
        CServicioCafeteria.h
        CProveedorCafeteria.h
        CListaProductosCafeteria.h
        CListaServiciosCafeterias.h
        CListaProductosTienda.h
        CListaOctogonos.h
        CListaProveedorDelivery.h
        CListaTiendas.h
        isnumeric.h
        CVenta.h)
