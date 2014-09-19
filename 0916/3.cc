#include <iostream>
#include <string>
#include <vector>
using namespace std;
void func(string &str)
{
    string s = str;
    str = "";
    string::size_type index = 0;
    while(index != s.size())    
    {
        if( !ispunct(s[index]))
            str += s[index];
        index ++;
    }
}
int main(int argc, const char *argv[])
{
    string str;
    while(cin >> str)
    {
        func(str);
        cout << str << endl;
    }
    return 0;
}
