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
                std::stack<int>& source, std::stack<int>& final, std::stack<int>& helper,
                char source_name, char final_name, char helper_name) {
    if (n == 0) {
        return;
    }

    solveHanoi(n - 1, source, helper, final, source_name, helper_name, final_name);

    int disk = source.top();
    source.pop();
    final.push(disk);
    std::cout << "Քայլ։ Տեղափոխել սկավառակ " << final << " " << source_name << "-ից -> " << final_name << std::endl;

    solveHanoi(n - 1, helper, final, source, helper_name, final_name, source_name);
}


int main() {
    // Ստեղծում ենք աշտարակները (ձողերը)
    std::stack<int> stick_A;
    std::stack<int> stick_B;
    std::stack<int> stivk_C;

    int num_disks;
    std::cin >> num_disks;

    for (int i = num_disks; i >= 1; --i) {
        rod_A.push(i);
    }
    printRods(rod_A, rod_B, rod_C);

    solveHanoi(num_disks, rod_A, rod_C, rod_B, 'A', 'C', 'B');

    printRods(rod_A, rod_B, rod_C);

    return 0; 
}