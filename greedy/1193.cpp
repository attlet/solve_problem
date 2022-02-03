#include<iostream>

using namespace std;

int main() {
	int x,i;
	int add = 2;
	int line = 2;
	cin >> x;

	if (x == 1) {
		cout << 1 << '/' << 1 << endl;
		return 0;
	}
	else {
		for (i = 3; ; i += add) {
			if (i >= x) {
				break;
			}
			line += 1;
			add += 1;
		}

		if (line % 2 == 0) {
			cout << line -  (i - x) << '/' << 1 + (i - x) << endl;
		}
		else {
			cout << 1 + (i - x) << '/' << line - (i - x) << endl;
		}
		return 0;
	}
}
