#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidParentheses(string s) {
    stack<char> received_parentheses;
    vector<char> open_parentheses({'(', '{', '['});

    int i = 0;
    bool valid = true;

    if (find(open_parentheses.begin(), open_parentheses.end(), s[i]) == open_parentheses.end()) {
        return false;
    }

    while (i<s.size() && valid) {
        if (find(open_parentheses.begin(), open_parentheses.end(), s[i]) != open_parentheses.end()) {
            received_parentheses.push(s[i]);
            i++;
            continue;
        }

        if (received_parentheses.empty()) {
            valid = false;
            break;
        }

        switch (s[i])
        {
        case ')':
            if (received_parentheses.top() != '(') {
                valid = false;
            }

            received_parentheses.pop();
            break;
        case '}':
            if (received_parentheses.top() != '{') {
                valid = false;
            }

            received_parentheses.pop();
            break;
        case ']':
            if (received_parentheses.top() != '[') {
                valid = false;
            }

            received_parentheses.pop();
            break;
        }

        i++;
    }

    return valid && received_parentheses.empty();
}

int main() {
    string s = "(){}}{";

    cout << isValidParentheses(s) << "\n";

    return 0;
}