#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int xy[n][2] = {};
	for (int i = 0; i < n;i++) {
		cin >> xy[i][0] >> xy[i][1];
	}
	float x = xy[0][1] * 1.0 / xy[0][0];
	for (int i = 1; i < n;i++) {
		float y = xy[i][1] * 1.0 / xy[i][0];
		if (fabs(x-y)<=0.05) {
			cout << "same" << endl;
		}
		else if (y-x>0.05) {
			cout << "better" << endl;
		}
		else if(x-y>0.05) {
			cout << "worse" << endl;
		}
	}
	return 0;
}
