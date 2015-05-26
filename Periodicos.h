#pragma once
#include "Publicaciones.h"

class Periodicos : public Publicaciones
{
protected:
    int secciones;
public:
    virtual ~Periodicos(){}
    Periodicos(  string autor,
                 string titulo,
                 int secciones,
                 int año,
               int mes,
               int dia,
                 int paginas,
                 int disponibles,
                 double precioDeCompra,
                 double precioDeVenta
                ) : Publicaciones( autor,
                                   titulo,
                                   año,mes,dia,
                                   paginas,
                                   disponibles,
                                   precioDeCompra,
                                  precioDeVenta),secciones(secciones){}
    int getSecciones(){return secciones;}
};