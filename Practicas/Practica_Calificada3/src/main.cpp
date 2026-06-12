#include <iostream>
#include <string>
#include <vector>
#include "solution.h"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::string> ops(n);
    std::vector<int> xs(n);
    std::vector<int> ys(n);

    std::vector<int> xsParaComprimir;

    for (int i = 0; i < n; i++) {
        std::cin >> ops[i] >> xs[i] >> ys[i];
        if (ops[i] == "add") {
            xsParaComprimir.push_back(xs[i]);
        }
    }

    PointsEficiente solver(xsParaComprimir);

    for (int i = 0; i < n; i++) {
        if (ops[i] == "add") {
            solver.add(xs[i], ys[i]);
        } else if (ops[i] == "remove") {
            solver.remove(xs[i], ys[i]);
        } else {
            Point r = solver.find(xs[i], ys[i]);
            if (r.x == -1) {
                std::cout << "-1\n";
            } else {
                std::cout << r.x << " " << r.y << "\n";
            }
        }
    }

    return 0;
}