#ifndef COMMON_H
#define COMMON_H

#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

void iswap(int&, int&);

void makeArray(std::vector<int>&);

void displayArray(std::vector<int>&);

void displaySortArray(std::vector<int>&);

// whether the next char is splitting token
bool isToken(char c, std::string &token);

// whether the next word is number or not
bool isNumber(std::string &str);

// transfer a string to integer
int str2int(std::string &str);

// read text from file
std::vector<std::string> readFile(std::ifstream &in, std::string &token);

#endif