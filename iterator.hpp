#pragma once

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

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

		randomAccessIterator() : _data(NULL) {};
		randomAccessIterator(pointer data) : _data(data) {};
		randomAccessIterator(randomAccessIterator const &src) : _data(src.getPointer()) {};
		randomAccessIterator& operator=(const randomAccessIterator& src)
		{
			if (this != &src)
				this->_data = src.getPointer();
			return *this;
		};
		~randomAccessIterator(){};
		pointer getPointer() const
		{
			return this->_data;
		};
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
		reference operator*()
		{
			return *this->_data;
		}
		pointer operator->()
		{
			return this->_data;
		}
	
	private:
		pointer	_data;
};

template <class T>
bool operator==(const randomAccessIterator<T>& lhs, const randomAccessIterator<T>& rhs)
{
	return lhs.getPointer() == rhs.getPointer();
};
template <class T>
bool operator!=(const randomAccessIterator<T>& lhs, const randomAccessIterator<T>& rhs)
{
	return !operator==(lhs,rhs);
};
template <class T>
bool operator<(const randomAccessIterator<T>& lhs, const randomAccessIterator<T>& rhs)
{
	return lhs.getPointer() < rhs.getPointer();
};
template <class T>
bool operator>(const randomAccessIterator<T>& lhs, const randomAccessIterator<T>& rhs)
{
	return operator<(rhs,lhs);
};
template <class T>
bool operator<=(const randomAccessIterator<T>& lhs, const randomAccessIterator<T>& rhs)
{
	return !operator>(lhs,rhs);
};
template <class T>
bool operator>=(const randomAccessIterator<T>& lhs, const randomAccessIterator<T>& rhs)
{
	return !operator<(lhs,rhs);
};
