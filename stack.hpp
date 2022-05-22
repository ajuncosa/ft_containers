#pragma once
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}

			stack(const stack &other) : c(other.c) {}

			stack &operator=(const stack &other)
			{
				if (this != &other)
					this->c = other.c;
				return *this;
			}

			~stack() {}

			bool empty() const
			{
				return this->c.empty();
			}

			size_type size() const
			{
				return this->c.size();
			}

			value_type& top()
			{
				return this->c.back();
			}

			const value_type& top() const
			{
				return this->c.back();
			}

			void push(const value_type& val)
			{
				this->c.push_back(val);
			}

			void pop()
			{
				this->c.pop_back();
			}
		
		protected:
			container_type	c;

		private:
			template <class U, class Cntr>
			friend bool operator==(const stack<U, Cntr>& lhs, const stack<U, Cntr>& rhs);

			template <class U, class Cntr>
			friend bool operator!=(const stack<U, Cntr>& lhs, const stack<U, Cntr>& rhs);

			template <class U, class Cntr>
			friend bool operator<(const stack<U, Cntr>& lhs, const stack<U, Cntr>& rhs);

			template <class U, class Cntr>
			friend bool operator<=(const stack<U, Cntr>& lhs, const stack<U, Cntr>& rhs);

			template <class U, class Cntr>
			friend bool operator>(const stack<U, Cntr>& lhs, const stack<U, Cntr>& rhs);

			template <class U, class Cntr>
			friend bool operator>=(const stack<U, Cntr>& lhs, const stack<U, Cntr>& rhs);
	};

	template <class T, class Container>
  	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c != rhs.c;
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c < rhs.c;
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c <= rhs.c;
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c > rhs.c;
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c >= rhs.c;
	}
}
