

# C++ Power Functions

This is a C++ project that provides implementations of three different algorithms for exponentiation (raising a number to a power). The functions are written using templates, allowing them to be used with any arithmetic type (e.g., `int`, `float`, `double`).

## Implemented functions


*   `iterativePow()` - Calculates the power using an iterative approach (a loop). Complexity: **O(n)**.
*   `recursivePow()` - Calculates the power using a classic recursive approach. Complexity: **O(n)**.
*   `logarithmicPow()` - Calculates the power using exponentiation by squaring, which is highly efficient. Complexity: **O(log n)**.


###  Calculating a Negative Power (IMPORTANT)

Our functions are designed to compute powers for non-negative exponents. For negative exponents (`x⁻ⁿ = 1/xⁿ`), the responsibility for getting the correct fractional result lies with the calling code (e.g., the `main` function).

**This is intentional.** It keeps the power functions generic and prevents them from returning a `double` when they were called with `int` arguments.

Here is the correct way to handle negative and Positive  exponents:


int main()
{

    int value1;
	  std::cout << "please insert a value: ";
  	std::cin >> value1;


    int number1;
    std::cout << "please insert a power of number: ";
    std::cin >> number1;

    if (number1 < 0) 
    {
        number1 = -number1;
        std::cout << "The " << number1 << "- th power of " << value1 << " number is    " << 1.0/iterativePow(value1, number1) << std::endl;
    }
    else std::cout << "The "<<number1<<"- th power of "<<value1<<" number is    "<< iterativePow(value1, number1) << std::endl;

    int value2;
    std::cout << "please insert a value: ";
    std::cin >> value2;
    std::cout << std::endl;

    int number2;
    std::cout << "please insert a power: ";
    std::cin >> number2;
    std::cout << std::endl;
 

    if (number2 < 0)
    {
        number2 = -number2;
        std::cout << "The " << number2 << "- th power of " << value2 << " number is    " << 1.0 / recursivePow(value2, number2) << std::endl;
    }
    else std::cout << "The " << number2 << "- th power of " << value2 << " number is    " << recursivePow(value2, number2) << std::endl;

    int value3;
    std::cout << "please insert a value: ";
    std::cin >> value3;
    std::cout << std::endl;

    int number3;
    std::cout << "please insert a power: ";
    std::cin >> number3;
    std::cout << std::endl;
 

    if (number2 < 0)
    {
        number3 = -number3;
        std::cout << "The " << number3 << "- th power of " << value3 << " number is    " << 1.0 / logarithmicPow(value3, number3) << std::endl;
    }
    else std::cout << "The " << number3 << "- th power of " << value3 << " number is    " << logarithmicPow(value3, number3) << std::endl;


    return 0;
}
