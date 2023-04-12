#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
//10:30
using namespace std;
/*
游戏规则：输入一个只包含英文字母的字符串，字符串中的两个字母如果相邻且相同，就可以消除。

在字符串上反复执行消除的动作，直到无法继续消除为止，此时游戏结束。
输出最终得到的字符串长度。

输入描述:
输入原始字符串 str ，只能包含大小写英文字母，字母的大小写敏感， str 长度不超过100。

输出描述:
输出游戏结束后，最终得到的字符串长度

示例1
输入
gg
输出
0
说明
gg 可以直接消除，得到空串，长度为0
示例2
输入
mMbccbc
输出
3
说明
在 mMbccbc 中，可以先消除 cc ；此时字符串变成 mMbbc ，可以再消除 bb ；此时字符串变成 mMc ，此时没有相邻且相同的字符，无法继续消除。最终得到的字符串为 mMc ，长度为3
备注:
输入中包含 非大小写英文字母 时，均为异常输入，直接返回 0*/
int main(int argc, char const *argv[]){
    
    string s;

    cin >> s;

    
    if(s[0] < 'a' && s[0] > 'Z' || s[0] > 'z' || s[0] < 'A'){
            return 0;
    }
    char last = s[0];
    for (int i = 1; i < s.length(); i++){
        if(s[i] < 'a' && s[i] > 'Z' || s[i] > 'z' || s[i] < 'A'){
            return 0;
        }

        if(s[i] == last){
            s[i] = ' ';
            s[i - 1] = ' ';
            // last = '1';
        }else{
            last = s[i];
        }
    }
    stringstream ss(s);
    string tag;
    string ans;
    while (ss>>tag){
        ans += tag;
    }
cout << ans.length()<<endl;
    cout << ans<<endl;
    
    
    return 0;
}
