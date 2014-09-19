#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
void test(const int &a, const int &b)
{
   if(b == 0)
       throw invalid_argument("非法参数!!");
   if(a / b == 0)
       throw logic_error("除数为零!!");
   else
       cout << a / b << endl;
}
int main(int argc, const char *argv[])
{
    int a, b;
    while(cin >> a >> b)
    {
        try
        {
            test(a, b);
        }
        catch(invalid_argument &e)
        {
            cout << "异常信息:" << e.what() << endl;
            continue;
        }
        catch(logic_error &e)
        {
            cout << "异常信息:" << e.what() << endl;
            continue;
        }
        cout << "继续运行" << endl;
    }
    return 0;
}
