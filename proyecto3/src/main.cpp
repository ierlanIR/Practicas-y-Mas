#include <iostream>
#include <ConjuntoVector.hpp>
#include <ConjuntoSet.hpp>
#include <ConjuntoUnorderedSet.hpp>
#include <cassert>


void PruebaIConjunto(IConjunto<int>& conjunto);

int main()
{
    // Prueba ConjuntoVector
    ConjuntoVector<int> conjunto;
    PruebaIConjunto(conjunto);
    std::cout << "Prueba ConjuntoVector OK" << std::endl;

    // Prueba ConjuntoSet
    ConjuntoSet<int> conjuntoSet;
    PruebaIConjunto(conjuntoSet);
    std::cout << "Prueba ConjuntoSet OK" << std::endl;

    // Prueba ConjuntoUnorderedSet
    ConjuntoUnorderedSet<int> conjuntoUnorderedSet;
    PruebaIConjunto(conjuntoUnorderedSet);
    std::cout << "Prueba ConjuntoUnorderedSet OK" << std::endl;
}

void PruebaIConjunto(IConjunto<int>& conjunto) {
conjunto.insertar(1);
conjunto.insertar(2);
conjunto.insertar(3);
assert(conjunto.pertenece(1));
assert(conjunto.pertenece(2));
assert(conjunto.pertenece(3));
assert(!conjunto.pertenece(4));
conjunto.insertar(2);
assert(conjunto.pertenece(2));
conjunto.eliminar(2);
assert(!conjunto.pertenece(2));
conjunto.eliminar(1);
assert(!conjunto.pertenece(1));
conjunto.insertar(2);
assert(conjunto.pertenece(2));
// Pruebas de sobrecarga de operadores
conjunto -= 21;
assert(!conjunto.pertenece(21));
conjunto += 21;
assert(conjunto.pertenece(21));
conjunto += 21;
assert(conjunto.pertenece(21));
conjunto -= 21;
assert(!conjunto.pertenece(21));
conjunto += 21;
assert(conjunto.pertenece(21));
}