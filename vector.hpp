#pragma once
#include <memory>
#include <stdexcept>
#include "iterator.hpp"
#include "iteratorTraits.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
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

			template <class InputIterator>
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
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
				if (n > this->max_size())
					throw std::length_error("vector");
				newData = this->_myAllocator.allocate(n);
				if (this->_data)
				{
					for (size_type i = 0; i < this->_size; i++)
					{
						this->_myAllocator.construct(&newData[i], this->_data[i]);
						this->_myAllocator.destroy(&this->_data[i]);
					}	
					this->_myAllocator.deallocate(this->_data, this->_capacity);
				}
				this->_capacity = n;
				this->_data = newData;
			}

			void resize (size_type n, value_type val = value_type())
			{
				for (size_type i = n; i < this->_size; i++)
					this->_myAllocator.destroy(&this->_data[i]);
				if (n > this->_capacity)
					this->reserve(n);
				for (size_type i = this->_size; i < n; i++)
					this->_myAllocator.construct(&this->_data[i], val);
				this->_size = n;
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

			template <class InputIterator>
  			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				size_type	newSize = 0;

				for (InputIterator it = first; it != last; it++)
					newSize++;
				for (size_type i = 0; i < this->_size; i++)
					this->_myAllocator.destroy(&this->_data[i]);
				if (newSize > this->_capacity)
					this->reserve(newSize);
				size_type	i = 0;
				for (InputIterator it = first; it != last; it++)
				{
					this->_myAllocator.construct(&this->_data[i], *it);
					i++;
				}
				this->_size = newSize;
			}

			void assign(size_type n, const value_type& val)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_myAllocator.destroy(&this->_data[i]);
				if (n > this->_capacity)
					this->reserve(n);
				for (size_type i = 0; i < n; i++)
					this->_myAllocator.construct(&this->_data[i], val);
				this->_size = n;
			}

			void push_back(const value_type& val)
			{
				if (this->_size == this->_capacity)
					this->reserve(this->_capacity * 2);
				this->_myAllocator.construct(&this->_data[this->_size], val);
				this->_size++;
			}

			void pop_back()
			{
				this->_myAllocator.destroy(&this->_data[this->_size - 1]);
				this->_size--;
			}

			iterator insert(iterator position, const value_type& val) //TODO: hacer clean code de los inserts (tal vez pueden compartir funciones con otros metodos como reserve y tal, e.g. reallocate un rango o algo asi)
			{
				pointer		tmp;
				size_type	tmpSize = 0;
				size_type	i;
				pointer		newData;
				size_type	newCapacity;

				if (position == this->end())
					this->push_back(val);
				else
				{
					for (iterator it = position; it != this->end(); it++)
						tmpSize++;
					tmp = this->_myAllocator.allocate(tmpSize);
					i = 0;
					for (iterator it = position; it != this->end(); it++)
					{
						this->_myAllocator.construct(&tmp[i], *it);
						this->_myAllocator.destroy(&*it);
						i++;
					}
					// reallocation:
					if (this->_size == this->_capacity)
					{
						newCapacity = this->_capacity * 2;
						if (newCapacity > this->max_size())
							throw std::length_error("vector");
						newData = this->_myAllocator.allocate(newCapacity);
						if (this->_data)
						{
							i = 0;
							for (iterator it = this->begin(); it != position; it++)
							{
								this->_myAllocator.construct(&newData[i], *it);
								this->_myAllocator.destroy(&*it);
								i++;
							}	
							this->_myAllocator.deallocate(this->_data, this->_capacity);
						}
						this->_capacity = newCapacity;
						this->_data = newData;
						position = iterator(&this->_data[i]);
					}
					// insert:
					this->_myAllocator.construct(&*position, val);
					this->_size++;
					// copy the after-insert part:
					i = 0;
					for (iterator it = position + 1; it != this->end(); it++)
					{
						this->_myAllocator.construct(&*it, tmp[i]);
						i++;
					}
					// free tmp:
					for (i = 0; i < tmpSize; i++)
						this->_myAllocator.destroy(&tmp[i]);
					this->_myAllocator.deallocate(tmp, tmpSize);
				}
				return position;
			}

			void insert(iterator position, size_type n, const value_type& val) //TODO: clean code
			{
				pointer		tmp;
				size_type	tmpSize = 0;
				size_type	i;
				iterator	it;
				size_type	newCapacity;
				pointer		newData;

				if (position == this->end())
				{
					for (size_type i = 0; i < n; i++)
						this->push_back(val);
					return;
				}
				for (iterator it = position; it != this->end(); it++)
					tmpSize++;
				tmp = this->_myAllocator.allocate(tmpSize);
				i = 0;
				for (iterator it = position; it != this->end(); it++)
				{
					this->_myAllocator.construct(&tmp[i], *it);
					this->_myAllocator.destroy(&*it);
					i++;
				}
				// reallocation:
				if ((this->_size + n) > this->_capacity)
				{
					if ((this->_size + n) > (this->_capacity * 2))
						newCapacity = this->_size + n;
					else
						newCapacity = this->_capacity * 2;
					if (newCapacity > this->max_size())
						throw std::length_error("vector");
					newData = this->_myAllocator.allocate(newCapacity);
					if (this->_data)
					{
						i = 0;
						for (iterator it = this->begin(); it != position; it++)
						{
							this->_myAllocator.construct(&newData[i], *it);
							this->_myAllocator.destroy(&*it);
							i++;
						}
						this->_myAllocator.deallocate(this->_data, this->_capacity);
					}
					this->_capacity = newCapacity;
					this->_data = newData;
					position = iterator(&this->_data[i]);
				}
				// insert:
				it = position;
				for (i = 0; i < n; i++)
				{
					this->_myAllocator.construct(&*it, val);
					this->_size++;
					it++;
				}
				// copy the after-insert part:
				i = 0;
				for (it = position + n; it != this->end(); it++)
				{
					this->_myAllocator.construct(&*it, tmp[i]);
					i++;
				}
				// free tmp:
				for (i = 0; i < tmpSize; i++)
					this->_myAllocator.destroy(&tmp[i]);
				this->_myAllocator.deallocate(tmp, tmpSize);
			}

			template <class InputIterator> //TODO: clean code
    		void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				pointer		tmp;
				size_type	tmpSize = 0;
				size_type	rangeSize = 0;
				size_type	i;
				iterator	it;
				size_type	newCapacity;
				pointer		newData;

				if (position == this->end())
				{
					for (InputIterator it = first; it != last; it++)
						this->push_back(*it);
					return;
				}
				for (InputIterator it = first; it != last; it++)
					rangeSize++;
				for (iterator it = position; it != this->end(); it++)
					tmpSize++;
				tmp = this->_myAllocator.allocate(tmpSize);
				i = 0;
				for (iterator it = position; it != this->end(); it++)
				{
					this->_myAllocator.construct(&tmp[i], *it);
					this->_myAllocator.destroy(&*it);
					i++;
				}
				// reallocation:
				if ((this->_size + rangeSize) > this->_capacity)
				{
					if ((this->_size + rangeSize) > (this->_capacity * 2))
						newCapacity = this->_size + rangeSize;
					else
						newCapacity = this->_capacity * 2;
					if (newCapacity > this->max_size())
						throw std::length_error("vector");
					newData = this->_myAllocator.allocate(newCapacity);
					if (this->_data)
					{
						i = 0;
						for (iterator it = this->begin(); it != position; it++)
						{
							this->_myAllocator.construct(&newData[i], *it);
							this->_myAllocator.destroy(&*it);
							i++;
						}
						this->_myAllocator.deallocate(this->_data, this->_capacity);
					}
					this->_capacity = newCapacity;
					this->_data = newData;
					position = iterator(&this->_data[i]);
				}
				// insert:
				it = position;
				for (InputIterator range = first; range != last; range++)
				{
					this->_myAllocator.construct(&*it, *range);
					this->_size++;
					it++;
				}
				// copy the after-insert part:
				i = 0;
				for (it = position + rangeSize; it != this->end(); it++)
				{
					this->_myAllocator.construct(&*it, tmp[i]);
					i++;
				}
				// free tmp:
				for (i = 0; i < tmpSize; i++)
					this->_myAllocator.destroy(&tmp[i]);
				this->_myAllocator.deallocate(tmp, tmpSize);
			}

			iterator erase(iterator position) //TODO: clean code
			{
				size_type	tmpSize = 0;
				size_type	i;
				pointer		tmp;

				if (position == (this->end() - 1))
				{
					this->pop_back();
					return position;
				}
				for (iterator it = position + 1; it != this->end(); it++)
					tmpSize++;
				tmp = this->_myAllocator.allocate(tmpSize);
				i = 0;
				for (iterator it = position + 1; it != this->end(); it++)
				{
					this->_myAllocator.construct(&tmp[i], *it);
					this->_myAllocator.destroy(&*it);
					i++;
				}
				//erase:
				this->_myAllocator.destroy(&*position);
				this->_size--;
				// copy the after-insert part:
				i = 0;
				for (iterator it = position; it != this->end(); it++)
				{
					this->_myAllocator.construct(&*it, tmp[i]);
					i++;
				}
				//free tmp:
				for (i = 0; i < tmpSize; i++)
					this->_myAllocator.destroy(&tmp[i]);
				this->_myAllocator.deallocate(tmp, tmpSize);
				return position;
			}

			iterator erase(iterator first, iterator last) //TODO: clean code
			{
				size_type	tmpSize = 0;
				size_type	i;
				pointer		tmp;

				for (iterator it = last; it != this->end(); it++)
					tmpSize++;
				tmp = this->_myAllocator.allocate(tmpSize);
				i = 0;
				for (iterator it = last; it != this->end(); it++)
				{
					this->_myAllocator.construct(&tmp[i], *it);
					this->_myAllocator.destroy(&*it);
					i++;
				}
				//erase:
				for (iterator it = first; it != last; it++)
				{
					this->_myAllocator.destroy(&*it);
					this->_size--;
				}
				// copy the after-insert part:
				i = 0;
				for (iterator it = first; it != this->end(); it++)
				{
					this->_myAllocator.construct(&*it, tmp[i]);
					i++;
				}
				//free tmp:
				for (i = 0; i < tmpSize; i++)
					this->_myAllocator.destroy(&tmp[i]);
				this->_myAllocator.deallocate(tmp, tmpSize);
				return first;
			}

		private:
			pointer			_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_myAllocator;
	};
}
