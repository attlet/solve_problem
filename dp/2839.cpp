#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

int main() {
	int n, ret = 0; 
	cin >> n;

	while (n >= 0) {
		if (n % 5 == 0) {
			ret += n / 5;
			cout << ret << '\n';
			return 0;
		}
		n -= 3;
		ret++;
	}
	cout << -1 << '\n';

}
