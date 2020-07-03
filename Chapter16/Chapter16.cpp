#include <iostream>

#include "Util.h"

using namespace std;

int main() {
    int x, y;
    while (cout << "0 0 to move on, or enter two integers.\n", cin >> x >> y) {
        if (x == 0 && y == 0) break;
        int result = compare(x, y);
        cout << "x: " << x << " is "
            << (result == 1 ? "greater than" : (result == 0 ? "equal to" : "less than"))
            << " y: " << y << endl;
    }
    string a, b;
    while (cin >> a >> b) {
        int result = compare(a, b);

        cout << "x: " << a << " is "
            << (result == 1 ? "greater than" : (result == 0 ? "equal to" : "less than"))
            << " y: " << b << endl;
    }
}
