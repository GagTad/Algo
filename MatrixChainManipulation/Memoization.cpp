#include <iostream>
#include <vector>
#include <climits> 

std::vector<std::vector<int>> memo;

int solveMCM(const std::vector<int>& p, int i, int j) {
    if (i == j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int currentCost = solveMCM(p, i, k) + solveMCM(p, k + 1, j) + (p[i - 1] * p[k] * p[j]);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
    }
    return memo[i][j] = minCost;
}

int main() {
    //  10x30, 30x5, 5x60
    std::vector<int> p = {10, 30, 5, 60};
    int n = p.size() - 1; 
    memo.assign(n + 1, std::vector<int>(n + 1, -1));
    for (int x : p) cout << x << " ";
    std::cout << std::endl;
    int result = solveMCM(p, 1, n);
    std::cout  << result << std::endl;
    
    return 0;
}
