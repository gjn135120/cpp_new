#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

struct WORD
{
    string s;
    int cnt;
};

int64_t getTime();
void readFile(ifstream &in, vector<WORD> &arr);
void addWord(vector<WORD> &arr, const string &word);
int isUseWord(string &s);
void printWord(const vector<WORD> &arr);
bool cmp(const WORD a, const WORD b);

int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);

    if(!in)
    {
        cout << "文件打开失败!!" << endl;
        return 1;
    }
    vector<WORD> arr;
    int64_t time1 = getTime();
    readFile(in, arr);
    int64_t time2 = getTime();
    int64_t readtime = time2 - time1;
    time1 = getTime();
    sort(arr.begin(), arr.end(), cmp);
    time2 = getTime();
    int64_t sorttime = time2 - time1;
    printWord(arr);
    cout << "读取文件花费 : " << readtime/1000 << "ms" << endl;
    cout << "排序花费 : " << sorttime/1000 << "ms" << endl;
    in.close();
    return 0;
}



void readFile(ifstream &in, vector<WORD> &arr)
{
    string s;
    while(in >> s)
    {
        if(isUseWord(s) == 0)
            addWord(arr, s);
    }
}

int isUseWord(string &s)
{
    ifstream use("use.txt");
    if(!use)
    {
        cout << "文件打开失败!!" << endl;
        return 1;
    }
    string word;
    while(use >> word)
    {
        if(word == s)
            return 1;
    }
    use.close();
    return 0;
}
void addWord(vector<WORD> &arr, const string &word)
{
    vector<WORD>::iterator it = arr.begin();
    for(; it != arr.end(); ++it)
    {
        if(word == it->s)
        {
            it->cnt ++;
            break;
        }
    }

    if(it == arr.end())
    {
        WORD pnew;
        pnew.s = word;
        pnew.cnt = 1;
        arr.push_back(pnew);
    }
}


void printWord(const vector<WORD> &arr)
{
    for(vector<WORD>::size_type index = 0; index != 10; ++ index)
    {
        printf("%10s : %5d\n", arr[index].s.c_str(), arr[index].cnt);
    }
}


int64_t getTime()
{
    struct timespec tm;
    memset(&tm, 0, sizeof(tm));
    if(clock_gettime(CLOCK_MONOTONIC, &tm) == -1)
        ERR_EXIT("gettimeofday");
    int s;
    s += tm.tv_sec * 1000 * 1000;
    s += tm.tv_nsec / 1000;
    return s;
}

bool cmp(const WORD a, const WORD b)
{
    return a.cnt > b.cnt;
}



