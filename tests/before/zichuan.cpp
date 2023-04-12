#include<string>
#include<vector>
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void do_s(deque<vector<char>>& arr,int start,string s){
    
    if(start == s.length()){
        cout <<"-----------"<<endl;
        for_each(arr.begin(),arr.end(),[](vector<char> str){
            
            for_each(str.begin(),str.end(),[](char c){
                cout <<c<<" " ;
            });
            cout <<",";
        });
        cout << endl;
        return;
    }
    for (int i = start; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            vector<char> inner;
            // cout << "----------"<<endl;
            for (int k = i; k <= j; k++){
                inner.push_back(s[k]);
                // cout << s[k];
            }
            // cout <<endl;
            arr.push_back(inner);
            do_s(arr,j + 1,s);
            arr.pop_back();

            //xxxxxxxxxxx

        }
    }
    
}

int main(int argc, char const *argv[])
{
    string s = "123";
    

    deque<vector<char>> arr;
    //第一个串长度

    do_s(arr,0,s);

    return 0;
}


