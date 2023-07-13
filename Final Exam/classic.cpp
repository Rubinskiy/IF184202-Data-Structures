#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool check_char(char c, string pos) {
    if (pos == "left") {
        return c == '(' || c == '{' || c == '[' || c == '<';
    } else {
        return c == ')' || c == '}' || c == ']' || c == '>';
    }
}

int main() {
    // make a program where we input brackets and '{' must have strength of 1 (which means position 0 in the string) and '(' must have strength 2
    // and '[' must have strength 3 and '<' must have strength 4
    // and the closing brackets must have the same strength as the opening brackets
    // and the brackets must be in the correct order
    // and the brackets must be balanced
    // and the brackets must be valid

    // () == valid
    // {[()]} == valid
    // {[()<>]} == invalid
    string input;
    cin >> input;
    stack<char> st;
    for (int i = 0; i < input.length(); i++) {
        if (input.length() % 2 != 0) {
            cout << "Invalid" << endl;
            return 0;
        } else if (input.length() > 2) {
            if (input[i] == '{' && i == 0) {
                st.push(input[i]);
            } else if (input[i] == '[' && i == 1) {
                st.push(input[i]);
            } else if (input[i] == '(' && i == 2) {
                st.push(input[i]);
            } else if (input[i] == '<' && i == 3) {
                st.push(input[i]);
            } else if (input[i] == ')' || input[i] == '}' || input[i] == ']' || input[i] == '>') {
                if (st.size() == 0) {
                    cout << "Invalid" << endl;
                    return 0;
                }
                char top = st.top();
                st.pop();
                if (input[i] == ')' && top != '(') {
                    cout << "Invalid" << endl;
                    return 0;
                } else if (input[i] == '}' && top != '{') {
                    cout << "Invalid" << endl;
                    return 0;
                } else if (input[i] == ']' && top != '[') {
                    cout << "Invalid" << endl;
                    return 0;
                } else if (input[i] == '>' && top != '<') {
                    cout << "Invalid" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Valid" << endl;
    return 0;
}