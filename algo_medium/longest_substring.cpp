#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int return_length = 0;
    int curr_length = 0;
    if (s.size() == 0) {
        return return_length;
    }

    unordered_map<int, bool> encountered_chars;

    int first_pointer = 0;
    int second_pointer = 0;

    while (second_pointer<s.size()) {
        if (encountered_chars[s[second_pointer]-0]) {
            // if new char encountered, delete all other chars occurence status till this char 
            for (int i=first_pointer; i<second_pointer; i++) {
                if (s[i] == s[second_pointer]) {
                    first_pointer = i+1;
                    curr_length = second_pointer - first_pointer + 1;
                    break;
                }
                encountered_chars[s[i]-0] = false;
            }

            second_pointer++;
            continue;
        }

        // if new char hasn't been encountered, add to the map and +1 length
        encountered_chars[s[second_pointer]-0] = true;
        curr_length++;

        if (curr_length > return_length) {
            return_length = curr_length;
        }
    
        second_pointer++;
    }

    return return_length;
}

int main() {
    string s = "pwwkew";

    cout << lengthOfLongestSubstring(s) << "\n";

    return 0;
}