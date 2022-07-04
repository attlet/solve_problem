#include<iostream>
#include<math.h>
using namespace std;

int t;

int main() {
	cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		int smallR, bigR, ret;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	
		int add = pow(r1 + r2, 2);
		int sub = pow(r1 - r2, 2);
		int distance = pow((x2 - x1), 2) + pow((y2 - y1), 2);
		if (distance == 0 && sub == 0) {
			cout << -1 << '\n';
			continue;
		}
		if (distance == add || distance == sub) {
			ret = 1;
		}
		else if (distance < add && distance > sub) {
			ret = 2;
		}
		else {
			ret = 0;
		}
		cout << ret << '\n';
	}
}
