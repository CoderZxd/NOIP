#include<iostream>
using namespace std;
int main()
{
    string M,N;
    cin >> M >> N;
    int mLen=M.length(),nLen=N.length();
    int m[100],n[100],result[10001];
    for(int i=0; i < mLen; i++) {
        m[mLen - i]= M[i] - '0';
    }
    for(int i=0; i < nLen; i++) {
        n[nLen - i]= N[i] - '0';
    }
    for(int i=1; i <= mLen; i++){
        int carry=0;
        for(int j=1; j <= nLen; j++){
            result[i + j - 1] = m[i] * n[j] + carry + result[i + j - 1];
            carry = result[i + j - 1] / 10;
            result[i + j - 1] %= 10;
        }
        result[i + nLen] = carry;
    }
    int rLen = mLen + nLen;
    while(result[rLen] == 0 && rLen > 1) {
        rLen--;
    }
    for(int i = rLen; i >= 1; i--) {
        cout << result[i];
    }
    return 0;
}