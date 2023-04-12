#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

int main1(int argc, char const *argv[])
{


    string str;
    cin >> str;
    replace(str.begin(),str.end(),'#',' ');
    stringstream ss(str);
    string tag;

    vector<long long > arr;
    while (ss >> tag)
    {

        cout << tag<<endl;
arr.push_back(atol(tag.c_str()));
    }
    long long ans = 0;
    ans += arr[0] * (long long)(256*256*256);
    ans += arr[1] * (long long)(256*256);
    ans += arr[2] * (long long)(256);
    ans += arr[3];

    cout << ans<<endl;


    // long long i = (long long)128*256*256*256 + (long long)255*256+255;
    // cout<<i<<endl;
    
    // long long w = (long long)1*256*256*256;
    // cout <<w<<endl;
    return 0;
}
