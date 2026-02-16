#include <iostream>

#include "Pila.hpp"

#define SIN_ELEMENTOS -1

Pila::Pila()
{
    tope = SIN_ELEMENTOS;
}

//***********************************

void Pila::Agregar(int valor)
{
    if( EstaLlena() ){
        throw "Pila llena";
    }
    ++tope;
    elemento[tope] = valor;

    //elemento[++tope] = valor;
}

//***********************************

void Pila::Eliminar()
{
    if(EstaVacia()){
        //throw "Pila vac\241a";
        throw PilaVacia(); // Eso es una llamada EXPLICITA al constructor de la clase "PilaVacia"
    }
    --tope;
    //elemento[tope];
}

//***********************************

int Pila::ObtenerTope() const
{
    if(EstaVacia()){
        //throw "Pila vac\241a";
        throw PilaVacia();
    }
    return elemento[tope];
}

//***********************************

bool Pila::EstaVacia() const
{
    if(tope == SIN_ELEMENTOS){
        return true;
    }

    return false;
}

//***********************************

bool Pila::EstaLlena() const
{
    if(tope == MAX_TAM-1){
        return true;
    }

    return false;
}

//***********************************

void Pila::Vaciar()
{
    tope = SIN_ELEMENTOS;
}

//***********************************


int Pila::ObtenerTam() const
{
    return tope +1;
}

//***********************************

void Pila::Imprimir() const
{
    std::cout << "(";
    for(int i = tope ; i >= 0 ; --i){
        std::cout << elemento[i] << ", ";
    }
    if(!EstaVacia()) std::cout << "\b\b)" << std::endl;
}

//***********************************
// Implementación de la clase PilaVacia
//***********************************

Pila::PilaVacia::PilaVacia() throw() /*: mensaje("La pila se encuentra vac\241a")*/{}

//***********************************

//const char *Pila::PilaVacia::QuePaso() const throw()
//{
//    return "La pila se encuentra vac\241a";
//}

const char *Pila::PilaVacia::what() const throw()
{
    return "La pila se encuentra vac\241a";
}

