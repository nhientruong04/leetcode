#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if (s.size() == 1 || numRows == 1) {
        return s;
    }

    string result;

    for (int i=0; i<numRows; i++) {
        int char_index = i;

        while (char_index < s.size()) {
            if (i == numRows-1) {
                result += s[char_index];
                char_index += i*2;
                continue;
            }

            result += s[char_index];

            char_index += (numRows - i - 1)*2;

            if (i == 0) {
                continue;
            }

            if (char_index < s.size()) {
                result += s[char_index];

                char_index += i*2;
            }
        }
    }

    return result;

    // -------------------------------- better solution on leetcode ----------------------------------
    // if(numRows <= 1) return s;

    // vector<string>v(numRows, ""); 

    // int j = 0, dir = -1;

    // for(int i = 0; i < s.length(); i++)
    // {

    //     if(j == numRows - 1 || j == 0) dir *= (-1); 
		 
    //     v[j] += s[i];

    //     if(dir == 1) j++;

    //     else j--;
    // }

    // string res;

    // for(auto &it : v) res += it; 

    // return res;
}

int main() {
    string s = "PAYPALISHIRING";
    int num_rows = 3;

    cout << convert(s, num_rows) << "\n";
    
    return 0;
}