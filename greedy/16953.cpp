#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int a, b, counter = 0;

	cin >> a >> b;

	while (a < b) {
		if (b % 2 == 0) {
			b /= 2;
		}
		else if (b % 10 == 1) {
			b /= 10;
		}
		else {
			break;
		}

		counter++;
	}

	if (a == b)
		cout << counter + 1 << '\n';
	else
		cout << -1 << '\n';
}
