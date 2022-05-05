#include<iostream>
#include<vector>

using namespace std;

int a, b;

int main() {
    int max_a = 0, min_a = 0, max_b = 0, min_b = 0;
    cin >> a >> b;

    int i = 1000000;

    while (i > 0) {
       
        
        if (a / i == 5) {
            min_a += (a / i) * i;
            max_a += ((a / i) + 1) * i;
        }
        else if (a / i == 6) {
            min_a += ((a / i) - 1) * i;
            max_a += (a / i) * i;
        }
        else {
            min_a += (a / i) * i;
            max_a += (a / i) * i;
        }
        if (b / i == 5) {
            min_b += (b / i) * i;
            max_b += ((b / i) + 1) * i;
        }
        else if (b / i == 6) {
            min_b += ((b / i) - 1) * i;
            max_b += (b / i) * i;
        }
        else {
            min_b += (b / i) * i;
            max_b += (b / i) * i;
        }
        a = a % i;
        b = b % i; 
        i /= 10;
    }

    cout << min_a + min_b <<' '<< max_a + max_b << '\n';
}
