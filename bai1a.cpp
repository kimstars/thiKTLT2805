#include <iostream>
#include <map>
#include <fstream>
using namespace std;

const int N = 1e6;

int a[N];

void phanA(string a)
{
    fstream fp;
    fp.open("output1.txt", ios::out);

    map<char, int> list;
    map<char, int>::iterator it;

    for (int i = 0; i < a.length(); i++)
    {
        list[a[i]]++;
    }
    for (it = list.begin(); it != list.end(); ++it)
    {
        fp << it->first << ": "<< it->second << endl;
    }

}


int main()
{
    fstream f;
    f.open("input1.txt", ios::in);
    string a;
    string line;
    while(!f.eof()){
        getline(f,line);
        a += line;
    }

    

    phanA(a);
}