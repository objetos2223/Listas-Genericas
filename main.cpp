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
    Lista<Lista<std::string> > listaListas;
    
    enteros.insertaInicio(3);
    enteros.insertaInicio(5);
    enteros.insertaInicio(7);
    prueba(enteros);
    enteros.imprime();
    
    flotantes.insertaInicio(3.1416);
    flotantes.insertaInicio(123.456);
    flotantes.insertaInicio(2.77);
    prueba(flotantes);
    flotantes.imprime();
	return 0;
}
