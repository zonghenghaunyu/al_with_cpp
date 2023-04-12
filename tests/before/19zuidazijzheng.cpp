#include <algorithm>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
using namespace std;

void do_al(int i,int j,int w,int& ans,vector<vector<int>> arr){

    if(i + w > arr.size() - 1 || j + w > arr[0].size() - 1){
        return;
    }
    int cur = 0;
    for (int idx = 0; idx <= w; idx++)
    {
        for (int idx1 = 0; idx1 <= w; idx1++)
        {
            cur+= arr[i + idx][j + idx1];
        }
    }
    if(cur >= ans){
        ans = cur;
    }
    do_al(i,j,w+1,ans,arr);
}

int main(int argc, char const *argv[])
{
    //init
    int n,m;
    cin >> n;
    cin >>m;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {

        vector<int> inner;
        int tag;
        for (int j = 0; j < m; j++)
        {
            cin >> tag;
            inner.push_back(tag);
        }
        arr.push_back(inner);
    }
    // for_each(arr.begin(),arr.end(),[](vector<int> xx){
    //     for_each(xx.begin(),xx.end(),[](int i){
    //         cout << i << " ";
    //     });
    //     cout << endl;
    // });
    /**
3 4
-3 5 -1 5
2 4 -2 4
-1 3 -1 3
    */
    //init finish
    int ans = INT32_MIN;
    int cur_ans = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            cur_ans = arr[i][j];
            if(cur_ans >= ans){
                ans = cur_ans;
            }
            do_al(i,j,1,ans,arr);

        }  

    }
    
    cout << ans<<endl;
    return 0;
}
