#pragma once
#include "Publicaciones.h"

class Revistas : public Publicaciones
{
protected:
    string topico;
public:
    virtual ~Revistas(){}
    Revistas( string autor,
              string titulo,
              string topico,
              int año, int mes, int dia,
              int paginas,
              int disponibles,
              double precioDeCompra,
              double precioDeVenta
              ) : Publicaciones(autor,
                             titulo,
                             año,mes,dia,
                             paginas,
                             disponibles,
                             precioDeCompra,
                             precioDeVenta),topico(topico){}
    string getTopico(){return topico;}
};
