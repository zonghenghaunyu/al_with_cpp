//
// Created by yyy on 2023/3/17.
//

#include "t1.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void print(vector<vector<int>> arr){
    if(arr.size() == 0){
        cout <<"[[]]"<<endl;
        return;
    }
    cout <<"[";
    for (int j = 0; j < arr.size() - 1; ++j) {
        vector<int> a = arr[j];

        cout <<"[";
        for (int i = 0; i < a.size() - 1; ++i) {
            cout << a[i] <<",";
        }
        cout << a[a.size() - 1];
        cout <<"]"<<",";
    }
    vector<int> a = arr[arr.size() - 1];
    cout <<"[";
    for (int i = 0; i < a.size() - 1; ++i) {
        cout << a[i] <<",";
    }
    cout << a[a.size() - 1];
    cout <<"]";
    cout <<"]";

}

int main1(){
    //init

    int tag;
    vector<int> first;
    vector<int> second;
    string input;
    cin >> input;
    int n ;
    cin >> n;
    string inner = input.substr(1,input.length() - 2);
    replace(inner.begin(),inner.end(),',',' ');
    stringstream ss(inner);
    string flag;
    while (ss >> flag){
        int tag = atoi(flag.c_str());
        if(tag >=0 && tag <= 3){
            first.push_back(tag);
        }else{
            second.push_back(tag);
        }
    }
    //todo
    vector<vector<int>> arr;
    if(n == 1){
        if(first.size() == 1 || second.size() == 1){
            if(first.size() == 1){
                arr.push_back(first);
            }
            if(second.size() == 1){
                arr.push_back(second);
            }
        }else if(first.size() == 3 || second.size() == 3){
            if(first.size() == 3){

                arr.push_back(first);

            }
            if(second.size() == 3){
                arr.push_back(second);

            }
        }else if(first.size() == 2 || second.size() == 2){
            if(first.size() == 2){
                arr.push_back(first);

            }
            if(second.size() == 2){
                arr.push_back(second);
            }
        }else if(first.size() == 4 || second.size() == 4){
            if(first.size() == 4){
                arr.push_back(first);
            }
            if(second.size() == 4){
                arr.push_back(second);
            }
        }


    }else if(n == 2){
        if(first.size() == 2 || second.size() == 2){
            if(first.size() == 2){
                arr.push_back(first);
            }
            if(second.size() == 2){
                arr.push_back(second);
            }
        }
        if(first.size() == 4 || second.size() == 4){
            if(first.size() == 4){
                arr.push_back(first);
            } if(second.size() == 4){
                arr.push_back(second);
            }
        }
        if(first.size() == 3 || second.size() == 3){
            if(first.size() == 3){
                arr.push_back(first);
            }
            if(second.size() == 3){
                arr.push_back(second);
            }
        }

    }else if(n == 4){
        if(first.size() == 4){
            arr.push_back(first);
        }
        if(second.size() == 4){
            arr.push_back(second);
        }
    }else if(n == 8){
        vector<int> xxx{0,1,2,3,4,5,6,7};
        if(first.size() + second.size() == 8){
            arr.push_back(xxx);
        }
    }
    print(arr);
    return 0;
}
