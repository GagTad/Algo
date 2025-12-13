#include <iostream>
#include <vector>
#include <climits>

std::vector<std::vector<int>> s;

void printOptimalParens(int i, int j) {
    if (i == j) {
        std::cout << "A" << i;
    } else {
        std::cout << "(";
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        std::cout << ")";
    }
}

void matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;
    std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1));
    s.assign(n + 1, std::vector<int>(n + 1));
    
    for (int L = 2; L <= n; L++) { 
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);

                if (q < m[i][j]) {
                    m[i][j] = q;   
                    s[i][j] = k;   
                }
            }
        }
    }

    std::cout << "Minimum Cost: " << m[1][n] << std::endl;
    std::cout << "Optimal Order: ";
    printOptimalParens(1, n);
    std::cout << endl;
}

int main() {
    // A1(10x30), A2(30x5), A3(5x60)
    vector<int> arr = {10, 30, 5, 60};

    cout << "Input Dimensions: ";
    for (int x : arr) cout << x << " ";
    std::cout << std::endl;

    matrixChainOrder(arr);

    return 0;
}
