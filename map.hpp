#pragma once
#include <memory>
#include <functional>
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

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const first_argument_type &x, const second_argument_type &y) const
					{
						return comp(x.first, y.first);
					}
					static value_compare constructObject(Compare c)
					{
						return value_compare(c);
					}
			};

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _alloc(alloc), _comp(comp) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _alloc(alloc), _comp(comp)
			{
				for (InputIterator it = first; it != last; it++)
					this->_tree.insert(*it);
			}

			map(const map &x) : _tree(x._tree), _alloc(x.get_allocator()), _comp(x.key_comp()) {}

			~map() {}

			bool empty() const
			{
				return this->_tree.empty();
			}
			
			size_type size() const
			{
				return this->_tree.getSize();
			}

			size_type max_size() const
			{
				return this->_alloc.max_size();
			}

			iterator find(const key_type &k)
			{
				return this->_tree.find(k);
			}

			const_iterator find(const key_type &k) const
			{
				return this->_tree.find(k);
			}

			size_type count(const key_type &k) const
			{
				return this->_tree.count(k);
			}

			iterator lower_bound(const key_type &k)
			{
				iterator	it = this->begin();

				while (it != this->end() && this->_comp(it->first, k))
					it++;
				return it;
			}

			const_iterator lower_bound(const key_type &k) const
			{
				const_iterator	it = this->begin();

				while (it != this->end() && this->_comp(it->first, k))
					it++;
				return it;
			}

			iterator upper_bound(const key_type &k)
			{
				iterator	it = this->begin();

				while (it != this->end() && !this->_comp(k, it->first))
					it++;
				return it;
			}

			const_iterator upper_bound(const key_type &k) const
			{
				const_iterator	it = this->begin();

				while (it != this->end() && !this->_comp(k, it->first))
					it++;
				return it;
			}

			pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				const_iterator lowerB = this->lower_bound(k);
				const_iterator upperB = this->upper_bound(k);

				return ft::make_pair<const_iterator, const_iterator>(lowerB, upperB);
			}

			pair<iterator, iterator> equal_range(const key_type &k)
			{
				iterator lowerB = this->lower_bound(k);
				iterator upperB = this->upper_bound(k);

				return ft::make_pair<iterator, iterator>(lowerB, upperB);
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

			void erase(iterator position)
			{
				this->_tree.eraseNode(position.getData());
			}

			size_type erase(const key_type &k)
			{
				this->erase(this->find(k));
				return 1;
			}

			void erase(iterator first, iterator last)
			{
				iterator it = first;
				iterator tmp = first;
				while (it != last)
				{
					tmp++;
					this->erase(it);
					it = tmp;
				}
			}

			void swap(map &x)
			{
				tree_type tmpTree = this->_tree;
				this->_tree = x._tree;
				x._tree = tmpTree;

				allocator_type tmpAlloc = this->_alloc;
				this->_alloc = x._alloc;
				x._alloc = tmpAlloc;

				key_compare tmpComp = this->_comp;
				this->_comp = x._comp;
				x._comp = tmpComp;
			}

			void clear()
			{
				erase(this->begin(), this->end());
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

			allocator_type get_allocator() const
			{
				return this->_alloc;
			}

			key_compare key_comp() const
			{
				return this->_comp;
			}

			value_compare value_comp() const
			{
				return value_compare::constructObject(this->_comp);
			}

		private:
			tree_type		_tree;
			allocator_type	_alloc;
			key_compare		_comp;
	};
}
