#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string str1, str2;
int dp[1001][1001];

int main() {

	cin >> str1;
	cin >> str2;

	str1 = '0' + str1;
	str2 = '0' + str2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[str1.size() - 1][str2.size() - 1] << '\n';

}

