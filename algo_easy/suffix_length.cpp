#include <iostream>
#include <algorithm>

using namespace std;

int lengthOfLastWord(string s) {
    string s1 = s;
    int length = 0;
    size_t index;

    if (s[s.size()-1] != ' ') {
        index = s.size() - 1;
    } else {
        string::iterator end_pos = remove(s.begin(), s.end(), ' ');
        s.erase(end_pos, s.end());

        index = s1.rfind(s[s.size()-1]);
    }

    while (index>=0 && s1[index]!=' ') {
        length++;

        if (index == 0) {
            break;
        }

        index--;
    }

    return length;
}

int main() {
    string s = "   the brown      fox     ";

    cout << lengthOfLastWord(s) << "\n";

    return 0;
}