#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x = sqrt(n);
	for(int i=x;i>=1;i--){
		if(n%i==0){
			bool flag = false;
			int y = sqrt(i);
			for(int j=y;j>1;j--){
				if(i%j==0){
					flag = true;
					break;
				}
			}
			if(!flag){
				int z = n/i;
				int m = sqrt(z);
				for(int j=m;j>1;j--){
					if(z%j==0){
						flag = true;
						break;
					}
				}
				if(!flag){
					if(i>z){
						cout<<i<<endl;
					}else{
						cout<<z<<endl;
					}
				}
			}
		}
	}
	return 0;
}
