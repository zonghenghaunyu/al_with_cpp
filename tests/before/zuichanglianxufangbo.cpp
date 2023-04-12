#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

/** 12:21
 * 输入一串方波信号，求取最长的完全连续交替方波信号，并将其输出，如果有相同长度的交替方波信号，输出任一即可，
方波信号高位用1标识，低位用0标识，如图：

说明：
1） 一个完整的信号一定以0开始然后以0结尾，即010是一个完整信号，但101，1010，0101不是
2）输入的一串方波信号是由一个或多个完整信号组成
3） 两个相邻信号之间可能有0个或多个低位，如0110010，011000010

4） 同一个信号中可以有连续的高位，如01110101011110001010，前14位是一个具有连续高位的信号

5） 完全连续交替方波是指10交替，如01010是完全连续交替方波，0110不是

输入描述:
输入信号字符串（长度>=3且<=1024）：

0010101010110000101000010
注：输入总是合法的，不用考虑异常情况
输出描述:
输出最长的完全连续交替方波信号串：

01010
若不存在完全连续交替方波信号串，输出 -1

示例1
输入
00101010101100001010010
输出
01010
备注:
输入信号串中有三个信号：0 010101010110(第一个信号段) 00 01010(第二个信号段) 010(第三个信号段)

第一个信号虽然有交替的方波信号段，但出现了11部分的连续高位，不算完全连续交替方波，
在剩下的连续方波信号串中01010最长
*/
using namespace std;

int main1(int argc, char const *argv[])
{
    string s;
    cin >> s;

    bool isZero =false;
    if(s[0] == '0'){
        isZero = true;
    }
    bool isStart = false;
    bool isFinsh = true;
    vector<vector<char>> all;
    vector<char> arr;
    for (int i = 1; i < s.length(); i++){
        if(isZero && s[i] == '1' && !isStart){
            isStart = true;
            arr.push_back(s[i-1]);
            arr.push_back(s[i]);
            isZero = false;
        }else if(s[i] == '0' && !isStart){
            isZero = true;
        }else if(s[i] == '0' && s[i- 1] == '0'){
            isStart = false;
            isZero = true;
            all.push_back(arr);
            arr.clear();
        }else if(isStart){
            arr.push_back(s[i]);
        }
        if(isStart && i == s.length() - 1 && s[i] == '0'&& s[i - 1] == '1'){
            all.push_back(arr);
        }
        /* code */
    }
    
    int max = 0;
    int current = 0;
    int idx = -1;
    for (int i = 0; i < all.size(); i++)
    {
        vector<char> inner = all[i];


        bool nowzero = true;
        for (int j = 0; j < inner.size(); j++)
        {
            if(nowzero && inner[j] == '0'){
                current++;
                nowzero = false;
            }else if(!nowzero && inner[j] == '1'){
                nowzero = true;
                current ++;
            }else{
                current = 0;
                break;
            }

            /* code */
        }
        if(current > max){
            idx = i;
            max = current;
        }
        current = 0;

        /* code */
    }
    
    if(idx != -1){
        vector<char> ans = all[idx];
        for_each(ans.begin(),ans.end(),[](char x){
            cout<<x;
        });
        cout << endl;
    }
    
    return 0;
}
