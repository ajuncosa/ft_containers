#pragma once
#include <memory>
#include "iterator.hpp"
#include "bstIterator.hpp"
#include "iteratorTraits.hpp"
#include "pair.hpp"
#include "binarySearchTree.hpp"

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
			typedef	binarySearchTree<key_type, mapped_type, key_compare, allocator_type> tree_type;
			typedef typename tree_type::iterator iterator;
			typedef typename tree_type::const_iterator const_iterator;
			//typedef reverse_iterator;
			//typedef const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc)
			{
				for (InputIterator it = first; it != last; it++)
					this->_tree.insert(*it);
			}

			map(const map &x) : _tree(x._tree) {}

			~map() {}

			iterator find(const key_type &k)
			{
				return this->_tree.find(k);
			}

			const_iterator find(const key_type &k) const
			{
				return this->_tree.find(k);
			}

			pair<iterator, bool> insert(const value_type &val)
			{
				return this->_tree.insert(val);
			}

			iterator insert(iterator hint, const value_type &val)
			{
				return this->_tree.insert(hint, val);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (InputIterator it = first; it != last; it++)
					this->_tree.insert(*it);
			}

			iterator begin()
			{
				return this->_tree.begin();
			}

			const_iterator begin() const
			{
				return this->_tree.begin();
			}

			iterator end()
			{
				return this->_tree.end();
			}

			const_iterator end() const
			{
				return this->_tree.end();
			}

		private:
			tree_type _tree;
	};
}
