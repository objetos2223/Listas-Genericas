#include "Lista.h"

int main(int argc, char **argv)
{
    Lista<int> enteros;
    Lista<float> flotantes;
    Lista<Lista<std::string> > listaListas;
    
    enteros.insertaInicio(3);
    enteros.insertaInicio(5);
    enteros.insertaInicio(7);
    enteros.imprime();
    
    flotantes.insertaInicio(3.1416);
    flotantes.insertaInicio(123.456);
    flotantes.insertaInicio(2.77);
    flotantes.imprime();
	return 0;
}
