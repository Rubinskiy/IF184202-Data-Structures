#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    vector<char> stack;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
            stack.push_back(input[i]);
        } else if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
            if (stack.size() == 0) {
                cout << "unvaldi" << endl;
                return 0;
            }
            char top = stack.back();
            stack.pop_back();
            if (input[i] == ')' && top != '(') {
                cout << "unvaldi" << endl;
                return 0;
            } else if (input[i] == '}' && top != '{') {
                cout << "unvaldi" << endl;
                return 0;
            } else if (input[i] == ']' && top != '[') {
                cout << "unvaldi" << endl;
                return 0;
            }
        }
    }
    if (stack.size() == 0) {
        cout << "valdi" << endl;
    } else {
        cout << "unvaldi" << endl;
    }
    return 0;
}