#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
int A[1001];
int dp[1001];
int Maxi = 0;

int main() {
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
		cin >> A[i];

	

	for (int i = 0; i < n; i++) {
		dp[i] = A[i];
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j] + A[i]);
			}
		}
		Maxi = max(Maxi, dp[i]);
	}

	cout << Maxi << '\n';
}

