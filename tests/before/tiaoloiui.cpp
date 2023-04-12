#include<vector>
#include<iostream>

using namespace std;

int main1(int argc, char const *argv[])
{
    
    //1,3
    int n = 50;
    vector<int> dp;
    for(int i = 0;i < n;i++){
        dp.push_back(0);
    }
    //dp[3] = 2
    //dp[i] = dp[i-1] + dp[i-3]

    dp[2] = 2;
    dp[1] = 1;
    dp[0] = 1;
    for(int i = 3;i < n;i++){
        dp[i] = dp[i-1]+ dp[i-3];
    }
    cout << dp[n-1]<<endl;
    return 0;
}
