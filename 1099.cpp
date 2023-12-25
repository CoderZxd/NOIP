#include <iostream>
using namespace std;

bool pd(int n){
	if(n<2){
		return false;
	}
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	int i=2;
	while(n-1>0){
		i++;
		if(pd(i)){
			n--;
		}
	}
	cout<<i<<endl;
	return 0;
}
