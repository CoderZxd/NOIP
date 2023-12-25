#include <iostream>
using namespace std;
int main(){
	double x;
	int n;
	cin >> x>>n;
	double result = 1.0;
	double r = 1.0;
	for(int i=1;i<=n;i++){
		r *= x;
		result += r;
	}
	printf("%.2f",result);
	return 0;
}
