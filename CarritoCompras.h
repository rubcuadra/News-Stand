#pragma once
#include "Publicaciones.h"


template <class Y>
class CarritoCompras
{
public:
    string* carrito;
    int* compras;
    
    int length;
    int numElems = 0;
    
    double montoTotal = 0;
    
    
    double getMontoTotal()
    {
        return montoTotal;
    }
    void AddElement(Y element,int cantidad) //NextFree
    {
        if (numElems == (length))
            ChangeSize();
        carrito[numElems] = element->getTitulo()  ;
        compras[numElems] = cantidad;
        ++numElems;
        montoTotal = element->getPrecioDeVenta()*cantidad;
        element->comprar(cantidad);
    }
    CarritoCompras()
    {
        carrito = new string[3];
        compras = new int[3];
        length = 3;
    }
    CarritoCompras(int _length)
    {
        length = _length;
        carrito = new string[length];
    }
    ~CarritoCompras()
    {
        delete [] carrito;
    }
    int getLength(){return length;}
    
    void ChangeSize() //ChangeSize(&Arreglo);
    {
        string* temporal = new string[length + 5];
        int* temp = new int[length+5];
        for(int i = 0; i<length;++i)
        {
            temporal[i] = carrito[i];
            temp[i] = compras[i];
        }
        length = length+5;
        delete [] carrito;
        delete [] compras;
        compras = temp;
        carrito = temporal;
    }
    void PagarCredito(string name,string numeroTarjeta)
    {
        for (int i = 0; i < numeroTarjeta.size()-4; ++i)
        {
            numeroTarjeta[i] = 'x';
        }
        cout<<"El cobro a la tarjeta de credito "<<numeroTarjeta<<" a nombre de"<<name<<" por un total de"<<montoTotal<<" ha sido exitoso"<<"\n";
        montoTotal = 0;
        deleteArrays();
    }
    void PagarDebito(string name,string numeroTarjeta)
    {
        for (int i = 0; i < numeroTarjeta.size()-4; ++i)
        {
            numeroTarjeta[i] = 'x';
        }
        cout<<"El cobro a la tarjeta de debito "<<numeroTarjeta<<" a nombre de "<<name<<" por un total de "<<montoTotal<<" ha sido exitoso"<<"\n";
        montoTotal = 0;
        deleteArrays();
    }
    void PagarEfectivo()
    {
        cout<<"Se mandaran las instrucciones a su telefono,el pago es en cualquier tienda Oxxo® por un monto total de "<<montoTotal<<" a la cuenta 0101-9102 y su pago se reflejara en 24hrs"<<"\n";
        montoTotal = 0;
        deleteArrays();
    }
    void Print()
    {
        std::cout<<"Sus Compras: "<<"\n";
        for (int i = 0; i< numElems; ++i)
        {
            cout<<"x"<<compras[i]<<" "<<carrito[i]<<"\n";
        }
        cout<<"Un total de: "<<montoTotal<<"\n";
    }
    void deleteArrays()
    {
        for (int i = 0; i<length; ++i)
        {
            *(carrito+i) = ' ';
            *(compras+i) = NULL;
        }
        numElems = 0;
    }
};