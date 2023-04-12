#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >>n;
    vector<int> arr1;
        vector<int> arr2;
    int tag;
    for(int i =0;i < n;i++){
        cin >> tag;
        arr1.push_back(tag);
    }
    cin >> m;
    for(int i =0;i < m;i++){
        cin >> tag;
        arr2.push_back(tag);
    }
    int num = 0;
    cin >> num;

    int i = 0;
    int j = 0;
    int ans = 0;
    ans += arr1[i];
    ans+= arr2[i];
    while (num > 1)
    {
        if(i == n - 1){
            ans += arr1[i];
            ans += arr2[j+1];
            j++;

            num--;
            if(j == m - 1){
                if(num != 0){
                    return 0;
                }
            }
            continue;
        }
        if(j == m - 1){
            ans += arr1[i + 1];
            ans += arr2[j];
            i++;
            num--;
            if(i == n - 1){
                if(num != 0){
                    return 0;
                }
            }
            continue;
        }

        if(arr1[i] + arr2[j+1] >arr1[i + 1] + arr2[j] ){
            ans+= arr1[i + 1];
            ans += arr2[j];
            i++;
        }else{
            ans+= arr1[i];
            ans += arr2[j + 1];
            j++;
        }

        num--;
    }
    cout << ans << endl;

    return 0;
}
