/**
 * Calculate the input expressions, and the numbers are all non-negative integers.
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define DEBUG

using namespace std;

enum ERROR
{
    VALID_EXPRESSION = 0,
    ZERO_IS_DIVISOR,
    MISMATCHED_PARENTHESES,
    REDUNDANT_ELEMENTS,
    CALCULATE_OVERFLOW
};

const char separator[] = {'(', ')', '+', '-', '*', '/'};

const char levels[3][2] = {{'+', '-'}, {'*', '/'}, {'(', ')'}};

ERROR ERROR_FLAG = VALID_EXPRESSION;

/* Judge whether the character is a separator or not. */
inline bool IsSeparator(char c)
{
    for(int i = 0; i < sizeof(separator); ++i)
    {
        if(c == separator[i])
        {
            return true;
        }
    }
    return false;
}

/* If the character is a separator, getting the priority level of this separator. */
inline int GetSeparatorLevel(char c)
{
    int i = 0, j = 0, k = -1;
    for(i = 0; i < 3 && k == -1; ++i)
    {
        for(j = 0; j < 2 && k == -1; ++j)
        {
            if(c == levels[i][j])
            {
                k = i;
            }
        }
    }
    return k;
}

/**
 * Check whether the parentheses are valid.
 * eg. CheckParentheses('(', ')', s)
 */
inline bool CheckParentheses(char pre, char pos, stack<char> &series)
{
    stack<char> temp;

    if(series.size() % 2 == 1)
    {
        return false;
    }

    while(true)
    {
        while(!series.empty() && !temp.empty() && series.top() == pre && temp.top() == pos)
        {
            series.pop();
            temp.pop();
        }    
        if(!temp.empty() && temp.top() == pre)
        {
            return false;
        }
        if(!series.empty())
        {
            temp.push(series.top());
            series.pop();
        }
        if(series.empty())
        {
            if(temp.empty())
            {
                break;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

/* Transfer the infix expression into suffix expression, in order to do calculation. */
inline void Transfer2SuffixExpression(vector<string> &elems, vector<int> &priority, vector<string> &suffixExpr)
{
    stack<char> oper;

    int i = 0, len = int(elems.size());

    for(i = 0; i < len; ++i)
    {
        // numbers
        if(priority[i] == -1)
        {
            suffixExpr.push_back(string(elems[i].begin(), elems[i].end()));
        }
        // '+', '-', '*' and '/'
        else if(priority[i] == 0 || priority[i] == 1)
        {
            while(!oper.empty() && GetSeparatorLevel(oper.top()) != 2 && priority[i] <= GetSeparatorLevel(oper.top()))
            {
                suffixExpr.push_back(string(1, oper.top()));
                oper.pop();
            }
            oper.push(elems[i][0]);
        }
        // '(' and ')'
        else if(priority[i] == 2)
        {
            if(elems[i][0] == '(')
            {
                oper.push('(');
            }
            else if(elems[i][0] == ')')
            {
                while(oper.top() != '(')
                {
                    suffixExpr.push_back(string(1, oper.top()));
                    oper.pop();
                }
                oper.pop();
            }
        }
    }

    while(!oper.empty())
    {
        suffixExpr.push_back(string(1, oper.top()));
        oper.pop();
    }
}

/* Calculate the suffix expression. */
inline int CalculateSuffixExpression(const vector<string> &suffixExpr)
{
    int pos = 0;
    int pre = 0;
    int res = 0;
    stack<int> calc;
    for(vector<string>::const_iterator it = suffixExpr.begin(); it != suffixExpr.end(); ++it)
    {
        string tmp((*it).begin(), (*it).end());
        if(tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/')
        {
            if(calc.size() < 2)
            {
                ERROR_FLAG = REDUNDANT_ELEMENTS;
                return -1;
            }
            pos = calc.top();
            calc.pop();
            pre = calc.top();
            calc.pop();
            if(tmp[0] == '/')
            {
                if(pos == 0)
                {
                    ERROR_FLAG = ZERO_IS_DIVISOR;
                    return -1;
                }
                res = pre / pos;
            }
            else if(tmp[0] == '*')
            {
                res = pre * pos;
                if(res != 0 && res / pre != pos)
                {
                    ERROR_FLAG = CALCULATE_OVERFLOW;
                    return -1;
                }
            }
            else if(tmp[0] == '+')
            {
                res = pre + pos;
                if((pre > 0 && pos > 0 && res < 0) || (pre < 0 && pos < 0 && res > 0))
                {
                    ERROR_FLAG = CALCULATE_OVERFLOW;
                    return -1;
                }
            }
            else if(tmp[0] == '-')
            {
                res = pre - pos;
            }

            calc.push(res);
        }
        else
        {
            calc.push(atoi(tmp.c_str()));
        }
    }
    if(calc.size() > 1)
    {
        ERROR_FLAG = REDUNDANT_ELEMENTS;
        return -1;
    }
    return calc.top();
}

/* Analysis the elements of this level. */
inline int CalLevel(vector<string> &elems, vector<int> &priority)
{
    stack<char> level2;
    vector<string> suffixExpr;

    for(int i = 0; i < int(elems.size()); ++i)
    {
        if(priority[i] == 2)
        {
            level2.push(elems[i][0]);
        }
    }

    if(level2.size() > 0 && !CheckParentheses('(', ')', level2))
    {
        ERROR_FLAG = MISMATCHED_PARENTHESES;
        return -1;
    }

    Transfer2SuffixExpression(elems, priority, suffixExpr);

    int res = CalculateSuffixExpression(suffixExpr);

    return res;
}

/* Separating the input expression as a series of numbers of operators. */
inline void Parsor(const char *expression, vector<string> &elems, vector<int> &priority)
{
    int i = 0;
    int len = strlen(expression);
    string elem;

    for(i = 0; i < len; )
    {
        if(IsSeparator(expression[i]) || expression[i] == ' ')
        {
            if(expression[i] != ' ')
            {
                if(expression[i] == '-' && (priority.empty() || priority.back() != -1))
                {
                    elems.push_back("0");
                    priority.push_back(-1);
                }
                elems.push_back(string(1, expression[i]));
                priority.push_back(GetSeparatorLevel(expression[i]));
            }
            i = i + 1;
        }
        
        while(expression[i] >= '0' && expression[i] <= '9')
        {
            elem.push_back(expression[i]);
            i += 1;
        }
        if(elem.size() > 0)
        {
            elems.push_back(string(elem.begin(), elem.end()));
            priority.push_back(-1);
            elem.clear();
        }
    }
}

/* Calculate the expression. */
inline int Cal(const char *expression)
{
    vector<string> elems;
    vector<int> priority;

    Parsor(expression, elems, priority);

    int res = CalLevel(elems, priority);

    if(ERROR_FLAG != VALID_EXPRESSION)
    {
        return -1;
    }
    return res;
}

/* Test whether the function CheckParentheses() is correct. */
void TestCheckParentheses()
{
    char t[6][100] = {"((()))()()", "(", "))()((", ")()()()", "((()()()))", "(()()())"}; 
    for(int i = 0; i < 6; ++i)
    {        
        stack<char> istack;
        for(int j = 0; j < int(strlen(t[i])); ++j)
        {
            istack.push(t[i][j]);
        }
        cout << "#" << i << ":" << t[i] << endl;
        cout << (CheckParentheses(levels[2][0], levels[2][1], istack) ? 1 : 0) << endl << endl;
    }
}

int main()
{
#ifdef DEBUG
    string line("-9 + (1 + 2 * 5) * 3 - (-1) * 2 * (902 - 89 * 2) * 5 + 6 * (9 + 1 * 2) + 9");

    int expected = -9 + (1 + 2 * 5) * 3 - (-1) * 2 * (902 - 89 * 2) * 5 + 6 * (9 + 1 * 2) + 9;
#else
    string line;
#endif

#ifndef DEBUG
    while(getline(cin, line), line.size() > 0)
    {
#endif
        ERROR_FLAG = VALID_EXPRESSION;

        int f = Cal(line.c_str());

        if(ERROR_FLAG != VALID_EXPRESSION)
        {
            switch(ERROR_FLAG)
            {
            case ZERO_IS_DIVISOR:
                cout << "0 can't be used as divisors." << endl;
                break;
            case MISMATCHED_PARENTHESES:
                cout << "There are mismatched parentheses." << endl;
                break;
            case REDUNDANT_ELEMENTS:
                cout << "There are some redundant elements." << endl;
                break;
            case CALCULATE_OVERFLOW:
                cout << "The calculation is over flow." << endl;
                break;
            default:
                break;
            }

            return 0;
        }
#ifndef DEBUG
    }
#endif

    return 0;
}