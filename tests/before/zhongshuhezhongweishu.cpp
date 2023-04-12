/**20:20  ---  51
 * 众数是指一组数据中出现次数量多的那个数，众数可以是多个
中位数是指把一组数据从小到大排列，最中间的那个数，如果这组数据的个数是奇数，那最中间那个就是中位数，如果这组数据的个数为偶数，那就把中间的两个数之和除以2，所得的结果就是中位数
查找整型数组中元素的众数并组成一个新的数组，求新数组的中位数
输入描述:
输入一个一维整型数组，数组大小取值范围 0<N<1000，数组中每个元素取值范围 0<E<1000
输出描述:
输出众数组成的新数组的中位数
————————————————
版权声明：本文为CSDN博主「向着百万年薪努力的小赵」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44688973/article/details/126263296
*/

#include <algorithm>
#include<string>
#include<vector>
#include<iostream>
#include <unordered_map>

using namespace std;

int main1(int argc, char const *argv[])
{
    
    int tag;
    vector<int> list;
    int i = 0;
    while (cin >> tag)
    {
        list.push_back(tag);

        if(cin.get() == '\n'){
            break;
        }
    }
    sort(list.begin(),list.end());
// cout <<"bbbbbbbbbbbbbbbbb"<<endl;
    int nums = 0;
    int cur_nums = 1;
    unordered_map<int,int> map;
    map.emplace(list[0],1);
    for (int i = 1; i < list.size(); i++)
    {
        
        if(list[i] == list[i - 1]){
            cur_nums ++;
            // cout <<"first if-cur_nums:"<<cur_nums<<"mapsize"<<map.size()<<endl;
            if(cur_nums > nums){
                nums = cur_nums;
                if(map.count(list[i]) != 0){
                    map[list[i]] += 1;
                }else{
                    map.clear();
                    map.emplace(list[i],nums);
                }

                // cout <<"cur_nums > nums-cur_nums:"<<cur_nums<<"mapsize"<<map.size()<<endl;
            }else if(cur_nums == nums){
                if(map.count(list[i]) != 0){
                    // cout <<"cur_nums == nums != 0 -cur_nums:"<<cur_nums<<"mapsize"<<map.size()<<endl;
                    map[list[i]] += 1;
                }else {
                    // cout <<"cur_nums == nums == 0 -cur_nums:"<<cur_nums<<"mapsize"<<map.size()<<endl;
                    map.emplace(list[i],nums);
                }
            }
        }else{
            cur_nums = 0;
            // cout <<"first else-cur_nums:"<<cur_nums<<"aaa:"<<map.size()<<endl;

        }
    }
    vector<int > anew;
    for (pair<int,int> p: map)
    {
        for (int i = 0; i < p.second; i++)
        {
            anew.push_back(p.first);
        }
    }
    sort(anew.begin(),anew.end());


    if(anew.size() == 1){
        cout << anew[0]<<endl;
        return 0;
    }
    //0 1 2 3 4 5 6 7
    int mid = (anew.size() - 1) / 2;
    if(anew.size()%2 == 0){
        cout << (anew[mid] + anew[mid + 1]) / 2 << endl;
    }else {
        cout << anew[mid] << endl;
    }

    return 0;
}
