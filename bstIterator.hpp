#pragma once
#include "iterator.hpp"
#include "enable_if.hpp"

namespace ft
{
	//FIXME: construir iterator normal a partir de uno const, no deberia funcionar
	template <class Node, class T, bool Const, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
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

			template <class U, class V, bool W>
			bstIterator(const typename ft::enable_if<!W, bstIterator<U, V, W> >::type &src) : _data(src.getData()), _sentinel(src.getSentinel()) {}
			
			bstIterator(const bstIterator &src) : _data(src.getData()), _sentinel(src.getSentinel()) {}

			bstIterator(Node *node, Node *sentinel) : _data(node), _sentinel(sentinel) {}

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

			reference operator*() const
			{
				return this->_data->value;
			}

			pointer operator->() const
			{
				return &this->_data->value;
			}

			bstIterator& operator++()
			{
				if (this->_data != this->_sentinel)
				{
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
				}
				return *this;
			}

			bstIterator operator++(int)
			{
				bstIterator tmp(*this);
				if (this->_data != this->_sentinel)
				{
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
				}
				return tmp;
			}

			bstIterator& operator--()
			{
				if (this->_data->left != this->_sentinel)
				{
					this->_data = this->_data->left;
					while (this->_data->right != this->_sentinel)
						this->_data = this->_data->right;
				}
				else
				{
					while (this->_data->parent != this->_sentinel && this->_data != this->_data->parent->right)
						this->_data = this->_data->parent;
					this->_data = this->_data->parent;
				}
				return *this;
			}

			bstIterator operator--(int)
			{
				bstIterator tmp(*this);
				if (this->_data->left != this->_sentinel)
				{
					this->_data = this->_data->left;
					while (this->_data->right != this->_sentinel)
						this->_data = this->_data->right;
				}
				else
				{
					while (this->_data->parent != this->_sentinel && this->_data != this->_data->parent->right)
						this->_data = this->_data->parent;
					this->_data = this->_data->parent;
				}
				return tmp;
			}

			Node *getData() const
			{
				return this->_data;
			}

			Node *getSentinel() const
			{
				return this->_sentinel;
			}

		private:
			template <class U, class V, bool W, class X, class Y, bool Z>
			friend bool operator==(const bstIterator<U, V, W> &lhs, const bstIterator<X, Y, Z> &rhs); 

			Node	*_data;
			Node	*_sentinel;
	};

	template <class T, class U, bool V, class W, class X, bool Y>
	bool operator==(const bstIterator<T, U, V> &lhs, const bstIterator<W, X, Y> &rhs) 
	{
		return lhs._data == rhs._data;
	}

	template <class T, class U, bool V, class W, class X, bool Y>
	bool operator!=(const bstIterator<T, U, V> &lhs, const bstIterator<W, X, Y> &rhs)
	{
		return !operator==(lhs, rhs);
	}
}
