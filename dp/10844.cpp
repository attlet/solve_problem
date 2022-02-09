#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<cmath>

using namespace std;
long long dp[101][10];

int main() {
	int n;
	cin >> n;

	dp[1][0] = 0;

	for (int i = 1; i < 10; i++) 
		dp[1][i] = 1;
	

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];

		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) %1000000000 ;
		}
	}
	long long ret = 0;
	for (int i = 0; i < 10; i++) {
		ret += dp[n][i];
	}
	cout << ret % 1000000000 << '\n';

 
}
