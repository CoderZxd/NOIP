#include <iostream>
using namespace std;
int main(){
	int L,R;
	cin>>L>>R;
	int nums = 0,temp;
	for(int i=L;i<=R;i++){
		temp = i;
		do{
			if(temp % 10 == 2){
				nums++;
			}
			temp /= 10;
		}while(temp!=0);
	}
	cout<<nums<<endl;
	return 0;
}
