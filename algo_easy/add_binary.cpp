#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
    string result;

    int index_a = a.length() - 1;
    int index_b = b.length() - 1;
    int r = 0;

    while (index_a >= 0 && index_b >= 0) {
        char c;

        if (r) {
            if (a[index_a] == '0') {
                c = '1';
                r--;
            } else {
                c = '0';
            }
        } else {
            c = a[index_a];
        }

        if (c=='1' && b[index_b]=='1') {
            r++;
            c = '0';
        } else if (c=='0' && b[index_b]=='0') {
            c = '0';
        } else {
            c = '1';
        }

        result.push_back(c);

        index_a--;
        index_b--;
    }

    string remainder_string = (index_a>=0) ? a.substr(0, index_a+1) : b.substr(0, index_b+1);
    int remainder_index = remainder_string.length() - 1;

    while (remainder_index>=0) {
        char c;
        if (r) {
            if (remainder_string[remainder_index] == '1') {
                c = '0';
            } else {
                c = '1';
                r--;
            }
            
        } else {
            c = remainder_string[remainder_index];
        }

        result.push_back(c);

        remainder_index--;
    }

    if (r) {
        result.push_back('1');
    }

    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    string a = "1010";
    string b = "1011";

    cout << addBinary(a, b);
    
    cout << "\n";

    return 0;
}