
#include "doctest.h"
#include "iostream"
#include"string"
using std::string;
using std::cout;
using std::endl;
bool isRobotBounded(string instructions) {

    int x = 0;
    int y = 0;
    int cur = 0;//顺时针+1 逆时针-1
    for(int i = 0;i < 4;i ++){

        for (int j = 0; j < instructions.length(); j++)
        {
            int tmp = cur < 0 ? 4 - abs(cur)%4 : cur;
            char c = instructions[j];
            if(c == 'G'){
                int direction = tmp % 4;
                if(direction == 0){
                    y++;
                }else if(direction == 1){
                    x++;
                }else if(direction == 2){
                    y--;
                }else if(direction == 3){
                    x--;
                }
            }else if(c == 'L'){
                cur--;
            }else if( c == 'R'){
                cur++;
            }

        }
        

    }
    if(x != 0 || y != 0){
        return false;
    }

    return true;
}

TEST_CASE("fort")
{
    bool s = isRobotBounded("GGLLGG");
    cout << s << endl;
    // cout<<"asdasdadsa"<<endl;

}

