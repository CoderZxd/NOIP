#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	float roof[n][3]={};
	float times = 0;
	for(int i=0;i<n;i++){
		cin>>roof[i][0]>>roof[i][1]>>roof[i][2];
		float distance = sqrt(roof[i][0]*roof[i][0]+roof[i][1]*roof[i][1]);
		times += distance/50*2;
		times += roof[i][2]*(1.0+0.5);
	}
	cout<<ceil(times)<<endl;
	return 0;
} 
