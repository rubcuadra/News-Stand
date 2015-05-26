#include <iostream>
#include "List.h"
#include "UserInterface.h"
#include "Publicaciones.h"
#include "Cientifica.h"
#include "Especializadas.h"
#include "Periodicos.h"
#include "Noticiero.h"
#include "Publicitario.h"
#include "Revistas.h"
#include "Ocio.h"
#include "CarritoCompras.h"

int main() //tecla 0 haga back
{
    Publicaciones *Reforma = new Noticiero("Grupo Reforma",
                                           "Periodico Reforma",
                                           "Mexico",
                                           10, //Secciones
                                           2016,04,30, //Año
                                           31,  //Paginas
                                           100, //Disponibles
                                           2,     //Me cuesta
                                           10);   //Lo vendo
    
    Publicaciones *NYTimes = new Noticiero("NYT Company",
                                           "New York Times",
                                           "Nueva York",
                                           18, //Secciones
                                           2016,04,30, //Año
                                           40,  //Paginas
                                           20, //Disponibles
                                           10,     //Me cuesta
                                           30);   //Lo vendo)
    Publicaciones *Publimetro = new Publicitario("Metro International",
                                           "Publimetro",
                                           "Metro S.A.",
                                           3, //Secciones
                                           2016,04,30, //Año
                                           10,  //Paginas
                                           200, //Disponibles
                                           -5);     //Me Pagan 5 por cada periodico
     
    Publicaciones *TVNotas = new Ocio(     "Grupo NOTMUSA",
                                           "TV Notas",
                                           "la farandula", //Tema
                                           2016,04,30, //Año
                                           33,  //Paginas
                                           80, //Disponibles
                                           15,     //Me cuesta
                                           35);   //Lo vendo)
    Publicaciones *EresNiño = new Ocio("Televisa",
                                      "EresNiño",
                                      "Niños", //Tema
                                      2016,04,30, //Año
                                      10,  //Paginas
                                      50, //Disponibles
                                      12,     //Me cuesta
                                      40);   //Lo vendo)
    Publicaciones *Vogue = new Ocio("Conde Nast",
                                      "Vogue",
                                      "Moda", //Tema
                                      2016,04,30, //Año
                                      40,  //Paginas
                                      50, //Disponibles
                                      20,     //Me cuesta
                                      50);   //Lo vendo)
    
    Publicaciones *QUO = new Cientifica("Hearst",
                                      "QUO",
                                      "Biotecnologia", //Tema
                                      2016,04,30, //Año
                                      40,  //Paginas
                                      30, //Disponibles
                                      20,     //Me cuesta
                                      90);   //Lo vendo)
    Publicaciones *laLey = new Especializadas("Wolters Kluwer",
                                        "La ley",
                                        "Derecho", //Tema
                                        2016,04,30, //Año
                                        80,  //Paginas
                                        10, //Disponibles
                                        90,     //Me cuesta
                                        200);   //Lo vendo)
    Publicaciones *Forbes = new Especializadas("BC Forbes",
                                              "Forbes",
                                              "Economia", //Tema
                                              2015,05,30, //Año
                                              80,  //Paginas
                                              10, //Disponibles
                                              90,     //Me cuesta
                                              200);   //Lo vendo)
    Publicaciones *GraffitiArt = new Especializadas("Ink Inc",
                                              "GraffitiArt",
                                              "Arte Urbano", //Tema
                                              2014,05,30, //Año
                                              80,  //Paginas
                                              10, //Disponibles
                                              90,     //Me cuesta
                                              200);   //Lo vendo)
    
    List<Publicaciones*> almacen(10);
    UserInterface* UI = new UserInterface();
    CarritoCompras<Publicaciones*> carritoCompras;
    almacen.AddElement(Reforma);    almacen.AddElement(NYTimes);
    almacen.AddElement(Publimetro); almacen.AddElement(TVNotas);
    almacen.AddElement(EresNiño);   almacen.AddElement(Vogue);
    almacen.AddElement(QUO);        almacen.AddElement(laLey);
    almacen.AddElement(Forbes);     almacen.AddElement(GraffitiArt);
    
    bool exit = false;  int busqueda;
    
try {
    while (exit == false)
{
    switch (UI->UserType())
    {
            
            
        case 0:
            exit = true;
            break;
        case 1:
            switch (UI->AdminMenu())
            {
                case 0:
                    break;
                case 1:
                    switch(UI->AbastecerMenu())
                {
                    case 0:
                        break;
                    case 1:
                        busqueda = UI->searchNombre(&almacen);
                        if(busqueda < 0)
                        {UI->searchError(); break;}
                        else
                        {
                            almacen[busqueda]->printPrice();
                            almacen[busqueda]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                        }
                        break;
                    case 2:
                        switch(UI->PeriodicosMenu(&almacen))
                    {
                        case 0:
                            break;
                        case 1: //Reforma
                            almacen[0]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 2: //NY times
                            almacen[1]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 3: //Publimetro
                            almacen[2]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        default:
                            UI->keyError();
                            break;
                    }
                        break;
                    case 3:
                        switch(UI->RevistasMenu(&almacen))
                    {
                        case 0:
                            break;
                        case 3: //TVNOTAS
                            almacen[2]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 4: //ERESNIÑO
                            almacen[3]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 5: //VOGUE
                            almacen[4]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 6: //QUO
                            almacen[5]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 7: //LaLey
                            almacen[6]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 8: //Forbes
                            almacen[7]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 9: //Forbes
                            almacen[8]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        case 10: //GrafittiArt
                            almacen[9]->abastecer(UI->ReadInt("Cantidad a abastecer"));
                            break;
                        default:
                            UI->keyError();
                            break;
                    }
                        break;
                    case 4:
                        almacen.EliminarCaducados();
                        break;
                    default:
                        UI->keyError();
                        break;
                }
                    break;
                case 2:
                    switch(UI->estadoCuentaMenu())
                {
                    case 0:
                        break;
                    case 1:
                        switch (UI->categoriasMenu())
                        {
                            case 0:
                                break;
                            case 1://Ventas de Periodicos
                                almacen.Ventas(0, &Publicaciones::getPK);
                                almacen.Ventas(1, &Publicaciones::getPK);
                                break;
                            case 2://Ventas de Revistas
                                almacen.Ventas(2, &Publicaciones::getPK);
                                almacen.Ventas(3, &Publicaciones::getPK);
                                almacen.Ventas(4, &Publicaciones::getPK);
                                break;
                            default:
                                UI->keyError();
                                break;
                        }
                        break;
                    case 2:
                        switch (UI->catalogoMenu(&almacen,true)) //Vista del Admin
                        {
                            case 0:
                                break;
                            case 1:
                                almacen[0]->printVentas();
                                break;
                            case 2:
                                almacen[1]->printVentas();
                                break;
                            case 3:
                                almacen[2]->printVentas();
                                break;
                            case 4:
                                almacen[3]->printVentas();
                                break;
                            case 5:
                                almacen[4]->printVentas();
                                break;
                            case 6:
                                almacen[5]->printVentas();
                                break;
                            case 7:
                                almacen[6]->printVentas();
                                break;
                            case 8:
                                almacen[7]->printVentas();
                                break;
                            case 9:
                                almacen[8]->printVentas();
                                break;
                            case 10:
                                almacen[9]->printVentas();
                                break;
                            default:
                                UI->keyError();
                                break;
                        }
                        break;
                    case 3:
                        almacen.PrintVentasTotales();
                        break;
                    case 4:
                        almacen.PrintGanancias();
                        break;
                    default:
                        UI->keyError();
                        break;
                }
                    break;
                case 3:
                    switch (UI->inventarioMenu())
                {
                        case 0:
                            break;
                        case 1:
                        almacen.PrintAllElements();
                            break;
                        case 2:
                            switch (UI->categoriasMenu())
                            {
                                case 0:
                                    break;
                                case 1://Ventas de Periodicos
                                    almacen.PrintAllElements(0, &Publicaciones::getPK);
                                    almacen.PrintAllElements(1, &Publicaciones::getPK);
                                    break;
                                case 2://Ventas de Revistas
                                    almacen.PrintAllElements(2, &Publicaciones::getPK);
                                    almacen.PrintAllElements(3, &Publicaciones::getPK);
                                    almacen.PrintAllElements(4, &Publicaciones::getPK);
                                    break;
                                default:
                                    UI->keyError();
                                    break;
                            }
                            break;
                        case 3:
                            switch (UI->catalogoMenu(&almacen,true)) //Vista del admin
                            {
                                case 0:
                                    break;
                                case 1:
                                    almacen[0]->print();
                                    break;
                                case 2:
                                    almacen[1]->print();
                                    break;
                                case 3:
                                    almacen[2]->print();
                                    break;
                                case 4:
                                    almacen[3]->print();
                                    break;
                                case 5:
                                    almacen[4]->print();
                                    break;
                                case 6:
                                    almacen[5]->print();
                                    break;
                                case 7:
                                    almacen[6]->print();
                                    break;
                                case 8:
                                    almacen[7]->print();
                                    break;
                                case 9:
                                    almacen[8]->print();
                                    break;
                                case 10:
                                    almacen[9]->print();
                                    break;
                                default:
                                    UI->keyError();
                                    break;
                            }
                            break;
                        case 4:
                        cout<<"Caducados:"<<"\n";
                        almacen.PrintAllElements(true , &Publicaciones::getCaducado);
                            break;
                        default:
                            UI->keyError();
                            break;
                    }
                    break;
                default:
                    UI->keyError();
                    break;
            }
            break;
        case 2:
            switch (UI->ClienteMenu())
            {
                case 0:
                    break;
                case 1:
                    busqueda = UI->searchNombre(&almacen);
                    if(busqueda < 0)
                    {UI->searchError(); break;}
                    else
                    {
                        almacen[busqueda]->print();
                        carritoCompras.AddElement(almacen[busqueda], UI->ReadInt("Cantidad a comprar"));
                    }
                    break;
                case 2:
                    switch (UI->categoriasMenu())
                    {
                    case 0:
                        break;
                    case 1:
                        switch(UI->PeriodicosMenu(&almacen))
                    {
                        case 0:
                            break;
                        case 1: //Reforma
                            carritoCompras.AddElement(almacen[0], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 2: //NY times
                            carritoCompras.AddElement(almacen[1], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 3: //Publimetro
                            carritoCompras.AddElement(almacen[2], UI->ReadInt("Cantidad a comprar"));
                            break;
                        default:
                            UI->keyError();
                            break;
                    }
                        break;
                    case 2:
                        switch(UI->RevistasMenu(&almacen))
                    {
                        case 0:
                            break;
                        case 4: //QUO
                            carritoCompras.AddElement(almacen[3], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 5: //LaLey
                            carritoCompras.AddElement(almacen[4], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 6: //Forbes
                            carritoCompras.AddElement(almacen[5], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 7: //GrafittiArt
                            carritoCompras.AddElement(almacen[6], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 8: //GrafittiArt
                            carritoCompras.AddElement(almacen[7], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 9: //GrafittiArt
                            carritoCompras.AddElement(almacen[8], UI->ReadInt("Cantidad a comprar"));
                            break;
                        case 10: //GrafittiArt
                            carritoCompras.AddElement(almacen[9], UI->ReadInt("Cantidad a comprar"));
                            break;
                        default:
                            UI->keyError();
                            break;
                    }
                }
                    break;
                case 3: //Carrito de Compras
                    switch (UI->carritoMenu(&carritoCompras))
                    {
                        case 0:
                            break;
                        case 1: //Credito
                            UI->PagarCredito(&carritoCompras);
                            break;
                        case 2: //Debito 
                            UI->PagarDebito(&carritoCompras);
                            break;
                        case 3: //Efectivo, oxxo 
                            UI->PagarEfectivo(&carritoCompras);
                            break;
                        default:
                            UI->keyError();
                            break;
                    }
                    break;
                default:
                UI->keyError();
                    break;
        }
            break;
        default:
            UI->keyError();
            exit = true;
            break;
    }
}
    } catch (exception e)
        {
            cout<<"Error: "<<e.what()<<"\n";
        }
    cout<<"Gracias Vuelva Pronto!";
    return 0;
}
