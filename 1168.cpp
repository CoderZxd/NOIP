#include<string>
#include<iostream>
using namespace std;
int main(){
	//1.声明两个字符串变量a和b，存储输入的两行非负整数 
    string a, b;
    //2.从标准输入设备接收a和b 
    cin >> a >> b;
    //3.计算a和b的长度 
    int aLen = a.length(), bLen = b.length();
   //4.计算a和b的最大长度 
    int maxLen = aLen > bLen ? aLen : bLen;
    //5.如果a和b没有达到最大长度,高位补零处理，为了方便后继逻辑处理简单化 
    while (a.length() != maxLen){
        a = "0" + a;
    }
    while (b.length() != maxLen){
        b = "0" + b;
    }
    //6.a和b每一位相加时的进位 
    int carry = 0;
    //7.用字符串保存a和b相加的结果 
    string result = "";
    //8.从a和b的字符串最后一位开始循环相加，直到字符串开始的位置（也就是从个位向高位计算加法） 
    for (int i = maxLen - 1; i >= 0; i--) {
    	//9.a[i] - '0'代表字符串a第i位的数字字符减去'0'字符，结果就是数字字符转为对应的数字整型，例如将'9'转换为9 ，同理 b[i] - '0'
    	//将a[i]和b[i]位相加，并加上上一位carry进位，跟10取余，即当前位计算结果 
        result += ((carry + (a[i] - '0') + (b[i] - '0')) % 10 + '0');
        //10.当前a[i]和b[i],加上上一位carry进位，除以10，就可以得到下一位计算的进位carry 
        carry = (carry + (a[i] - '0') + (b[i] - '0')) / 10;
    }
    //11.最后循环结束后，最后以为高位相加，也可能会有进位，此时结果的长度会大于maxLen。
	//如果有进位，需要将carry再加到结果字符串的最高位 
    result += (carry + '0');
    //12.最后的结果result因为在步骤5时进行了高位补0操作，所以result高位可能存在多个0，所以要从最高位向低位开始找第一个不是0的位置，之后的字符串才是最终结果 
    //定义变量k，记录从最高位向低位第一个不是0的位置 
    int k;
    //13. result的最右面代表结果的最高位，所以要从字符串结尾向起始位进行循环判断 
    for (k = result.length() - 1; k >= 0; k--){
        if (result[k] != '0'){
            break;
        }
    }
    //14.如果结果全部为0，则直接输出0 
    if (k==-1){
        cout << "0";
    }else{
    	//15.否则，就从第k位开始，将字符串从右向左进行循环输出，即将结果从高位向低位循环输出 
        for (int i = k; i >= 0; i--){
            cout << result[i];
        }
    }
}
