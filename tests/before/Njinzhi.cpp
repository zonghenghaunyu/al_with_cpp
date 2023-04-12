#include <iostream>
#include <algorithm>
int toNBase(int num,int base){
    int res = 0,factor = 1;
    while (num){
        res += factor*(num%base);
        num/=base;
        factor *= 10;
    }
    return res;
}

int to10Base(int num,int base){
    int res,factor = 1;
    while (num){

        res += factor*(num%10);
        num/=10;
        factor*=base;
    }
    return res;
    
}


int main(int argc, char const *argv[]){

    // int num,n;
    // std::cin >> num>>n;
    int a = to10Base(1010 ,2);
    std::cout<<"转为10进制"<<a<<std::endl;
    int b = toNBase(10,3);
    std::cout<<"转为N进制"<<a<<std::endl;
    std::cout<<"----------------------"<<a<<std::endl;
    
}
