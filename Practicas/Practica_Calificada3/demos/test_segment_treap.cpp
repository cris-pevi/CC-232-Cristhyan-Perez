#include "segment_treap.h"
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

    std::cout << "\n... La construcción y destrucción OK ..." << std::endl;
    return 0;
}