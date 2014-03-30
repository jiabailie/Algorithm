#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>

const int len = 1024;

inline bool judge(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 != len2)
    {
        return false;
    }

    for(int i = 0; i < len1; ++i)
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

inline void push(const char *buffer, int &content, std::string &ret)
{
    for(int i = 0; i < strlen(buffer); ++i)
    {
        if(buffer[i] == '<')
        {
            content = 2;
            break;
        }
        ret.push_back(buffer[i]);
    }
}

std::string analyse(const char *path, const char *tag)
{    
    std::ifstream fin(path);

    if(!fin)
    {
        std::cout << "File open error" << std::endl;
        return std::string();
    }

    int i = 0;
    bool less = false;
    int content = 0;
    char buffer[len];
    std::string cmptag;
    std::string ret;
    
    while(fin.get(buffer, len, '\0') != NULL && content != 2)
    {
        if(content == 1)
        {
            push(buffer, content, ret);
        }
        else if(content == 0)
        {
            for(i = 0; i < strlen(buffer) && content == 0; ++i)
            {
                if(less)
                {
                    if(buffer[i] == '/')
                    {
                        less = false;
                        continue;
                    }
                    else if(buffer[i] != '<' && buffer[i] != '>')
                    {
                        cmptag.push_back(buffer[i]);
                    }
                    else if(buffer[i] == '>')
                    {
                        less = false;
                        cmptag.push_back(buffer[i]);
                        if(judge(cmptag.c_str(), tag))
                        {
                            content = 1;
                        }
                    }
                }
                else if(!less)
                {
                    if(buffer[i] == '<')
                    {
                        if(i + 1 < len && buffer[i + 1] == '/')
                        {
                            continue;
                        }

                        less = true;
                        cmptag.clear();
                        cmptag.push_back(buffer[i]);
                    }
                }
            }

            if(content == 1)
            {
                for(; i < strlen(buffer); ++i)
                {
                    if(buffer[i] == '<')
                    {
                        content = 2;
                        break;
                    }
                    ret.push_back(buffer[i]);
                }
            }
        }
    }

    fin.close();

    return ret;
}

int main()
{
    char requestPath[] = "E:/Projects/lab/lab/txt/request.xml";
    char responsePath[] = "E:/Projects/lab/lab/txt/response.xml";

    char requestTag[] = "<requestXML>";
    char responseTag[] = "<RequestResult>";

    std::string request = analyse(requestPath, requestTag);

    std::cout << request.c_str() << std::endl;

    std::cout << std::endl << std::endl;

    std::string response = analyse(responsePath, responseTag);
    
    std::cout << response.c_str() << std::endl;

    return 0;
}