/**6-16
 * 某农场主管理了一大片果园，fields[i]表示不同
 * 果林的面积，单位：（m^2），现在要为所有的果林施
 * 肥且必须在 n 天之内完成，否则影响收成。 
 * 小布是果林的工作人员，他每次选择一片果林进行施肥，
 * 且一片果林施肥完后当天不再进行施肥作业。 
 * 假设施肥机的能效为 k，单位：（m^2/day），
 * 请问至少租赁能效 k 为多少的施肥机才能
 * 确保不影响收成？ 如果无法完成施肥任务，则返回-1。

输入
第一行输入为m和n，
m表示fields中的元素个数，
n表示施肥任务必须在n天内（含n天）完成； 
第二行输入为fields，fields[i]表示
果林i的面积，单位：（m^2）
5 7
5 7 9 15 10

输出
对于每组数据，
输出最小施肥机的能效（k），
无多余空格 
作者：发量迷人的乔喻 https://www.bilibili.com/read/cv22366170 出处：bilibili
*/

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int m,n;
    cin >>m>>n;
    
    int tag = 0;
    vector<int> arr;
    for(int i = 0;i < m ;i++){
        cin >> tag;
        arr.push_back(tag);
    }

    sort(arr.begin(),arr.end());
    int min = arr[m-1];
    for(int k = arr[0];k <arr[m - 1] ;k++){
        int times = 0;
        for (int i = 0; i < m; i++)
        {
            int tmp = arr[i];
            if(k == tmp){
                times++;
            }else{
                while (tmp>0)
                {
                    times++;
                    tmp -= k;
                    if(times > n){
                        break;
                    }
                }
            }
            if(times > n){
                break;
            }
        }
        if(times <= n && k < min){
            min = k;
        }
    }
    cout << min <<endl;

    return 0;
}
