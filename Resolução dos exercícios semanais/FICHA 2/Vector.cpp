//#include "Vector.h"
//#include <stdlib.h> 
//
//template <class T>
//Vector<T>::Vector()
//{
//	buffer = (int*)malloc(sizeof(T) * 0);
//	bufferSize = 0;
//}
//
//template <class T>
//Vector<T>::Vector(unsigned int size)
//{
//	buffer = (T*)malloc (sizeof(T) * size);
//	bufferSize = size;
//}
//
//template <class T>
//Vector<T>::Vector(unsigned int size, const T& initial)
//{
//	buffer = (T*)malloc(sizeof(T) * size);
//	bufferSize = size;
//	*buffer = (*initial);
//}
//
//template<class T>
//Vector<T>::Vector(const Vector<T>& v)
//{
//	buffer = v.buffer;
//	bufferSize = v.bufferSize;
//}
//
//template<class T>
//Vector<T>::~Vector()
//{
//	free (buffer);
//}
//
//template<class T>
//size_t Vector<T>::size() const
//{
//	return bufferSize;
//}
//
//template<class T>
//bool Vector<T>::empty() const
//{
//	return(bufferSize == 0);
//}
//
//template<class T>
//T& Vector<T>::front()
//{
//	return buffer;
//}
//
//template<class T>
//T& Vector<T>::back()
//{
//	return buffer + (bufferSize - 1);
//}
//
//template<class T>
//T& Vector<T>::at(size_t index)
//{
//	return *(buffer + index);
//}
//
//template<class T>
//void Vector<T>::push_back(const T& value)
//{
//	bufferSize++;
//	buffer = (T*)realloc((void*)buffer, sizeof(T) * (bufferSize));
//	*(buffer + bufferSize - 1) = value;
//}
//
//template<class T>
//void Vector<T>::pop_back()
//{
//	bufferSize--;
//	buffer = (T*)realloc((void*)buffer, (bufferSize - 1) * sizeof(T));
//}
//
//template<class T>
//void Vector<T>::clear()
//{
//	bufferSize = 0;
//	buffer = (T*)realloc(buffer, 0);
//}
//
