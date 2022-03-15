#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long dp[16];

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n+1);

	for (int i = 1; i <= n; i++) 
		cin >> v[i].first >> v[i].second;
    
	for (int i = n; i > 0; i--) {
		if (v[i].first + i > n + 1) dp[i] = dp[i + 1];
		else {
			dp[i] = max(dp[i + 1], v[i].second + dp[v[i].first + i]);
		}
	}

	cout << dp[1] << '\n';
}

//거꾸로 생각하기
