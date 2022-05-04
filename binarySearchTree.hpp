#pragma once
#include <memory>
#include "pair.hpp"
#include "bstIterator.hpp"
#include "node.hpp"
#include "reverse_iterator.hpp"

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
			typedef bstIterator<node_type, value_type, false> iterator;
			typedef bstIterator<node_type, const value_type, true> const_iterator;
			typedef reverse_iterator<const_iterator> const_reverse_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;

			binarySearchTree(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _size(0), _comp(comp), _alloc(alloc), _nodeAlloc()
			{
				this->_sentinel = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(this->_sentinel, node_type());
				this->_root = this->_sentinel;
			}

			binarySearchTree(const binarySearchTree &src) : _size(0), _comp(src.getComp()), _alloc(src.getAlloc()), _nodeAlloc()
			{
				this->_sentinel = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(this->_sentinel, node_type());
				this->_root = this->_sentinel;
				for (const_iterator it = src.begin(); it != src.end(); it++)
					this->insert(*it);
			}

			binarySearchTree &operator=(const binarySearchTree &src)
			{
				if (this != &src)
				{
					this->_deallocateTree(this->_root);
					this->_deleteNode(this->_sentinel);
					this->_size = 0;
					this->_comp = src.getComp();
					this->_alloc = src.getAlloc();
					this->_nodeAlloc = node_alloc_type();
					this->_sentinel = this->_nodeAlloc.allocate(1);
					this->_nodeAlloc.construct(this->_sentinel, node_type());
					this->_root = this->_sentinel;
					for (const_iterator it = src.begin(); it != src.end(); it++)
						this->insert(*it);
				}
				return *this;
			}

			~binarySearchTree()
			{
				this->_deallocateTree(this->_root);
				this->_deleteNode(this->_sentinel);
			}

			iterator find(const key_type &k)
			{
				node_type *finder = this->_root;

				while (finder != this->_sentinel)
				{
					if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else if (this->_comp(finder->value.first, k) == true)
						finder = finder->right;
					else
						break;
				}
				return iterator(finder, this->_sentinel);
			}

			const_iterator find(const key_type &k) const
			{
				node_type *finder = this->_root;

				while (finder != this->_sentinel)
				{
					if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else if (this->_comp(finder->value.first, k) == true)
						finder = finder->right;
					else
						break;
				}
				return const_iterator(finder, this->_sentinel);
			}

			size_type count(const key_type &k) const
			{
				node_type	*finder = this->_root;

				while (finder != this->_sentinel)
				{
					if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else if (this->_comp(finder->value.first, k) == true)
						finder = finder->right;
					else
						return 1;
				}
				return 0;
			}

			node_type *min(node_type *root) const
			{
				node_type *finder = root;
				while (finder != this->_sentinel && finder->left != this->_sentinel)
					finder = finder->left;
				return finder;
			}

			node_type *max(node_type *root)
			{
				node_type *finder = root;
				while (finder != this->_sentinel && finder->right != this->_sentinel)
					finder = finder->right;
				return finder;
			}

			pair<iterator, bool> insert(const value_type &newData)
			{
				iterator	return_iter;

				if (this->_root == this->_sentinel)
				{
					this->_root = this->_nodeAlloc.allocate(1);
					this->_nodeAlloc.construct(this->_root, node_type(this->_sentinel, this->_sentinel, this->_sentinel, newData));
					this->_sentinel->right = this->_root;
					this->_sentinel->left = this->_root;
					return_iter = iterator(this->_root, this->_sentinel);
				}
				else
				{
					return_iter = this->find(newData.first);
					if (return_iter != this->end())
						return ft::make_pair<iterator, bool>(return_iter, false);
					return_iter = this->insertNodeIntoSubtree(this->_root, newData);
				}
				this->_size++;
				this->balanceTree();
				return ft::make_pair<iterator, bool>(return_iter, true);
			}

			iterator insert(iterator hint, const value_type &newData)
			{
				iterator ret;
				iterator tmp = hint;
				iterator hintNext = ++hint;
				hint = tmp;
				
				ret = this->find(newData.first);
				if (ret != this->end())
					return ret;
				if ((hint != this->end()) && this->_comp(hint->first, newData.first) && ((hintNext == this->end()) || this->_comp(newData.first, hintNext->first)))
				{
					ret = insertNodeIntoSubtree(hint.getData(), newData);
					this->_size++;
				}
				else
					ret = insert(newData).first;
				return ret;
			}

			void eraseNode(node_type *node)
			{
				if (node == this->_sentinel)
					return ;
				if (node == this->max(this->_root))
					this->_sentinel->left = (--iterator(node, this->_sentinel)).getData();
				// case where node has no children || only a right child:
				if (node->left == this->_sentinel)
					this->_nodeTransplant(node, node->right);
				// case where node has only a left child:
				else if (node->right == this->_sentinel)
					this->_nodeTransplant(node, node->left);
				// case where node has two children:
				else
				{
					node_type *inOrderSuccessor = this->min(node->right);
					if (inOrderSuccessor->parent != node)
					{
						this->_nodeTransplant(inOrderSuccessor, inOrderSuccessor->right);
						inOrderSuccessor->right = node->right;
						node->right->parent = inOrderSuccessor;
					}
					this->_nodeTransplant(node, inOrderSuccessor);
					inOrderSuccessor->left = node->left;
					node->left->parent = inOrderSuccessor;
				}
				this->_deleteNode(node);
				this->_size--;
			}

			iterator begin()
			{
				node_type *node = this->min(this->_root);
				return iterator(node, this->_sentinel);
			}

			const_iterator begin() const
			{
				node_type *node = this->min(this->_root);
				return const_iterator(node, this->_sentinel);
			}

			iterator end()
			{
				return iterator(this->_sentinel, this->_sentinel);
			}

			const_iterator end() const
			{
				return const_iterator(this->_sentinel, this->_sentinel);
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

			size_type getSize() const
			{
				return this->_size;
			}

			key_compare getComp() const
			{
				return this->_comp;
			}

			allocator_type getAlloc() const
			{
				return this->_alloc;
			}

			node_type *getRoot() const
			{
				return this->_root;
			}

			node_type *getSentinel() const
			{
				return this->_sentinel;
			}

			bool empty() const
			{
				return this->_size == 0;
			}

			void swap(binarySearchTree &src)
			{
				size_type		tmpSize;
				key_compare		tmpComp;
				allocator_type	tmpAlloc;
				node_alloc_type	tmpNodeAlloc;
				node_type		*tmpRoot;
				node_type		*tmpSentinel;

				tmpSize = this->_size;
				tmpComp = this->_comp;
				tmpAlloc = this->_alloc;
				tmpNodeAlloc = this->_nodeAlloc;
				tmpRoot = this->_root;
				tmpSentinel = this->_sentinel;
				this->_size = src._size;
				this->_comp = src._comp;
				this->_alloc = src._alloc;
				this->_nodeAlloc = src._nodeAlloc;
				this->_root = src._root;
				this->_sentinel = src._sentinel;
				src._size = tmpSize;
				src._comp = tmpComp;
				src._alloc = tmpAlloc;
				src._nodeAlloc = tmpNodeAlloc;
				src._root = tmpRoot;
				src._sentinel = tmpSentinel;
			}

			void printTree() // FIXME: borrar
			{
				if (this->_root)
					printTreeHelper(this->_root, "", true);
			}

			void printTreeHelper(node_type *root, std::string indent, bool last)
			{
				if (root != this->_sentinel)
				{
					std::cout<<indent;
					if (last)
					{
						std::cout<<"R----";
						indent += "     ";
					}
					else
					{
						std::cout<<"L----";
						indent += "|    ";
					}
					if (!root->colour)
						std::cout<< "\x1b[31m[" << root->value.first << "] => " << root->value.second << "\x1b[0m" <<std::endl;
					else
						std::cout<< "\x1b[32m[" << root->value.first << "] => " << root->value.second << "\x1b[0m"<<std::endl;
					
					printTreeHelper(root->left, indent, false);
					printTreeHelper(root->right, indent, true);
				}
			}

		protected:
			typedef	typename allocator_type::template rebind<node_type>::other node_alloc_type;

			size_type		_size;
			key_compare		_comp;
			allocator_type	_alloc;
			node_alloc_type	_nodeAlloc;
			node_type		*_root;
			node_type		*_sentinel;
		
			void _deleteNode(node_type *node)
			{
				this->_nodeAlloc.destroy(node);
				this->_nodeAlloc.deallocate(node, 1);
			}

			void _deallocateTree(node_type *root)
			{
				if (root == this->_sentinel)
					return ;
				_deallocateTree(root->left);
				_deallocateTree(root->right);
				_deleteNode(root);
			}

			void _nodeTransplant(node_type *oldNode, node_type *newNode)
			{
				if (oldNode->parent == this->_sentinel)
				{
					this->_root = newNode;
					this->_sentinel->right = newNode;
				}
				else if (oldNode == oldNode->parent->left)
					oldNode->parent->left = newNode;
				else
					oldNode->parent->right = newNode;
				if (newNode != this->_sentinel)
					newNode->parent = oldNode->parent;
			}

			iterator insertNodeIntoSubtree(node_type *root, const value_type &newData)
			{
				node_type *finder;
				node_type *tmp;

				finder = root;
				while (finder->left != this->_sentinel || finder->right != this->_sentinel)
				{
					if (this->_comp(newData.first, finder->value.first) && finder->left != this->_sentinel)
						finder = finder->left;
					else if (this->_comp(finder->value.first, newData.first) && finder->right != this->_sentinel)
						finder = finder->right;
					else
						break;
				}
				tmp = this->_nodeAlloc.allocate(1);
				if (this->_comp(newData.first, finder->value.first))
					finder->left = tmp;
				else
					finder->right = tmp;
				this->_nodeAlloc.construct(tmp, node_type(finder, this->_sentinel, this->_sentinel, newData));
				if (tmp == this->max(this->_root))
					this->_sentinel->left = tmp;
				return iterator(tmp, this->_sentinel);
			}

			void leftRotate(node_type *node)
			{
				node_type *parent = node->parent;
				node_type *right = node->right;
				
				if (node == this->_sentinel || right == this->_sentinel)
					return ;
				if (node->parent == this->_sentinel)
				{
					this->_root = right;
					this->_sentinel->right = right;
				}
				else if (node == parent->left)
					parent->left = right;
				else
					parent->right = right;
				right->parent = node->parent;
				node->right = right->left;
				right->left = node;
				node->parent = right;
			}

			void rightRotate(node_type *node)
			{
				node_type *parent = node->parent;
				node_type *left = node->left;
				
				if (node == this->_sentinel || left == this->_sentinel)
					return ;
				if (node->parent == this->_sentinel)
				{
					this->_root = left;
					this->_sentinel->right = left;
				}
				else if (node == parent->left)
					parent->left = left;
				else
					parent->right = left;
				left->parent = node->parent;
				node->left = left->right;
				left->right = node;
				node->parent = left;
			}

			void balanceTree()
			{
				/*
					Red-black properties:
					1. Every node is either red or black.
					2. The root node of the tree is black
					3. Every leaf (NULL) node is black.
					4. If a node is red, then both its children are black.
					5. Every simple path from a node to a leaf contains the same number of black nodes.
				*/
			}
	};
}
