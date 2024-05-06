#include <unordered_map>
#include <iostream>
#include <stack>
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
    stack<int> digit_stack;
    int num_rank = -1;

    while (num > 0) {
        digit_stack.push(num%10);

        num_rank++;
        num = (num - num%10)/10;
    }

    while (!digit_stack.empty()) {
        int curr_num = digit_stack.top();

        if (curr_num == 4 || curr_num == 9) {
            result += roman_map[int(pow(10, num_rank))];
            result += roman_map[(curr_num+1) * int(pow(10, num_rank))];

            num_rank--;
            digit_stack.pop();
            continue;
        }

        if (curr_num == 5) {
            result += roman_map[5 * int(pow(10, num_rank))];
            num_rank--;
            digit_stack.pop();
            continue;
        }

        int remainder;

        if (curr_num > 5) {
            remainder = curr_num - 5;
            result += roman_map[5 * int(pow(10, num_rank))];
        } else {
            remainder = curr_num;
        }

        while (remainder > 0) {
            result += roman_map[int(pow(10, num_rank))];
            remainder--;
        }

        digit_stack.pop();
        num_rank--;
    }

    return result;
}

int main() {
    int num = 101;
    cout << intToRoman(num) << "\n";

    return 0;
}