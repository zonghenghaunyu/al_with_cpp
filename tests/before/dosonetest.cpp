#include <algorithm>
#include<vector>
#include<deque>
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    vector<int> a{3,2,1,5,3,2,3,7,89,3};
    vector<int> b{6,4,2,34,2,65,3,43,23,3};
    vector<int> c{32,43,2,11,22,33,21,23,23};
    vector<vector<int>> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    vector<vector<int>> xxx;
    for (int i = 0; i < 3; i++)
    {
        vector<int> inner = arr[i];
        sort(inner.begin(),inner.end());
        xxx.push_back(inner);
        /* code */
    }
       
    for (int i = 0; i < 3; i++)
    {
        vector<int> inner = xxx[i];
        for_each(inner.begin(),inner.end(),[](int i){
            cout << i << " ";
        });
        cout << endl;
        /* code */
    } 
    
    return 0;
}
