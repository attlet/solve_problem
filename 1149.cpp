#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<cmath>

using namespace std;
int dp[1001][3];
int color[1001][3];

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < 3; j++) 
			cin >> color[i][j];
		
	
	for (int i = 0; i < 3; i++)
		dp[1][i] = color[1][i];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			int min = 987654321;
			
			for (int z = 0; z < 3; z++) {
				if (z == j) continue;
				if (min > dp[i - 1][z]) min = dp[i - 1][z];
			}
			dp[i][j] = min + color[i][j];
		}
	}
		
	int ret = 987654321;

	for (int i = 0; i < 3; i++) {
		if (ret > dp[n][i]) ret = dp[n][i];
	}

	cout << ret << '\n';
 
}
