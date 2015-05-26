#pragma once
#include "Revistas.h"

class Ocio : public Revistas
{    
public:
    ~Ocio(){}
    Ocio    (string autor,
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
                          año,mes, dia,
                          paginas,
                          disponibles,
                          precioDeCompra,
                          precioDeVenta){primaryKey = 2;}
    void print()
    {
        cout<<titulo<<", revista de ocio dedicada a "<< topico << " editado por "<< autor<<" tiene un total de "<< paginas<< " paginas, cuesta "<<precioDeVenta<<"MXN y quedan "<<disponibles<<". Edicion: "<<dia<<"/"<<mes<<"/"<<año<<"\n";
    }
};