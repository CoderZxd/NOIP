//1186：出现次数超过一半的数
//
//【题目描述】
//给出一个含有n（0 < n <= 1000）个整数的数组，请找出其中出现次数超过一半的数。数组中的数大于-50且小于50。
//
//【输入】
//第一行包含一个整数n，表示数组大小；
//
//第二行包含n个整数，分别是数组中的每个元素，相邻两个元素之间用单个空格隔开。
//
//【输出】
//如果存在这样的数，输出这个数；否则输出no。
//
//【输入样例】
//3
//1 2 2
//【输出样例】
//2

#include "iostream"
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100] = {};
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        a[temp+50]++;
        if(a[temp+50]>n/2){
            cout<<temp<<endl;
            goto skip;
        }
    }
    cout<<"no"<<endl;
    skip:
    return 0;
}