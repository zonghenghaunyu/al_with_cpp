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
有一个特殊的5键键盘，上面有a，ctrl-c，ctrl-x，ctrl-v，ctrl-a五个键。
a键在屏幕上输出一个字母a；ctrl-c将当前选择的字母复制到剪贴板；
ctrl-x将当前选择的字母复制到剪贴板，并清空选择的字母；
ctrl-v将当前剪贴板里的字母输出到屏幕；ctrl-a选择当前屏幕上的所有字母。
注意：
1 剪贴板初始为空，新的内容被复制到剪贴板时会覆盖原来的内容
2 当屏幕上没有字母时，ctrl-a无效
3 当没有选择字母时，ctrl-c和ctrl-x无效
4 当有字母被选择时，a和ctrl-v这两个有输出功能的键会先清空选择的字母，再进行输出
输入描述:
输入为一行，为简化解析，用数字1 2 3 4 5代表a，ctrl-c，ctrl-x，ctrl-v，ctrl-a五个键
    的输入，数字用空格分隔
输出描述:
输出一个数字，为最终屏幕上字母的数量
*/
//input
void command1(int& screan, int& table, bool& isSelect) {
    if (isSelect) {
        screan = 0;
        isSelect = false;
    }
    screan++;
}
//cc
void command2(int& screan, int& table, bool& isSelect) {
    if (isSelect) {
        table = screan;
    }
}
//cx
void command3(int& screan, int& table, bool& isSelect) {
    if (isSelect) {
        table = screan;
        screan = 0;
        isSelect = false;
    }
}
void command4(int& screan, int& table, bool& isSelect) {
    if (isSelect) {
        screan = table;
        isSelect = false;
    }else {
        screan += table;
    }
}
void command5(int& screan,bool& isSelect) {
    if(screan != 0){
        isSelect = true;
    }
}

int main1(){
    int screen = 0;
    int table = 0;
    bool isSelect = false;
    int command;
 
    while (cin >> command){
        if (command == 1) {
            command1(screen, table, isSelect);
        }
        if (command == 2) {
            command2(screen, table, isSelect);
         }
        if (command == 3) {
            command3(screen, table, isSelect);
        }
        if (command == 4) {
            command4(screen, table, isSelect);
        }
        if (command == 5) {
            command5(screen,isSelect);
        }
        if(cin.get() == '\n'){
            cout << screen<<endl;
            break;
        }
    }
}