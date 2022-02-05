#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;




int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> dp1(n+1);
        vector<int> dp0(n+1);

        dp1[1] = dp1[2] = 1;
        dp0[0] = dp0[2] = dp0[3] = 1;

        for (int i = 4; i <= n; i++) {
            dp0[i] = dp0[i - 1] + dp0[i - 2];
        }

        for (int i = 3; i <= n; i++) {
            dp1[i] = dp1[i - 1] + dp1[i - 2];
        }

        cout << dp0[n] << ' ' << dp1[n] << '\n';
    }

}
