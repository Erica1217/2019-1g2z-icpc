#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b);

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        
        int x;
        int g;
        while (a != 1){
            x = (b / a) + 1;
            a = a * x - b;
            b = b * x;
            
            g = gcd(a,b);
            a /= g;
            b /= g;
            
        }
        cout << b << endl;
    }
    
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
