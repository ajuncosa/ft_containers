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

			bstIterator() : _data(NULL) {}

			template <class U, class V>
			bstIterator(const bstIterator<U, V> &src) : _data(src._data) {}
			
			bstIterator(const bstIterator &src) : _data(src._data) {}

			bstIterator &operator=(const bstIterator &src)
			{
				if (this != &src)
					this->_data = src._data;
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
				if (this->_data->sentinel == true)
				{
					std::cout << "what" << std::endl; // FIXME: add empty map and error management
				}
				if (this->_data->right->sentinel == false)
				{
					this->_data = this->_data->right;
					while (this->_data->left->sentinel == false)
						this->_data = this->_data->left;
				}
				else
				{
					pointer tmp = this->_data->right;
					while (this->_data->parent->sentinel == false && this->_data != this->_data->parent->left)
						this->_data = this->_data->parent;
					this->_data = this->_data->parent;
					if (this->_data->sentinel == true)
						this->_data = tmp;
				}
				return *this;
			}

			bstIterator operator++(int)
			{
				bstIterator tmp(*this);
				if (this->_data->sentinel == true)
				{
					std::cout << "what" << std::endl; // FIXME: add empty map and error management
				}
				if (this->_data->right->sentinel == false)
				{
					this->_data = this->_data->right;
					while (this->_data->left->sentinel == false)
						this->_data = this->_data->left;
				}
				else
				{
					pointer tmp = this->_data->right;
					while (this->_data->parent->sentinel == false && this->_data != this->_data->parent->left)
						this->_data = this->_data->parent;
					this->_data = this->_data->parent;
					if (this->_data->sentinel == true)
						this->_data = tmp;
				}
				return tmp;
			}

		private:
			template <class U, class V, class W, class X>
			friend class binarySearchTree;

			template <class U, class V, class W, class X, class Y>
			friend class bstIterator;

			template <class U, class V, class W, class X>
			friend bool operator==(const bstIterator<U, V> &lhs, const bstIterator<W, X> &rhs); 

			pointer	_data;

			bstIterator(pointer node) : _data(node) {}
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
