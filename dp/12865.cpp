#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

long long dp[101][100001];
int w[101];
int v[101];

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];

			else
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
		}
	}

	cout << dp[n][k] << '\n';
}

