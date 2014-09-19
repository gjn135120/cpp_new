#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    if(!in || !out)
    {
        cout << "文件打开失败!!" << endl;
        return 1;
    }
    string s;
    while(getline(in, s))
    {
        out << s << endl;
    }
    in.close();
    out.close();
    return 0;
}
