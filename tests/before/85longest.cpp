#include<algorithm>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>
/**1:40-59
 * 有N个正整数组成的一个序列。给定整数sum，求长度最长的连续子序列，
 * 使他们的和等于sum，返回此子序列的长度，如果没有满足要求的序列，返回-1。

输入描述:

输入
1,2,3,4,2
6
输出
3
说明
解释：1,2,3和4,2两个序列均能满足要求，所以最长的连续序列为1,2,3，因此结果为3
示例2
输入
1,2,3,4,2
20
输出
-1
说明
解释：没有满足要求的子序列，返回-1
备注:
输入序列仅由数字和英文逗号构成，数字之间采用英文逗号分隔；
序列长度：1 <= N <= 200；
输入序列不考虑异常情况，由题目保证输入序列满足要求。
*/


using namespace std;

int main1(int argc, char const *argv[]){
    string str;
    cin >> str;
    int sum;
    cin >> sum;

    replace(str.begin(),str.end(),',',' ');

    stringstream ss(str);
    string tag;
    vector<int > arr;
    while (ss >>tag){
        arr.push_back(atoi(tag.c_str()));
    }

    int maxLength = -1;
    int cur_len = 0;
    int cur_sum = 0;
    for (int i = 0; i < arr.size(); i++){

        for (int j = i; j < arr.size(); j++){
           
           cur_sum+= arr[j];
           cur_len++;
           if(cur_sum == sum && cur_len > maxLength){
                maxLength = cur_len;
                break;
           }
           if(cur_sum > sum){
                break;
           }
        }
        cur_sum = 0;
        cur_len = 0;
        
    }
    
    cout << maxLength << endl;


    return 0;
}
