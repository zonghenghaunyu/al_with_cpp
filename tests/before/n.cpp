#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

string getstr(string s,int start,int end) {

    string w = s.substr(start,end - start + 1);
    return w;
}

void print(deque<string>& que) {

    for_each(que.begin(), que.end(), [](string s) {
        cout << s << ","; });
}

void dostr(string s,vector<vector<string>>& inner,deque<string>& que,vector<bool>& used,int start) {
    if (start == s.length()) {
        print(que);
        cout << endl;
        return;
    }
    int j = start;
    while (j < s.length())
    {
        string str = getstr(s, start, j);
        que.push_back(str);
        dostr(s, inner,que,used,j + 1);
        que.pop_back();
        j++;
    }
    
}
int main(int argc, char const* argv[])
{
    string s;
    cin >> s;
    vector<vector<string>> inner;
    deque<string> que;
    vector<bool> used;
    for (int i = 0; i < s.length(); i++){
        used.push_back(false);
    }
    dostr(s, inner, que,used,0);
    return 0;
}
