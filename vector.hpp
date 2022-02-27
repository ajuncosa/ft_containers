#pragma once
#include <memory>
#include "iterator.hpp"
#include "iteratorTraits.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> > //TODO: catch exceptions from allocator
	class vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef randomAccessIterator<value_type> iterator;
			typedef randomAccessIterator<const value_type> const_iterator;
			//typedef reverse_iterator;
			//typedef const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;

			explicit vector(const allocator_type& alloc = allocator_type())
			{
				this->_size = 0;
				this->_capacity = 0;
				this->_myAllocator = alloc;
				this->_data = NULL;
			}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				this->_size = n;
				this->_capacity = n;
				this->_myAllocator = alloc;
				this->_data = this->_myAllocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_myAllocator.construct(&this->_data[i], val);
			}
/*
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				this->_size = 0;
				for (InputIterator it = first; it != last; it++)
					this->_size++;
				this->_capacity = this->_size;
				this->_myAllocator = alloc;
				this->_data = this->_myAllocator.allocate(this->_capacity);
				size_type i = 0;
				for (InputIterator it = first; it != last; it++)
				{
					this->_myAllocator.construct(&this->_data[i], *it);
					i++;
				}
			};
*/
			vector(const vector& x)
			{
				this->_size = x.size();
				this->_capacity = x.capacity();
				this->_myAllocator = x.get_allocator();
				this->_data = this->_myAllocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_myAllocator.construct(&this->_data[i], x._data[i]);
			}

			vector& operator=(const vector& x)
			{
				if (this != &x)
				{
					if (this->_data)
					{
						for (size_type i = 0; i < this->_size; i++)
							this->_myAllocator.destroy(&this->_data[i]);
						this->_myAllocator.deallocate(this->_data, this->_capacity);
					}
					this->_size = x.size();
					this->_capacity = x.capacity();
					this->_data = this->_myAllocator.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; i++)
						this->_myAllocator.construct(&this->_data[i], x._data[i]);
				}
				return *this;
			}

			~vector()
			{
				/*
				for (size_type i = 0; i < this->_size; i++)
					std::cout << this->_data[i];
				std::cout << std::endl;
				*/
				if (this->_data)
				{
					for (size_type i = 0; i < this->_size; i++)
						this->_myAllocator.destroy(&this->_data[i]);
					this->_myAllocator.deallocate(this->_data, this->_capacity);
				}
			}

			allocator_type get_allocator() const
			{
				return this->_myAllocator;
			}

			size_type size() const
			{
				return this->_size;
			}

			size_type max_size() const
			{
				return this->_myAllocator.max_size();
			}

			/*void resize (size_type n, value_type val = value_type())
			{

			}*/

			size_type capacity() const
			{
				return this->_capacity;
			}

			bool empty() const
			{
				return this->_size == 0 ? true : false;
			}

			void reserve(size_type n)
			{
				pointer	newData;

				if (n <= this->_capacity)
					return;
				newData = this->_myAllocator.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
					this->_myAllocator.construct(&newData[i], this->_data[i]);
				if (this->_data)
				{
					for (size_type i = 0; i < this->_size; i++)
						this->_myAllocator.destroy(&this->_data[i]);
					this->_myAllocator.deallocate(this->_data, this->_capacity);
				}
				this->_capacity = n;
				this->_data = newData;
			}

			iterator begin()
			{
				iterator it(this->_data);
				return it;
			}

			const_iterator begin() const
			{
				const_iterator it(this->_data);
				return it;
			}

			iterator end()
			{
				if (this->empty())
					return this->begin();
				iterator it(&this->_data[this->size()]);
				return it;
			}

			const_iterator end() const
			{
				if (this->empty())
					return this->begin();
				const_iterator it(&this->_data[this->size()]);
				return it;
			}
			/*
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			*/

		private:
			pointer			_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_myAllocator;
	};
}
