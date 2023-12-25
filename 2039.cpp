#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n] = {};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0,j=i+1;i<n-1 && j<n;){
		if(a[i]>a[j]){
			swap(a[i],a[j]);
		}
		i++;
		j++;
		if(j==n){
			cout<<a[n-1]<<endl;
			n--;
			i=0;
			j=i+1;
		}
	}
	cout<<a[0]<<endl;
	return 0;
}
