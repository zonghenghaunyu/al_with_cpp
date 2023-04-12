#include <algorithm>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
using namespace std;

void addnother(vector<bool>& used,vector<int> arr,int level,int cur_sum,int sum,int& ans){
//10 9 8 7 6 5 4 3 2 1
    if(level == 5){

        if(abs(sum - cur_sum - cur_sum) < ans ){
            ans = abs(sum - cur_sum - cur_sum);
        }
        
        return;
    }
    for(int i = 0;i < arr.size();i++){
        if(used[i]){
            continue;
        }
        used[i] = true;
        cur_sum += arr[i];
        addnother(used,arr,level + 1,cur_sum,sum,ans);
        if(ans == 0){
            return;
        }
        used[i] = false;
        cur_sum -= arr[i];
    }

}

int main(int argc, char const *argv[])
{


    int tag;
    vector<int> arr;
    vector<bool> used;
    int sum = 0;
    while (cin >> tag)
    {   
        sum += tag;
        arr.push_back(tag);
        used.push_back(false);
        if(cin.get() == '\n'){
            break;
        }
        /* code */
    }
    deque<int> queue;
    int cur_cum = 0;
    int ans = INT32_MAX;
    cout <<"sum:";
    cout << sum<<endl;
    for(int i = 0;i < arr.size();i++){
        int cur_ans = INT32_MAX;
        used[i] = true;
        cur_cum += arr[i];
        addnother(used,arr,1,cur_cum,sum,cur_ans);
        cout <<"curans:"<< cur_ans<<endl;
        if(cur_ans < ans){
            if(cur_ans == 0){
                cout << 0<<endl;
                return 0;
            }
            ans = cur_ans;
        }
        used[i] = false;
        cur_cum -= arr[i];

    }
    cout << ans<<endl;
    return 0;
}
