#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct WORD
{
    string s;
    int count;
};
int main(int argc, const char *argv[])
{
    ifstream in("123.txt");
    if(!in)
    {
        cout << "文件打开失败!!" << endl;
        return 1;
    }
    vector<string> arr;
    string s;
    while(in >> s)
    {
        arr.push_back(s);
    }
    cout << arr.size() << endl;
    return 0;
}
