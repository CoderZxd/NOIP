#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum = 0;
	start:
	for(int i=1;i<=n;i++){
		if(i % 7 != 0){
			int temp = i;
			bool flag = false;
			do{
				if(temp % 10 == 7){
					flag = true;
					break;
				}
				temp /= 10;
			}while(temp != 0);
			if(!flag){
				sum += i*i;		
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
