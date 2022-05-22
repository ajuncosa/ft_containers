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
			typedef typename node_type::Colour node_colour_type;
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
					this->_root->recolor();
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
				node_type			*substitute;
				node_type			*substituteParent;
				node_colour_type 	originalColour;

				if (node == this->_sentinel)
					return ;
				if (node == this->max(this->_root))
					this->_sentinel->left = (--iterator(node, this->_sentinel)).getData();
				originalColour = node->colour;
				// case where node has no children || only a right child:
				if (node->left == this->_sentinel)
				{
					substitute = node->right;
					substituteParent = node->parent;
					this->_nodeTransplant(node, node->right);
				}
				// case where node has only a left child:
				else if (node->right == this->_sentinel)
				{
					substitute = node->left;
					substituteParent = node->parent;
					this->_nodeTransplant(node, node->left);
				}
				// case where node has two children:
				else
				{
					node_type *inOrderSuccessor = this->min(node->right);
					substitute = inOrderSuccessor->right;
					/*
						"substitute" is the node that substitutes the recently deleted node.
						In my implementation, to avoid invalidation of pointers and iterators, the
						deleted node is fully substituted with another one, even if it has two children.
						However, for theoretical purposes, we assume that the deleted node is actually
						inOrderSuccessor (as if we replaced node's contents with IOS's contents,
						and then deleted IOS, because we "can only delete leaf nodes"), thus
						"substitute" is the node that substitutes IOS.
					*/
					substituteParent = inOrderSuccessor;
					if (inOrderSuccessor->parent != node)
					{
						substituteParent = inOrderSuccessor->parent;
						this->_nodeTransplant(inOrderSuccessor, inOrderSuccessor->right);
						inOrderSuccessor->right = node->right;
						node->right->parent = inOrderSuccessor;
					}
					originalColour = inOrderSuccessor->colour; //colour of the "theorically" deleted node, i.e. IOS, in this case.
					this->_nodeTransplant(node, inOrderSuccessor);
					inOrderSuccessor->left = node->left;
					node->left->parent = inOrderSuccessor;
					inOrderSuccessor->colour = node->colour; // as if we were simply replacing the contents of the node, IOS keeps node's colour.
				}
				this->_deleteNode(node);
				this->_size--;
				if (originalColour)
					this->balanceTreeAfterDelete(substitute, substituteParent);
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
					this->_root = newNode;
				if (oldNode == oldNode->parent->left)
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
				this->balanceTreeAfterInsert(tmp);
				return iterator(tmp, this->_sentinel);
			}

			void leftRotate(node_type *node)
			{
				node_type *right = node->right;
				
				if (node == this->_sentinel || right == this->_sentinel)
					return ;
				this->_nodeTransplant(node, right);
				node->right = right->left;
				right->left->parent = node;
				right->left = node;
				node->parent = right;
			}

			void rightRotate(node_type *node)
			{
				node_type *left = node->left;
				
				if (node == this->_sentinel || left == this->_sentinel)
					return ;
				this->_nodeTransplant(node, left);
				node->left = left->right;
				left->right->parent = node;
				left->right = node;
				node->parent = left;
			}

			void balanceTreeAfterInsert(node_type *newNode)
			{
				node_type	*uncle;
				node_type	*parent = newNode->parent;
				node_type	*grandparent = parent->parent;
				/*
					Red-black properties:
					1. Every node is either red or black.
					2. The root node of the tree is black
					3. Every leaf (NULL) node is black.
					4. If a node is red, then both its children are black.
					5. Every simple path from a node to a leaf contains the same number of black nodes.
				*/

				while (!parent->colour)
				{
					uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;
					if (!uncle->colour)
					{
						uncle->recolor();
						parent->recolor();
						if (grandparent != this->_root)
							grandparent->recolor();
						newNode = grandparent;
					}
					else
					{
						if (parent == grandparent->right)
						{
							if (newNode == parent->right)
							{
								this->leftRotate(grandparent);
								grandparent->recolor();
								parent->recolor();
							}
							else
							{
								this->rightRotate(parent);
								this->leftRotate(grandparent);
								grandparent->recolor();
								newNode->recolor();
							}
						}
						else
						{
							if (newNode == parent->left)
							{
								this->rightRotate(grandparent);
								grandparent->recolor();
								parent->recolor();
							}
							else
							{
								this->leftRotate(parent);
								this->rightRotate(grandparent);
								grandparent->recolor();
								newNode->recolor();
							}
						}
					}
					parent = newNode->parent;
					grandparent = parent->parent;
					if (newNode == this->_root)
						break ;
				}
				if (!this->_root->colour)
					this->_root->recolor();
			}

 			// x is the node that substitutes the recently deleted node
			void balanceTreeAfterDelete(node_type *x, node_type *parent)
			{
				node_type *sibling;

				if (!x->colour)
				{
					x->recolor();
					return;
				}
				// x acts as placeholder
				while (x != this->_root && x->colour)
				{
					if (x == parent->left)
					{
						sibling = parent->right;
						if (!sibling->colour)
						{
							sibling->recolor();
							if (parent->colour)
								parent->recolor();
							this->leftRotate(parent);
							sibling = parent->right;
						}
						if (sibling != this->_sentinel && sibling->left->colour && sibling->right->colour)
						{
							sibling->recolor();
							x = parent;
						}
						else
						{
							if (sibling != this->_sentinel && sibling->right->colour)
							{
								if (!sibling->left->colour)
									sibling->left->recolor();
								if (sibling->colour)
									sibling->recolor();
								this->rightRotate(sibling);
								sibling = parent->right;
							}
							sibling->colour = parent->colour;
							if (!parent->colour)
								parent->recolor();
							if (sibling != this->_sentinel && !sibling->right->colour)
								sibling->right->recolor();
							this->leftRotate(parent);
							x = this->_root;
						}
					}
					else
					{
						sibling = parent->left;
						if (!sibling->colour)
						{
							sibling->recolor();
							if (parent->colour)
								parent->recolor();
							this->rightRotate(parent);
							sibling = parent->left;
						}
						if (sibling != this->_sentinel && sibling->right->colour && sibling->left->colour)
						{
							sibling->recolor();
							x = parent;
						}
						else
						{
							if (sibling != this->_sentinel && sibling->left->colour)
							{
								if (!sibling->right->colour)
									sibling->right->recolor();
								if (sibling->colour)
									sibling->recolor();
								this->leftRotate(sibling);
								sibling = parent->left;
							}
							sibling->colour = parent->colour;
							if (!parent->colour)
								parent->recolor();
							if (sibling != this->_sentinel && !sibling->left->colour)
								sibling->left->recolor();
							this->rightRotate(parent);
							x = this->_root;
						}
					}
					parent = x->parent;
				}
				if (!x->colour)
					x->recolor();
			}
	};
}
