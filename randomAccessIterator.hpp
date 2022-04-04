#pragma once
#include "iterator.hpp"

namespace ft
{
	template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class randomAccessIterator : public iterator<std::random_access_iterator_tag, T, Distance, Pointer, Reference>
	{
		public:
			typedef iterator<std::random_access_iterator_tag, T, Distance, Pointer, Reference> iterator;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
			typedef typename iterator::iterator_category	iterator_category;

			randomAccessIterator() : _data(NULL) {}

			randomAccessIterator(pointer data) : _data(data) {} // TODO: comprobar si puedo hacer este constructor privado (el original no lo tiene?)

			template <class U>
			randomAccessIterator(const randomAccessIterator<U> &src) : _data(src.getPointer()) {}
			
			randomAccessIterator& operator=(const randomAccessIterator& src)
			{
				if (this != &src)
					this->_data = src.getPointer();
				return *this;
			}
			
			~randomAccessIterator(){};
			
			pointer getPointer() const
			{
				return this->_data;
			}

			randomAccessIterator& operator++()
			{
				this->_data++;
				return *this;
			}

			randomAccessIterator operator++(int)
			{
				randomAccessIterator tmp(*this);
				this->_data++;
				return tmp;
			}

			randomAccessIterator& operator--()
			{
				this->_data--;
				return *this;
			}

			randomAccessIterator operator--(int)
			{
				randomAccessIterator tmp(*this);
				this->_data--;
				return tmp;
			}

			reference operator*() const
			{
				return *this->_data;
			}

			pointer operator->()
			{
				return this->_data;
			}

			reference operator[](difference_type index) const
			{
				return *(this->_data + index);
			}

			randomAccessIterator& operator+=(difference_type rhs)
			{
				this->_data += rhs;
				return *this;
			}

			randomAccessIterator& operator-=(difference_type rhs)
			{
				this->_data -= rhs;
				return *this;
			}

			template<class U, class V>
			friend bool operator==(const randomAccessIterator<U>& lhs, const randomAccessIterator<V>& rhs);
			
			template <class U, class V>
			friend bool operator<(const randomAccessIterator<U>& lhs, const randomAccessIterator<V>& rhs);
			
			template <class U, class V>
			friend typename randomAccessIterator<U>::difference_type operator-(randomAccessIterator<U> lhs, randomAccessIterator<V> rhs);
			
		private:
			pointer	_data;
	};

	template <class T, class U>
	bool operator==(const randomAccessIterator<T>& lhs, const randomAccessIterator<U>& rhs) 
	{
		return lhs._data == rhs._data;
	}

	template <class T, class U>
	bool operator!=(const randomAccessIterator<T>& lhs, const randomAccessIterator<U>& rhs)
	{
		return !operator==(lhs,rhs);
	}

	template <class T, class U>
	bool operator<(const randomAccessIterator<T>& lhs, const randomAccessIterator<U>& rhs)
	{
		return lhs._data < rhs._data;
	}

	template <class T, class U>
	bool operator>(const randomAccessIterator<T>& lhs, const randomAccessIterator<U>& rhs)
	{
		return operator<(rhs,lhs);
	}

	template <class T, class U>
	bool operator<=(const randomAccessIterator<T>& lhs, const randomAccessIterator<U>& rhs)
	{
		return !operator>(lhs,rhs);
	}

	template <class T, class U>
	bool operator>=(const randomAccessIterator<T>& lhs, const randomAccessIterator<U>& rhs)
	{
		return !operator<(lhs,rhs);
	}

	template <class T>
	randomAccessIterator<T> operator+(randomAccessIterator<T> lhs, typename randomAccessIterator<T>::difference_type rhs)
	{
		lhs += rhs;
		return lhs;
	}

	template <class T>
	randomAccessIterator<T> operator+(typename randomAccessIterator<T>::difference_type lhs, randomAccessIterator<T> rhs)
	{
		rhs += lhs;
		return rhs;
	}

	template <class T>
	randomAccessIterator<T> operator-(randomAccessIterator<T> lhs, typename randomAccessIterator<T>::difference_type rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	template <class T>
	randomAccessIterator<T> operator-(typename randomAccessIterator<T>::difference_type lhs, randomAccessIterator<T> rhs)
	{
		rhs -= lhs;
		return rhs;
	}
	
	template <class T, class U>
	typename randomAccessIterator<T>::difference_type operator-(randomAccessIterator<T> lhs, randomAccessIterator<U> rhs)
	{	
		return lhs._data - rhs._data;
	}
}
