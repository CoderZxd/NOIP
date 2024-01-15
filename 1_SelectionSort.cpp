//
// Created by Administrator on 15/01/2024.
//
// 选择排序（英语：Selection sort）是一种简单直观的排序算法。
// 它的工作原理是每次找出第 i 小的元素（也就是 A{i..n} 中最小的元素），然后将这个元素与数组第 i 个位置上的元素交换。
//稳定性
//由于 swap（交换两个元素）操作的存在，选择排序是一种不稳定的排序算法。
//
//时间复杂度
//选择排序的最优时间复杂度、平均时间复杂度和最坏时间复杂度均为 O(n^2)。
//排序效果图:
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
        std::swap(a[i],a[min]);
    }
}

int main(){
    int a[10] = {8,2,6,3,10,9,4,1,7,5};
    selection_sort(a,10);
    return 0;
}