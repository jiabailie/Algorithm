#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

class TextBlock {  
    public: 
	TextBlock(string s)
	{
		text = string(s.begin(), s.end());
	}
        const char& operator[] (std::size_t position) const  
        {
		return text[position];
	}  
        char& operator[] (std::size_t position)  
        {
		return text[position];
	}  
    private:  
        string text;  
};

int main()
{
    TextBlock tb("Hello");  
    std::cout << tb[0];  
       
    const TextBlock ctb("World");  
    std::cout << ctb[0];  

    return 0;
}
