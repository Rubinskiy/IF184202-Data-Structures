#include <iostream>
#include <vector>
#include <string>

#define lld long long int
using namespace std;

int main() {
    lld cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        lld items;
        lld counter = 0;
        cin >> items;
        for (int j = 0; j < items; j++) {
            string item;
            cin >> item;
            counter++;
        }
        //if (items == 2 && )
        if (counter % 2 == 1) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
}