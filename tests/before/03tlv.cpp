#include<string>
#include <algorithm>
#include <vector>
 #include <iostream>

 using namespace std;

/**Tag固定占一个字节，Length固定占两个字节
 * 输入
31
32 01 00 AE 90 02 00 01 02 30 03 00 AB 32 31 31 02 00 32 33 33 01 00 CC
输出
32 33
说明
需要解析的信元的Tag是31，从码流的起始处开始匹配
，Tag为32的信元长度为1（01 00，小端序表示为1）；
第二个信元的Tag是90，其长度为2；第三个信元的Tag是30，其长度为3；
第四个信元的Tag是31，其长度为2（02 00），所以返回长度后面的两个字节即可，即32 33。
*/

int main1(int argc, char const *argv[])
{
    /* code */

    string input;
    string find_key;
    cin >> find_key;
    string current_key;
    bool do_key = true;
    bool do_length1 = false;
    bool do_length2 = false;
    int length = -1;
    bool do_value = false;
    string all_length;

    bool isRight = false;

    vector<string> ans;
    while (cin >> input){
        if(do_key){
            current_key = input;
            do_key = false;
            do_length1 = true;
            if(current_key == find_key){
                isRight = true;
            }
        }else
        if(do_length1){
            all_length = input;
            do_length1 = false;
            do_length2 = true;
        }else
        if(do_length2){
            string tmp = input;
            tmp.append(all_length);
            all_length = tmp;
            length = atoi(all_length.c_str());
            do_length2 = false;
            do_value = true;
            all_length.clear();
        }else
        if(do_value){
            string tag = input;
            if(isRight){
                ans.push_back(tag);
            }
            for (int i = 1; i < length; i++){
                cin >> tag;
                if(isRight){
                    ans.push_back(tag);
                }
            }
            if(isRight){
                for_each(ans.begin(),ans.end(),[](string aaa){cout << aaa << " ";});
                return 0;
            }
            do_value = false;
            do_key = true;
        }
        if(cin.get() == '\n'){
            return 0;
        }
    }
    

    return 0;
}
