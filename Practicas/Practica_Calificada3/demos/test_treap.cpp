#include "treap.h"
#include <cassert>
#include <iostream>

int main() {    
    {
        Treap t;
        assert(t.successor(5) == -1);
        assert(t.successor(0) == -1);
        std::cout << "Caso 1 OK: Treap vacio devuelve -1 en successor" << std::endl;
    }

    {
        Treap t;
        t.insert(10);
        assert(t.successor(9) == 10);
        assert(t.successor(10) == -1);
        assert(t.successor(5) == 10);
        std::cout << "Caso 2 OK: Insercion individual y successor correcto" << std::endl;
    }
    
    {
        Treap t;
        t.insert(5);
        t.insert(10);
        t.insert(3);
        t.insert(7);
        t.insert(15);

        assert(t.successor(0) == 3);
        assert(t.successor(3) == 5);
        assert(t.successor(4) == 5);
        assert(t.successor(7) == 10);
        assert(t.successor(10) == 15);
        assert(t.successor(15) == -1);
        assert(t.successor(100) == -1);
        std::cout << "Caso 3 OK: Successor correcto con multiples claves" << std::endl;
    }

    {
        Treap t;
        t.insert(5);
        t.insert(10);
        t.insert(15);
        assert(t.successor(7) == 10);
        t.erase(10);

        assert(t.successor(7) == 15);
        assert(t.successor(5) == 15);
        std::cout << "Caso 4 OK: Erase elimina correctamente el valor" << std::endl;
    }

    {
        Treap t;
        for (int i = 1; i <= 100; i++) {
            t.insert(i);
        }
        assert(t.successor(0) == 1);
        assert(t.successor(50) == 51);
        assert(t.successor(99) == 100);
        assert(t.successor(100) == -1);
        std::cout << "Caso 5 OK: Insercion ordenada de 100 valores funciona" << std::endl;
    }

    {
        Treap t;
        for (int i = 1; i <= 50; i++) {
            t.insert(i * 2);
        }
        
        assert(t.successor(5) == 6);
        
        t.erase(6);
        assert(t.successor(5) == 8);
        
        for (int i = 1; i <= 25; i++) {
            t.erase(i * 4);
        }
                
        assert(t.successor(1) == 2);
        std::cout << "Caso 6 OK: Insercion y borrado alternados funcionan" << std::endl;
    }

    std::cout << "\n... Todos los test pasaron ..." << std::endl;
    return 0;
}