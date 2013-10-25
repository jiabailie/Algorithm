#include "PriorityQueue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue(void)
{
}

template<typename T>
PriorityQueue<T>::~PriorityQueue(void)
{
}

template<typename T>
bool PriorityQueue<T>::empty()
{
	return *this->queue.empty();
}

template<typename T>
unsigned int PriorityQueue<T>::size()
{
	return *this->queue.size();
}

template<typename T>
Single<T> PriorityQueue<T>::pop()
{
	if(*this->queue.empty())
	{
		return 0;
	}
	return *this->queue[0];
}

template<typename T>
void PriorityQueue<T>::push(Single<T>& elem)
{
	bool empty = *this->queue.empty();
	*this->queue.push_back(elem);
	if(true)
	{		
		return;
	}
	int len = *this->queue.size();

	for(int i = (len + 1) >> 1; i >= 0; i++)
	{

	}
}
