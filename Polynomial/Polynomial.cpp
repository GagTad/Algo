#include <iostream>
#include <vector>
#include <map>
#include <cmath> 


void SolveAndPrintPolynomial(const std::vector<pair<int, int>>& inputTerms) {
    std::map<int, int, greater<int>> polyMap;

    for (const auto& term : inputTerms) {
        polyMap[term.first] += term.second;
    }

    std::cout << " Polynomial: ";

    bool isFirst = true;
    bool isEmpty = true; 

    for (const auto& [deg, coef] : polyMap) {
        if (coef == 0) continue;

        isEmpty = false;

        if (!isFirst) {
            if (coef > 0) std::cout << " + ";
            else cout << " - ";
        } else {
            if (coef < 0) std::cout << "-";
        }
        
        int absCoef = abs(coef);

        if (deg == 0 || absCoef != 1) {
            std::cout << absCoef;
        }

        if (deg > 0) {
            cout << "x";
            if (deg > 1) {
                std::cout << "^" << deg;
            }
        }

        isFirst = false;
    }

    if (isEmpty) {
        std::cout << "0";
    }

    std::cout << std::endl;
}

int main() {

    std::vector<pair<int, int>> terms = {
        {2, 3}, {4, 5}, {8, 2}, {4, -1}, {0, 7}, {0, -5}, {1, -1}
    };

    SolveAndPrintPolynomial(terms);

    return 0;
}
