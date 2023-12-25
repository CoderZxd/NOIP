#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n] = {};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int head = a[0];
	for(int i=1;i<n;i++){
		a[i-1]=a[i];
		cout<<a[i]<<" ";
	}
	a[n-1]=head;
	cout<<head<<endl;
	return 0;
} 
