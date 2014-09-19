#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
using namespace std;

int func(const vector<int> &arr, int key)
{
    vector<int>::size_type low, high, mid;
    low = 0;
    high = arr.size() - 1;
    while(low <= high)
    {
        if(arr[low] == key)
            return low;
        if(arr[high] == key)
            return high;
        mid = low + (high - low) / 2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(low >= high)
        return -1;
}
int main(int argc, const char *argv[])
{
    
  
    fstream fd1("123.txt");
    fstream fd2("haha.txt");
    vector<int> arr1, arr2;
    int a;
    string s;
   // stringstream b;
    int i = 0;
    while(getline(fd1, s))
    {
        a = atoi(s.c_str());
        arr1.push_back(a);
    }
    while(getline(fd2, s))
    {
        a = atoi(s.c_str());
        arr2.push_back(a);
    }
    sort(arr2.begin(), arr2.end());
    for(vector<int>::size_type index = 0; index != arr1.size(); ++ index)
        if(func(arr2, arr1[index]) == -1)
        {
            cout << arr1[index] << endl;
            ++ i ;
        }
   cout << i << endl;
    return 0;
}
