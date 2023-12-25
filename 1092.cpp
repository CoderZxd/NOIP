#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	double e = 1.0;
	double x = 1;
	for(int i=1;i<=n;i++){
		x*=i;
		e += 1.0/x;
	}
	printf("%.10f",e);
	return 0;
}
