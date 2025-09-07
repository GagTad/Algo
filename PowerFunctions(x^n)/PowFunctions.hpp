#include <iostream>
#include <type_traits>

template <typename T>
T iterativePow(const T value, const int power)
{
	static_assert(std::is_arithmetic<T>::value, "Template type must be arithmetic");
    T result = 1;
    for (int i = 0; i < power; ++i) 
    {
        result *= value;
    }
    return result;
}


template <typename T>
T recursivePow(const T value,  int power)
{
    static_assert(std::is_arithmetic<T>::value, "Template type must be arithmetic");
    if(power == 0)
    {
        return 1;
    }
    return value * recursivePow(value, power -1);
   
}



template <typename T>
T logarithmicPow(T value, int pow)
{
	static_assert(std::is_arithmetic<T>::value, "Template type must be arithmetic");
	if (pow == 0)
	{
		return 1;
	}
	if (pow % 2 == 0)
	{
		T half = logarithmicPow(value, pow / 2);
		return half * half;
	}
	else
	{
		return value * logarithmicPow(value, pow - 1);
	}
}
