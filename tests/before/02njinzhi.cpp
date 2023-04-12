#include <set>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
/**
 * 第一个参数是整数形式的进制N值，N值范围为大于等于2、小于等于35。
第二个参数为被减数字符串；
第三个参数为减数字符串。有效的字符包括0~9以及小写字母a~z，字符串有效字符个数最大为100个字符，另外还有结尾的\0。
限制：
输入的被减数和减数，除了单独的0以外，不能是以0开头的字符串。 
如果输入有异常或计算过程中有异常，此时应当输出-1表示错误。 
输出描述:
输出：2个。
其一为减法计算的结果，-1表示出错，0表示结果为整数，1表示结果为负数。
其二为表示结果的字符串。

示例1:
输入
2 11 1
输出
0 10
说明
按二进制计算 11 -1 ，计算正常，0表示符号为正数，结果为10
*/

bool check(string num,int n,unordered_map<char,int> map){
    //一会补
    return false;
}
bool isFalse(string num1,string num2,int n,unordered_map<char,int> map){
    if(n < 2 || n > 35) return true;
    if(num1[0] == '0' &&  num1.length() == 1 || num2[0] == '0' && num2.length() == 1){
        return true;
    }
    if(check(num1,n,map)){
        return true;
    }else if(check(num2,n,map)){
        return true;
    }else {
        return false;
    }
}
int main(){
    // 'a' = 97

    char a[]{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h'
    ,'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    unordered_map<char,int> map;
    for (int i = 0; i < 35; i++)
    {
        cout << a[i];
        map.emplace(a[i],i);
        /* code */
    }
    int count = 0;

    int n;
    cin >> n;
    string num1,num2;
    cin >> num1 >> num2;
    if(isFalse(num1,num2,n,map)){
        return -1;
    }


    char an1 = 0;
    char an2 = 0;
    //--: -2 - -3 = 3 - 2
    vector<int> ans;
    if(num1[0] == '-' || num2[0] == '-'){
        int idx1 = num1.length() - 1;
        int idx2 = num2.length() - 1;
        while (idx1 >0 && idx2 > 0){

            int n1 = map.at(num1[idx1]);

        }

        
        

        return -1;
    }
    // //-+: -2 - 3 = - (2 + 3)
    // if(num1[0] == '-' || num2[0] != '-'){
    //     return -1;
    // }
    // //+-: 2 - 3 = 2 - 3
    // if(num1[0] != '-' || num2[0] == '-'){
    //     return -1;
    // }

}
