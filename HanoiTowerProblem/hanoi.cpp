#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm> 

void printRods(const std::stack<int>& source, const std::stack<int>& final, const std::stack<int>& helper) {
   
    auto printSingleStack = [](std::string name, std::stack<int> s) {
        std::cout << name << ": [ ";
        std::vector<int> temp;
        while (!s.empty()) {
            temp.push_back(s.top());
            s.pop();
        }
        std::reverse(temp.begin(), temp.end());
        for (int disk : temp) {
            std::cout << disk << " ";
        }
        std::cout << "]" << std::endl;
    };

    printSingleStack("Stick A", source);
    printSingleStack("Stick B", final);
    printSingleStack("Stick C", helper);
    std::cout << "------------------------------------" << std::endl;
}

void solveHanoi(int n,
                std::stack<int>& source, std::stack<int>& final, std::stack<int>& helper) {
    if (n == 0) {
        return;
    }

    solveHanoi(n - 1, source, helper, final);

    int disk = source.top();
    source.pop();
    final.push(disk);

    solveHanoi(n - 1, helper, final, source);
}


int main() {
    std::stack<int> stick_A;
    std::stack<int> stick_B;
    std::stack<int> stick_C;

    int num_disks;
    std::cin >> num_disks;

    for (int i = num_disks; i >= 1; --i) {
        stick_A.push(i);
    }
    printRods(stick_A, stick_B, stick_C);

    solveHanoi(num_disks, stick_A, stick_C, stick_B);

    printRods(stick_A, stick_B, stick_C);

    return 0; 
}