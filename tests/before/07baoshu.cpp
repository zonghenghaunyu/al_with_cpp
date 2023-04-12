#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<unordered_set>
/**
 * 100个人围号为多少？
成一圈，每个人有一个编码，编号从1开始到100。他们从1开始依次报数，
报到为M的人自动退出圈圈，然后下一个人接着从1开始报数，直到剩余的人数小于M。
请问最后剩余的人在原先的编
输入描述:
输入一个整数参数M
输出描述:
如果输入参数M小于等于1或者大于等于100，输出“ERROR!”；
否则按照原先的编号从小到大的顺序，以英文逗号分割输出编号字符串

示例1：
输入
3
输出
58,91
说明
输入M为3，最后剩下两个人
示例2：
输入
4
输出
34,45,97
说明
输入M为4，最后剩下三个人
*/
using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    if(n <= 1 || n >= 100){
        cout << "ERROR!" << endl;
        return 0;
    }

    vector<int> s;
    for (int i = 0; i < 100; i++)
    {
        s.push_back(i+1);
        /* code */
    }
    int need = 100 - n + 1;
    int idx = 0;
    int c = 0;
    while (true){
        if(idx == need){
            break;
        }
        for (int i = 0; i < 100; i++)
        {
            if(idx == need){
                break;
            }
            if(s[i] == -1){
                continue;
            }
            c++;
            if(c == n){
                idx ++;
                c = 0;
                s[i] = -1;
            }
        }
    
    }
    int j = 1;
    for (int i = 0; i < 100; i++){
        if(s[i] != -1){
            if(j == n - 1){
                cout<<s[i];
                return 0;
            }else{
                cout<<s[i]<<",";
            }
            j++;
        }
    }

    return 0;
}
