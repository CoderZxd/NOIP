//【题目描述】
//若一个数（首位不为零）从左向右读与从右向左读都是一样，我们就将其称之为回文数。例如：给定一个 10进制数 56，将 56加 65（即把56从右向左读），得到 121是一个回文数。又如，对于10进制数87，
//STEP1： 87＋78= 165 STEP2： 165＋561= 726
//STEP3： 726＋627＝1353 STEP4：1353+3531=4884
//在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。
//写一个程序，给定一个N（2＜N＜＝10或N=16）进制数 M．求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible” 。
//【输入】
//第1行，给定一个N（2＜N≤10或N=16）表示进制；
//第2行，一个N进制数M。
//【输出】
//最少几步。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible”。
//【输入样例】
//9
//87
//【输出样例】
//6

#include<iostream>
using namespace std;

int main(){
    //用int类型存储M的进制
    int N;
    //用string类型存储M
    string M;
    cin >> N >> M;
    //记录结果步数
    int step = 0;
    //用字符串记录两个数相加的和
    string result;
    //如果步数<30，就继续进行相加和判断
    for(;step < 30;step++){
        //记录当前数字是不是回文数
        bool isPalindromicWord = true;
        int len = M.length();
        //判断M是不是回文数
        for(int i=0,j= len - 1; i <= j; i++,j--){
            if(M[i] != M[j]){
                isPalindromicWord = false;
                break;
            }
        }
        //如果是，输出step，结束循环
        if(isPalindromicWord){
            cout << step << endl;
            break;
        }
        //如果不是，则需要将M进行倒置后，相加
        //保存进位
        int carry = 0;
        //将result重置
        result = "";
        //将M进行倒置相加
        for (int i = len - 1,j=0; i >= 0 && j<= len -1; i--,j++) {
            //因为可能是16进制，所以需要处理一下16进制加法的逻辑，超过10，需要转换成对应的16进制字母,比如10应该是A，15应该是F;
            //小于等于10进制，没有特殊字母，所以不需要特殊处理
            int iValue = (M[i] - '0')>10 ? (M[i] - 'A'+10):(M[i] - '0');
            int jValue = (M[j] - '0')>10 ? (M[j] - 'A'+10):(M[j] - '0');
            int sum = carry + iValue + jValue;
            //余数
            int remain = sum % N;
            //如果是10进制以上，说明可能出现字母的情况，需要处理一下result在拼接时的逻辑；
            //否则不需要特殊处理
            if(N > 10){
                //如果余数超过10，将余数转换成对应的字母
                if(remain >=10){
                    result += (remain -10 + 'A');
                }else{
                    result += (remain + '0');
                }
            }else{
                result += (sum % N + '0');
            }
            carry = sum / N;
        }
        //如果有进位，这需要继续将进位加到结果result中，得到最后的和
        if(carry > 0){
            result += (carry + '0');
        }
        //将result赋值给M，继续下一次for循环处理
        M = result;
    }
    //如果step>=超过30了,输出Impossible
    if(step >=30){
        cout<<"Impossible"<<endl;
    }
    return 0;
}