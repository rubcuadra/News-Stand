#pragma once
#include "Publicaciones.h"

class Noticiero : public Periodicos
{
protected:
    string ciudad;
public:
    ~Noticiero(){}
    Noticiero( string autor,
               string titulo,
               string ciudad,
               int secciones,
               int año,int mes, int dia,
               int paginas,
               int disponibles,
               double precioDeCompra,
               double precioDeVenta
               ) : Periodicos(   autor,
                                 titulo,
                                 secciones,
                                 año, mes, dia,
                                 paginas,
                                 disponibles,
                                 precioDeCompra,
                                precioDeVenta),ciudad(ciudad){primaryKey = 0;}
    
    string getCiudad(){return ciudad;}
    void print()
    {
        cout<<titulo<<" de la ciudad de "<< ciudad<< " editado por "<< autor<< " posee "<<secciones<<" secciones, con un total de "<< paginas<< " paginas, cuesta "<<precioDeVenta<<"MXN y quedan "<<disponibles<<". Edicion: "<<dia<<"/"<<mes<<"/"<<año<<"\n";
    }
};