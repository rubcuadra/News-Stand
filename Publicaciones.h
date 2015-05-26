#pragma once
#include <string.h>
#include <iostream>
#include <ctime> //Comparar Fecha actual con la del escrito, si es menor o igual poner bandera de caducado
using namespace std;

class Publicaciones
{
protected:
    string autor;
    string titulo;
    
    double precioDeCompra;
    double precioDeVenta;
    int año; int dia; int mes;
    
    int ventas;
    int disponibles;
    int paginas;
    int compradosInicio;

public:
    virtual ~Publicaciones(){}
    
    bool caducado;
    int primaryKey = 0;
    
    virtual void print() = 0;
    virtual void printPrice()
    {
        cout<< titulo<<", Precio Compra: "<<precioDeCompra<<" Precio Venta: "<<precioDeVenta<<" Quedan: "<< disponibles<<"\n";
        
    }
    virtual void printVentas()
    {
        std::cout<<titulo<<" Almacen Inicio: "<<compradosInicio<<
        " ,se han vendido "<<ventas<<"\n";
    }
    
    Publicaciones(string autor,
                  string titulo,
                  int año, int mes, int dia,
                  int paginas,
                  int disponibles,
                  double precioDeCompra,
                  double precioDeVenta): autor(autor),titulo(titulo),
                              precioDeCompra(precioDeCompra),precioDeVenta(precioDeVenta),
                año(año),ventas(0),disponibles(disponibles),paginas(paginas),compradosInicio(disponibles),mes(mes),dia(dia)
    {
        time_t t = time(0);
        struct tm *now = localtime( & t );
        
        int actualYear = now->tm_year+1900;
        int actualMonth = now->tm_mon+1;
        int actualDay = now->tm_mday;
        
        if (año < actualYear || (año<actualYear && mes<actualMonth) || (año<actualYear && mes<actualMonth && dia<actualDay))
        {
            caducado = true;
        }
        else{caducado = false;} //Si es menor a la fecha de hoy se considera caducado
    }
    Publicaciones(){}
    
    string getAutor(){return autor;}
    const string getTitulo(){return titulo;}
    double getPrecioDeCompra(){return precioDeCompra;}
    double getPrecioDeVenta(){return precioDeVenta;}
    int getCompradosInicio(){return compradosInicio;}
    int getAño(){return año;}
    int getVentas(){return ventas;}
    int getDisponibles(){return disponibles;}
    int getPaginas(){return paginas;}
    int getPK(){return primaryKey;}
    
    bool getCaducado(){return caducado;}
    
    void actualizarFecha()
    {
        time_t t = time(0);
        struct tm *now = localtime( & t );
        año = now->tm_year+1900;
        mes = now->tm_mon+1;
        dia = now->tm_mday;
    }


    void abastecer(int cantidad)
    {
        disponibles = disponibles+cantidad;
        compradosInicio = compradosInicio+cantidad;
        cout<<"Se abastecio con exito"<<"\n";
    }
    
    void comprar(int cantidad)
    {
        if(disponibles-cantidad >= 0 && caducado != true)
        {
            disponibles = disponibles-cantidad;
            ventas = ventas+cantidad;
            cout<<"La compra se añadio a su carrito"<<"\n";
        }
        else
        { cout<<"Error al Procesar su compra, no hay suficientes productos"<<"\n";}
    }
    double getBalance()
    {
        return (ventas*precioDeVenta)-(precioDeCompra*compradosInicio);
    }
};