#include <algorithm>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;

    vector<pair<int,int>> input1;
    vector<pair<int,int>> input2;
    vector<pair<int,int>> input3;
    vector<pair<int,int>> input4;
    vector<pair<int,int>> input5;
    vector<int> output;
    int i = 0;
    while (i < n){
        string tag;
        cin >> tag;
        if(tag == "IN"){
            i++;
            int a,b;
            cin >> a>>b;
            pair<int,int> s = make_pair(b,i);
            if(a == 1){
                input1.push_back(s);
            }else if(a == 2){
                input2.push_back(s);
            }else if(a == 3){
                input3.push_back(s);
            }else if(a == 4){
                input4.push_back(s);
            }else if(a == 5){
                input5.push_back(s);
            }
            
        }else{
            i++;
            int idx;
            cin >> idx;
            output.push_back(idx);
        }
    }
    vector<vector<pair<int,int>>> arr;
    arr.push_back(input1);
    arr.push_back(input2);
    arr.push_back(input3);
    arr.push_back(input4);
    arr.push_back(input5);

    vector<vector<pair<int,int>>> tmp;
    for(auto a : arr){
        sort(a.begin(),a.end(),[](pair<int,int> a,pair<int,int> b){
        if(a.first > b.first){
            return true;
        }else if(a.first == b.first && a.second < b.second){
            return true;
        }
        return false;
    });
    tmp.push_back(a);
        // cout << "sort"<<endl;
        // for_each(a.begin(),a.end(),[](pair<int,int> a){
        //     cout << a.first<<":"<<a.second<<",";
        // });
        // cout << endl;
    }
    int i1=0;
    int i2=0;
    int i3=0;
    int i4=0;
    int i5=0;
    for(int i = 0;i < output.size();i++){
        int cur = output[i] - 1;
        if(cur == 0){
            vector<pair<int,int>> s = tmp[cur];
            for_each(s.begin(),s.end(),[](pair<int,int> sc){
                cout <<"cur1--"<<sc.first<<":"<<sc.second<<",";
            });
            cout << endl;
            if(s.size() > 0){
                if(i1 >= s.size()){cout << "NULL"<<endl;}else{pair<int,int> as = s[i1];i1++;cout << as.second<<endl;}
            }else{cout << "NULL"<<endl;}
        }
        if(cur == 1){
            vector<pair<int,int>> s = tmp[cur];
            for_each(s.begin(),s.end(),[](pair<int,int> sc){
                cout <<"cur2--"<<sc.first<<":"<<sc.second<<",";
            });
            cout << endl;
            if(s.size() > 0){
                if(i2 >= s.size()){
                    cout << "NULL"<<endl;
                }else{
                    pair<int,int> as = s[i2];
                    i2++;
                    cout << as.second<<endl;}
            }else{
                cout << "NULL"<<endl;
                }
        }
        if(cur == 2){
            vector<pair<int,int>> s = tmp[cur];
            if(s.size() > 0){
                if(i3 >= s.size()){cout << "NULL"<<endl;}else{pair<int,int> as = s[i3];i3++;cout << as.second<<endl;}
            }else{cout << "NULL"<<endl;}
        }
        if(cur == 3){           
            vector<pair<int,int>> s = tmp[cur];
            if(s.size() > 0){
                if(i4 >= s.size()){cout << "NULL"<<endl;}else{pair<int,int> as = s[i4];i4++;cout << as.second<<endl;}
            }else{cout << "NULL"<<endl;}        }
        if(cur == 4){
            vector<pair<int,int>> s = tmp[cur];
            if(s.size() > 0){
                if(i5 >= s.size()){cout << "NULL"<<endl;}else{pair<int,int> as = s[i5];i5++;cout << as.second<<endl;}
            }else{cout << "NULL"<<endl;}
        }
    }

    return 0;
}
