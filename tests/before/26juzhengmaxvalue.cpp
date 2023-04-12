
/**515  - 56
 * 给定一个仅包含0和1的N*N二维矩阵，请计算二维矩阵的最大值，计算规则如下：
1、 每行元素按下标顺序组成一个二进制数（下标越大越排在低位），二进制数的值就是该行的值。
矩阵各行值之和为矩阵的值。
2、允许通过向左或向右整体循环移动每行元素来改变各元素在行中的位置。
      比如： [1,0,1,1,1]向右整体循环移动2位变为[1,1,1,0,1]，二进制数为11101，值为29。
                  [1,0,1,1,1]向左整体循环移动2位变为[1,1,1,1,0]，二进制数为11110
                  ，值为30。

输入描述:
1、输入的第一行为正整数，记录了N的大小，0 < N <= 20。
2、输入的第2到N+1行为二维矩阵信息，行内元素边角逗号分隔。
输出描述:
矩阵的最大值。

示例1：
输入
5
1,0,0,0,1
0,0,0,1,1
0,1,0,1,0
1,0,0,1,1
1,0,1,0,1
输出
122
说明 2 2 2 2 2
第一行向右整体循环移动1位，得到本行的最大值[1,1,0,0,0]，二进制值为11000，十进制值为24。
第二行向右整体循环移动2位，得到本行的最大值[1,1,0,0,0]，二进制值为11000，十进制值为24。
第三行向左整体循环移动1位，得到本行的最大值[1,0,1,0,0]，二进制值为10100，十进制值为20。
第四行向右整体循环移动2位，得到本行的最大值[1,1,1,0,0]，二进制值为11100，十进制值为28。
第五行向右整体循环移动1位，得到本行的最大值[1,1,0,1,0]，二进制值为11010，十进制值为26。
因此，矩阵的最大值为122。
*/

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<sstream>


using namespace std;

int get_num(deque<int>& inner){
    int tag = 0;
    
    int sum = 0;
    for (int i = inner.size() - 1; i >= 0; i--)
    {
        tag++;
        int cur_dec = inner[i];
        if(cur_dec == 0){
            continue;
        }
        for (int j = 1; j < tag; j++)
        {
            cur_dec *= 2;
            /* code */
        }
        sum += cur_dec;

    }
    // cout << "inner list:";
    // for_each(inner.begin(),inner.end(),[](int it){
    //     cout << it<<",";
    // });
    // cout <<endl;
// cout << "outter:"<< sum<<endl;
    return sum;

}

int makebig( deque<int>& inner){

    int sum = 0;

    int cur_sum = 0;
    int n = inner.size();
    while (n >0)
    {
        /* code */
        cur_sum = get_num(inner);
        if(cur_sum > sum){
            sum = cur_sum;
        }
        int last = inner.back();
        inner.emplace_front(last);
        inner.pop_back();
        n--;
    }
    return sum;
}



int main1(int argc, char const *argv[]){


    int n ;
    cin >> n;

    vector<deque<int >> arr;

    int ans = 0;
    for (int i = 0; i < n; i++){
        deque<int> inner;
        string tag;
        cin >> tag;
        replace(tag.begin(),tag.end(),',',' ');
        stringstream ss(tag);
        string flag;
        while (ss >> flag)
        {
            inner.push_back(atoi(flag.c_str()));
        }
        
        ans += makebig(inner);

        arr.push_back(inner);
        
    }
    

    cout <<"ans:"<<ans<<endl;

    return 0;
}
