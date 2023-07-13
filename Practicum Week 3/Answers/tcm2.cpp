#include <iostream>
#include <vector>
#include <algorithm>

#define lld long long int
using namespace std;

const lld MOD = 1000000007;

// Function to calculate the factorial of a number modulo MOD
lld factorial(lld n) {
    if (n <= 1)
        return 1;

    lld fact = 1;
    for (lld i = 2; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

// Function to find the lexicographical order of a given permutation modulo MOD
lld findLexicalOrder(vector<lld>& permutation) {
    lld n = permutation.size();
    vector<lld> sortedPermutation = permutation;
    sort(sortedPermutation.begin(), sortedPermutation.end());

    lld lexicalOrder = 0;
    for (lld i = 0; i < n; i++) {
        lld position = find(sortedPermutation.begin(), sortedPermutation.end(), permutation[i]) - sortedPermutation.begin();
        lexicalOrder = (lexicalOrder + (position * factorial(n - i - 1)) % MOD) % MOD;
        sortedPermutation.erase(sortedPermutation.begin() + position);
    }

    return lexicalOrder;
}

int main() {
    lld queries; 
    cin >> queries;
    vector<lld> permutation;

    // input the array
    for (lld i = 0; i < queries; ++i) {
        lld input;
        cin >> input;
        permutation.push_back(input);
    }

    lld lexicalIndex = findLexicalOrder(permutation);
    cout << lexicalIndex + 1 << endl;

    return 0;
}
