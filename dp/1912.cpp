#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<long long> A(n);
    vector<long long> dp(n);

    for (auto& a : A)
        cin >> a;

    dp[0] = A[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(A[i], dp[i - 1] + A[i]);
    }
    
    sort(dp.begin(), dp.end());

    cout << dp[n-1] << '\n';

   
}
