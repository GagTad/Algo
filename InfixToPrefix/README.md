
#  Infix to Postfix Expression Converter

This is a C++ project that provides a robust function to convert mathematical expressions from standard infix notation (e.g., `(A + B) * C`) to postfix notation, also known as Reverse Polish Notation (RPN) (e.g., `A B + C *`).

Postfix notation is often used in computing, particularly in stack-oriented programming languages and by compilers, because it allows for the straightforward evaluation of expressions without the need for parentheses or complex operator precedence rules.

## Key Features

*   **Accurate Conversion:** Correctly converts infix expressions to postfix, respecting operator precedence (`^`, `*`, `/`, `+`, `-`).
*   **Parenthesis Handling:** Properly manages nested parentheses to enforce the desired order of operations.
*   **Safe and Robust:** The primary strength of this implementation is its focus on safety. It is designed to handle invalid user input gracefully instead of crashing.
*   **Comprehensive Error Handling:** The converter validates the input expression and throws descriptive exceptions for various syntax errors, including:
    *   Mismatched opening or closing parentheses (e.g., `(A+B` or `A+B)`).
    *   Missing operators between operands (e.g., `A B`).
    *   Missing operands before or after operators (e.g., `*A` or `A+*B`).
    *   Empty expressions within parentheses (e.g., `A + ()`).
    *   Invalid characters within the expression.
*   **Whitespace Insensitive:** The parser correctly ignores any spaces within the expression.

## Safe Implementation through Exception Handling

Safety is a primary design goal of this implementation. Instead of returning an error code or allowing the program to crash on invalid input, the `infToPost` function throws a `std::runtime_error` exception.

This approach cleanly separates the conversion logic from the error-handling logic. The calling code (in this case, the `main` function) is responsible for **"catching"** these exceptions and presenting the error to the user in a controlled manner. This prevents the program from terminating unexpectedly and provides clear, actionable feedback to the user.

## Usage Example

To use the converter function safely, you **must** call it within a `try...catch` block. This ensures that any `std::runtime_error` thrown by the function during validation or conversion will be caught and handled properly.

The following `main` function demonstrates how to read an expression from the user and handle both successful conversions and potential errors.

```cpp
#include <iostream>
#include <string>
#include <stdexcept>

std::string infToPost(const std::string& infix);

int main()
{
    std::string str;
    std::cout << "Please insert infix expression: " << std::endl;
    
    std::cin >> str;

    
    try {
       
        std::string postfix = infToPost(str);
       
        std::cout << "Success! Postfix expression: " << postfix << std::endl;
    }
    
    catch (const std::runtime_error& e) {
       
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

### Example Scenarios:

**1. Successful Conversion:**

```
Please insert infix expression:
A * (B + C) / D
Success! Postfix expression: ABC+*D/
```

**2. Failed Conversion (Invalid Input):**

```
Please insert infix expression:
A B + C
Error: Missing operator between operands.
```

**3. Failed Conversion (Mismatched Parentheses):**

```
Please insert infix expression:
(A + B * (C - D)
Error: Mismatched opening parenthesis '('.
```

## Dependencies
This implementation relies on a custom `ArrayBasedStack` class. Ensure that the header file (`ArrayBasedStack.h`) is accessible at the specified path (`..\..\ArrayBasedStack\ArrayBasedStack\ArrayBasedStack.h`) or modify the include path accordingly. Alternatively, the code can be easily adapted to use the C++ standard library's `std::stack`.
