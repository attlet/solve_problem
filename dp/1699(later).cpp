#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

long long dp[100001];

int main() {
	
	int n, standard = 1;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 2; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';

}

