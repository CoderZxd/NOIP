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
    int N;
    string M;
    cin >> N >> M;
    int step = 0;
    string result;
    for(;step < 30;step++){
        bool isPalindromicWord = true;
        int len = M.length();
        for(int i=0,j= len - 1; i <= j; i++,j--){
            if(M[i] != M[j]){
                isPalindromicWord = false;
                break;
            }
        }
        if(isPalindromicWord){
            cout << step << endl;
            break;
        }
        int carry = 0;
        result = "";
        for (int i = len - 1,j=0; i >= 0 && j<= len -1; i--,j++) {
            int sum = 0;
            if(N > 10){
                sum = carry + (M[i] - '0') + (M[j] - '0');
                int remain = sum % N;
                if(remain >=10){
                    result += (remain -10 + 'A');
                }
            }else{
                sum = carry + (M[i] - '0') + (M[j] - '0');
                result += (sum % N + '0');
            }
            carry = sum / N;
        }
        if(carry > 0){
            result += (carry + '0');
        }
        M = result;
    }
    if(step >=30){
        cout<<"Impossible"<<endl;
    }
    return 0;
}