#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;


/**
 * 22:51 -- 23:10
*/

int main(int argc, char const *argv[])
{
    
    string target,source;
    cin >> target >> source;

    int sourceLen = source.length();
    int targetLen = target.length();
    reverse(source.begin(),source.end());
    reverse(target.begin(),target.end());

    int idx = -1;

    int i = 0;
    for (int j = 0; j < targetLen; j++)
    {
        char find = target[j];
        for(;i < sourceLen ; i ++ ){

            if(source[i] == find){
                if(j == targetLen - 1){
                    idx = i;
                }
                break;
            }

        }
    }
    //0,1,2,3,4,5,6,7
    if(idx != -1){
        cout << sourceLen - 1 - idx<<endl;
    }else{
        cout <<idx<<endl;
    }
        
    return 0;
}
