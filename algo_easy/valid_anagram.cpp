#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// hash map approach
bool isAnagram_unordered_map(string s, string t) {
    if (s.size()!=t.size()) {
        return false;
    }

    unordered_map <char, int> checkmap;

    // construct key map
    for (int i=0; i<s.size(); i++) {
        if (checkmap.find(s[i]) != checkmap.end()) {
            checkmap[s[i]]++;
        } else {
            checkmap[s[i]] = 1;
        }
    }

    // check t
    for (int i=0; i<s.size(); i++) {
        if (checkmap.find(t[i]) != checkmap.end() && checkmap[t[i]] > 0) {
            checkmap[t[i]]--;
        } else {
            return false;
        }
    }

    return true;
}

// occurence array approach
bool isAnagram_occurence_arr(string s, string t) {
    if (s.size()!=t.size()) {
        return false;
    }

    vector<int> occurrence_arr(26,0);

    // construct key map
    for (int i=0; i<s.size(); i++) {
        occurrence_arr[s[i]-'a']++;
    }

    // check t
    for (int i=0; i<s.size(); i++) {
        if (occurrence_arr[t[i]-'a']>0) {
            occurrence_arr[t[i]-'a']--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "cat";
    string t = "rat";

    cout << isAnagram_occurence_arr(s, t) << endl;    

    return 0;
}