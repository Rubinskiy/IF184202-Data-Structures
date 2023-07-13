#include <iostream>
#include <vector>

#define lld long long int
using namespace std;

// modulus because even lld cant handle that many nums
const lld modulo = 1000000007;

// function to the result of n! % modulo
lld factor_out (lld n) {
    lld res = 1;

    // multiply res by i and mod it by modulo
    for (lld i = 2; i <= n; i++) {
        res = (res * i) % modulo;
    }
    return res;
}

// function to find the lexical index of a given permutation
lld lexical_index (vector<lld> arr) {
    lld n = arr.size();
    lld index = 0;
    for (lld i = 0; i < n; i++) {
        int smaller = 0;

        // count the number of elements smaller than arr[i] to the right of it
        for (lld j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                smaller++;
            }
        }

        // add the number of smaller elements * (n - i - 1)! to the index
        index = (index + (smaller * factor_out(n - i - 1)) % modulo) % modulo;
    }
    return (index + 1) % modulo;
}

int main() {
    lld queries; 
    cin >> queries;
    vector<lld> arr;

    // input the array
    for (lld i = 0; i < queries; ++i) {
        lld input;
        cin >> input;
        arr.push_back(input);
    }

    lld index = lexical_index(arr);
    cout << index << endl;
    return 0;
}