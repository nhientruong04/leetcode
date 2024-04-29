#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size()) {
        return -1;
    }

    int index = -1;

    for (int i=0; i<=haystack.size()-needle.size(); i++) {
        if (haystack[i] != needle[0]) {
            continue;
        }

        if (haystack.substr(i, needle.size()) == needle) {
            index = i;
            break;
        }
    }
    
    return index;
}

int main() {
    string s = "adbutsad";
    string needle = "sad";

    cout << strStr(s, needle) << "\n";    

    return 0;
}