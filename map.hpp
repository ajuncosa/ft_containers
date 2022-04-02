#pragma once
#include <memory>
#include "iterator.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			//typedef value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			//typedef iterator;
			//typedef const_iterator;
			//typedef reverse_iterator;
			//typedef const_reverse_iterator;
			//typedef iterator_traits<iterator>::difference_type difference_type
			typedef size_t size_type;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				this->_comp = comp;
				this->_alloc = alloc;
			//	this->_size = 0;
			//	this->_nodeAlloc = node_alloc_type();
			//	this->_root = this->_nodeAlloc.allocate(1);
			//	this->_nodeAlloc.construct(this->_root, Node());
			}

		/*	template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				size_type count = 0;
				this->_comp = comp;
				this->_alloc = alloc;
				this->_sentinel = this->_nodeAlloc.allocate(sizeof(Node));
				this->_nodeAlloc.construct(this->_sentinel, Node());
				this->_root = _sentinel;
				for (InputIterator it = first; it != last; it++)
				{
					count++;
				}
			}*/

			/*map(const map& x)
			{

			}*/

			/*~map()
			{
			}*/

		private:
		/*
			size_type		_size;
			allocator_type	_alloc;
			node_alloc_type	_nodeAlloc;
			key_compare		_comp;
			Node			*_root;*/
	};
}
