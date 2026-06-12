#include "segment_treap.h"
#include <cassert>
#include <iostream>

int main() {
    {
        SegmentTreap st(8);
        std::cout << "Caso 1 OK: SegmentTreap con n=8 construido y destruido" << std::endl;
    }

    {
        SegmentTreap st(1);
        std::cout << "Caso 2 OK: SegmentTreap con n=1 construido y destruido" << std::endl;
    }

    {
        SegmentTreap st(200000);
        std::cout << "Caso 3 OK: SegmentTreap con n=200000 construido y destruido" << std::endl;
    }

    {
        SegmentTreap st(8);
        st.insertar(0, 100);
        st.insertar(3, 50);
        st.insertar(7, 200);
        st.insertar(3, 75);
        std::cout << "Caso 4 OK: Insertar varios puntos sin crash" << std::endl;
    }

    {
        SegmentTreap st(8);
        st.insertar(0, 100);
        st.insertar(3, 50);
        st.insertar(7, 200);
        st.borrar(0, 100);
        st.borrar(3, 50);
        st.insertar(5, 25);
        st.borrar(5, 25);
        std::cout << "Caso 5 OK: Insertar y borrar varios puntos sin crashear" << std::endl;
    }

    {
        SegmentTreap st(10);

        st.insertar(1, 50);
        st.insertar(3, 80);
        st.insertar(5, 30);
        st.insertar(7, 90);
        st.insertar(9, 20);

        int r1 = st.consultar(0, 25);
        std::cout << "consultar(0, 25) = " << r1 << " (esperado: 1)" << std::endl;
        assert(r1 == 1);

        int r2 = st.consultar(3, 25);
        std::cout << "consultar(3, 25) = " << r2 << " (esperado: 5)" << std::endl;
        assert(r2 == 5);

        int r3 = st.consultar(5, 50);
        std::cout << "consultar(5, 50) = " << r3 << " (esperado: 7)" << std::endl;
        assert(r3 == 7);

        int r4 = st.consultar(7, 50);
        std::cout << "consultar(7, 50) = " << r4 << " (esperado: -1)" << std::endl;
        assert(r4 == -1);

        st.borrar(3, 80);

        int r5 = st.consultar(0, 70);
        std::cout << "consultar(0, 70) despues de borrar (3, 80) = " << r5 << " (esperado: 7)" << std::endl;
        assert(r5 == 7);

        std::cout << "Caso 6 OK: consultar funciona correctamente" << std::endl;
    }

    std::cout << "\n... La construcción y destrucción OK ..." << std::endl;
    return 0;
}