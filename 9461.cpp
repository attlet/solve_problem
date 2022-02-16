#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long dp[101];

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		dp[1] = dp[2] = dp[3] = 1;
		dp[4] = dp[5] = 2;

		for (int i = 6; i <= n; i++) {
			dp[i] = dp[i - 5] + dp[i - 1];
		}

		cout << dp[n] << '\n';
	}
}
