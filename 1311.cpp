//1311：【例2.5】求逆序对
//
//【题目描述】
//给定一个序列a1,a2,…,an，如果存在i<j并且ai>aj，那么我们称之为逆序对，求逆序对的数目。
//
//【输入】
//第一行为n,表示序列长度，接下来的n行，第i+1行表示序列中的第i个数。
//
//【输出】
//所有逆序对总数。
//
//【输入样例】
//4
//3
//2
//3
//2
//【输出样例】
//3
//【提示】
//N≤10^5，Ai≤10^5。

#include "iostream"
using namespace std;

int num[100000];
//临时数组
int tmp[100000];

//归并排序
long long merge(int l, int r) {
    if (l + 1 == r){
        return 0;
    }
    int m = (l + r) / 2;
    //先分
    long long res = merge(l, m) + merge(m, r);
    //后合
    for (int i = l, j = m, k = l; k < r; k++) {
        //左边数组中的小，直接排
        if (j == r || (i < m && num[i] <= num[j])) {
            tmp[k] = num[i];
            i++;
        } else {
            //否则右边数组中的小，产生逆序对
            tmp[k] = num[j];
            j++;
            //计算逆序对数量
            res += m - i;
        }
    }
    //将排好顺序的数据复制回num数组中
    for (int k = l; k < r; k++){
        num[k] = tmp[k];
    }
    return res;
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    cout << merge(0, n) << endl;
    return 0;
}

//timeout
int main_1(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int nums = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                nums++;
            }
        }
    }
    cout<<nums<<endl;
    return 0;
}