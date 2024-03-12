#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long n; int k; cin >> n >> k;

    int cnt = 0;
    for (int i = 0; i < 30; i++) {
        if (n & ((long)1 << i)) {
            cnt++;
        }
    }
    int p = 0;
    while (cnt > k) {
        cnt = 0;
        n++; p++;
        for (int i = 0; i < 30; i++) {
            if (n & ((long)1 << i)) {
                cnt++;
            }
        }
    }
    cout << p;
    

    return 0;
}

