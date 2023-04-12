//23:10 -- 11:48
#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
#include<vector>

/**
服务器广播
题目：服务器连接方式包括直接相连，间接连接。 A 和 B 直接连接， 
B 和 c 直接连接，则 A 和 c 间接连接。
直接连接和间接连接都可以发送广播。
给出一个 N * N 数组，代表 N 个服务器， matrix[i][j] == 1 ，
则代表 i 和 j 直接连接；不等于 1 时，代表 i 和 j 不直接连接。
 matrix[i][i]== 1 ，即自己和自己直接连接。 matrix[i][j]==matrix[j][i] 
 。计算初始需要给几台服务器广播，才可以使侮个服务器都收到广播。
输入描述： n * n 矩阵，
// 0 1 2
//0 1 直接 1 2直接 0 2间接
[[0,1,2],
 [1,0,1],
 [2,1,0]]

//
// 
// A B直接 C自己一个
  A B C
[[1,1,0],
 [1,1,0],
 [0,0,1]]
2
输出描述：整数


*/

using namespace std;

void findAll(vector<bool>& used, vector<vector<int>> all,int cur){

    for (int j = cur + 1; j < all.size(); j++)
        {
            if(all[cur][j] == 1){
                used[j] = true;
                findAll(used,all,j);
            }
            /* code */
    }
}

int main(int argc, char const *argv[])
{
    int num = 0;
    vector<int> arr;
    vector<vector<int>> all;
    while (cin >> num)
    {
        arr.push_back(num);
        if(cin.get() == '\n'){
            all.push_back(arr);
            if(all.size() == arr.size()){
                break;
            }
            arr.clear();
        }
    }
    
    int i = 0;
    int j = 0;
    vector<bool> used;
    for (int i = 0; i < all.size(); i++)
    {
        used.push_back(false);
        /* code */
    }
    
    int ans = 0;
    for (int i = 0; i < all.size(); i++)
    {
        //给第i台广播
        if(!used[i]){
            ans++;
            used[i] = true;
            findAll(used,all,i);
        }
        /* code */
    }
    
    
    cout << ans << endl;




    // for_each(all.begin(),all.end(),[](vector<int> i){
    //     cout << endl;
    //     for_each(i.begin(),i.end(),[](int n){
    //         cout << n << ",";
    //     });
    //     cout << endl;
    // });
    
    return 0;
}
