//1170：计算2的N次方
//【题目描述】
//任意给定一个正整数N(N<=100)，计算2的n次方的值。
//
//【输入】
//输入一个正整数N。
//
//【输出】
//输出2的N次方的值。
//
//【输入样例】
//5
//【输出样例】
//32

#include <iostream>
using namespace std;

int main(){
    int N=0;
    cin >> N;
    int a[105]={1};
    int len = 1;
    for(int i=1;i<=N;i++){
        int carry = 0;
        for(int j=0;j<len;j++){
            int value = a[j]*2+carry;
            a[j] = value % 10;
            carry = value / 10;
            if(carry > 0 && a[j+1] == 0){
                len++;
            }
        }
    }
    int size = sizeof(a)/sizeof(&a);
    while(a[size-1] == 0 && size>0) {
        size--;
    }
    for(int i= size-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}