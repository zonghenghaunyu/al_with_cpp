#include <algorithm>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;
//满减100 -10，打折92，无门栏5
void getMin(int all,int a,int b,int c,vector<bool> used,int& min,int& sum,int& l,int& ans){
    if(sum < min){
        ans = l;
        min = sum;
    }
/*    if(used[0] && used[1]&& used[2]){
        cout << sum << ":" <<ans << endl;
    }*/
    if(!used[0]){
        used[0] = true;
        //使用a
        int tag = sum/100;
        sum = sum - tag * 10;
        l+=tag;
        getMin(all,a,b,c,used,min,sum,l,ans);
        l-=tag;
        sum = sum + tag * 10;
        used[0] = false;
    }
    if(!used[1]){
        used[1] = true;
        int cache = sum;
        //使用b
        sum = sum*0.92;

        l++;
        getMin(all,a,b,c,used,min,sum,l,ans);
        l--;
        sum = cache;
        used[1] = false;
    }
    if(!used[2]){
        used[2] = true;
        //使用c
        int tag = c * 5;
        sum = sum - tag;
        l+=c;
        getMin(all,a,b,c,used,min,sum,l,ans);
        l-=c;
        sum = sum + tag;
        used[2] = false;
    }
}

int main1(int argc, char const *argv[])
{
    //满减100 -10，打折92，无门栏5
    int a,b,c;
    cin >> a >> b>>c;
    int n;
    //人数
    cin >> n;
    vector<int> price;
    int i = n;
    int tag;
    while ( i > 0)
    {
        i--;
        cin >>tag;
        price.push_back(tag);
        /* code */
    }
    vector<bool> used;
    for (int i = 0; i < 3; i++)
    {
        used.push_back(false);
    }

    vector<int> anss;
    vector<int> u;
    for(int i : price){
        int min = INT32_MAX;
        int sum = i;
        int l = 0;
        int ans = 0;
        getMin(i,a,b,c,used,min,sum,l,ans);
        anss.push_back(min);
        u.push_back(ans);
    }

    for (int i = 0; i < anss.size(); ++i) {
        cout << anss[i]<<" "<<u[i]<<endl;
    }

    return 0;
}