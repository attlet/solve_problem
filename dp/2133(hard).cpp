#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

long long dp[31];


int main() {
	int n;
	cin >> n;

	dp[1] = 0;
	dp[2] = 3;

	if (n % 2 == 0) {
		for (int i = 4; i <= n; i += 2) {
			dp[i] += 2;
			dp[i] += dp[i - 2] * 3;
			for (int j = 4; j < i; j += 2) {
				dp[i] += dp[i - j] * 2;
			}
	    }
	}
	cout << dp[n] << '\n';
}

