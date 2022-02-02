#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;
int dp[1001];

int main() {
    int n;
    cin >> n;

    vector<int> A(n);

    for (auto& a : A)
        cin >> a;

    int ret = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ret = max(ret, dp[i]);
    }

    cout << ret << '\n';
   
}
