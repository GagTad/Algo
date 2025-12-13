#include <iostream>
#include <vector>
#include <climits> 

int matrixChainMultiplication(const std::vector<int>& p) {
    int n = p.size() - 1; 
    std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1));
  
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
  
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n];
}

int main() {
  //10x30 , 30x5 , 5x60 
    std::vector<int> arr = {10, 30, 5, 60};
    for (int x : arr) cout << x << " ";
    cout << endl;
    int minOps = matrixChainMultiplication(arr);
    cout <<  minOps << endl;

    return 0;
}
