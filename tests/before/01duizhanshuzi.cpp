#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main1(int argc, char const *argv[])
{
    //5 10 20 50 85 1
    int num = 0;
    vector<int> arr;
    
    while (cin >> num){
        arr.push_back(num);
        if(cin.get() == '\n'){
            break;
        }
    }
    deque<int> queue;
    queue.push_front(arr[0]);
    for(int i = 1;i < arr.size();i++){

        int inner = arr[i];
        int flag = 0;
        bool insert = false;
        cout <<"------------"<<endl;
        for (int j = 0; j < queue.size(); j++)
        {
            flag += queue[j];
cout << "flag inner:"<<flag<<":"<<inner<<endl;
            if(flag == inner){
                for (int k = 0; k <= j; k++)
                {   
                    
                    queue.pop_front();
                }
                queue.push_front(flag*2);
                insert = true;
                break;
            }
            if(flag > inner){
                break;
            }

        }
        if(!insert){
            queue.push_front(arr[i]);
        }
    }

    while (!queue.empty())
    {
        cout << queue.front()<<" ";
        queue.pop_front();
        /* code */
    }
    

    return 0;
}
