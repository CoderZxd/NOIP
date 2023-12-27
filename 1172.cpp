//��10000����n�Ľ׳�
//
//����Ŀ������
//��10000����n�Ľ׳ˡ�
//
//�����롿
//ֻ��һ�����룬����n��0��n��10000����
//
//�������
//һ�У���n!��ֵ��
//
//������������
//4
//�����������
//24

#include <vector>
#include "iostream"
using namespace std;

vector<int> deal(vector<int> vct, int n) {
    int mod = n % 10;
    n = n/10;
    int i = 0;
    vector<int> result(vct.size()+2,0);
    do{
        int carry = 0;
        for(int j=0;j<vct.size();j++){
            result[j+i] = result[j+i] + vct[j] * mod + carry;
            carry = result[j+i] / 10;
            result[j+i] %= 10;
        }
        i++;
        mod = n % 10;
        n = n/10;
    } while (n != 0 || mod != 0);
    return result;
}

int main(){
    int n;
    cin>>n;
    if(n<2){
        cout<<n<<endl;
    }
    vector<int> vec  = {1};
    for(int i=2;i<=n;i++){
        vec = deal(vec, i);
    }
    int end = vec.size()-1;
    while (vec[end]==0){
        end--;
    }
    for(int i=end;i>=0;i--){
        cout<<vec[i];
    }
    cout<<endl;
    return 0;
}