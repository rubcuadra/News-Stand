#pragma once
#include <string.h>
#include "CarritoCompras.h"
#include "Publicaciones.h"
#include "List.h"
#include <sstream>
using namespace std;
class UserInterface
{
public:
    UserInterface(){}
    
    static string ReadString(string prompt)
    {
        cout<<prompt<<": ";
        string option;
        cin>>option;
        cout<<"\n";
        return option;
    }
    static int ReadInt(const string prompt)
    {
        stringstream ss(ReadString(prompt));
        int choice;
        
        while (!ss.eof())
        {
            if (ss >> choice)
            {
                ss >> choice;
                return choice;
            }
            ss.clear();
            ss.ignore();
        }
        return 666;
    }
    static int UserType()
    {
        cout<<"Ingresa como: "<<"\n";
        cout<<" 1) Administrador"<<"\n";
        cout<<" 2) Cliente"<<"\n";
        cout<<" 0) Salir"<<"\n";
        return ReadInt("Tu eleccion");
    }
    static int AdminMenu()
    {
        cout<<"Seleccione operacion: "<<"\n";
        cout<<" 0) Salir"<<"\n";
        cout<<" 1) Abastecer"<<"\n";
        cout<<" 2) Estado de cuenta"<<"\n";
        cout<<" 3) Checar Inventario"<<"\n";
        return ReadInt("Operacion");
    }
    static int ClienteMenu()
    {
        cout<<"Seleccione operacion: "<<"\n";
        cout<<" 0) Salir"<<"\n";
        cout<<" 1) Busqueda"<<"\n";
        cout<<" 2) Menu"<<"\n";
        cout<<" 3) Ir a Compras"<<"\n";
        return ReadInt("Operacion");
    }
    static int AbastecerMenu()
    {
        cout<<"Seleccione operacion: "<<"\n";
        cout<<" 0) Regresar"<<"\n";
        cout<<" 1) Buscar por nombre"<<"\n";
        cout<<"Abastecer:    "<<"\n";
        cout<<" 2) Periodicos"<<"\n";
        cout<<" 3) Revistas"<<"\n";
        cout<<"Eliminar:    "<<"\n";
        cout<<" 4) Productos caducados"<<"\n";
        return ReadInt("Operacion");
    }
    static int estadoCuentaMenu()
    {
        cout<<"Seleccione operacion: "<<"\n";
        cout<<" 0) Regresar"<<"\n";
        cout<<" 1) Venta por categorias"<<"\n";
        cout<<" 2) Venta por productos"<<"\n";
        cout<<" 3) Total de Ventas"<<"\n";
        cout<<" 4) Obtener balance"<<"\n";
        return ReadInt("Operacion");
    }
    static int inventarioMenu()
    {
        cout<<"Seleccione operacion: "<<"\n";
        cout<<" 0) Regresar"<<"\n";
        cout<<" 1) Imprimir inventario"<<"\n";
        cout<<" 2) Imprimir por categorias"<<"\n";
        cout<<" 3) Imprmir por producto"<<"\n";
        cout<<" 4) Productos caducados"<<"\n";
        return ReadInt("Operacion");
    }
    static int PeriodicosMenu(List<Publicaciones*> *almacen)
    {
        cout<<"Noticieros:"<<"\n";
        almacen->PrintSamePrimaryKey(0);
        cout<<"Publicitarios:"<<"\n";
        almacen->PrintSamePrimaryKey(1);
        cout<<"0) Regresar"<<"\n";
        return ReadInt("Operacion");
    }
    static int RevistasMenu(List<Publicaciones*> *almacen)
    {
        cout<<"Ocio:"<<"\n";
        almacen->PrintSamePrimaryKey(2);
        cout<<"Cientificas:"<<"\n";
        almacen->PrintSamePrimaryKey(3);
        cout<<"Especializadas:"<<"\n";
        almacen->PrintSamePrimaryKey(4);
        cout<<"0) Regresar"<<"\n";
        return ReadInt("Operacion");
    }
    static int catalogoMenu(List<Publicaciones*> *almacen, bool admin)
    {
        cout<<"Tienda : "<<"\n";
        almacen->PrintAllList(admin);
        cout<<"0) Regresar"<<"\n";
        return ReadInt("Operacion");
    }
    
    int searchNombre(List<Publicaciones*> *almacen)
    {
        cout<<"Ingrese el Nombre del objeto deseado"<<"\n";
        string name;
        cin>>name;
        return almacen->search(name, &Publicaciones::getTitulo); //Find in string y acabamos, Subir manual, codigo fuente, screenshots
    }
    int carritoMenu(CarritoCompras<Publicaciones*> *compras)
    {
        compras->Print();
        
        cout<<"Selecciona el metodo de pago:"<<"\n";
        cout<<"1) Tarjeta de Credito"<<"\n";
        cout<<"2) Tarjeta de Debito"<<"\n";
        cout<<"3) Efectivo"<<"\n";
        cout<<"0) Regresar"<<"\n";

        return ReadInt("Operacion");
    }
    
    int categoriasMenu()
    {
        cout<<"1)Periodicos:"<<"\n";
        cout<<" Noticieros"<<"\n";
        cout<<" Publicitarios"<<"\n";
        cout<<"2)Revistas:"<<"\n";
        cout<<" Ocio:"<<"\n";
        cout<<" Cientificas"<<"\n";
        cout<<" Especializadas"<<"\n";
        cout<<"0) Regresar"<<"\n";
        return ReadInt("Operacion");
    }
    
    void searchError()
    {
        cout<< "Objeto no encontrado"<<"\n";
    }
    
    void keyError()
    {
        cout<< "Comando incorrecto, vuelva a intentar"<<"\n";
    }
    void PagarCredito(CarritoCompras<Publicaciones*> *compras)
    {
        string name; string numeroTarjeta; string fake;
        cout<<"Visa o Mastercard: ";
        cin>>fake;
        cout<<"Ingrese el nombre del tarjethabiente: ";
        cin>>name;
        cout<<"Ingresa el numero de la Tarjeta: ";
        cin>>numeroTarjeta;
        cout<<"Ingresa el codigo de seguridad:(Parte trasera de la tarjeta)";
        cin>>fake; cout<<"\n";
        compras->PagarCredito(name, numeroTarjeta);
    }
    void PagarDebito(CarritoCompras<Publicaciones*> *compras)
    {
        string name; string numeroTarjeta; string fake;
        cout<<"Visa o Mastercard: ";
        cin>>fake;
        cout<<"Ingrese el nombre del tarjethabiente: ";
        cin>>name; 
        cout<<"Ingresa el numero de la Tarjeta: ";
        cin>>numeroTarjeta;
        cout<<"Ingresa el codigo de seguridad:(Parte trasera de la tarjeta)";
        cin>>fake; cout<<"\n";
        compras->PagarDebito(name, numeroTarjeta);
    }
    void PagarEfectivo(CarritoCompras<Publicaciones*> *compras)
    {
        string fake;
        cout<<"Escriba su Nombre: ";
        cin>>fake; 
        cout<<"Ingrese su Numero Telefonico: ";
        cin>>fake; cout<<"\n";
        compras->PagarEfectivo();
    }
    
};


/*
 
 
 */

