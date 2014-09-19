#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct WORD
{
    string s;
    int count;
};
bool cmp(WORD a, WORD b)
{
    return a.count > b.count;
}
int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "文件打开失败!!" << endl;
        return 1;
    }
    vector<WORD> arr;
    WORD s;
    vector<WORD>::size_type index;
    while(in >> s.s)
    {
        s.count = 1;
        for(index = 0; index != arr.size(); index ++)
            if(arr[index].s == s.s)
            { 
                arr[index].count ++;
                break;
            }
        if(index == arr.size())
            arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(index = 0; index != 10; index ++)
        printf("%s  \t: %6d\n", arr[index].s.c_str(), arr[index].count);
    return 0;
}
