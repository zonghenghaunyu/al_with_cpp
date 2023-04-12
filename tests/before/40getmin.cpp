/**
 * 输入字符串s，输出s中包含所有整数的最小和
说明
1. 字符串s，只包含 a-z A-Z +- ；
2. 合法的整数包括
    1） 正整数 一个或者多个0-9组成，如 0 2 3 002 102
    2）负整数 负号 - 开头，数字部分由一个或者多个0-9组成，如 -0 -012 -23 -00023

输入描述:
包含数字的字符串
输出描述:
所有整数的最小和

示例1
输入
bb1234aa
输出
10
示例2
输入
bb12-34aa
输出
-31
说明
1+2+（-34） = 31
*/

#include <algorithm>
#include <iostream>
#include <string>
#include<unordered_set>
#include<vector>

using namespace std;

int main1(int argc, char const *argv[])
{
    string s ;
    cin >> s;

    unordered_set<char> a{'0','1','2','3','4','5','6','7','8','9'};

    vector<string> nums;
    for (int i = 0; i < s.length(); i++){
        
        if(s[i] == '-'){
            i++;
            if(a.count(s[i]) != 0){
                // cout<<"for"<<s[i]<<endl;
                string anum = "-";
                for (; i < s.length(); i++){
                    if(a.count(s[i] == 0)){
                        break;
                    }else{
                        anum += string(1,s[i]);
                    }
                }
                if(anum != "-"){
                    nums.push_back(anum);
                }
            }
        }
        if(a.count(s[i]) != 0){
            nums.push_back(string(1,s[i]));
        }
    }
    
    int ans = 0;
    for(auto a : nums){
        ans += atoi(a.c_str());
    }

    cout <<ans<<endl;
    
    return 0;
}
