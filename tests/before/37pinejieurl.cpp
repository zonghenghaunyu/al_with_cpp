#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

/**
 * 给定一个URL前缀和URL后缀，通过","分割，需要将其连接为一个完整的URL，
 * 如果前缀结尾和后缀开头都没有“/”，需自动补上“/”连接符，如果前缀结尾和后缀开头都为“/”，
 * 需自动去重。
约束：不用考虑前后缀URL不合法情况。

输入描述:
URL前缀（一个长度小于100的字符串),URL后缀（一个长度小于100的字符串）。
输出描述:
拼接后的URL。
示例1
输入
/acm,/bb
输出
/acm/bb
示例2
输入
/abc/,/bcd
输出
/abc/bcd
示例3
输入
/acd,bef
输出
/acd/bef
示例4
输入
,
输出
/
*/
int main1(int argc, char const *argv[])
{
    string url;
    cin>>url;
    replace(url.begin(),url.end(),',',' ');
        replace(url.begin(),url.end(),'/',' ');
    stringstream ss(url);
    string tag;
    vector<string> vec;
    while (ss >> tag)
    {
        vec.push_back(tag);
    }
    string ans = "/";

    for (auto &inner : vec){
        ans+=inner;
        ans+="/";
    }
    if(ans.length() == 1){
        cout<<ans<<endl;
        return 0;
    }
    auto rst = ans.substr(0,ans.length() - 1);

    cout<<rst<<endl;

    return 0;
}
