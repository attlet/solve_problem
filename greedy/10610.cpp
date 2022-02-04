#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

int main() {
	string s;
    int sum = 0;

	cin >> s;

	sort (s.begin(), s.end(), greater<>());

	for (int i = 0; i < s.length(); i++) 
		sum = sum + (s[i] - '0');
	

	if (s.back() == '0' && (sum % 3) == 0) {
		cout << s << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}
