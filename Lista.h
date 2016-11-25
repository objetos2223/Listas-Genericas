#ifndef LISTA_H
#define LISTA_H

#include <iostream>

/* declaración adelantada para que el Nodo conozca a la Lista */
template <typename TipoGen> class Lista;

/* El nodo es una plantilla (template) de tipo genérico */
template <typename TipoGen>
class Nodo
{
private:
    TipoGen dato;  /* el dato es de tipo genérico */
    Nodo<TipoGen> *sig;
    friend class Lista<TipoGen>; /* amistad de clases */
public:
    Nodo(TipoGen d, Nodo<TipoGen> *s = 0) : dato(d), sig(s) {}
};

/* La lista es una plantilla de tipo genérico porque tiene
   un apuntador a un nodo genérico */
template <typename TipoGen>
class Lista
{
public:
    Lista()
    {
        cab = 0;
        std::cout << "Constructor por omisión\n";
    }
    
    Lista(const Lista& otra)
    {
        std::cout << "Constructor de copia\n";
        this->copiar(otra);
    }
    
    void copiar(const Lista& otra)
    {
        this->cab = 0;
        Nodo<TipoGen> *aux = otra.cab;
        Nodo<TipoGen> *ult = 0;
        while (aux != 0)    {
            Nodo<TipoGen> *nuevo = new Nodo<TipoGen>(aux->dato);
            if (this->cab == 0)  {
                this->cab = nuevo;
                ult = nuevo;
            }
            else    {
                ult->sig = nuevo;
                ult = nuevo;
            }
            aux = aux->sig;
        }
    }

    Lista operator+(const Lista& otra)
    {
        // concatenar esta lista con otra y regresar una nueva
        Lista resultado;
        
        // agregar la información de esta lista al resultado
        resultado.copiar(*this);
        if (resultado.cab == 0) {
            resultado.copiar(otra);
        }
        else    {
            // agregar la información de otra lista al resultado
            Nodo<TipoGen> *ult = resultado.cab;
            while (ult->sig != 0)   {
                ult = ult->sig;
            }
            Nodo<TipoGen> *aux = otra.cab;
            while (aux != 0)    {                
                Nodo<TipoGen> *nuevo = new Nodo<TipoGen>(aux->dato);
                ult->sig = nuevo;
                ult = nuevo;
                aux = aux->sig;
            }
        }
        return resultado;
    }
    
    // TAREA: sobrecargar el operador de asignación (operator=)
    const Lista& operator=(const Lista& otra)
    {
        this->libera();
        this->copiar(otra);
        return otra;
    }

    ~Lista()
    {
        this->libera();
    }
    
    void libera()
    {
        Nodo<TipoGen> *aux = cab;
        while (aux != 0)    {
            aux = aux->sig;
            delete cab;
            cab = aux;
        }
    }
    
    void insertaInicio(TipoGen dato)
    {
        cab = new Nodo<TipoGen>(dato, cab);
    }
    
    void imprime()
    {
        Nodo<TipoGen> *aux = cab;
        while (aux != 0)    {
            std::cout << aux->dato << "->";
            aux = aux->sig;
        }
        std::cout << std::endl;
    }
private:
    Nodo<TipoGen> *cab;
};

#endif // LISTA_H
