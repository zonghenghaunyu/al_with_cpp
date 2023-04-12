#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<tuple>

using namespace std;
//11:4  11:41
/*
在通信系统中，一个常见的问题是对用户进行不同策略的调度，会得到不同的系统消耗和性能。

假设当前有n个待串行调度用户，每个用户可以使用A/B/C三种不同的调度策略，
不同的策略会消耗不同的系统资源。请你根据如下规则进行用户调度，并返回总的消耗资源数。
规则：

1.     相邻的用户不能使用相同的调度策略，例如，第1个用户使用了A策略，
       则第2个用户只能使用B或者C策略。
2.     对单个用户而言，不同的调度策略对系统资源的消耗可以归一化后抽象为数值。
       例如，某用户分别使用A/B/C策略的系统消耗分别为15/8/17。
3.     每个用户依次选择当前所能选择的对系统资源消耗最少的策略（局部最优），
       如果有多个满足要求的策略，选最后一个。

输入描述:
第一行表示用户个数n
接下来每一行表示一个用户分别使用三个策略的系统消耗resA resB resC
输出描述:
最优策略组合下的总的系统资源消耗数
示例1
输入
3
15 8 17
12 20 9
11 7 5
输出
24
说明1号用户使用B策略，2号用户使用C策略，3号用户使用B策略。系统资源消耗: 8 + 9 + 7 = 24。
备注:
所有策略对系统的资源消耗均为正整数，n < 1000
*/
vector<pair<int,int>> getLest(tuple<int,int,int> t){
    int a = get<0>(t);
    int b = get<1>(t);
    int c = get<2>(t);
    pair<int,int> a1(a,0);
    pair<int,int> a2(b,1);
    pair<int,int> a3(c,2);
    vector<pair<int,int>> s;
    s.push_back(a1);
    s.push_back(a2);
    s.push_back(a3);
    sort(s.begin(),s.end(),[](pair<int,int> p1,pair<int,int> p2) -> bool{
        if(p1.first < p2.first){
            return true;
        }else if(p1.first == p2.first && p1.second > p2.second){
            return true;
        }else{
            return false;
        }
    });
    for_each(s.begin(),s.end(),[](pair<int,int> w){
        cout << "sort:"<<w.first<<":"<<w.second<<endl;
    });

    return s;
}
int main(int argc, char const *argv[]){

    int n;
    cin >> n;
    vector<tuple<int,int,int>> s;
    for (int i = 0; i < n; i++){
        int e,f,g;
        cin >>e;cin >>f;cin >>g;
        tuple<int,int,int> a = make_tuple(e,f,g);
        s.push_back(a);
    }
    int last_select = 0;
    tuple<int,int,int> first = s[0];
    pair<int,int> xx = getLest(first)[0];
    last_select = xx.second;
    cout<<last_select<<endl;
    int sum = xx.first;
    for (int i = 1; i < n; i++){
        vector<pair<int,int>> list = getLest(s[i]);
        
        if(last_select == list[0].second){
            last_select = list[1].second;
            sum += list[1].first;
        }else{
            last_select = list[0].second;
            sum += list[0].first;
        }
        cout<<last_select<<endl;
 
    }
    
    cout <<sum<<endl;
    

    
    return 0;
}
