#pragma once
#include "Revistas.h"

class Cientifica : public Revistas
{
public:
    ~Cientifica(){}
    Cientifica    (string autor,
             string titulo,
             string topico,
             int año,int mes, int dia,
             int paginas,
             int disponibles,
             double precioDeCompra,
             double precioDeVenta
             ) : Revistas( autor,
                          titulo,
                          topico,
                          año, mes, dia,
                          paginas,
                          disponibles,
                          precioDeCompra,
                          precioDeVenta){primaryKey = 3;}
    void print()
    {
        cout<<titulo<<", revista cientifica dedicada a "<< topico << " editado por "<< autor<<" tiene un total de "<< paginas<< " paginas, cuesta "<<precioDeVenta<<"MXN y quedan "<<disponibles<<". Edicion: "<<dia<<"/"<<mes<<"/"<<año<<"\n";
    }
};