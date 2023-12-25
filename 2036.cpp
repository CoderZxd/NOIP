#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int door[n+1] = {};
	for(int i=1;i<=n;i++){
		door[i] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j=j+i){
			door[j]=1-door[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(door[i]==1){
			cout<<i<<" ";
		}
	}
	return 0;
}
