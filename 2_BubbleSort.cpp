//
// Created by Administrator on 15/01/2024.
//
//定义
//        冒泡排序（英语：Bubble sort）是一种简单的排序算法。由于在算法的执行过程中，较小的元素像是气泡般慢慢「浮」到数列的顶端，故叫做冒泡排序。
//
//过程
//        它的工作原理是每次检查相邻两个元素，如果前面的元素与后面的元素满足给定的排序条件，就将相邻两个元素交换。当没有相邻的元素需要交换时，排序就完成了。
//
//经过 i 次扫描后，数列的末尾 i 项必然是最大的 i 项，因此冒泡排序最多需要扫描 n-1 遍数组就能完成排序。
//
//性质
//稳定性
//      冒泡排序是一种稳定的排序算法。
//
//时间复杂度
//       在序列完全有序时，冒泡排序只需遍历一遍数组，不用执行任何交换操作，时间复杂度为 O(n)。
//
//在最坏情况下，冒泡排序要执行
//
//(n-1)*n/2次交换操作，时间复杂度为 O(n^2)。
//
//冒泡排序的平均时间复杂度为 O(n^2)。

#include "iostream"
using namespace std;


void bubble_sort(int* a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                std::swap(a[j],a[j+1]);
            }
        }
    }
}

//如果在一次遍历过程中没有发生过交换，那么意味着序列已经是有序的，不需要继续排序。
//可以通过设置一个标记来优化算法。如果在某次遍历中没有发生交换，则直接结束排序。
void bubble_sort_optimize(int* a,int n){
    bool flag = true;
    //对于已排序的位置，减少不必要的交换次数
    int j=0;
    while (flag){
        j++;
        flag = false;
        for(int i=0;i<n-j;i++){
            if(a[i]>a[i+1]){
                flag = true;
                std::swap(a[i],a[i+1]);
            }
        }
    }
}

int main(){
    int a[10] = {8,2,6,3,10,9,4,1,7,5};
//    bubble_sort(a,10);
    bubble_sort_optimize(a,10);
    return 0;
}