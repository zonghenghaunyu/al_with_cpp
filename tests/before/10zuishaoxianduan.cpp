#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
#include<deque>
#include<vector>
#include<unordered_map>

using namespace std;

int main1(int argc, char const *argv[])
{
  
    int n;
    cin >> n;

    unordered_map<int,int> map;
    string s;
    for(int i = 0;i < n;i++){
        cin >> s;
        replace(s.begin(),s.end(),',', ' ');
        stringstream ss(s);
        string xx;
        pair<int,int> inner;
        ss >> xx;
        int first = atoi(xx.c_str());
        inner.first = first;
        ss >> xx;
        int second = atoi(xx.c_str());
        inner.second = second;

        if(map.count(first) != 0){
            int a = map.at(first);
            if(second > a){
                map.emplace(first,second);
            }
        }else{
            map.emplace(first,second);
        }
    }
    if(n == 0){
        return 0;
    }
    vector<pair<int,int>> arr;
    for(pair<int,int> a : map){
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end(),[](pair<int,int> a,pair<int,int> b) -> bool{
        if(a.first < b.first){
            return true;
        }else if(a.first == b.first && a.second > b.second){
            return true;
        }
        return false;
    });

    if(arr.size() == 1){
        cout << 1<<endl;
        return 0;
    }
    if(arr.size() == 2){
        pair<int,int> a1 = arr[0];
        pair<int,int> a2 = arr[1];
        if(a2.second > a1.second){
            cout << 2<<endl;
        }else{
            cout << 1<<endl;
        }
        return 0;
    }

    pair<int,int>  pri2 = arr[0];
    pair<int,int> pri1 = arr[1];
    vector<pair<int,int>> ans;
    ans.push_back(pri2);
    ans.push_back(pri1);
    for(int i = 2;i < arr.size();i++){
        if(arr[i].first > pri2.second){
            ans.push_back(arr[i]);
            pri2 = pri1;
            pri1 = arr[i];
        }else if(arr[i].first < pri2.first && arr[i].second > pri1.second){
            ans[ans.size() - 1] = arr[i];
            pri1 = arr[i];
        }
    }

    // cout <<"--------------"<<endl;
    for(pair<int,int> a : ans){

        cout << a.first << ":" << a.second<<endl;
    }

    cout << ans.size()<<endl;

    return 0;
}
