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

    std::cout << "\n... La construcción y destrucción OK ..." << std::endl;
    return 0;
}