#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main1(int argc, char const *argv[])
{
    
    int n ;
    cin >> n;
    int tag;
    vector<int > arr;
    vector<bool> bools;
    while (cin >>tag)
    {
        bools.push_back(false);
  
        arr.push_back(tag);
        if(cin.get() == '\n'){
            break;
        }
    }
    sort(arr.begin(),arr.end());
    int ans = 0;
    for(int i = 0;i < arr.size();i++){
 
        if(bools[i]){
            continue;
        }else{
            ans++;
            for (int j = i+1; j < arr.size(); j++)
            {
                if(arr[j] % arr[i] == 0){
                    bools[j] = true;
                }
            }
        }
    }

    cout << ans<<endl;

    return 0;
}
