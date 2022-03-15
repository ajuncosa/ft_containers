#pragma once
#include "iteratorTraits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::reference reference;

			reverse_iterator() : _base(iterator_type()) {}

			explicit reverse_iterator (iterator_type it) : _base(it) {}

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {}

			iterator_type base() const
			{
				return iterator_type(this->_base);
			}

			reference operator*() const
			{
				return *(this->_base - 1);
			}

			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(this->_base - n);
			}

			reverse_iterator& operator++()
			{
				this->_base--;
				return *this;
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			reverse_iterator& operator+=(difference_type n)
			{
				this->_base -= n;
				return *this;
			}

			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(this->_base + n);
			}

			reverse_iterator& operator--()
			{
				this->_base++;
				return *this;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			reverse_iterator& operator-=(difference_type n)
			{
				this->_base += n;
				return *this;
			}

			pointer operator->() const
			{
				return &(this->operator*());
			}

			reference operator[](difference_type n) const
			{
				return this->_base[-n - 1];
			}

		private:
			iterator_type	_base;
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return rev_it + n;
	}

	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}
}
