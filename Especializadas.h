#pragma once
#include "Revistas.h"

class Especializadas : public Revistas
{
public:
    ~Especializadas(){}
    Especializadas();
    Especializadas    (string autor,
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
                                año,mes,dia,
                                paginas,
                                disponibles,
                                precioDeCompra,
                                precioDeVenta){primaryKey = 4;}
    void print()
    {
        cout<<titulo<<", revista especializada en "<< topico << " editado por "<< autor<<" tiene un total de "<< paginas<< " paginas, cuesta "<<precioDeVenta<<"MXN y quedan "<<disponibles<<". Edicion:"<<dia<<"/"<<mes<<"/"<<año<<"\n";
    }
};