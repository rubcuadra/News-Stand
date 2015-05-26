#pragma once
#include "Publicaciones.h"

class Publicitario : public Periodicos
{
protected:
    string patrocinios;
public:
    ~Publicitario(){}
    Publicitario(string autor,
              string titulo,
              string patrocinios,
              int secciones,
              int año, int mes, int dia,
              int paginas,
              int disponibles,
              double precioDeCompra
              ) : Periodicos(autor,
                             titulo,
                             secciones,
                             año, mes, dia,
                             paginas,
                             disponibles,
                             precioDeCompra,
                             0),patrocinios(patrocinios){primaryKey = 1;}
    
    string getPatrocinios(){return patrocinios;}
    void print()
    {
        cout<<titulo<<" patrocinado por "<< patrocinios<< " editado por "<< autor<< " posee "<<secciones<<" secciones, con un total de "<< paginas<< " paginas, es gratis y quedan "<<disponibles<<". Edicion: "<<dia<<"/"<<mes<<"/"<<año<<"\n";
    }
};