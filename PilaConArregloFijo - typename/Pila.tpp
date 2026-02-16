#define SIN_ELEMENTOS -1

template <typename T, int tam>
Pila<T, tam>::Pila() // Como ahora la clase es una plantilla de clase, hay que ponerle Pila<T>
{
    tope = SIN_ELEMENTOS;
}

//***********************************

template <typename T, int tam>
void Pila<T, tam>::Agregar(T valor)
{
    if( EstaLlena() ){
        throw "Pila llena";
    }
    ++tope;
    elemento[tope] = valor;

    //elemento[++tope] = valor;
}

//***********************************

template <typename T, int tam>
void Pila<T, tam>::Eliminar()
{
    if(EstaVacia()){
        //throw "Pila vac\241a";
        throw PilaVacia(); // Eso es una llamada EXPLICITA al constructor de la clase "PilaVacia"
    }
    --tope;
    //elemento[tope];
}

//***********************************

template <typename T, int tam>
T Pila<T, tam>::ObtenerTope() const
{
    if(EstaVacia()){
        //throw "Pila vac\241a";
        throw PilaVacia();
    }
    return elemento[tope];
}

//***********************************

template <typename T, int tam>
bool Pila<T, tam>::EstaVacia() const
{
    if(tope == SIN_ELEMENTOS){
        return true;
    }

    return false;
}

//***********************************

template <typename T, int tam>
bool Pila<T, tam>::EstaLlena() const
{
    if(tope == MAX_TAM-1){
        return true;
    }

    return false;
}

//***********************************

template <typename T, int tam>
void Pila<T, tam>::Vaciar()
{
    tope = SIN_ELEMENTOS;
}

//***********************************

template <typename T, int tam>
int Pila<T, tam>::ObtenerTam() const
{
    return tope +1;
}

//***********************************

template <typename T, int tam>
void Pila<T, tam>::Imprimir() const
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

template <typename T, int tam>
Pila<T, tam>::PilaVacia::PilaVacia() throw() /*: mensaje("La pila se encuentra vac\241a")*/{}

//***********************************

template <typename T, int tam>
const char *Pila<T, tam>::PilaVacia::what() const throw()
{
    return "La pila se encuentra vac\241a";
}

//***********************************
// Amiguitas de la plantilla de clase Pila<T>
//***********************************

template <typename TT, int ttam>
std::ostream & operator<<(std::ostream & salida, const Pila<TT, ttam> &pila)
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


