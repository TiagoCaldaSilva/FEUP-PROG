// 8.a

#include <cstdlib>

// Vector.h

template <class T>
class Vector
{
public:
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial) {}
    Vector(const Vector<T> & v) {}
    ~Vector();
    size_t size() const;
    bool empty() const;
    T & front() {}
    T & back() {}
    T & at(size_t index) {}
    void push_back(const T & value) {}
    void pop_back() {}
    void clear() {}
private:
    T * buffer;
    size_t bufferSize;
};

// Vector.cpp

template <class T>
Vector<T>::Vector()
{
    bufferSize = 0;
    buffer = NULL;
}

template <class T>
Vector<T>::Vector(unsigned int size)
{
    bufferSize = 10;
    buffer = malloc(sizeof(T)*bufferSize);
}

/*
Vector::Vector(unsigned int size, const T & initial)
{
}

Vector::Vector(const Vector<T> & v)
{
}
*/

template <class T>
Vector<T>::~Vector()
{
    free(buffer);
}

template <class T>
size_t Vector<T>::size() const
{
    return bufferSize;
}

template <class T>
bool Vector<T>::empty() const
{
    return bufferSize == 0;
}

/*
T & Vector::front()
{
}

T & Vector::back()
{
}

T & at(size_t index);
void push_back(const T & value);
void pop_back();
void clear();
*/

template <class T>
void Vector<T>::push_back(const T & value)
{
    bufferSize++;
    // ...
    // realloc
}

//
//int main()
//{
//    Vector<double> v;
//}
