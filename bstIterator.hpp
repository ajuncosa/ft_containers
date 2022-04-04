#pragma once
#include "iterator.hpp"

namespace ft
{
	template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class bstIterator : public iterator<std::bidirectional_iterator_tag, T, Distance, Pointer, Reference>
	{
		public:
			typedef iterator<std::bidirectional_iterator_tag, T, Distance, Pointer, Reference> iterator;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
			typedef typename iterator::iterator_category	iterator_category;

			bstIterator() : _data(NULL) {}

			template <class U>
			bstIterator(const bstIterator<U> &src) : _data(src._data) {}
			
			bstIterator &operator=(const bstIterator &src)
			{
				if (this != &src)
					this->_data = src._data;
				return *this;
			}
			
			~bstIterator() {};

		private:
			template <class U, class V, class W, class X> //TODO: revisar que esto funcione
			friend class binarySearchTree;

			pointer	_data;
			bstIterator(pointer node) : _data(node) {}
			//friend class bstIterator;
	};
}
