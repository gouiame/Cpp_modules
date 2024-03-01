#include "Array.hpp"

int main()
{
    std::cout << "     First test" << std::endl;
    Array<int> a(5);

    try
    {
        a[0] = 1;
        a[1] = 2;

        std::cout << "a[0] = " << a[0] << std::endl;
        std::cout << "a[1] = " << a[1] << std::endl;
        std::cout << "a[10] = " << a[10] << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout <<"     Second test" << std::endl;
    Array<int> A1(3);
    A1[0] = 1;
    A1[1] = 2;
    A1[2] = 3;

	Array<int> A2(A1); // copy constructor
	Array<int> A3;
	A3 = A1; // assignation operator
    
    std::cout << "A1[0] = " << A1[0] << std::endl;
    std::cout << "A1[1] = " << A1[1] << std::endl;
    std::cout << "A1[2] = " << A1[2] << std::endl << std::endl;
    std::cout << "A2[0] = " << A2[0] << std::endl;
    std::cout << "A2[1] = " << A2[1] << std::endl;
    std::cout << "A2[2] = " << A2[2] << std::endl << std::endl;
    std::cout << "A3[0] = " << A3[0] << std::endl;
    std::cout << "A3[1] = " << A3[1] << std::endl;
    std::cout << "A3[2] = " << A3[2] << std::endl;

    std::cout << "third test with emty array"   << std::endl;
    
    Array<std::string> B(5);
    for (unsigned int i = 0; i < B.size(); i++)
      std::cout << B[i] << std::endl;
    return 0;
}
