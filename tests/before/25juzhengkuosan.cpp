/**
 * 20.13
 */

#include <algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>

/**
 * 存在一个m*n的二维数组，其成员取值范围为0或1。其中值为1的成员具备扩散性，
 * 每经过1S，将上下左右值为0的成员同化为1。二维数组的成员初始值都为0，
 * 将第[i,j]和[k,l]两个个位置上元素修改成1后，求矩阵的所有元素变为1需要多长时间。

输入描述:
输出数据中的前2个数字表示这是一个m*n的矩阵，m和n不会超过1024大小；
中间两个数字表示一个初始扩散点位置为i,j；最后2个数字表示另一个扩散点位置为k,l。

输出描述:
输出矩阵的所有元素变为1所需要秒数。

示例1：
输入
4,4,0,0,3,3
输出
3
说明
输出数据中的前2个数字表示这是一个4*4的矩阵；中间两个数字表示一个初始扩散点位置为0,0；
最后2个数字表示另一个扩散点位置为3,3。
给出的样例是一个很简单模型，初始点在对角线上，达到中间的位置分别为3次迭代，即3秒。
所以输出为3。
0,0,0,1
0,0,0,0
0,0,0,0
1,0,0,0

0,0,0,0
0,0,1,0
0,1,0,0
0,0,0,0
*/
using namespace std;

int main(int argc, char const *argv[]){
    
    string s;
    cin >> s;
    replace(s.begin(),s.end(),',',' ');
    stringstream ss(s);
    string tag;
    vector<int> nums;
    while (ss>>tag)
    {
        nums.push_back(atoi(tag.c_str()));
    }
    
    int m ,n;
    int ax,ay,bx,by;
    m = nums[0];
    n = nums[1];
    ax = nums[2];
    ay = nums[3];
    bx = nums[4];
    by = nums[5];
    cout << ax<<":"<<ay<<":"<<bx<<":"<<by<<":"<<m<<":"<<n<<endl;
    pair<int,int>a(ax,ay);
    pair<int,int>b(bx,by);

/*
0,0,0,0, 0,0
0,0,0,0, 0,0
0,0,0,1, 0,0

0,0,0,0, 0,0
0,0,0,0, 1,0
0,0,0,0, 0,0


*/
//x+y

    if(a.first < b.first){
        //a左b右
        if(a.second < b.second){
            //a左下b右上
        }else{
            //a左上b右下
        }
    }else{
        if(a.second < b.second){
            //a右下b左上
        }else{
            //a右上b左下
        }
    }


    
    bool is_continue = true;
    int midx = m/2;
    int midy = n/2;
    int time = 0;


    if(!arr[0][0]){
        time++;
    }
    cout << time<<endl;



    return 0;
}
/**
 *                   if(flg[j]){
                    if(i+1 < m){
                        vector<bool> t = arr[i+1];
                        t[j] = true;
                        // arr[i + 1][j] = true;
                    }
                    if(j + 1 < n){
                        flg[j + 1] = true;
                    }
                    if(j - 1 >= 0){
                        flg[j - 1] = true;
                    }
                    if(i - 1 >= 0){
                        vector<bool> t = arr[i-1];
                        t[j] = true;                
                    }
                    // arr[i - 1][j] = true;
                }  
*/

/**
 *    if(arr[0][0]){
        arr[0][1] = true;
        arr[1][0] = true;
        
        if(bx - 1 >=0){
            arr[bx - 1][by] = true;
        }
        if(bx + 1 <m){
            arr[bx + 1][by] = true;
        }
        if(by + 1 < n){
            arr[bx][by+1] = true;
        }
        if(by - 1 >= 0){
            arr[bx][by-1] = true;
        }
        time++;
    }else if(arr[m-1][n-1]){
        arr[m-1 - 1][n-1] = true;
        arr[m - 1][n - 1 -1] = true;
        if(ax - 1 >=0){
            arr[ax - 1][ay] = true;
        }
        if(ax + 1 <m){
            arr[ax + 1][ay] = true;
        }
        if(ay + 1 < n){
            arr[ax][ay+1] = true;
        }
        if(ay - 1 >= 0){
            arr[ax][ay-1] = true;
        }
        time++;
    }
*/

/**
 * 

*/