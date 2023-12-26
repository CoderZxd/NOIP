//【题目描述】 大整数的因子
//已知正整数k满足2≤k≤9，现给出长度最大为30位的十进制非负整数c，求所有能整除c 的k。
//
//【输入】
//一个非负整数c，c的位数≤30。
//
//【输出】
//若存在满足 c%k == 0 的k，从小到大输出所有这样的k，相邻两个数之间用单个空格隔开；若没有这样的k，则输出"none"。
//
//【输入样例】
//30
//【输出样例】
//2 3 5 6

#include <iostream>
using namespace std;

int main(){
    string c;
    cin>>c;
    int len = c.length();
    int C[len];
    for(int i=0; i < len; i++) {
        C[i]= c[i] - '0';
    }
    for(int k=3;k<=9;k++){

    }
    //能被2整除
    if(C[len-1]%2 == 0){
        cout<<2<<" ";
    }
    return 0;
}