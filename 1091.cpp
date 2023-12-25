#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum=0;
	int s=1;
	for(int i=1;i<=n;i++){
		s *= i;
		sum += s;
	}
	cout<<sum<<endl;
	return 0;
}
