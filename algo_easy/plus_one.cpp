#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    for (int i=digits.size()-1; i>=0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }

        digits[i] = 0;
    }

    if (digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main() {
    vector<int> digits({9,9,9,9});
    vector<int> plus_digits = plusOne(digits);

    for (auto i=plus_digits.begin(); i!=plus_digits.end(); i++) {
        cout << *i;
    }
    
    cout << "\n";

    return 0;
}