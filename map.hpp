#pragma once
#include <memory>
#include <functional>
#include "iterator.hpp"
#include "bstIterator.hpp"
#include "iteratorTraits.hpp"
#include "pair.hpp"
#include "binarySearchTree.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

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
			typedef reverse_iterator<const_iterator> const_reverse_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;
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

			map &operator=(const map &x)
			{
				if (this != &x)
				{
					this->_tree = x._tree;
					this->_comp = x.key_comp();
				}
				return *this;
			}

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

			mapped_type &operator[](const key_type &k)
			{
				iterator kElement = this->insert(ft::make_pair(k, mapped_type())).first;
				return kElement->second;
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
				iterator found = this->find(k);

				if (found == this->end())
					return 0;
				this->erase(found);
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
				this->_tree.swap(x._tree);
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

			reverse_iterator rbegin()
			{
				return reverse_iterator(this->end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(this->end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(this->begin());
			}
			
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(this->begin());
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

			void printMap() //FIXME: borrar
			{
				_tree.printTree();
			}

		private:
			tree_type		_tree;
			allocator_type	_alloc;
			key_compare		_comp;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		if (!(lhs.size() == rhs.size()))
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key,T,Compare,Alloc> &x, map<Key,T,Compare,Alloc> &y)
	{
		x.swap(y);
	}
}
