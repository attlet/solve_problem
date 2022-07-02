#include<iostream>
#include<string>
#include<vector>

using namespace std;

string name;
string ret;
int alpha[26];
int Find[26];

int check = 0;

int main() {
    cin >> name;

    for (int i = 0; i < name.size(); i++) 
        alpha[name[i] - 65]++;
    
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 1) {
            Find[i] = 0;
        }
        else if (alpha[i] == 0) {
            Find[i] = -1;
        }
        else if(alpha[i] % 2 == 1){
            Find[i] = 1;
        }
     
    }
    int len = name.size();

    
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 == 1) {
            check++;
        }
    }

    if (check > 1 || ((check == 1) && (name.size() % 2 == 0))) {
        cout<<"I'm Sorry Hansoo"<<'\n';
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alpha[i]/2; j++) {
            ret += 'A' + i;
        }
       
    }

    for (int i = 0; i < 26; i++) {
        if (Find[i] == 0 || Find[i] == 1) {
            ret += 'A' + i;
        }
    }
    
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < alpha[i] / 2; j++) {
            ret += 'A' + i;
        }
    }



    
    cout << ret << '\n';

}
