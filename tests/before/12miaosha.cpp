#include<algorithm>
#include<string>
#include<iostream>
#include<vector>

using namespace std;


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    string l;
    cin >> l;

    int idx = 0;
    int find = 0;
    for (int i = 0; i < s.length(); i++)
    {
        while (idx < l.length())
        {
            if(s[i] == l[idx]){
                find++;
                idx++;
                if(find == s.length()){
                    cout <<idx - 1<<endl;
                    return 0;
                }
                break;
            }
            idx ++;
        }
        
    }
    cout  <<-1<<endl;

    return 0;
}
