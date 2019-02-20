#ifndef NODE
#define NODE

template<class T>
struct Node
{
	Node(const T& data, Node<T>* next=nullptr)
			: m_data(data), m_next(next)
	{
	}
private:
T m_data;
Node<T>* m_next; 
};

#endif
