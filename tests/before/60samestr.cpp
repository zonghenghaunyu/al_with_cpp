//10:44     11:04
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;
/**
 * 给你两个字符串 t 和 p ，要求从 t 中找到一个和 p 相同的连续子串，
 * 并输出该字串第一个字符的下标。

输入描述:
输入文件包括两行，分别表示字符串 t 和 p ，保证 t 的长度不小于 p ，
且 t 的长度不超过1000000，p 的长度不超过10000。
输出描述:
如果能从 t 中找到一个和 p 相等的连续子串，则输出该子串第一个字符在t中的下标（
下标从左到右依次为1,2,3,…）；如果不能则输出”No”；
如果含有多个这样的子串，则输出第一个字符下标最小的。

示例1
输入
AVERDXIVYERDIAN
RDXI
输出
4
*/
int main(int argc, char const *argv[]){
    
    string base,find;
    cin >> base >> find;

    for (int i = 0; i <= base.length() - find.length(); i++){
        
        int curidx = i;
        int end = 0;
        for (int j = 0; j < find.length(); j++){
            
            cout<<base[curidx] << ":"<<find[j]<<endl; 
            if(base[curidx] != find[j]){
                break;
            }else{
                end = j;
                curidx++;
            }
        }
    
        if(end == find.length() - 1){
            
            cout<<i + 1<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
