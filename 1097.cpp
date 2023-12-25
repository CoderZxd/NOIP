#include <iostream>
using namespace std;
int main(){
	int h,w,r;
	char c;
	cin>>h>>w>>c>>r;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(r==0 &&i != 0 && i!= h-1 && j != 0 && j !=w-1){
				cout<<" ";
				continue;
			}
			cout<<c;
		}
		cout<<endl;
	}
	return 0;
}
