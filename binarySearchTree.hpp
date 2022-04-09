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
				// TODO: no se puede liberar con iteradores, buscar otra forma
			}

			/*node_type *find(const key_type &k)
			{
				node_type *finder = this->_root;

				//this->_sentinel->key = k;
				while (finder != this->_sentinel && finder->value.first != k)
				{
					if (this->_comp(k, finder->value.first) == true)
						finder = finder->left;
					else
						finder = finder->right;
				}
				//this->_sentinel->value = value_type();
				return finder;
			}
			*/

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

			void insert(const value_type &newData)
			{
				node_type *tmp;
				node_type *finder;

				if (this->_root == this->_sentinel)
				{
					this->_root = this->_nodeAlloc.allocate(1);
					this->_nodeAlloc.construct(this->_root, node_type(this->_sentinel, this->_sentinel, this->_sentinel, newData));
					this->_sentinel->right = this->_root;
				}
				else
				{
					finder = this->_root;
					while (finder->left != this->_sentinel && finder->right != this->_sentinel)
					{
						if (this->_comp(newData.first, finder->value.first) == true)
							finder = finder->left;
						else if (this->_comp(finder->value.first, newData.first) == true)
							finder = finder->right;
						else
							return;
					}
					tmp = this->_nodeAlloc.allocate(1);
					if (this->_comp(newData.first, finder->value.first) == true)
						finder->left = tmp;
					else
						finder->right = tmp;
					this->_nodeAlloc.construct(tmp, node_type(finder, this->_sentinel, this->_sentinel, newData));
					if (tmp == this->max(this->_root))
						this->_sentinel->parent = tmp; // TODO: comprobar si esto funciona para el --
				}
				this->_size++;
			}

		/*	void eraseNode(node_type *node)
			{
				node_type* current = node;
				if (current->sentinel)
					return;
				if (current->left->sentinel && current->right->sentinel)
				{
					if (current != this->_root)
					{
						if (current->parent->left == current) {
							current->parent->left->s;
						}
						else {
							current->parent->right = nullptr;
						}
					}
					// if the tree has only a root node, set it to null
					else {
						root = nullptr;
					}
			
					// deallocate the memory
					free(current);        // or delete current;
				}
			
				// Case 2: node to be deleted has two children
				else if (current->left && current->right)
				{
					// find its inorder successor node
					Node* successor = getMinimumKey(current->right);
			
					// store successor value
					int val = successor->data;
			
					// recursively delete the successor. Note that the successor
					// will have at most one child (right child)
					deleteNode(root, successor->data);
			
					// copy value of the successor to the current node
					current->data = val;
				}
			
				// Case 3: node to be deleted has only one child
				else {
					// choose a child node
					Node* child = (current->left)? current->left: current->right;
			
					// if the node to be deleted is not a root node, set its parent
					// to its child
					if (current != root)
					{
						if (current == parent->left) {
							parent->left = child;
						}
						else {
							parent->right = child;
						}
					}
			
					// if the node to be deleted is a root node, then set the root to the child
					else {
						root = child;
					}
			
					// deallocate the memory
					free(current);
				}
				
				
				this->_size--;
			}*/

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
				node_type *finder = this->_root;
				while (finder != this->_sentinel)
					finder = finder->right;
				return iterator(finder, this->_sentinel);
			}

			const_iterator end() const
			{
				node_type *finder = this->_root;
				while (finder != this->_sentinel)
					finder = finder->right;
				return const_iterator(finder, this->_sentinel);
			}

		private:
			typedef	typename allocator_type::template rebind<node_type>::other node_alloc_type;

			node_type		*_root;
			node_type		*_sentinel;
			size_type		_size;
			allocator_type	_alloc;
			node_alloc_type	_nodeAlloc;
			key_compare		_comp;

			void deleteNode(node_type *node)
			{
				this->_nodeAlloc.destroy(node);
				this->_nodeAlloc.deallocate(node, 1);
			}
	};
}
