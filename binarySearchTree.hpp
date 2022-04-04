#pragma once
#include <memory>
#include "pair.hpp"
#include "bstIterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class binarySearchTree
	{
		private:
			struct Node;

		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef bstIterator<Node> iterator;

			binarySearchTree(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _size(0), _comp(comp), _alloc(alloc), _nodeAlloc(node_alloc_type())
			{
				this->_root = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(this->_root, Node());
			}

			//TODO: add copy constructor, assignment op

			~binarySearchTree() // TODO: destruir con el iterador para eliminarlo todo
			{
				std::cout << "THIS TREE CONTAINS: " << std::endl;
				Node *it;
				if (this->_root->sentinel == false)
				{
					this->_nodeAlloc.destroy(this->_root->parent);
					this->_nodeAlloc.deallocate(this->_root->parent, 1);
				}
				for (it = this->_root; it->sentinel == false; it = it->right)
				{
					std::cout << "value: " << it->value.first << ", " << it->value.second << std::endl;
					this->_nodeAlloc.destroy(it);
					this->_nodeAlloc.deallocate(it, 1);
				}
				this->_nodeAlloc.destroy(it);
				this->_nodeAlloc.deallocate(it, 1);
			}

			Node *find(const key_type &k)
			{
				Node *finder = this->_root;
				while (finder->sentinel == false)
				{
					if (!this->_comp(k, finder->value.first) && !this->_comp(finder->value.first, k))
						return finder;
					else if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else
						finder = finder->right;
				}
				return finder;
			}

			void insert(const value_type &newData)
			{
				Node *tmp;
				Node *sentinelOne;
				Node *sentinelTwo;

				sentinelOne = this->_nodeAlloc.allocate(1);
				sentinelTwo = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(sentinelOne, Node());
				this->_nodeAlloc.construct(sentinelTwo, Node());
				if (this->_root->sentinel == true)
				{
					tmp = this->_root;
					this->_root = this->_nodeAlloc.allocate(1);
					sentinelOne->parent = this->_root;
					sentinelTwo->parent = this->_root;
					this->_nodeAlloc.construct(this->_root, Node(tmp, sentinelOne, sentinelTwo, newData));
				}
				else
				{
					Node *finder = find(newData.first);
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
					this->_nodeAlloc.construct(tmp, Node(finder, sentinelOne, sentinelTwo, newData));
				}
				this->_size++;
			}

		private:
			struct Node
			{
				bool		sentinel;
				Node		*left;
				Node		*right;
				Node		*parent;
				value_type	value;

				Node() : sentinel(true), parent(NULL), left(NULL), right(NULL), value() {}
				Node(Node *parent, Node *left, Node *right, value_type value) : sentinel(false), parent(parent), left(left), right(right), value(value) {}
				Node(const Node &src) : sentinel(src.sentinel), parent(src.parent), left(src.left), right(src.right), value(src.value) {}
				/*Node &operator=(const Node &src)
				{
					if (this != &src)
					{
						this->sentinel = src.sentinel;
						this->left = src.left;
						this->right = src.right;
						this->parent = src.parent;
						this->value = src.value;
					}
					return *this;
				}*/
				~Node() {}
			};

			typedef	typename allocator_type::template rebind<Node>::other node_alloc_type;

			Node 			*_root;
			size_type		_size;
			allocator_type	_alloc;
			node_alloc_type	_nodeAlloc;
			key_compare		_comp;
	};
}
