//23:43 - 16

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
/**
 * 给定两个整数数组array1、array2，数组元素按升序排列。
 * 假设从array1、array2中分别取出一个元素可构成一对元素，现在需要取出k对元素，
 * 并对取出的所有元素求和，计算和的最小值
注意：两对元素如果对应于array1、array2中的两个下标均相同，则视为同一对元素。

输入描述:
输入两行数组array1、array2，每行首个数字为数组大小size(0 < size <= 100);
0 < array1[i] <= 1000
0 < array2[i] <= 1000
接下来一行为正整数k
0 < k <= array1.size() * array2.size()
输出描述:
满足要求的最小和

示例1
输入
3 1 1 2
3 1 2 3
2
输出
4
说明
用例中，需要取2对元素
取第一个数组第0个元素与第二个数组第0个元素组成1对元素[1,1];
取第一个数组第1个元素与第二个数组第0个元素组成1对元素[1,1];
求和为1+1+1+1=4，为满足要求的最小和
*/
using namespace std;

int getMin(vector<int> small,vector<int> big,int k){

    int sum = big[0] + small[0];

    int sidx = 0;
    int bidx = 0;
    while (k > 1){

        if(sidx == small.size()){
            bidx++;
            sum += small[sidx - 1];
            sum += big[bidx];
        }else if(bidx == big.size()){
            sidx++;
            sum += small[sidx];
            sum += big[bidx - 1];

        }else if(small[sidx] + big[bidx + 1] < small[sidx + 1] + big[bidx]){
            bidx++;
            sum += small[sidx];
            sum += big[bidx];
        }else {
            sidx++;
            sum += small[sidx];
            sum += big[bidx];
        }
        k--;
    }
    
    return sum;


}

int main1(int argc, char const *argv[]){
    
    int n1,n2 ;
    cin >> n1;
    vector<int> list1;
    int tag;
    for (int i = 0; i < n1; i++){
        cin >> tag;
        list1.push_back(tag);
    }
    cin >> n2;
    vector<int> list2;
    for (int i = 0; i < n2; i++){
        cin >> tag;
        list2.push_back(tag);
    }
    int k;
    cin >> k;
    sort(list1.begin(),list1.end());
    sort(list2.begin(),list2.end());


    int min = getMin(list1,list2,k);
    
    cout<<min<<endl;

    return 0;
}
