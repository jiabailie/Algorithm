#pragma once
#include <vector>
#include <map>
#include <cstring>

using namespace std;

inline int HeapLeft(int p) { return (p << 1) + 1; }

inline int HeapRight(int p) { return (p + 1) << 1; }

template<typename T>
struct Single
{
	int key;
	T* value;

};

template<typename T>
inline void iSwap(Single<T>& a, Single<T>& b)
{
}

template<typename T>
class PriorityQueue
{
private:
	vector<Single<T> > queue;
public:
	PriorityQueue(void);

	~PriorityQueue(void);

	bool empty();

	unsigned int size();

	Single<T> pop();

	void push(Single<T>&);
};
