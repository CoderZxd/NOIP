#include <iostream>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	int person[N+1] = {};
	for(int i=1;i<=N;i++){
		person[i] = 1;
	}
	int nums = 0;
	int i = 1;
	int count = 0;
	while(nums != N){
		if(person[i] == 1){
			count++;
			if(count % M == 0 ){
				cout<<i<<" ";
				person[i]= 0;
				nums++;
			}
		}
		i++;
		if(i==N+1){
			i=1;
		}
	}
	return 0;
}
