#pragma once
#include <stdlib.h>
template <class T>
class Vetor
{
public:
    Vetor();
    Vetor(unsigned int size);
    Vetor(unsigned int size, const T& initial);
    Vetor(const Vetor<T>& v);
    ~Vetor();
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t n);
    bool empty() const;
    T& front();
    T& back();
    T& at(size_t index);
    void push_back(const T& value);
    void pop_back();
    void clear();
private:
    T* buffer;
    size_t bufferSize;
    size_t bufferCapacity;
};
 

template <typename T>
Vetor<T>::Vetor()
{
	buffer = (T*)malloc(sizeof(T) * 0);
	bufferSize = 0;
	bufferCapacity = 0;
}

template <typename T>
Vetor<T>::Vetor(unsigned int size)
{
	buffer = (T*)malloc(sizeof(T) * size);
	bufferSize = size;
	bufferCapacity = size;
}

template <typename T>
Vetor<T>::Vetor(unsigned int size, const T& initial)
{
	buffer = (T*)malloc(sizeof(T) * size);
	bufferSize = size;
	bufferCapacity = 0;
	*buffer = (*initial);
}

template<typename T>
Vetor<T>::Vetor(const Vetor<T>& v)
{
	buffer = v.buffer;
	bufferSize = v.bufferSize;
	bufferCapacity = v.bufferCapacity;
}

template<typename T>
Vetor<T>::~Vetor()
{
	free(buffer);
}

template<typename T>
size_t Vetor<T>::size() const
{
	return bufferSize;
}

template<typename T>
size_t Vetor<T>::capacity() const
{
	return bufferCapacity;
}

template<typename T>
void Vetor<T>::reserve(size_t n)
{
	//*Vetor<T>* x;
	///x = (T*)malloc(sizeof(T) * 2 * bufferCapacity + n);
	//for (int i = 0; i < bufferCapacity; i++)
	//{
	//	*(x + i) = *(buffer + i);
	//}
	//bufferCapacity += n;
	//free(buffer);
	//buffer = x;	
	buffer = (T*)realloc((void*)buffer, sizeof(T) * 2 * bufferCapacity);
	bufferCapacity *= 2;
}

template<typename T>
bool Vetor<T>::empty() const
{
	return(bufferSize == 0);
}

template<typename T>
T& Vetor<T>::front()
{
	return buffer;
}

template<typename T>
T& Vetor<T>::back()
{
	return buffer + (bufferSize - 1);
}

template<typename T>
T& Vetor<T>::at(size_t index)
{
	return *(buffer + index);
}

template<typename T>
void Vetor<T>::push_back(const T& value)
{
	if (bufferSize == bufferCapacity)
		reserve(bufferCapacity);
	bufferSize++;
	*(buffer + bufferSize - 1) = value;
}

template<typename T>
void Vetor<T>::pop_back()
{
	bufferSize--;
	buffer = (T*)realloc((void*)buffer, (bufferSize - 1) * sizeof(T));
}

template<typename T>
void Vetor<T>::clear()
{
	bufferSize = 0;
	buffer = (T*)realloc(buffer, 0);
}

