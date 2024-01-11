//1311������2.5���������
//
//����Ŀ������
//����һ������a1,a2,��,an���������i<j����ai>aj����ô���ǳ�֮Ϊ����ԣ�������Ե���Ŀ��
//
//�����롿
//��һ��Ϊn,��ʾ���г��ȣ���������n�У���i+1�б�ʾ�����еĵ�i������
//
//�������
//���������������
//
//������������
//4
//3
//2
//3
//2
//�����������
//3
//����ʾ��
//N��10^5��Ai��10^5��

#include "iostream"
using namespace std;

int num[100000];
//��ʱ����
int tmp[100000];

//�鲢����
long long merge(int l, int r) {
    if (l + 1 == r){
        return 0;
    }
    int m = (l + r) / 2;
    //�ȷ�
    long long res = merge(l, m) + merge(m, r);
    //���
    for (int i = l, j = m, k = l; k < r; k++) {
        //��������е�С��ֱ����
        if (j == r || (i < m && num[i] <= num[j])) {
            tmp[k] = num[i];
            i++;
        } else {
            //�����ұ������е�С�����������
            tmp[k] = num[j];
            j++;
            //�������������
            res += m - i;
        }
    }
    //���ź�˳������ݸ��ƻ�num������
    for (int k = l; k < r; k++){
        num[k] = tmp[k];
    }
    return res;
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    cout << merge(0, n) << endl;
    return 0;
}

//timeout
int main_1(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int nums = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                nums++;
            }
        }
    }
    cout<<nums<<endl;
    return 0;
}