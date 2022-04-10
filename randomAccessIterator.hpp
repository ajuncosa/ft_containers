#pragma once
#include "iterator.hpp"

namespace ft
{
	//FIXME: volver a poner un getter y quitar friends y constructor publico
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

			template <class U>
			randomAccessIterator(const randomAccessIterator<U> &src) : _data(src.getData()) {}
			
			randomAccessIterator(const randomAccessIterator &src) : _data(src.getData()) {}
			
			randomAccessIterator(pointer data) : _data(data) {}

			randomAccessIterator& operator=(const randomAccessIterator& src)
			{
				if (this != &src)
					this->_data = src.getData();
				return *this;
			}
			
			~randomAccessIterator(){};

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

			pointer getData() const
			{
				return this->_data;
			}
			
		private:
			template <class U, class V>
			friend bool operator==(const randomAccessIterator<U>& lhs, const randomAccessIterator<V>& rhs);
			
			template <class U, class V>
			friend bool operator<(const randomAccessIterator<U>& lhs, const randomAccessIterator<V>& rhs);
			
			template <class U, class V>
			friend typename randomAccessIterator<U>::difference_type operator-(randomAccessIterator<U> lhs, randomAccessIterator<V> rhs);

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
