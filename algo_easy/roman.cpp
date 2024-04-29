#include <map>
#include <iostream>

int roman_to_integer(std::string s) {
    std::map<char, int> roman_map;
    roman_map['I'] = 1;
    roman_map['V'] = 5;
    roman_map['X'] = 10;
    roman_map['L'] = 50;
    roman_map['C'] = 100;
    roman_map['D'] = 500;
    roman_map['M'] = 1000;

    int result = 0;

    for (int i=0; i<s.length(); i++) {
        int curr_value = roman_map[s[i]];
        int next_value = roman_map[s[i+1]];

        if (curr_value<next_value && i+1<s.length()) {
            result -= curr_value;
            continue;
        }

        result += curr_value;
    }

    return result;
}

int main() {
    std::string s = "MCMXCIV";
    std::cout << roman_to_integer(s) << "\n";

    return 0;
}