#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;
long long dp[1001];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }

    cout << dp[n] << '\n';
   
}
