//
// Created by Administrator on 18/01/2024.
//
//定义
//        插入排序（英语：Insertion sort）是一种简单直观的排序算法。它的工作原理为将待排列元素划分为「已排序」和「未排序」两部分，每次从「未排序的」元素中选择一个插入到「已排序的」元素中的正确位置。
//
//一个与插入排序相同的操作是打扑克牌时，从牌桌上抓一张牌，按牌面大小插到手牌后，再抓下一张牌。
//
//实现逻辑
//1.从第一个元素开始，将其视为已排序部分。
//2.取出下一个元素，从后向前扫描已排序部分，找到插入位置。
//3.如果当前元素大于被比较元素，则将被比较元素向后移动一位。
//4.重复步骤3，直到找到插入位置。
//5.将当前元素插入到插入位置后。
//6.重复步骤2~5，直到所有元素都插入到已排序部分。
//
//性质
//        稳定性
//插入排序是一种稳定的排序算法。
//
//时间复杂度
//        插入排序的最优时间复杂度为 O(n)，在数列几乎有序时效率很高。
//
//插入排序的最坏时间复杂度和平均时间复杂度都为 O(n^2)。

#include "iostream"
using namespace std;

void insertionSort(int* a,int n){
    for(int i = 1; i < n; i++){
        int current = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > current){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current;
    }
}

//折半插入排序
//        因为当前元素之前的所有元素是已排序的，所以可以通过折半查找找到插入点优化性能，在排序元素数量较多时优化的效果比较明显。
//
//时间复杂度
//        折半插入排序与直接插入排序的基本思想是一致的，折半插入排序仅对插入排序时间复杂度中的常数进行了优化，所以优化后的时间复杂度仍然不变。
void insertionSortOptimize(int* a,int n){
    for(int i = 1; i < n; i++){
        int current = a[i];
        int left = 0;
        int right = i -1;
        while(left <= right){
            int middle = (right+left)/2;
            if(a[middle] > current){
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }
        for(int j = i-1; j >= left; j--){
            a[j+1] = a[j];
        }
        a[left] = current;
    }
}

int main(){
    int a[9] = {8,2,6,3,9,4,1,7,5};
//    insertionSort(a,9);
    insertionSortOptimize(a,9);
    return 0;
}