#include <iostream>
#include <string>
#include <vector>
using namespace std;
void func(const int a, string &s)
{
    int flag = 0;
    int num = a;
    if ( a < 0)
    {
        flag = 1;
        num = - num;
    }
    while(num != 0)
    {
        s +=(char)(num % 10 +'0');
        num = num / 10;
    }
    if (flag == 1)
        s += '-';
    char c;
    int up = 0, down = s.size() - 1;
    while( up < down)
    {
        c = s[up];
        s[up] = s[down];
        s[down] = c;
        up ++;
        down --;
    }
}
int main(int argc, const char *argv[])
{
    int a;
    string s;
    cin >> a;
    func(a, s);
    cout << s << endl;
    return 0;
}
