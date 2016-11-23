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
    }
    ~Lista()
    {
        // pendiente: liberar cada uno de los nodos
        // tarea: libear cada nodo con delete
    }
    
    void insertaInicio(TipoGen dato)
    {
        cab = new Nodo<TipoGen>(dato, cab);
    }
    
    void imprime()
    {
        Nodo<TipoGen> *aux = cab;
        while (aux != 0)    {
            std::cout << aux->dato << std::endl;
            aux = aux->sig;
        }
    }
private:
    Nodo<TipoGen> *cab;
};

#endif // LISTA_H
