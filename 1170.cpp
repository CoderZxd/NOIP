//1170������2��N�η�
//����Ŀ������
//�������һ��������N(N<=100)������2��n�η���ֵ��
//
//�����롿
//����һ��������N��
//
//�������
//���2��N�η���ֵ��
//
//������������
//5
//�����������
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