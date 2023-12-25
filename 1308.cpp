#include <iostream>
using namespace std;
string M,N;
int a[301];//被除数
int b[301];//除数
int c[301];//商

//被除数从最高位到第x位，是否大于等于除数
bool compare(int x){
    //如果被除数比除数多一位，返回true
    if(a[x+b[0]]>0) {
        return true;
    }
    for(int i=b[0];i>=1;i--){
        //除数大
        if (a[x+i-1]<b[i]){
            return false;
        }else if (a[x+i-1]>b[i]){
            //被除数大
            return true;
        }
    }
    return true;
}

int main(){
    //输入被除数和除数
    cin >> M >> N;
    //数组的第一个元素存储被除数和除数的长度
    a[0]=M.length(),b[0]=N.length();
    //下面将M做反转处理，将低位放到数组的低位，高位放到数组的高位，方便后继for循环处理
    for (int i=0; i < M.length(); i++){
        a[a[0]-i]= M[i] - '0';
    }
    //同上
    for (int i=0; i < N.length(); i++){
        b[b[0]-i]= N[i] - '0';
    }
    //从被除数长度-除数长度的位置计算被除数是否大于等于除数
    for(int i=a[0]-b[0]+1;i>=1;i--){
        //够减
        while(compare(i)){
            //商加1
            c[i]++;
            //逐位相减
            for(int j=1;j<=b[0];j++){
                //够减
                if (a[i+j-1]>=b[j]){
                    //直接减
                    a[i+j-1]-=b[j];
                }else{//不够减
                    //借位
                    a[i+j]--;
                    //加10再减
                    a[i+j-1]+=10-b[j];
                }
            }
        }
    }
    //假设有前导零
    bool flag=1;
    //假设答案为0
    bool y=0;
    //逆序打印商
    for (int i=a[0];i>=1;i--){
        //如果不是前导零或者当前位大于0
        if (flag==0||c[i]>0){
            //输出当前位
            cout<<c[i];
            //没有前导零了
            flag=0;
            //答案不为0
            y=1;
        }
    }
    //如果是0，输出0
    if(y==0) cout<<0;
    cout<<endl;
    //假设有前导零
    flag=1;
    //假设答案为0
    y=0;
    //逆序打印余数
    for (int i=a[0];i>=1;i--){
        //如果不是前导零或者当前位大于0
        if (flag==0||a[i]>0){
            //输出当前位
            cout<<a[i];
            //没有前导零了
            flag=0;
            //答案不为0
            y=1;
        }
    }
    //如果是0，输出0
    if (y==0) cout<<0;
    return 0;
}