#pragma once
#include <iostream>

template <class Y>
class List
{
private:
    Y* list;
    int length;
    int numElems = 0;
    int nextFree = 0;
public:
    List();                     //Constructor sin parametro
    List(int length);           //Constructor con parametro
    List(const List& original); //Constructor copia
    ~List();                    //Destructor
    int getLength();
    void ChangeSize(Y*& S, int size);
    void AddElement(Y element);
    Y& operator [](int index);
    
    void BubbleSort();
    void BubbleSortInverso();
    
    void PrintAllPrice();
    void PrintAll();
    void PrintAllList(bool adminView);
    
    void PrintSamePrimaryKey(short primaryKey);
    void DeleteLastElement();
    void DeleteElement(int posicion);
    void RecorrerElements();
    
    template <class Param, class Func>
    void PrintElement(Param value, Func metodo) //Busca por lo que le digas y lo imprime si lo encuentra
    {
        int index = search(value,metodo);
        if (index == -1)
        {   std::cout<< "No se encontro objeto con ese nombre"<<"\n";
            return;
        }
        list[index]->print();
    }
    template <class Param, class Func>
    void PrintAllElements(Param value, Func metodo)
    {
        for (int i = 0; i<length; ++i)
        {
            if(list[i] == nullptr)
                continue;
            if((list[i]->*metodo)() == value)
                list[i]->print();
        }
    }
    void PrintAllElements()
    {
        for (int i = 0; i<length; ++i)
        {
            if(list[i] == nullptr)
                continue;
            list[i]->print();
        }
    }
    template <class Param, class Func>
    void Ventas(Param value, Func metodo)
    {
        for (int i = 0; i<length; ++i)
        {
            if(list[i] == nullptr)
                continue;
            if((list[i]->*metodo)() == value)
            {
                list[i]->printVentas();
            }
        }
    }
    template <class Param, class Func>
    int search(Param value, Func metodo) //Returns index
    {
        for (int i = 0; i < numElems; i++)
        {
            if(list[i] == nullptr)
                continue;
            if ((list[i]->*metodo)() == value)
            {
                return i;
            }
        }
        return -1;
    }
/////////////////////MI TIENDA
    void Abastecer(int carga, int index);
    void PrintGanancias();
    void EliminarCaducados();
    void PrintVentasTotales();
    
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// Aqui es el cpp

template <class Y>
void List<Y>::RecorrerElements()
{
    for (int i = 0; i<length-1; ++i)
    {
        if (list[i] == nullptr && list[i+1] != nullptr)
        {
            list[i] = list[i+1];
            list[i+1] = nullptr;
        }
    }
}

template <class Y>
void List<Y>::PrintVentasTotales()
{
    int ventas = 0;
    for (int i = 0; i<length; ++i)
    {
        if (list[i] == nullptr)
            continue;
            list[i]->printVentas();
            ventas = ventas + list[i]->getVentas();
    }
    std::cout<<"Ventas totales: "<<ventas<<"\n";
}
template <class Y>
void List<Y>::EliminarCaducados()
{
    for (int i = 0; i<length; ++i)
    {
        if (list[i] == nullptr)
            continue;
        if(list[i]->caducado)
        {
            std::cout<<"Caducó "<<list[i]->getTitulo()<<"\n";
            DeleteElement(i);
        }
    }
    std::cout<<"Se han eliminado todos los productos caducados"<<"\n";
}

template <class Y>
void List<Y>::PrintGanancias() //NextFree
{
    double balance = 0;
    for (int i = 0; i<length; ++i)
    {
        if (list[i] == nullptr)
            continue;
        list[i]->printPrice();
        std::cout<<"Almacen Inicio: "<<list[i]->getCompradosInicio()<<
        " ,se han vendido "<<list[i]->getVentas()<<"\n";
        balance = balance + list[i]->getBalance();
    }
    std::cout<<"El saldo es de "<<balance<<"\n";
}

template <class Y>
void List<Y>::Abastecer(int carga, int index) //NextFree
{
    list[index]->abastecer(carga);
}

template <class Y>
void List<Y>::AddElement(Y element) //NextFree
{
    if (nextFree == (length))
        return;
    list[nextFree] = element;
    ++nextFree;
    ++numElems;
}

template <class Y>
void List<Y>::DeleteLastElement() 
{
    if(numElems>0)
    {
     list[numElems-1] = nullptr;
        --numElems;
        --nextFree;
    }
}

template <class Y>
Y& List<Y>::operator[](int index) //SetGet
{
    return *(list+index);
}

template <class Y>
List<Y>::List() //Constructor sin Param
{
    list= new Y[10];
    length = 10;
}

template <class Y>
List<Y>::List(int length) //Constructor con Param
{
    list= new Y[length];
    this->length = length;
}

template <class Y>
List<Y>::List(const List& original) //Constructor Copia
{
    list= new Y[original.GetLength()];
    this->length = original.GetLength();
    numElems = 0;
}

template <class Y>
int List<Y>::getLength()
{
    return length;
}

template <class Y>
List<Y>::~List() //Destructor
{
    delete []list;
}


template <class Y> //Se manda a llamar como ChangeSize(&Arreglo);
void List<Y> :: ChangeSize(Y*& s, int newSize)
{
    delete [] s;
    s = new Y[newSize];
}

template <class Y>
void List<Y>::DeleteElement(int posicion)
{
    list[posicion] = nullptr;
    --numElems;
    RecorrerElements();
}
/*
template <class Y>
void List<Y>::BubbleSort()  //implementado para Año, Coches Menor a Mayor
{   bool done = false;
    Y temp;
    
    while (done == false)
    {
        for (int i = 0; i<numElems-1; ++i)
        {
            
            if( list[i]->GetAño() < list[i+1]->GetAño())
            {
                temp = *(list+i);
                *(list+i) = *(list+i+1);
                *(list+i+1) = temp;
                done = false;
                break;
            }
        done = true;
        }
    }
}

template <class Y>
void List<Y>::BubbleSortInverso()
{   bool done = false;
   
    
    while (done == false)
    {
        for (int i = 0; i<numElems-1; ++i)
        {
            if( list[i]->getPrecio() > list[i+1]->getPrecio())
            {
                temp = *(list+i);
                *(list+i) = *(list+i+1);
                *(list+i+1) = temp;
                done = false;
                break;
            }
            done = true;
        }
    }
}*/
template <class Y>
void List<Y>::PrintAll()
{
    for (int i = 0; i<numElems; ++i)
    {
        if (list[i] == nullptr)
            continue;
        list[i]->print();
    }
}
template <class Y>
void List<Y>::PrintAllPrice()
{
    for (int i = 0; i<numElems; ++i)
    {
        if (list[i] == nullptr)
            continue;
        list[i]->printPrice();
    }
}
template <class Y>
void List<Y>::PrintAllList(bool adminView)
{
    if(adminView)
    {
        for (int i = 0; i<numElems; ++i)
        {
            if (list[i] == nullptr)
                continue;
            std::cout<<i+1<<") "<<list[i]->getTitulo()<<"\n";
        }
    }
    else
    {
        for (int i = 0; i<numElems; ++i)
        {
            if (list[i] == nullptr||list[i]->getCaducado()||list[i]->getDisponibles() <= 0)
                continue;
            std::cout<<i+1<<") "<<list[i]->getTitulo()<<"\n";
        }
    }
}

template <class Y>
void List<Y>::PrintSamePrimaryKey(short primaryKey) //1) Print
{   for (int i = 0; i<numElems; ++i)
    {
        if (list[i] == nullptr||list[i]->getCaducado()||list[i]->getDisponibles() <= 0)
            continue;
        if(primaryKey == list[i]->primaryKey)
        {   std::cout<<"    "<<i+1<<") ";
            list[i]->printPrice();
        }
    }
}