#include<string>
#include<iostream>
using namespace std;
int main(){
	//1.声明两个字符串变量a和b，存储输入的两行非负整数 
    string a, b;
    //2.从标准输入设备接收a和b 
    cin >> a >> b;
    int aLen = a.length();
    //如果b没有a长，b前导补0,方便后继代码处理逻辑 
    while (b.length() != aLen){
        b = "0" + b;
    }
    //减法是否有借位 
    int carry = 0;
    //存储结果 
    string result = "";
    //从低位向高位循环执行减法操作 
    for (int i = aLen - 1; i >= 0; i--) {
    	//如果够减，则不需要借位 
    	if((a[i] - '0') - (b[i] - '0') - carry >= 0){
			result += (((a[i] - '0') - (b[i] - '0') - carry ) % 10 + '0');
			carry = 0;
		}else{
			//如果不够减，则需要借位 
			result += (((a[i] - '0') + 10 - (b[i] - '0') - carry ) % 10 + '0');
			carry = 1;
		}
    }
    //找到剩余的前导0的位置 
    int k;
    for (k = result.length() - 1; k >= 0; k--){
        if (result[k] != '0'){
            break;
        }
    }
    //输出结果 
    if (k==-1){
        cout << "0";
    }else{
        for (int i = k; i >= 0; i--){
            cout << result[i];
        }
    }
}
