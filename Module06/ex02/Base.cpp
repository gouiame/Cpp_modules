#include "Base.hpp"

Base::~Base() {}

Base * generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
        return new A;// A *ptr = new A; return ptr;
    if (random == 1)
        return new B;
    return new C;
}

void identify(Base *p)
{
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);

    if (a != NULL)
        std::cout << "The actual type of the object : A" << std::endl;
    else if (b != NULL)
        std::cout << "The actual type of the object : B" << std::endl;
    else if (c != NULL)
        std::cout << "The actual type of the object : C" << std::endl;
    else 
        std::cout << "The actual type of the object : Unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The actual type of the object : A" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "The actual type of the object : B" << std::endl;
        }
        catch (std::bad_cast &bc)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "The actual type of the object : C" << std::endl;
            }
            catch (std::bad_cast &bc)
            {
                std::cout << "The actual type of the object : Unknown" << std::endl;
            }
        }
    }
}
    