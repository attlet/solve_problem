#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

long long dp[1001][10];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) 
		dp[1][i] = 1;
	
	for (int i = 0; i <= n; i++) 
		dp[i][0] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			for (int z = 1; z <= i; z++) {
				dp[i][j] += dp[z][j - 1];
			}
			dp[i][j] = dp[i][j] % 10007;
		}
	}

	long long ret = 0;
	for (int i = 0; i < 10; i++)
		ret += dp[n][i];

	cout << ret % 10007 << '\n';
}

