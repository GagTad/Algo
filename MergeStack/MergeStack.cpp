#include <iostream>
#include <stack>
#include <vector> 

std::stack<int> sortStack(std::stack<int> &input) {
    std::stack<int> tmpStack;

    while (!input.empty()) {
        int temp = input.top();
        input.pop();
      
        while (!tmpStack.empty() && tmpStack.top() < temp) {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(temp);
    }

    return tmpStack;
}


std::stack<int> mergeAndSortStacks(std::stack<int> s1, std::stack<int> s2) {
    std::stack<int> combinedStack;

    while (!s1.empty()) {
        combinedStack.push(s1.top());
        s1.pop();
    }
  
    while (!s2.empty()) {
        combinedStack.push(s2.top());
        s2.pop();
    }

    return sortStack(combinedStack);
}

int main() {
    std::stack<int> stack1;
    stack1.push(10);
    stack1.push(4);
    stack1.push(20);

    std::stack<int> stack2;
    stack2.push(5);
    stack2.push(15);
    stack2.push(3);

    std::stack<int> resultStack = mergeAndSortStacks(stack1, stack2);

    while (!resultStack.empty()) {
        std::cout << resultStack.top() << " ";
        resultStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
