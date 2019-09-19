#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

void dec_to_n(int n, int digit);
bool is_palindrome(int n);

int remainder_for_convert[100];

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        int result = 0;
        for (int j = 2; j <= 64; j++) {
            dec_to_n(n, j);

            if (is_palindrome(n)) {
                result = 1;
                break;
            }
            else {
                result = 0;
            }
        }

        cout << result << endl;
    }

    return 0;
}

void dec_to_n(int n, int digit) {
    for (int i = 0; i < 100; i++) {
        remainder_for_convert[i] = -1;
    }

    int number_to_divide = n;
    int remainder;

    int index = 0;
    while (number_to_divide >= digit) {
        remainder = number_to_divide % digit;
        number_to_divide /= digit;
        remainder_for_convert[index] = remainder;
        index++;
    }
    remainder_for_convert[index] = number_to_divide;
}

bool is_palindrome(int n) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        if (remainder_for_convert[i] != -1) {
            count++;
        }
    }

    bool is_same = true;
    for (int i = 0; i < count; i++) {
        if (remainder_for_convert[i] != remainder_for_convert[count - i - 1]) {
            is_same = false;
            break;
        }
    }
    return is_same;
}