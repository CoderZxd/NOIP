//
// Created by Administrator on 15/01/2024.
//
// ѡ������Ӣ�Selection sort����һ�ּ�ֱ�۵������㷨��
// ���Ĺ���ԭ����ÿ���ҳ��� i С��Ԫ�أ�Ҳ���� A{i..n} ����С��Ԫ�أ���Ȼ�����Ԫ��������� i ��λ���ϵ�Ԫ�ؽ�����
//�ȶ���
//���� swap����������Ԫ�أ������Ĵ��ڣ�ѡ��������һ�ֲ��ȶ��������㷨��
//
//ʱ�临�Ӷ�
//ѡ�����������ʱ�临�Ӷȡ�ƽ��ʱ�临�ӶȺ��ʱ�临�ӶȾ�Ϊ O(n^2)��
//����Ч��ͼ:
// https://oi-wiki.org/basic/images/selection-sort-animate.svg

#include "iostream"
using namespace std;

void selection_sort(int* a,int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }
        }
        /******************************����̨����߼�--��ʼ*******************************/
        for(int j=0;j<n;j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
        for(int j=0;j<n;j++){
            if(i == min && j==i){
                cout<<"|";
            }else{
                if(j==i){
                    cout<<"|-";
                }
                if(j==min){
                    cout<<"|";
                }
            }
            if(j<i){
                cout<<"  ";
            }
            if(j>i && j<min){
                cout<<"--";
            }
        }
        cout<<endl;
        cout<<endl;
        /******************************����̨����߼�--����*******************************/
        std::swap(a[i],a[min]);
    }
}

int main(){
    int a[9] = {8,2,6,3,9,4,1,7,5};
    selection_sort(a,9);
    return 0;
}