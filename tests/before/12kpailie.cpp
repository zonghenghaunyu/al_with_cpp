//47 -- 15
/**
 * 给定参数n，从1到n会有n个整数：1,2,3,…,n，这n个数字共有 n! 种排列。
按大小顺序升序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
*/
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<deque>

using namespace std;

void change(vector<bool>& tag,deque<int>& quque,int k,int level,int n,int& flag){
            // cout <<"level:"<<level<<"inner:";
            // for_each(quque.begin(),quque.end(),[](int a){
            //     cout<< a<<",";
            // });
            // cout <<endl;
    if(level == n){
        //exit--do something
  
        flag++;
        if(flag == k){
            for_each(quque.begin(),quque.end(),[](int a){
                cout << a;
            });
            cout << endl;
        };
       
    }

    for(int i = 1;i <= n ; i++){
    
        if(tag[i - 1]){
            continue;
        }
        tag[i - 1] = true;
        quque.push_back(i);
        change(tag,quque,k,level + 1,n,flag);
        if(flag == k){
            return;
        }
        quque.pop_back();
        tag[i - 1] = false;
    }
    
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n>>k;
    
    vector<bool> tag;
    for(int i = 0;i<n;i++){
        tag.push_back(false);
    }
    int flag = 0;
    deque<int> quque;
    for(int i = 1;i <= n ; i++){
        // cout<<"dijige"<<i<<endl;
        tag[i - 1] = true;
        quque.push_back(i);
        change(tag,quque,k,1,n,flag);
        if(flag == k){
            return 0 ;
        }
        quque.pop_back();
        tag[i - 1] = false;
    }

    return 0;
}
