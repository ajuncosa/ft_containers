#pragma once

template <class T>
class vector
{
	private:
		T *data;
		//std::allocator<T> myAllocator;

	public:
		typedef typename T value_type;
		typedef typename std::allocator<T> allocator_type;
		typedef typename std::allocator<T>::reference reference;
};
