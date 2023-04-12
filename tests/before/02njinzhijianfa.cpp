#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    string num1,num2;
    cin >> n >> num1 >> num2;

    int max_len = max(num1.length(),num2.length());
    int carry = 0;
    string ans = "";
    for (int i = 0; i < max_len; i++){
        
        carry += i < num1.length() ? (num1[num1.length() - 1 - i] - '0') : 0;
        carry += i < num2.length() ? (num2[num2.length() - 1 - i] - '0') : 0;
        char ss = (char)(carry%n + '0');
        cout << "中间："<< ss << endl;
        ans.push_back(ss);
         cout << "中间ans:"<< ans << endl;
        carry /= n;
    }
    if(carry > 0){
        ans.append("1");
    }

    reverse(ans.begin(),ans.end());
    cout << ans<<endl;

}