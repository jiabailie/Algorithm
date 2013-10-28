#pragma once
#include <vector>
#include <map>
#include <cstring>

using namespace std;

inline int HeapLeft(int p) { return (p << 1) + 1; }

inline int HeapRight(int p) { return (p + 1) << 1; }

template<typename T>
class Single
{
public:
        int key;
        T* value;

        Single() {}

        Single(const int _key, const void* _value)
        {
                key = _key;
                value = (T*)_value;  // set the current pointer points at the address of _value
		_value = 0;	     // free the original pointer
        }

        Single(const Single& _single)
        {
                if(&_single == this) { return; }
                Single(_single.key, _single.value);
        }

        Single& operator=(const Single& _single)
        {
                if(&_single == this) { return *this; }
                Single(_single.key, _single.value);
                return *this;
        }

        ~Single()
        {
                delete value;
        }
};

template<typename T>
inline void iSwap(Single<T>*& a, Single<T>*& b)
{
        Single<T>* c = a;
        a = b;
        b = c;
}

template<typename T>
class PriorityQueue
{
private:
        vector<Single<T>*> queue;
public:
        PriorityQueue(void) {};

        ~PriorityQueue(void) {};

        bool empty() { return queue.empty(); }

        unsigned int size() { return queue.size(); }

        Single<T>* pop()
        {
                if(queue.empty())
                {
                        return 0;
                }
                Single<T>* top = queue[0];
                queue.erase(queue.begin());
                if(!queue.empty())
                {
                        build();
                }
                return top;
        }

        void push(Single<T>* elem)
        {
                bool empty = queue.empty();
                queue.push_back(elem);
                if(empty)
                {                
                        return;
                }
                build();
        }

        void build()
        {
                int len = queue.size();
        
                int left = 0;
                int right = 0;
                int qmax = 0;
                for(int i = (len + 1) >> 1; i >= 0; i--)
                {
                        qmax = i;
                        left = HeapLeft(i);
                        right = HeapRight(i);
        
                        if(left < len && queue[left]->key > queue[qmax]->key) { qmax = left; }
                        if(right < len && queue[right]->key > queue[qmax]->key) { qmax = right; }
        
                        if(qmax != i) { iSwap(queue[i], queue[qmax]); }
                }
        }
};
