#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<cmath>
using namespace std;




int main() {
    int counter = 0, counter1 = 0;
    bool temp = false;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0' ) {
            temp = true;
            while(s[i] == '0' && i < s.length()) i++;
        }
        if (temp) {
            counter++;
            temp = false;
        }     
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            temp = true;
            while (s[i] == '1' && i < s.length()) i++;
        }
        if (temp) {
            counter1++;
            temp = false;
        }
    }
    cout << min(counter, counter1) << '\n';
}
