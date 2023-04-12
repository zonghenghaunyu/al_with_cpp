#include <algorithm>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string tag;
    vector<string> words;
    while (cin >> tag)
    {
        words.push_back(tag);
        if(cin.get() == '\n'){
            break;
        }
    }
    int start,end;
    cin >> start >> end;
    vector<string> ans;
    deque<string> queue;
    for(int i = 0;i < words.size();i++){
 
        if(i < start || i > end){
            ans.push_back(words[i]);
        }else if(i >= start && i < end){
            queue.push_front(words[i]);
        }else if(i == end){
            queue.push_front(words[i]);
            while (!queue.empty())
            {
                string x = queue.front();
                ans.push_back(x);
                queue.pop_front();
            }
            
        }
 
    }

     for_each(ans.begin(),ans.end(),[](string s){
        cout << s<<" ";
     });
    return 0;
}
