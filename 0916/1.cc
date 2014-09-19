#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string sum = "";
    string s;
    cin >> sum;
    while(cin >> s)
    {
        sum += '$';
        sum += s;
    }
    cout << sum << endl;
    return 0;
}
