#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int maxX = c/a;
	int i = 0;
	for(int x=0;x<=maxX;x++){
		if((c-a*x)%b == 0){
			i++;
		}
	}
	cout<<i<<endl;
	return 0;
}
