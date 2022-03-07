#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int arr[101];
long long dp[10001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;

	
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k] << '\n';
	
}

