#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define DEBUG
#undef  DEBUG

using namespace std;

const int n = 9;

int d[n][n];

bool larger(int a, int b)
{
	return a >= b;
}

struct vertex
{
public:
	int value;

	int position;

	vertex(int _value, int _position) : value(_value), position(_position) {}

	vertex(const vertex &_vertex) : value(_vertex.value), position(_vertex.position) {}

	vertex& operator=(const vertex &_vertex)
	{
		if(this == &_vertex)
		{
			return *this;
		}

		this->value = _vertex.value;
		this->position = _vertex.position;

		return *this;
	}

	~vertex() {}
private:
	vertex();
};

template<typename T>
inline void iswap(T &a, T &b)
{
	T ta(a);
	T tb(b);

	a = tb;
	b = ta;
}

struct line
{
	vector<vertex> elems;

	line() {}

	line(const line &_line) : elems(_line.elems.begin(), _line.elems.end()) {}

	line& operator=(const line &_line)
	{
		if(this == &_line)
		{
			return *this;
		}
		elems = vector<vertex>(_line.elems.begin(), _line.elems.end());
		return *this;
	}

	vertex operator[](int) const;

	vertex& operator[](int);

	bool empty();

	void adjust(bool(*)(int, int));

	void push(vertex);

	vertex pop();	
};

vertex line::operator[](int index) const
{
	if(index < 0 || index >= elems.size())
	{
		cerr << "The index is illegal." << endl;
		return vertex(0, 0);
	}
	return elems[index];
}

vertex& line::operator[](int index)
{
	if(index < 0 || index >= elems.size())
	{
		cerr << "The index is illegal." << endl;
		return vertex(0, 0);
	}
	return elems[index];
}

bool line::empty()
{
	return this->elems.empty();
}

void line::adjust(bool (*comp)(int, int))
{
	int i = 0;
	int j = 0;
	int m = 0;
	int len = elems.size();	
	int left = 0;
	int right = 0;
	for(j = len; j > 0; --j)
	{
		for(i = (j >> 1); i >= 0; --i)
		{
			m = i;
			left = 2 * i + 1;
			right = 2 * i + 2;

			if(left < j && (*comp)(elems[left].value, elems[m].value))
			{
				m = left;
			}
			if(right < j && (*comp)(elems[right].value, elems[m].value))
			{
				m = right;
			}
			if(m != i)
			{
				iswap<vertex>(elems[i], elems[m]);
			}
		}
		iswap<vertex>(elems[0], elems[j - 1]);
	}
}

void line::push(vertex _elem)
{
	elems.push_back(vertex(_elem));
	if(elems.size() == 1)
	{
		return;
	}
	adjust(&larger);
}

vertex line::pop()
{
	if(elems.empty())
	{
		cerr << "There are no elements in current heap." << endl;
		return vertex(0, 0);
	}

	vertex top(elems.back());
	elems.pop_back();

	return top;
}

#ifdef DEBUG
void display(int d1, int d2, int arr[][n])
{
	int i = 0;
	int j = 0;
	for(i = 0; i < d1; ++i)
	{
		for(j = 0; j < d2; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void displayline(line &_line)
{
	while(!_line.empty())
	{
		vertex top = _line.pop();
		cout << "value=" << top.value << ",position=" << top.position << endl;
	}
}
#endif

int main()
{
	int i = 0;
	int j = 0;

	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			d[i][j] = rand() % ((i + 7) * 5 + (j + 11));
		}
	}

#ifdef DEBUG
	display(n, n, d);
#endif

	vector<line> lines;

	for(i = 0; i < n; ++i)
	{
		line tmp;
		for(j = 0; j < n; ++j)
		{
			tmp.push(vertex(d[i][j], j));
		}
		lines.push_back(line(tmp));
	}

	return 0;
}