#include "iter.hpp"

template <typename U>
void	ft_print(U &c)
{
	std::cout << c << std::endl;
}

int main()
{
	std::cout << "      First test" << std::endl;

	int array[] = {1, 2, 3, 4, 5};
	int length = sizeof(array) / sizeof(array[0]);
	iter(array, length, ft_print<int>);

	std::cout << "      Second test" << std::endl;

	std::string array2[] = {"one", "two", "three", "four", "five"};
	length = sizeof(array2) / sizeof(array2[0]);
	iter(array2, length, ft_print<std::string>);

	std::cout << "      Third test" << std::endl;

	double array3[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	length = sizeof(array3) / sizeof(array3[0]);
	iter(array3, length, ft_print<double>);
	
	return 0;
}