#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int nums = 0,temp;
	for(int i=1;i<=n;i++){
		temp = i;
		do{
			if(temp % 10 == 1){
				nums++;
			}
			temp /= 10;
		}while(temp!=0);
	}
	cout<<nums<<endl;
	return 0;
}
