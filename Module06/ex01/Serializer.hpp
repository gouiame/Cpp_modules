#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
    std::string s1;
    int n;
} Data;

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &copy);
        Serializer &operator=(Serializer const &copy);
        ~Serializer();

    public:
        static Data *deserialize(uintptr_t raw);
        static uintptr_t serialize(Data *ptr);
};

#endif