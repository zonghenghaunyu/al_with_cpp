#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<set>
#include<tuple>
/**
 * 某学校举行运动会，学生们按编号(1、2、3…n)进行标识，现需要按照身高由低到高排列，对身高相同的人，按体重由轻到重排列；对于身高体重都相同的人，维持原有的编号顺序关系。请输出排列后的学生编号。

输入描述:
两个序列，每个序列由n个正整数组成（0 < n <= 100）。第一个序列中的数值代表身高，第二个序列中的数值代表体重。
输出描述:
排列结果，每个数值都是原始序列中的学生编号，编号从1开始

示例1：
输入
4
100 100 120 130
40 30 60 50
输出
2 1 3 4
说明
输出的第一个数字2表示此人原始编号为2，即身高为100，体重为30的这个人。由于他和编号为1的人身高一样，但体重更轻，因此要排在1前面。

示例2：
输入
3
90 110 90
45 60 45
输出
1 3 2
说明
1和3的身高体重都相同，需要按照原有位置关系让1排在3前面，而不是3 1 2
*/
using namespace std;


int main(int argc, char const *argv[]){

    vector<int> high;
    vector<int> weight;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int tag;
        cin >> tag;
        high.push_back(tag);
    }
    for (int i = 0; i < n; i++){
        int tag;
        cin >> tag;
        weight.push_back(tag);
    }
    vector<tuple<int,int,int>> persons;
    for (int i = 0; i < n; i++){
        persons.push_back(make_tuple(high[i],weight[i],i));
    }
    sort(persons.begin(),persons.end(),[](tuple<int,int,int> a,tuple<int,int,int> b){
        if(get<0>(a) > get<0>(b)){
            return false;
        }else if(get<0>(a) == get<0>(b) && get<1>(a) > get<1>(b)){
            return false;
        }else if(get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) > get<2>(b)){
            return false;
        }else return true;
    });
    for_each(persons.begin(),persons.end(),[](tuple<int,int,int> a){
        cout<<get<0>(a)<<":"<<get<1>(a)<<":"<<get<2>(a) + 1<<endl;
    });
    


    return 0;
}
