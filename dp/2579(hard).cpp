#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long dp[301];

int main() {
    int n;
    cin >> n;

    vector<int> v(n+1);

    for (int i = 1; i <= n ; i++)
        cin >> v[i];

    dp[1] = v[1];
    dp[2] = max(v[1], v[1] + v[2]);
    dp[3] = max(v[1] + v[3], v[2] + v[3]);

    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 2] + v[i], v[i - 1] + dp[i - 3] + v[i]);
    }

    cout << dp[n] << '\n';
   

}
