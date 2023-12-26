//【题目描述】 大整数的因子
//已知正整数k满足2≤k≤9，现给出长度最大为30位的十进制非负整数c，求所有能整除c 的k。
//
//【输入】
//一个非负整数c，c的位数≤30。
//
//【输出】
//若存在满足 c%k == 0 的k，从小到大输出所有这样的k，相邻两个数之间用单个空格隔开；若没有这样的k，则输出"none"。
//
//【输入样例】
//30
//【输出样例】
//2 3 5 6

#include <iostream>
using namespace std;

int main(){
    string c;
    cin>>c;
    int len = c.length();
    //将c转换成数组，数组每一位存储的是c各个数值位的数，比如123456，拆解成[1,2,3,4,5,6]
    int a[len];
    for(int i=0; i<len; i++) {
        a[i]= c[i] - '0';
    }
    //存储结果，如果能被2整除，就设置result[2]=1,方便最后输出
    int result[10]={};
    //是否需要打印none
    bool none = true;
    //判断是否能够被9-2整除
    /*
     * 如果想要让程序减少不必要的处理逻辑，可以加入以下逻辑:
     * 1.如果能被9整除，那么就能被3整除，即判断3是否能够被整除的逻辑可以省略，下同;
     * 2.如果能被8整除，那么就能被4和2整除;
     * 3.如果能被6整除，那么就能被3和2整除;
     * 4.如果能被4整除，那么就能被2整除.
     * */
    for(int k=9;k>=2;k--){
        /*****如果当前位已经通过之前判断设置了结果，则跳过*****/
        if(result[k] == 1){
            continue;
        }
        /**********************************************/
        //从高位向低位，模拟进行除法运算。
        //因为我们只需要判断是否能够除尽，所以只保留每次余数即可。
        int remain = 0;
        for(int i=0;i<len;i++){
            remain = (remain*10 + a[i]) % k;
        }
        //如果最后余数为0，则说明能够被k除尽
        if(remain == 0){
            result[k]=1;
            /**********根据当前结果设置可以得到的其它结果**********/
            if(k==9){
                result[3]=1;
            }else if(k==8){
                result[4]=1;
                result[2]=1;
            }else if(k==6){
                result[3]=1;
                result[2]=1;
            }else if(k==4){
                result[2]=1;
            }
            /**********************************************/
            //如果可以除尽K,则不需要打印none
            none = false;
        }
    }
    //如果2~9都不可以除尽，打印none
    if(none){
        cout<<"none"<<endl;
        return 0;
    }
    //否则就根据result指定位是否为1，打印输出结果
    for(int i=0;i<10;i++){
        if(result[i] == 1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}