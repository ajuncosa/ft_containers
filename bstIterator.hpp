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

			typename value_type::value_type &operator*() const
			{
				return this->_data->value;
			}

			typename value_type::value_type *operator->()
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

			//template <class U, class V, class W, class X>
			//friend class bstIterator;

			template <class U, class V>
			friend bool operator==(const bstIterator<U> &lhs, const bstIterator<V> &rhs); 

			pointer	_data;

			bstIterator(pointer node) : _data(node) {}
	};

	template <class T, class U>
	bool operator==(const bstIterator<T> &lhs, const bstIterator<U> &rhs) 
	{
		return lhs._data == rhs._data;
	}

	template <class T, class U>
	bool operator!=(const bstIterator<T>& lhs, const bstIterator<U>& rhs)
	{
		return !operator==(lhs, rhs);
	}
}
