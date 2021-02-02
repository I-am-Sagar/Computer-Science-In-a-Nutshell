#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template <class T, int n>
class Array
{
    private:
        T arr[n];
    public:
        Array() {};
        explicit Array (const T & v);
        virtual T & operator [] (int i);
        virtual T operator [] (int i) const;
};

template <class T, int n>
Array<T, n> :: Array (const T & v)
{
    for (int i = 0; i < n; i++)
    arr[i] = v;
}

template <class T, int n>
T & Array <T, n> :: operator [] (int i)
{
    if ( i < 0 || i > n)
    {
        std::cerr << "Error in array limits: " << i << "is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    else 
        return arr[i];
}

template <class T, int n>
T Array <T, n> :: operator [] (int i) const
{
    if (i < 0|| i > n)
    {
        std::cerr << "Error in array limits: " << i << "is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    else 
        return arr[i];
}

#endif
