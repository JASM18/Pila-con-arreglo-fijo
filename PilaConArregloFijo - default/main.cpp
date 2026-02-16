#include <iostream>
#include "Pila.hpp"

using namespace std;

int main()
{
    try{
        Pila A;

        cout << A.ObtenerTope() << endl;

        A.Imprimir();

        for(int i = 0 ; i < 5 ; ++i){
            A.Agregar(i);
        }
        cout << endl;
        A.Imprimir();


    /*}catch(const char *error){
        cerr << "Error: " << error << endl;*/
    }catch(Pila::PilaVacia &errorVacio){
        //cerr << "Error: " << errorVacio.QuePaso() << endl;
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado" << endl;
    }

    return 0;
}
