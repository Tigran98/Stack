#ifndef LSTACK
#define LSTACK

#include "IStack.hpp"
#include "Node.hpp"
#include "assert.h"

template<class T>
class LStack : public IStack<T>
{
public:
	LStack()
		: m_top(nullptr), m_size(0u)
	{
	}

	virtual ~LStack()
	{
		clear();
	}

	virtual void push(const T& value)
	{
		m_top = new Node<T>(value, m_top);
		++m_size;
	}

	virtual const T& top() const
	{
		assert(!empty());
		return m_top->m_data;
	}

	virtual size_t size() const
	{
		return m_size;	
	}

	virtual void clear()
	{	
		while(!empty())
		{
			pop();
		}
	}

	virtual T pop()
	{	
		const T val = top();
		Node<T>* top = m_top;
		m_top = m_top->next;
		delete top;
		--m_size;
		return val;
	}

private:
Node<T>* m_top;
unsigned int m_size;

};
#endif
