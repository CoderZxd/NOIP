#include<string>
#include<iostream>
using namespace std;
int main(){
	//1.���������ַ�������a��b���洢��������зǸ����� 
    string a, b;
    //2.�ӱ�׼�����豸����a��b 
    cin >> a >> b;
    int aLen = a.length();
    //���bû��a����bǰ����0,�����̴��봦���߼� 
    while (b.length() != aLen){
        b = "0" + b;
    }
    //�����Ƿ��н�λ 
    int carry = 0;
    //�洢��� 
    string result = "";
    //�ӵ�λ���λѭ��ִ�м������� 
    for (int i = aLen - 1; i >= 0; i--) {
    	//�������������Ҫ��λ 
    	if((a[i] - '0') - (b[i] - '0') - carry >= 0){
			result += (((a[i] - '0') - (b[i] - '0') - carry ) % 10 + '0');
			carry = 0;
		}else{
			//���������������Ҫ��λ 
			result += (((a[i] - '0') + 10 - (b[i] - '0') - carry ) % 10 + '0');
			carry = 1;
		}
    }
    //�ҵ�ʣ���ǰ��0��λ�� 
    int k;
    for (k = result.length() - 1; k >= 0; k--){
        if (result[k] != '0'){
            break;
        }
    }
    //������ 
    if (k==-1){
        cout << "0";
    }else{
        for (int i = k; i >= 0; i--){
            cout << result[i];
        }
    }
}
