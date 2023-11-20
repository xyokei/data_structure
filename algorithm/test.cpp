//
// Created by AutumnSigni on 2023/10/23.
//
#include <iostream>
#include <string>

using namespace std;

string add(const string& a, const string& b) {
    string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 10;
        sum %= 10;
        result.insert(result.begin(), sum + '0');
    }

    return result;
}
string subtract(const string& a, const string& b) {
    string result;
    int borrow = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? (a[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;

        int diff = x - y - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.insert(result.begin(), diff + '0');
        i--;
        j--;
    }

    // Remove leading zeros
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
}
string multiply(const string& x, const string& y) {
    int n = max(x.size(), y.size());

    if (n == 1) {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }

    int mid = n / 2;
    string x1 = x.substr(0, x.size() - mid);
    string x0 = x.substr(x.size() - mid);
    string y1 = y.substr(0, y.size() - mid);
    string y0 = y.substr(y.size() - mid);

    string z0 = multiply(x0, y0);
    string z2 = multiply(x1, y1);
    string z1 = multiply(add(x0, x1), add(y0, y1));
    z1 = subtract(subtract(z1, z0), z2);
    string result = z2;
    for (int i = 0; i < 2 * mid; ++i) {
        z2.push_back('0');
    }
    for (int i = 0; i < mid; ++i) {
        z1.push_back('0');
    }
    result = add(z2, z1);
    result = add(result, z0);

    return result;
}

int main() {
    string x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    string result = multiply(x, y);
    cout << "Multiplication result: " << result << endl;

    return 0;
}
