#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<cmath>
using namespace std;


map<char, int> m;


int main() {
    
    int n;
    cin >> n;

    vector<string> str(n);

    for (int i = 0; i < n; i++) {
        cin >> str[i];
        
        for (int j = 0; j < str[i].size(); j++) {
          
            m[str[i][j]] += pow(10, str[i].size() - 1 - j);
        }

    }
    
    vector<int> v;

    for (int i = 0; i < 26; i++) {
        if (m['A' + i] != 0) {
            v.push_back(m['A' + i]);
        }
    }

    sort(v.begin(), v.end(), greater<>());

    int ans = 0;

    for (int i = 0; i < v.size(); i++) {
        ans += (9 - i) * v[i];
    }

    cout << ans << '\n';
}
