#include <unordered_map>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string intToRoman(int num) {
    unordered_map<int, char> roman_map;
    roman_map[1] = 'I';
    roman_map[5] = 'V';
    roman_map[10] = 'X';
    roman_map[50] = 'L';
    roman_map[100] = 'C';
    roman_map[500] = 'D';
    roman_map[1000] = 'M';

    string result;
    string num_str = to_string(num);
    int num_rank = num_str.size()-1;

    for (int i=0; i<num_str.size(); i++) {
        int curr_num = num_str[i] - '0';

        if (roman_map.find(curr_num * int(pow(10, num_rank - i))) != roman_map.end()) {
            result += roman_map[curr_num * int(pow(10, num_rank - i))];
            continue;
        }

        if (curr_num == 4 || curr_num == 9) {
            result += roman_map[int(pow(10, num_rank - i))];
            result += roman_map[(curr_num+1) * int(pow(10, num_rank - i))];
            continue;
        }

        int remainder;

        if (curr_num > 5) {
            remainder = curr_num - 5;
            result += roman_map[5 * int(pow(10, num_rank - i))];
        } else {
            remainder = curr_num;
        }

        while (remainder > 0) {
            result += roman_map[int(pow(10, num_rank - i))];
            remainder--;
        }
    }

    return result;
}

int main() {
    int num = 3749;
    cout << intToRoman(num) << "\n";

    return 0;
}