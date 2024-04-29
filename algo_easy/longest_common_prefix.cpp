#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) {
        return *strs.begin();
    }
    
    std::sort(strs.begin(), strs.end());

    if (*strs.begin() == "") {
        return "";
    }

    std::string result("");
    int char_index = 0;

    while(1) {
        if (char_index == (*strs.begin()).size()) {
            break;
        }

        char first_item_char = (*(strs.begin()))[char_index];
        char last_item_char = (*(strs.end()-1))[char_index];

        if (first_item_char != last_item_char) {
            break;
        }

        result += first_item_char;
        char_index += 1;
    }

    return result;
}

int main() {
    vector<string> strs({"floral", "flower", "flour"});
    cout << longestCommonPrefix(strs) << "\n";

    return 0;
}