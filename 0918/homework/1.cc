#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
void readFile(ifstream &in, vector<string> &arr);
void readStr(istringstream &line, vector<string> &words);
int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "文件打开失败!!\n" << endl;
        return 1;
    }
    vector<string> arr;
    vector<string> words;
    readFile(in, arr);
    for(vector<string>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        istringstream line(*it);
        readStr(line, words);
    }
    cout << "行数:  " << arr.size() << endl;
    cout << "单词数:" << words.size() << endl;
    return 0;
}
void readFile(ifstream &in, vector<string> &arr)
{
    string s;
    while(getline(in, s))
        arr.push_back(s);
}
void readStr(istringstream &line, vector<string> &words)
{
    string s;
    while(line >> s)
        words.push_back(s);
}
