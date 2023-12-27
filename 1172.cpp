//求10000以内n的阶乘
//
//【题目描述】
//求10000以内n的阶乘。
//
//【输入】
//只有一行输入，整数n（0≤n≤10000）。
//
//【输出】
//一行，即n!的值。
//
//【输入样例】
//4
//【输出样例】
//24

#include <vector>
#include "iostream"
using namespace std;

vector<int> deal(vector<int> vct, int n) {
    int mod = n % 10;
    n = n/10;
    int i = 0;
    vector<int> result(vct.size()+2,0);
    do{
        int carry = 0;
        for(int j=0;j<vct.size();j++){
            result[j+i] = result[j+i] + vct[j] * mod + carry;
            carry = result[j+i] / 10;
            result[j+i] %= 10;
        }
        i++;
        mod = n % 10;
        n = n/10;
    } while (n != 0 || mod != 0);
    return result;
}

int main(){
    int n;
    cin>>n;
    if(n<2){
        cout<<n<<endl;
    }
    vector<int> vec  = {1};
    for(int i=2;i<=n;i++){
        vec = deal(vec, i);
    }
    int end = vec.size()-1;
    while (vec[end]==0){
        end--;
    }
    for(int i=end;i>=0;i--){
        cout<<vec[i];
    }
    cout<<endl;
    return 0;
}