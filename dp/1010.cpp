#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main() {

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		long long dp[31][31] = { 0, };

		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1) 
					dp[i][j] = j;
				else if (i == j) 
					dp[i][j] = 1;
				else 
					dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			
			}
		}

		cout << dp[n][m] << '\n';
	}

}

