#include <iostream>
#include <stack>
#include <string>

bool areBracketsBalanced(const std::string& expr) {
    std::stack<char> s;

    for (char ch : expr) {
       
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
       
        else if (ch == ')' || ch == '}' || ch == ']') {
            
            if (s.empty()) {
                return false;
            }

            char top = s.top(); 

            
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
            {
                s.pop();
            }
            else {
                return false; 
            }
        }
    }

   
    return s.empty();
}

int main() {
    std::string test_cases[] = {
        "{ [ ( ) ] } ()",  
        "{ [ ( ] ) }",    
        "((()))",          
        "([)]",           
        "(()",            
        "hello(world)",    
        ""                 
    };

    for (const auto& str : test_cases) {
        if (areBracketsBalanced(str)) {
            std::cout << str << " is Balanced." << std::endl;
        }
        else {
            std::cout << str << " is NOT Balanced." << std::endl;
        }
    }

    return 0;
}
