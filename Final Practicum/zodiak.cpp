#include <bits/stdc++.h>
#include <cmath>

#define lld long long int
#define mod 1000000009
using namespace std;

lld getPow(lld n) {
    return (n * (n - 1))/2;
}

lld pow_function(lld number, lld exponent) {
    lld result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * number) % mod;
        }
        number = (number * number) % mod;
        exponent >>= 1;
    }
    return result;
}

int main() {
    lld m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        lld n;
        cin >> n;
        lld power = getPow(n);
        lld res = pow_function(2, power);
        cout << "Zodiak found: " << res % mod << " signs" << endl;
    }
}