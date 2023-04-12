#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include <thread>
#include <chrono>
/**
 * 这道题对于OD考试来讲，是输入一个 字符串 num 和 一个数字 n， 
 * 而力扣是 直接入参是 一个字符串 num 和一个数字 n 。仅此差别而已。

让你求的是， 从num 中删掉 n 个数字后， 得到的数值最小。 
力扣给了更多提示，但OD机考的时候没有那么多提示，比如 n 大于 num.size() 怎么办，
 没有写，应该是没有这类用例，所以你不用考虑。
*/
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    int n;
    cin >>n;
    if(n >= str.length()){
        cout << 0<<endl;
        return 0;
    }    

    int tag = 0;
    for (int j = 0; j < n; j++){
        char last = str[str.length() - 1];
        bool ischange = false;
        for (int i = 1; i < str.length() - 1; i++){
            if(str[i] > str[i+1]){
                str[i] = ' ';
                tag++;
                ischange = true;
                break;
            }
        }
        if(!ischange){
            str[str.length() - 1] = ' ';
        }
        str.erase(remove(str.begin(),str.end(),' '),str.end());
    }
    cout << str<<endl;
    return 0;
}
