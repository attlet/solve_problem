#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

int up_dp[1001];
int down_dp[1001];
long long dp[1001];
int A[1001];

int main() {
	int n, Max = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> A[i];


	up_dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		up_dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if(A[i] > A[j])
			    up_dp[i] = max(up_dp[i], up_dp[j] + 1);
		}
	}

	down_dp[n] = 1;

	for (int i = n-1; i >= 1; i--) {
		down_dp[i] = 1;
		for (int j = n; j >= i; j--) {
			if (A[i] > A[j])
				down_dp[i] = max(down_dp[i], down_dp[j] + 1);
		}
	}

	

	for (int i = 1; i <= n; i++) 
		Max = max(Max, up_dp[i] + down_dp[i]);
	
	cout << Max-1 << '\n';




}

