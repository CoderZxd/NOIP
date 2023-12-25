#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int salary = 0;
	for(int i=1;;i++){
		if(n-i>=0){
			salary += i*i;
		}else{
			salary += n*i;
			break;
		}
		n -=i;
	}
	cout<<salary<<endl;
	return 0;
}
