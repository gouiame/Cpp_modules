#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->n = 1337;
    data->s1 = "Coding School";

    uintptr_t raw = Serializer::serialize(data);
    Data *ptr = Serializer::deserialize(raw);

    std::cout << "Before : " << data->n << " " << data->s1 << std::endl;
    std::cout << "After  : " << ptr->n << " " << ptr->s1 << std::endl;

    delete ptr;
    return 0;

}
