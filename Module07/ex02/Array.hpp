#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *data;
        unsigned int n;
    public:
        Array(): data(NULL), n(0) {}
        Array(unsigned int n): n(n)
        {
            this->data = new T[this->n];
        }
        Array(Array const &copy)
        {
            this->n = copy.n;
            this->data = new T[this->n];
            for (unsigned int i = 0; i < this->n; i++)
                this->data[i] = copy.data[i];
        }
        Array &operator=(Array const &copy)
        {
            if (this->data != NULL)
                delete[] this->data;
            if (this != &copy)
            {
                this->n = copy.n;
                this->data = new T[this->n];
                for (unsigned int i = 0; i < this->n; i++)
                    this->data[i] = copy.data[i];
            }
            return *this;
        }
        ~Array()
        {
            if (this->data != NULL)
                delete[] this->data;
        }
        T &operator[](unsigned int i)
        {
            if (i >= this->n)
                throw std::out_of_range("Index out of range");
            return this->data[i];
        }
        const T &operator[](unsigned int i) const 
        {
            if (i >= this->n)
                throw std::out_of_range("Index out of range");
            return this->data[i];
        }
        unsigned int size() const
        {
            return this->n;
        }
};

#endif
