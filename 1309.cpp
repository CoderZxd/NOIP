//����Ŀ������
//��һ��������λ��Ϊ�㣩�������Ҷ���������������һ�������Ǿͽ����֮Ϊ�����������磺����һ�� 10������ 56���� 56�� 65������56��������������õ� 121��һ�������������磬����10������87��
//STEP1�� 87��78= 165 STEP2�� 165��561= 726
//STEP3�� 726��627��1353 STEP4��1353+3531=4884
//�������һ����ָ������һ��N���Ƶļӷ���������������4���õ�������4884��
//дһ�����򣬸���һ��N��2��N����10��N=16�������� M�������پ����������Եõ��������������30�����ڣ�����30���������ܵõ����������������Impossible�� ��
//�����롿
//��1�У�����һ��N��2��N��10��N=16����ʾ���ƣ�
//��2�У�һ��N������M��
//�������
//���ټ����������30�����ڣ�����30���������ܵõ����������������Impossible����
//������������
//9
//87
//�����������
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