#define SIN_ELEMENTOS -1

template <typename T /*= int*/>
Pila<T>::Pila() // Como ahora la clase es una plantilla de clase, hay que ponerle Pila<T>
{
    capacidad = 0;
    tope = SIN_ELEMENTOS;
    elemento = nullptr;
}

//***********************************

template <typename T>
void Pila<T>::Agregar(T valor)
{
    if( EstaLlena() ){
        throw "Pila llena";
    }
    ++tope;
    elemento[tope] = valor;

    //elemento[++tope] = valor;
}

//***********************************

template <typename T>
void Pila<T>::Eliminar()
{
    if(EstaVacia()){
        //throw "Pila vac\241a";
        throw PilaVacia(); // Eso es una llamada EXPLICITA al constructor de la clase "PilaVacia"
    }
    --tope;
    //elemento[tope];
}

//***********************************

template <typename T>
T Pila<T>::ObtenerTope() const
{
    if(EstaVacia()){
        //throw "Pila vac\241a";
        throw PilaVacia();
    }
    return elemento[tope];
}

//***********************************

template <typename T>
bool Pila<T>::EstaVacia() const
{
    if(tope == SIN_ELEMENTOS){
        return true;
    }

    return false;
}

//***********************************

template <typename T>
bool Pila<T>::EstaLlena() const
{
    if(tope == capacidad-1){
        return true;
    }

    return false;
}

//***********************************

template <typename T>
void Pila<T>::Vaciar()
{
    tope = SIN_ELEMENTOS;
}

//***********************************

template <typename T>
int Pila<T>::ObtenerTam() const
{
    return tope +1;
}

//***********************************

template <typename T>
void Pila<T>::Imprimir() const
{
    std::cout << "tope -> ";
    for(int i = tope ; i >= 0 ; --i){
        std::cout << elemento[i] << ", ";
    }
    if(!EstaVacia()) std::cout << "\b\b" << std::endl;
}

//***********************************
// Implementación de la clase PilaVacia
//***********************************

template <typename T>
Pila<T>::PilaVacia::PilaVacia() throw() /*: mensaje("La pila se encuentra vac\241a")*/{}

//***********************************

template <typename T>
const char *Pila<T>::PilaVacia::what() const throw()
{
    return "La pila se encuentra vac\241a";
}

//***********************************
// Amiguitas de la plantilla de clase Pila<T>
//***********************************

template <typename TT>
std::ostream & operator<<(std::ostream & salida, const Pila<TT> &pila)
{
    salida << "[ ";
    for(int i = pila.tope ; i >= 0 ; --i){
        salida << pila.elemento[i] << ", ";
    }
    if(!pila.EstaVacia()){
        salida << "\b\b ]";
    }

    return salida;
}


