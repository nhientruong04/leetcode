#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

// occurence array approach
bool isAnagram(vector <int> s, string t) {
    bool ret = true;

    // check size
    if (t.size() != accumulate(s.begin(), s.end(), 0)) {
        return false;
    }

    // check empty
    if (t == "") {
        for (int i=0; i<s.size(); i++) {
            if (s[i] != 0) {
                ret = false;
                break;
            }
        }
    }

    for (int i=0; i<t.size(); i++) {
        if (s[t[i]-'a'] > 0) {
            s[t[i]-'a']--;
        } else {
            ret = false;
            break;
        }
    }

    return ret;
}

void build_map (vector <int> &t_map, string t) {
    // construct key map
    for (int i=0; i<t.size(); i++) {
        t_map[t[i]-'a']++;
    }
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector <vector <string>> ret;
    vector <vector <int>> groups;

    bool contains_empty = false;

    for (int i=0; i<strs.size(); i++) {
        if (strs[i] == "") {
            if (!contains_empty) {
                contains_empty = true;
                vector <int> empty(26, 0);
                vector <string> empty_str {""};

                groups.push_back(empty);
                ret.push_back(empty_str);

                continue;
            }
        }

        bool added = false;

        for (int j=0; j<groups.size(); j++) {
            if (isAnagram(groups[j], strs[i])) {
                ret[j].push_back(strs[i]);
                added = true;
                break;
            }
        }

        if (added) {
            continue;
        }

        vector <int> occurrence_map(26, 0);
        vector <string> t_vector {strs[i]};
        build_map(occurrence_map, strs[i]);

        groups.push_back(occurrence_map);
        ret.push_back(t_vector);
    }

    return ret;
}

int main() {
    // vector <string> strs {"eat","tea","tan","ate","nat","bat"};
    vector <string> strs {"ac","c"};
    vector<vector<string>> ret = groupAnagrams(strs);

    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;
}