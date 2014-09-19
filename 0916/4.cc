#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool to_up(int a, int b)
{
    return a > b;
}
bool to_down(int a, int b)
{
    return b > a;
}
typedef bool(*pfunc)(int, int);
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
void func(vector<int> &arr, pfunc p)
{
    vector<int>::size_type low, high;
    for(low = 0; low != arr.size(); low ++)
        for(high = 0; high != arr.size() - low - 1; high ++)
            if(p(arr[high], arr[high + 1]))
                swap(arr[high], arr[high + 1]);
}
void print(vector<int> &arr)
{
    for(vector<int>::size_type index = 0; index != arr.size(); ++ index)
        cout << arr[index] << " ";
}
int main(int argc, const char *argv[])
{
    vector<int> arr;
    int a;
    while(cin >> a)
        arr.push_back(a);
    cin.clear();
    cout << "up ? or down ?" <<endl;
    string b;
    cin >> b;
    cout << "befor : " << endl;
    print(arr);
    cout << endl;
    if(b == "up")
        func(arr, to_up);
    else if(b == "down")
        func(arr, to_down);
    cout << "after : " << endl;
    print(arr);
    cout << endl;
    return 0;
}
