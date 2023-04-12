#include <algorithm>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

void findstr(string str,int i,int j,vector<vector<bool>> used,vector<vector<char>> arr
,int level,deque<pair<int,int>>& quque
,deque<pair<int,int>> ans){
    if(level == str.length()){
        ans = quque;
        return;
    }

    if(i - 1 > 0 && !used[i - 1][j] && arr[i - 1][j] == str[level]){
        used[i - 1][j] = true;
        quque.push_back(make_pair(i-1,j));
        findstr(str,i - 1,j,used,arr,level + 1,quque,ans);
        if(ans.size() != 0){
            return;
        }
        used[i - 1][j] = false;
        quque.pop_back();
    }
    if(i + 1 <= arr.size() - 1 && !used[i + 1][j] && arr[i + 1][j] == str[level]){
        used[i + 1][j] = true;
        quque.push_back(make_pair(i+1,j));
        findstr(str,i + 1,j,used,arr,level + 1,quque,ans);
        if(ans.size() != 0){
            return;
        }
        used[i + 1][j] = false;
        quque.pop_back();
    }
    if(j - 1 > 0 && !used[i ][j - 1] && arr[i][j - 1] == str[level]){
        used[i][j - 1] = true;
        quque.push_back(make_pair(i,j - 1));
        findstr(str,i,j - 1,used,arr,level + 1,quque,ans);
        if(ans.size() != 0){
            return;
        }
        used[i][j -1] = false;
        quque.pop_back();
    }
    if(j + 1 <= arr[0].size() - 1  && !used[i ][j + 1] && arr[i][j + 1] == str[level]){
        used[i][j + 1] = true;
        quque.push_back(make_pair(i,j + 1));
        findstr(str,i,j + 1,used,arr,level + 1,quque,ans);
        if(ans.size() != 0){
            return;
        }
        used[i][j +1 ] = false;
        quque.pop_back();
    }

}

int main1(int argc, char const *argv[])
{
/*
4
A,C,C,F
C,D,E,D
D,E,S,S
F,E,C,A
ACCESS
*/
    int n;
    cin >> n;
    vector<vector<char>> arr;
    vector<vector<bool>> used;
     for (int i = 0; i < n; i++)
     {
        string tag;
        cin >> tag;
        vector<char> inner;
        vector<bool> innerb;
        for (int j = 0; j < tag.length(); j++)
        {
            if(tag[j] != ','){
                innerb.push_back(false);
                inner.push_back(tag[j]);
            }

        }
        used.push_back(innerb);
        arr.push_back(inner);

     }
     string find;
     cin >> find;

    deque<pair<int,int>> quque;
    deque<pair<int,int>> ans;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if(arr[i][j] == find[0]){
                used[i][j] = true;
                quque.push_back(make_pair(i,j));
                findstr(find,i,j,used,arr,1,quque,ans);
                if(ans.size() != 0){
                    for (int xx = 0; xx < ans.size() - 1; xx++)
                    {
                        cout << ans[xx].first<<","<<ans[xx].second<<",";
                    }
                    cout << ans[ans.size() - 1].first<<","<<ans[ans.size() - 1].second<<endl;
                    return 0;
                }
                quque.pop_back();
                used[i][j] = false;
            }
        }
    }
    return 0;
}
