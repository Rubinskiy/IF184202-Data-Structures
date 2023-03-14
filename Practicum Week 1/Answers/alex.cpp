#include <deque>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    // n and q
    int n, q;
    // size of deque and queries
    scanf(" %d %d", &n, &q);
    deque<int> nums;
    // add to deque
    for (int i = 0; i < n; i++) {
        int num;
        scanf(" %d", &num);
        nums.push_back(num);
    }

    // if there are no queries, print input not valid
    if (q == 0) {
        printf("Input Not Valid\n");
        return 0;
    }

    deque<pair<int,int>> output;
    // for each query, do the following
    for (int i = 0; i < q; i++) {
        int m;
        scanf(" %d", &m);
        // make a copy of nums to do the operations
        deque<int> nums_copy = nums;
        for (int j = 1; j <= m; j++) {
            // pop A and B so the next batch can come in
            int a = nums_copy.front();
            nums_copy.pop_front();
            int b = nums_copy.front();
            nums_copy.pop_front();

            // if the iteration is the last one, add to the output
            if (j == m) {
                output.push_back(make_pair(a, b));
            }

            // operation requirement
            if (a > b) {
                nums_copy.push_front(a);
                nums_copy.push_back(b);
            } else if (a < b) {
                nums_copy.push_front(b);
                nums_copy.push_back(a);
            }
        }
    }

    // print the outputs  
    for (int i = 0; i < q; i++) {
        printf("%d %d\n", output[i].first, output[i].second);
    }
    return 0;
}