#include <unordered_map>
#include <iostream>
using namespace std;
int main(){

    int a = 10;
    int b = 20;
    int c = max(a,b);
    cout << c << endl;

    unordered_map<char,int> map;
    map.emplace('b',20);
    auto w = map.count('b');
    cout << w << endl;
    return 0;

}