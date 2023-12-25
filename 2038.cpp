#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n] = {};
	int max=0;
	int p=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>max){
			max = a[i];
			p = i;
		}
	}
	cout<<p+1<<endl;
	return 0;
}
