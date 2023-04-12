/**
 * 2:33 - 2:47
 * 现有一字符串仅由 '('，')'，'{'，'}'，'['，']'六种括号组成。
若字符串满足以下条件之一，则为无效字符串：
  ①任一类型的左右括号数量不相等；
  ②存在未按正确顺序（先左后右）闭合的括号。
输出括号的最大嵌套深度，若字符串无效则输出0。
0≤字符串长度≤100000

输入描述:
一个只包括 '('，')'，'{'，'}'，'['，']'的字符串
输出描述:
一个整数，最大的括号深度

示例1
输入
[]
输出
1
说明
有效字符串，最大嵌套深度为1
示例2
输入
([]{()})
输出
3
说明
有效字符串，最大嵌套深度为3
示例3
输入
(]
输出
0
说明
无效字符串，有两种类型的左右括号数量不相等
示例4
输入
([)]
输出
0
说明
无效字符串，存在未按正确顺序闭合的括号
示例5
输入
)(
输出
0
说明
无效字符串，存在未按正确顺序闭合的括号
 * 
*/

#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
#include<unordered_set>
#include<deque>

using namespace std;

int main(int argc, char const *argv[]){
    unordered_set<char> left{'(','{','['};
    unordered_set<char> right{')','}',']'};

    deque<char> queue;
    string str;
    cin >> str;

    int max = 0;
    int cur_num = 0;

    for (int i = 0; i < str.length(); i++){
        if(left.count(str[i]) != 0){
            queue.emplace_front(str[i]);
            cur_num = 0;
        }
        if(right.count(str[i]) != 0){
            char s = queue.front();
            if(s == '(' && str[i] != ')' || s == '[' && str[i] != ']' || s == '{' && str[i] != '}'){
                cout<<0<<endl;
                return 0;
            }
            if(s == '(' && str[i] == ')' || s == '[' && str[i] == ']' || s == '{' && str[i] == '}'){
                queue.pop_front();
                cur_num++;
            }

            if(cur_num > max){
                max = cur_num;
            }
        }
        
    }
    
cout<<max<<endl;
    return 0;
}
