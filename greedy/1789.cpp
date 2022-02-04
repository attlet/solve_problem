#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

int main() {
	long long s;
	long long i = 1;
	long long counter = 0;
	
	cin >> s;
	if (s == 1) {
		cout << 1 << '\n';
		return 0;
	}
	while (s > 0 && s >= i) {
		s -= i;
		i++;
		counter++;
	}
	
	cout << counter << '\n';

}
