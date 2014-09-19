#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main(int argc, const char *argv[])
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(16);
    arr.push_back(20);
    arr.push_back(5);
    sort(arr.rbegin(), arr.rend(), cmp);
    for(vector<int>::size_type index = 0; index != arr.size(); ++ index)
        cout << arr[index] << " ";
    cout << endl;
    return 0;
}
