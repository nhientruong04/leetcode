#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    if (s.size()==1) {
        return s;
    }
    if (s.size()==2) {
        if (s[0]==s[1]) {
            return s;
        } else {
            return s.substr(0,1);
        }
    }

    int i = 1;
    string ret_string = s.substr(0,1);
    int max_length = 0;

    while (i<s.size()) {
        if (s[i]==s[i-1]) {
            int left_ptr = i-1;
            int right_ptr = i;

            while (right_ptr<s.size()-1) {
                if (s[right_ptr] == s[right_ptr+1]) {
                    right_ptr++;
                } else {
                    break;
                }
            }

            while (left_ptr>0) {
                if (s[left_ptr] == s[left_ptr-1]) {
                    left_ptr--;
                } else {
                    break;
                }
            }

            right_ptr++;
            left_ptr--;

            while (right_ptr < s.size() && left_ptr>=0) {
                if (s[left_ptr]!=s[right_ptr]) {
                    break;
                }
                left_ptr--;
                right_ptr++;
            }

            int length = right_ptr-left_ptr-1;

            if (length > max_length) {
                max_length = length;
                ret_string = s.substr(left_ptr+1, length);
            }
        }
        
        if (i>=2 && s[i] == s[i-2]) {
            int left_ptr = i-3;
            int right_ptr = i+1;

            while (right_ptr < s.size() && left_ptr>=0) {
                if (s[left_ptr]!=s[right_ptr]) {
                    break;
                }
                left_ptr--;
                right_ptr++;
            }

            int length = right_ptr-left_ptr-1;

            if (length > max_length) {
                max_length = length;
                ret_string = s.substr(left_ptr+1, length);
            }
        }

        i++;
    }

    return ret_string;
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s) << endl;

    return 0;
}