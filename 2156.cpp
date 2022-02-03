#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> A(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> A[i];
    
    dp[1] = A[1];
    dp[2] = A[1] + A[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (dp[i] < dp[i - 2] + A[i]) dp[i] = dp[i - 2] + A[i];
        if (dp[i] < dp[i - 3] + A[i - 1] + A[i]) dp[i] = dp[i - 3] + A[i - 1] + A[i];
    }

    cout << dp[n] << '\n';
   
}
