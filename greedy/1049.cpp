#include<iostream>
#include<vector>

using namespace std;

int n, m;
int Min_six = 1001, Min_one = 1001, Min_price = 9876543;

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (Min_six > a) Min_six = a;
		if (Min_one > b)Min_one = b;
	}

	for (int i = 0; i <= n / 6 + 1; i++) {
		int remain, price;
		if (i == n / 6 + 1) remain = 0;
		else remain = n - (6 * i);

		price = Min_six * i + Min_one * remain;

		if (Min_price > price) Min_price = price;
	}

	cout << Min_price << '\n';
	

}
