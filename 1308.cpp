#include <iostream>
using namespace std;
string M,N;
int a[301];//������
int b[301];//����
int c[301];//��

//�����������λ����xλ���Ƿ���ڵ��ڳ���
bool compare(int x){
    //����������ȳ�����һλ������true
    if(a[x+b[0]]>0) {
        return true;
    }
    for(int i=b[0];i>=1;i--){
        //������
        if (a[x+i-1]<b[i]){
            return false;
        }else if (a[x+i-1]>b[i]){
            //��������
            return true;
        }
    }
    return true;
}

int main(){
    //���뱻�����ͳ���
    cin >> M >> N;
    //����ĵ�һ��Ԫ�ش洢�������ͳ����ĳ���
    a[0]=M.length(),b[0]=N.length();
    //���潫M����ת��������λ�ŵ�����ĵ�λ����λ�ŵ�����ĸ�λ��������forѭ������
    for (int i=0; i < M.length(); i++){
        a[a[0]-i]= M[i] - '0';
    }
    //ͬ��
    for (int i=0; i < N.length(); i++){
        b[b[0]-i]= N[i] - '0';
    }
    //�ӱ���������-�������ȵ�λ�ü��㱻�����Ƿ���ڵ��ڳ���
    for(int i=a[0]-b[0]+1;i>=1;i--){
        //����
        while(compare(i)){
            //�̼�1
            c[i]++;
            //��λ���
            for(int j=1;j<=b[0];j++){
                //����
                if (a[i+j-1]>=b[j]){
                    //ֱ�Ӽ�
                    a[i+j-1]-=b[j];
                }else{//������
                    //��λ
                    a[i+j]--;
                    //��10�ټ�
                    a[i+j-1]+=10-b[j];
                }
            }
        }
    }
    //������ǰ����
    bool flag=1;
    //�����Ϊ0
    bool y=0;
    //�����ӡ��
    for (int i=a[0];i>=1;i--){
        //�������ǰ������ߵ�ǰλ����0
        if (flag==0||c[i]>0){
            //�����ǰλ
            cout<<c[i];
            //û��ǰ������
            flag=0;
            //�𰸲�Ϊ0
            y=1;
        }
    }
    //�����0�����0
    if(y==0) cout<<0;
    cout<<endl;
    //������ǰ����
    flag=1;
    //�����Ϊ0
    y=0;
    //�����ӡ����
    for (int i=a[0];i>=1;i--){
        //�������ǰ������ߵ�ǰλ����0
        if (flag==0||a[i]>0){
            //�����ǰλ
            cout<<a[i];
            //û��ǰ������
            flag=0;
            //�𰸲�Ϊ0
            y=1;
        }
    }
    //�����0�����0
    if (y==0) cout<<0;
    return 0;
}