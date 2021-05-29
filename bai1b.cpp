#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

stack<string> split(string str, string sep)
{
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    stack<std::string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != NULL)
    {
        arr.push(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}

int main()
{
    vector<string> list;
    stack<string> s;
    fstream fin, fout;
    
    fin.open("input1.txt", ios::in);
    fout.open("output2.txt", ios::out);
    string a = "";
    int i = 0;
    string line;
    while (!fin.eof())
    {
        getline(fin, line);
        if (line != "")
        {
            a += line;
            i++;
        }
    }
    s = split(a," ");

    while(!s.empty()){
        fout << s.top() << " ";
        s.pop();
    }
    fin.close();
    fout.close();
}