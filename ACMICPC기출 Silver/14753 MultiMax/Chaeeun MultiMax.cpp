#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int input[10000];

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        input[i] = n;
    }

    sort(input, input + T);

    int case_array[7] = {0, };

    case_array[0] = input[0] * input[1];
    case_array[1] = input[0] * input[1] * input[2];
    case_array[2] = input[T-1] * input[T-2];
    case_array[3] = input[T-1] * input[T-2] * input[T-3];
    case_array[4] = input[0] * input[1] * input[T-1];
    case_array[5] = input[0] * input[T-1] * input[T-2];
    case_array[6] = input[0] * input[T-1];

    int max = 0;

    for (int i = 0; i < 7; i++) {
        if (max < case_array[i]) {
            max = case_array[i];
        }
    }
    cout << max << endl;

    return 0;
}