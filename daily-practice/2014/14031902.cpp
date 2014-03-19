/* Reference: aszt.inf.elte.hu/~gsd/halado_cpp/ch02s07.html */
#include <iostream>

using namespace std;

class X
{
public:
    X() { throw 1; }
};

class Y
{
private:
    X x;
public:
    Y()try : x()
    {}
    catch(...)
    {}
};

int main()
try
{
    Y y;
    return 0;
}
catch(int i)
{
    cerr << "Exception: " << i << endl;
}