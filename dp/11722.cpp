#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

int dp[1001];

int main() {
	
	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] > A[i]) 
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int Max = dp[0];

	for (int i = 1; i < n; i++)
		Max = max(Max, dp[i]);

	cout << Max << '\n';
}

