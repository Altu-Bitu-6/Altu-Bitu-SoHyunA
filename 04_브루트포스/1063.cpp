#include <iostream>

using namespace std;

void kdMove(string m, char &k_c,int &k_i,char &d_c,int &d_i) {
    if (m == "R") {
        if (k_c == 'H') {
            return;
        }
        k_c++;
        if (d_c == k_c and d_i == k_i) {
            if (d_c == 'H') {
                k_c--;
                return;
            }
            d_c++;
        }
    }
    else if (m == "L") {
        if (k_c == 'A') {
            return;
        }
        k_c--;
        if (d_c == k_c and d_i == k_i) {
            if (d_c == 'A') {
                k_c++;
                return;
            }
            d_c--;
        }
    }
    else if (m == "B") {
        if (k_i == 1) {
            return;
        }
        k_i--;
        if (d_c == k_c and d_i == k_i) {
            if (d_i == 1) {
                k_i++;
                return;
            }
            d_i--;
        }
    }
    else if (m == "T") {
        if (k_i == 8) {
            return;
        }
        k_i++;
        if (d_c == k_c and d_i == k_i) {
            if (d_i == 8) {
                k_i--;
                return;
            }
            d_i++;
        }
    }
    else if (m == "RT") {
        if (k_c == 'H' or k_i == 8) {
            return;
        }
        k_c++; k_i++;
        if (d_c == k_c and d_i == k_i) {
            if (d_c == 'H' or d_i == 8) {
                k_c--; k_i--;
                return;
            }
            d_c++; d_i++;
        }
    }
    else if (m == "LT") {
        if (k_c == 'A' or k_i == 8) {
            return;
        }
        k_c--; k_i++;
        if (d_c == k_c and d_i == k_i) {
            if (d_c == 'A' or d_i == 8) {
                k_c++; k_i--;
                return;
            }
            d_c--; d_i++;
        }
    }
    else if (m == "RB") {
        if (k_c == 'H' or k_i == 1) {
            return;
        }
        k_c++; k_i--;
        if (d_c == k_c and d_i == k_i) {
            if (d_c == 'H' or d_i == 1) {
                k_c--; k_i++;
                return;
            }
            d_c++; d_i--;
        }
    }
    else if (m == "LB") {
        if (k_c == 'A' or k_i == 1) {
            return;
        }
        k_c--; k_i--;
        if (d_c == k_c and d_i == k_i) {
            if (d_c == 'A' or d_i == 1) {
                k_c++; k_i++;
                return;
            }
            d_c--; d_i--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string k, d; cin >> k >> d;
    char k_c = k[0]; int k_i = k[1]-48;
    char d_c = d[0]; int d_i = d[1]-48;

    int n; cin >> n;
    string m;
    while (n--) {
        cin >> m;
        kdMove(m, k_c, k_i, d_c, d_i);
    }
    cout << k_c << k_i << "\n" << d_c << d_i;
}
