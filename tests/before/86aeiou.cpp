#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;

/**19- 31
 * 定义：当一个字符串只有元音字母（aeiouAEIOU）组成，称为元音字符串。
现给定一个字符串，请找出其中最长的元音字符子串，并返回其长度；如果找不到，则返回0。

子串：字符串中任意个连续的字符组成的子序列称为该字符串的子串。
输入描述:
一个字符串，其长度范围：0 < length <= 65535。
字符串仅由字符a-z和A-Z组成。

输出描述:
一个整数，表示最长的元音字符子串的长度。

示例1
输入
asdbuiodevauufgh
输出
3
说明
样例1解释：最长元音子串为 “uio” 或 “auu”，其长度都为3，因此输出3
*/
int main1(int argc, char const *argv[]){
    
    string str;
    cin >> str;
    unordered_set<char> aset{'a','e','i','o','u','A','E','I','O','U'};

    bool last_is_right = false;
    int max_len = 0;
    int cur_len = 0;

    if(aset.count(str[0]) != 0){
        max_len++;
        cur_len++;
        last_is_right = true;
    }
    for (int i = 1; i < str.length(); i++)
    {
        if(aset.count(str[i]) != 0 && last_is_right){
            cur_len++;
            if(cur_len > max_len){
                max_len = cur_len;
            }
        }else if(aset.count(str[i]) != 0 && !last_is_right){
            cur_len = 1;
            last_is_right = true;
            if(cur_len > max_len){
                max_len = cur_len;
            }
        }else {
            last_is_right = false;
            cur_len = 0;
        }
    }
    cout << max_len<< endl;

    return 0;
}
