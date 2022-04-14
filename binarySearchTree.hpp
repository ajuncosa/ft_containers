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
	/*	private:
			struct Sentinel : public Node<pair<const Key, T> >
			{
				// variable to be able to improve find method using sentinel (bc pair key is const)
				typedef Node<pair<const Key, T> > node_type;
				Key key;
				Sentinel() : node_type(), key() {}
			};*/

		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef	Node<value_type> node_type;
			typedef bstIterator<node_type, value_type> iterator;
			typedef bstIterator<node_type, const value_type> const_iterator;

			binarySearchTree(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _size(0), _comp(comp), _alloc(alloc), _nodeAlloc(node_alloc_type())
			{
				this->_sentinel = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(this->_sentinel, node_type());
				this->_root = this->_sentinel;
			}

			//TODO: add copy constructor, assignment op

			~binarySearchTree()
			{
				this->_deallocateTree(this->_root);
				this->_deleteNode(this->_sentinel);
			}

			iterator find(const key_type &k)
			{
				node_type *finder = this->_root;

				while (finder != this->_sentinel && finder->value.first != k)
				{
					if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else
						finder = finder->right;
				}
				return iterator(finder, this->_sentinel);
			}

			const_iterator find(const key_type &k) const
			{
				node_type *finder = this->_root;

				while (finder != this->_sentinel && finder->value.first != k)
				{
					if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else
						finder = finder->right;
				}
				return const_iterator(finder, this->_sentinel);
			}

			node_type *min(node_type *root)
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
				node_type 	*tmp;
				node_type 	*finder;
				iterator	return_iter;

				if (this->_root == this->_sentinel)
				{
					this->_root = this->_nodeAlloc.allocate(1);
					this->_nodeAlloc.construct(this->_root, node_type(this->_sentinel, this->_sentinel, this->_sentinel, newData));
					this->_sentinel->right = this->_root;
					return_iter = iterator(this->_root, this->_sentinel);
				}
				else
				{
					return_iter = find(newData.first);
					if (return_iter != this->end())
						return ft::make_pair<iterator, bool>(return_iter, false);
					finder = this->_root;
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
					return_iter = iterator(tmp, this->_sentinel);
				}
				this->_size++;
				return ft::make_pair<iterator, bool>(return_iter, true);
			}

			void eraseNode(node_type *node)
			{
				if (node == this->_sentinel)
					return ;
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

			size_type getSize() const
			{
				return this->_size;
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
				else if (oldNode == oldNode->parent->left)
					oldNode->parent->left = newNode;
				else
					oldNode->parent->right = newNode;
				if (newNode != this->_sentinel)
					newNode->parent = oldNode->parent;
			}
	};
}
