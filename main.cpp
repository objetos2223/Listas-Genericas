#include "Lista.h"

template <typename Tipo>
void prueba(Lista<Tipo> unaLista)
{
    unaLista.imprime();
}

int main(int argc, char **argv)
{
    Lista<int> enteros;
    Lista<float> flotantes;
    
    enteros.insertaInicio(3);
    enteros.insertaInicio(5);
    enteros.insertaInicio(7);

    {
        Lista<int> a, b;
    
        a = b = enteros;
        
        Lista<int> c = a + b;
    
        a.imprime();
        b.imprime();
        c.imprime();
    }
    enteros.imprime();
    
    flotantes.insertaInicio(3.1416);
    flotantes.insertaInicio(123.456);
    flotantes.insertaInicio(2.77);
	return 0;
}
