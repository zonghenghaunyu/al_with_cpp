#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

/** 16 - 39
 * 输入一个由n个大小写字母组成的字符串，按照Ascii码值从小到大的排序规则，
 * 查找字符串中第k个最小ascii码值的字母（k>=1），
 * 输出该字母所在字符串的位置索引(字符串的第一个字符位置索引为0）。
k如果大于字符串长度，则输出最大ascii值的字母所在字符串的位置索引，
如果有重复的字母，则输出字母的最小位置索引。

输入描述:
第一行输入一个由大小写字母组成的字符串
第二行输入k，k必须大于0，k可以大于输入字符串的长度
输出描述:
输出字符串中第k个最小ascii码值的字母所在字符串的位置索引。
k如果大于字符串长度，则输出最大ascii值的字母所在字符串的位置索引，
如果第k个最小ascii码值的字母存在重复，则输出该字母的最小位置索引。

示例1
输入
AbCdeFG
3
输出
5
说明
根据ascii码值排序，第3个最小ascii码值的字母为F，F在字符串中的位置索引为5
（0为字符串的第一个字母位置索引）
示例2
输入
fAdDAkBbBq
4
输出
6
说明
根据ascii码值排序，前4个字母为AABB ，由于B重复，
则只取B的（第一个）最小位置索引6 ，而不是第二个B的位置索引8
*/
int main(int argc, char const *argv[])
{
    /* code */

    string str;
    cin >> str;
    int need_find;
    cin >> need_find;
    vector<char> chars;
    unordered_map<char ,int> idex_map;
    for (int i = 0; i < str.length(); i++){
        chars.push_back(str[i]);
        if(idex_map.count(str[i]) == 0){
            idex_map.emplace(str[i],i);
        }
    }
    sort(chars.begin(),chars.end());
    unordered_map<int ,char> cmap;
    for (int i = 0; i < chars.size(); i++){
        cmap.emplace(i+1,chars[i]);
    }
    
    if(cmap.count(need_find) != 0){
        char the_c = cmap.at(need_find);
        int f_idx = idex_map.at(the_c);
        cout << f_idx << endl;
        return 0;
    }
    char the_c = cmap.at(chars.size());
    int f_idx = idex_map.at(the_c);
    cout << f_idx << endl;
    return 0;
}
