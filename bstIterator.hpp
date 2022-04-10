#pragma once
#include "iterator.hpp"

namespace ft
{
	//FIXME: construir iterator normal a partir de uno const, no deberia funcionar
	template <class Node, class T, class Distance = ptrdiff_t, class Pointer = Node*, class Reference = Node&>
	class bstIterator : public iterator<std::bidirectional_iterator_tag, Node, Distance, Pointer, Reference>
	{
		public:
			typedef iterator<std::bidirectional_iterator_tag, Node, Distance, Pointer, Reference> iterator;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
			typedef typename iterator::iterator_category	iterator_category;
			typedef T value_type;

			bstIterator() : _data(NULL), _sentinel(NULL) {}

			template <class U, class V>
			bstIterator(const bstIterator<U, V> &src) : _data(src.getData()), _sentinel(src.getSentinel()) {}
			
			bstIterator(const bstIterator &src) : _data(src.getData()), _sentinel(src.getSentinel()) {}

			bstIterator(pointer node, pointer sentinel) : _data(node), _sentinel(sentinel) {}

			bstIterator &operator=(const bstIterator &src)
			{
				if (this != &src)
				{
					this->_data = src.getData();
					this->_sentinel = src.getSentinel();
				}
				return *this;
			}
			
			~bstIterator() {};

			value_type &operator*() const
			{
				return this->_data->value;
			}

			value_type *operator->()
			{
				return &this->_data->value;
			}

			bstIterator& operator++()
			{
				if (this->_data == this->_sentinel)
				{
					std::cout << "what" << std::endl; // FIXME: add empty map and error management
				}
				if (this->_data->right != this->_sentinel)
				{
					this->_data = this->_data->right;
					while (this->_data->left != this->_sentinel)
						this->_data = this->_data->left;
				}
				else
				{
					while (this->_data->parent != this->_sentinel && this->_data != this->_data->parent->left)
						this->_data = this->_data->parent;
					this->_data = this->_data->parent;
				}
				return *this;
			}

			bstIterator operator++(int)
			{
				bstIterator tmp(*this);
				if (this->_data == this->_sentinel)
				{
					std::cout << "what" << std::endl; // FIXME: add empty map and error management
				}
				if (this->_data->right != this->_sentinel)
				{
					this->_data = this->_data->right;
					while (this->_data->left != this->_sentinel)
						this->_data = this->_data->left;
				}
				else
				{
					while (this->_data->parent != this->_sentinel && this->_data != this->_data->parent->left)
						this->_data = this->_data->parent;
					this->_data = this->_data->parent;
				}
				return tmp;
			}

			pointer getData() const
			{
				return this->_data;
			}

			pointer getSentinel() const
			{
				return this->_sentinel;
			}

		private:
			template <class U, class V, class W, class X>
			friend bool operator==(const bstIterator<U, V> &lhs, const bstIterator<W, X> &rhs); 

			pointer	_data;
			pointer	_sentinel;
	};

	template <class T, class U, class V, class W>
	bool operator==(const bstIterator<T, U> &lhs, const bstIterator<V, W> &rhs) 
	{
		return lhs._data == rhs._data;
	}

	template <class T, class U, class V, class W>
	bool operator!=(const bstIterator<T, U>& lhs, const bstIterator<V, W>& rhs)
	{
		return !operator==(lhs, rhs);
	}
}
