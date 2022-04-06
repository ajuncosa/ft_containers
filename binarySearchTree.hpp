#pragma once
#include <memory>
#include "pair.hpp"
#include "bstIterator.hpp"
#include "node.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class binarySearchTree
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef	Node<value_type> node_type;
			typedef Node<const value_type> const_node_type;
			typedef bstIterator<node_type> iterator;
			typedef bstIterator<const_node_type> const_iterator;

			binarySearchTree(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _size(0), _comp(comp), _alloc(alloc), _nodeAlloc(node_alloc_type())
			{
				this->_root = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(this->_root, node_type());
			}

			//TODO: add copy constructor, assignment op

			~binarySearchTree()
			{
				if (this->_root->sentinel == false)
				{
					this->_nodeAlloc.destroy(this->_root->parent);
					this->_nodeAlloc.deallocate(this->_root->parent, 1);
				}
				// TODO: no se puede liberar con iteradores, buscar otra forma
			}

			node_type *find(const key_type &k)
			{
				node_type *finder = this->_root;
				while (finder->sentinel == false)
				{
					if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else if (this->_comp(finder->value.first, k) == true)
						finder = finder->right;
					else
						break;
				}
				return finder;
			}

			void insert(const value_type &newData)
			{
				node_type *tmp;
				node_type *sentinelOne;
				node_type *sentinelTwo;

				sentinelOne = this->_nodeAlloc.allocate(1);
				sentinelTwo = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(sentinelOne, node_type());
				this->_nodeAlloc.construct(sentinelTwo, node_type());
				if (this->_root->sentinel == true)
				{
					tmp = this->_root;
					this->_root = this->_nodeAlloc.allocate(1);
					sentinelOne->parent = this->_root;
					sentinelTwo->parent = this->_root;
					this->_nodeAlloc.construct(this->_root, node_type(tmp, sentinelOne, sentinelTwo, newData));
				}
				else
				{
					node_type *finder = find(newData.first);
					if (finder->sentinel == false)
						return ;
					tmp = this->_nodeAlloc.allocate(1);
					sentinelOne->parent = tmp;
					sentinelTwo->parent = tmp;
					finder = finder->parent;
					if (this->_comp(newData.first, finder->value.first) == true)
					{
						this->_nodeAlloc.destroy(finder->left);
						this->_nodeAlloc.deallocate(finder->left, 1);
						finder->left = tmp;
					}
					else
					{
						this->_nodeAlloc.destroy(finder->right);
						this->_nodeAlloc.deallocate(finder->right, 1);
						finder->right = tmp;
					}
					this->_nodeAlloc.construct(tmp, node_type(finder, sentinelOne, sentinelTwo, newData));
				}
				this->_size++;
			}

			void erase_element(node_type *node)
			{
				if (node == node->parent->left)
					node->parent->left = node->left;
				else if (node == node->parent->right)
					node->parent->right = node->right;
				this->_nodeAlloc.destroy(node);
				this->_nodeAlloc.deallocate(node, 1);
				this->_size--;
			}

			iterator begin()
			{
				node_type *finder = this->_root;
				while (finder->sentinel == false && finder->left->sentinel == false)
					finder = finder->left;
				return iterator(finder);
			}

			const_iterator begin() const
			{
				const_node_type *finder = this->_root;
				while (finder->sentinel == false && finder->left->sentinel == false)
					finder = finder->left;
				return const_iterator(finder);
			}

			iterator end()
			{
				node_type *finder = this->_root;
				while (finder->sentinel == false)
					finder = finder->right;
				return iterator(finder);
			}

			/*const_iterator end() const
			{
				const_node_type *finder = this->_root;
				while (finder->sentinel == false)
					finder = finder->right;
				return const_iterator(finder);
			}*/

		private:
			typedef	typename allocator_type::template rebind<node_type>::other node_alloc_type;

			node_type		*_root;
			size_type		_size;
			allocator_type	_alloc;
			node_alloc_type	_nodeAlloc;
			key_compare		_comp;
	};
}
